//TP 2021/2022: Zadaća 5, Zadatak 5
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <cmath>
#include <fstream>
#include <vector>

template <typename TipEl>
class Matrica
{
    int br_redova, br_kolona;
    TipEl **elementi;
    char ime_matrice;
    static TipEl **AlocirajMemoriju(int br_redova, int br_kolona);
    static void DealocirajMemoriju(TipEl **elementi, int br_redova);
    void KopirajElemente(TipEl **elementi);
public:
    Matrica(int br_redova, int br_kolona, char ime = 0);
    Matrica(const char ime_datoteke[], bool binarna_dat);
    ~Matrica()
    {
        DealocirajMemoriju(elementi, br_redova);
    }
    TipEl* operator [](int indeks) const
    {
        return elementi[indeks];
    }
    TipEl* &operator [](int indeks)
    {
        return elementi[indeks];
    }
    TipEl &operator ()(int a, int b)
    {
        if (a<1 || a>br_redova || b<1 || b>br_kolona)
        {
            throw std::range_error("Neispravan indeks");
        }
        return elementi[a-1][b-1];
    }
    TipEl operator ()(int a,int b) const
    {
        if (a<1 || a>br_redova || b<1 || b>br_kolona)
        {
            throw std::range_error("Neispravan indeks");
        }
        return elementi[a-1][b-1]; 
    }
    Matrica(const Matrica &m);
    Matrica(Matrica &&m);
    Matrica &operator =(const Matrica &m);
    Matrica &operator =(Matrica &&m);
    friend Matrica<TipEl> &operator +=(Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
    {
        auto m3=m1+m2;
        m1=m3;
        return m1;
    }
    friend Matrica<TipEl> &operator -=(Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
    {
        auto m3=m1-m2;
        m1=m3;
        return m1;
    }
    friend Matrica<TipEl> operator *=(Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
    {
        auto m3=m1*m2;
        m1=m3;
        return m1;
    }
    friend Matrica<TipEl> operator *=(Matrica<TipEl> &m1, double a)
    {
        auto m3=m1*a;
        m1=m3;
        return m1;
    }
    void SacuvajUTekstualnuDatoteku(const char ime_datoteke[]) const
    {
        std::ofstream izlazni_tok(ime_datoteke);
        for(int i=0;i<br_redova;i++)
        {
            for(int j=0;j<br_kolona;j++)
            {
                if(j!=br_kolona-1)
                {
                    izlazni_tok << elementi[i][j] << ",";
                }
                else
                izlazni_tok << elementi[i][j];
            }
            izlazni_tok << "\n";
        }
        if(!izlazni_tok)
        {
            throw std::logic_error("Problemi sa upisom u datoteku");
        }
    }
    void SacuvajUBinarnuDatoteku(const char ime_datoteke[]) const
    {
        std::ofstream izlazni_tok(ime_datoteke);
        izlazni_tok.write(reinterpret_cast<const char*>(this),sizeof *this);
        for(int i=0;i<br_redova;i++)
        {
            for(int j=0;j<br_kolona;j++)
            {
                izlazni_tok.write(reinterpret_cast<const char*>(&elementi[i][j]), sizeof (TipEl));
            }
        }
        if(!izlazni_tok)
        {
            throw std::logic_error("Problemi sa upisom u datoteku");
        }
    }
    void ObnoviIzTekstualneDatoteke(const char ime_datoteke[])
    {
        std::ifstream ulazni_tok(ime_datoteke);
        if(!ulazni_tok)
        {
            throw std::logic_error("Trazena datoteka ne postoji");
        }
        TipEl element;
        int col=0;
        std::vector<int> kolone;
        int red=0;
        while(ulazni_tok >> element)
        {
            col++;
            if(ulazni_tok.peek()==EOF)
            {
                red++;
                break;
            }
            char znak=ulazni_tok.get();
            if(znak!=',' && znak!='\n')
            {
                ulazni_tok.setstate(std::ios::failbit);
            }
            if(znak=='\n')
            {
                red++;
                kolone.push_back(col);
                col=0;
            }
        }
        if(ulazni_tok.eof());
        else if(ulazni_tok.bad())
        {
            throw std::logic_error("Problemi pri citanju datoteke");
        }
        else
        {
            throw std::logic_error("Datoteka sadrzi besmislene podatke");
        }
        bool grbava_matrica=false;
        for(int i=0; i<int(kolone.size())-1;i++)
        {
            if(kolone.at(i)!=kolone.at(i+1))
            {
                grbava_matrica=true;
            }
        }
        if(grbava_matrica==true)
        {
            throw std::logic_error("Datoteka sadrzi besmislene podatke");
        }
        DealocirajMemoriju(elementi, br_redova);
        br_redova=red;
        br_kolona=kolone.at(0);
        try
        {
            elementi=AlocirajMemoriju(br_redova,br_kolona);
        }
        catch(...)
        {
            throw;
        }
        std::ifstream ulazni_tok1(ime_datoteke);
        for(int i=0;i<red;i++)
        {
            for(int j=0;j<col;j++)
            {
                char znak;
                ulazni_tok1 >> elementi[i][j];
                znak=ulazni_tok1.get();
                if(znak=='\n')
                {
                    break;
                }
                else if(znak==-1)
                {
                    return;
                }
            }
        }
    }
    void ObnoviIzBinarneDatoteke(const char ime_datoteke[])
    {
        std::ifstream ulazni_tok(ime_datoteke, std::ios::binary);
        if(!ulazni_tok)
        {
            throw std::logic_error("Trazena datoteka ne postoji");
        }
        DealocirajMemoriju(elementi, br_redova);
        ulazni_tok.read(reinterpret_cast<char*>(this), sizeof *this);
        elementi=new TipEl*[br_redova] {};
        try
        {
            for(int i=0;i<br_redova;i++)
            {
                elementi[i]=new TipEl[br_kolona];
            }
        }
        catch(...)
        {
            DealocirajMemoriju(elementi, br_redova);
            throw;
        }
        for(int i=0;i<br_redova;i++)
        {
            for(int j=0;j<br_kolona;j++)
            {
                ulazni_tok.read(reinterpret_cast<char*>(&elementi[i][j]), sizeof elementi[i][j]);
            }
        }
        if(!ulazni_tok)
        {
            for(int i=0;i<br_redova;i++)
            {
                delete[] elementi[i];
            }
            delete[] elementi;
            if(ulazni_tok.bad())
            {
                throw std::logic_error("Problemi pri citanju datoteke");
            }
            else
            {
                throw std::logic_error("Datoteka sadrzi besmislene podatke");
            }
        }
    }
    friend std::ostream &operator <<(std::ostream &tok, const Matrica<TipEl> &mat)
    {
        int br=tok.width();
        for(int i=0; i<mat.br_redova; i++)
        {
            for(int j=0; j<mat.br_kolona; j++)
            {
                tok<<std::setw(br)<<mat.elementi[i][j];
            }
        std::cout<< std::endl;
        }
        return tok;
    }
    friend std::istream &operator >>(std::istream &tok, Matrica<TipEl> &m)
    {
        for(int i=0; i<m.br_redova; i++)
        {
            for(int j=0; j<m.br_kolona; j++)
            {
            std::cout<<m.ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            tok >> m.elementi[i][j];
            }
        }
        return tok;
    }
    friend Matrica<TipEl> operator +(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
    {
        if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
        {
            throw std::domain_error("Matrice nemaju jednake dimenzije!");
        }
        Matrica<TipEl> m3(m1.br_redova,m1.br_kolona);
        for(int i=0; i<m1.br_redova; i++)
        {
            for(int j=0; j<m1.br_kolona; j++)
            {
                m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
            }
        }
        return m3;
    }
    friend Matrica<TipEl> operator -(const Matrica<TipEl> &m1,const Matrica<TipEl> &m2)
    {
        if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
        {
            throw std::domain_error("Matrice nemaju jednake dimenzije!");
        }
        Matrica<TipEl> m3(m1.br_redova,m2.br_kolona);
        for(int i=0; i<m1.br_redova; i++)
        {
            for(int j=0; j<m1.br_kolona; j++)
            {
                m3.elementi[i][j]=m1.elementi[i][j]-m2.elementi[i][j];
            }
        }
        return m3;
    }
    friend Matrica<TipEl> operator *(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
    {
        if(m1.br_kolona!=m2.br_redova)
        {
            throw std::domain_error("Matrice nisu saglasne za mnozenje");
        }
        Matrica<TipEl> m3(m1.br_redova,m2.br_kolona);
        for(int i=0; i<m1.br_redova; i++)
        {
            for(int j=0; j<m2.br_kolona; j++)
            {
                int proizvod=0;
                for(int k=0; k<m2.br_redova; k++)
                {
                    proizvod+=m1.elementi[i][k]*m2.elementi[k][j];
                }
            m3.elementi[i][j]=proizvod;
            }
        }
        return m3;
    }
    friend Matrica<TipEl> operator *(int a, const Matrica<TipEl> &m)
    {
        Matrica<TipEl> m3(m.br_redova,m.br_kolona);
        for(int i=0; i<m.br_redova; i++)
        {
            for(int j=0; j<m.br_kolona; j++)
            {
                m3.elementi[i][j]=m.elementi[i][j]*a;
            }
        }
        return m3;
    }
    friend Matrica<TipEl> operator *(const Matrica<TipEl> &m, int a)
    {
        Matrica<TipEl> m3(m.br_redova,m.br_kolona);
        for(int i=0; i<m.br_redova; i++)
        {
            for(int j=0; j<m.br_kolona; j++)
            {
                m3.elementi[i][j]=m.elementi[i][j]*a;
            }
        }
        return m3;
    }
    operator std::string() const
    {
        std::string stri;
        stri.push_back('{');
        for(int i=0; i<br_redova; i++)
        {
            stri.push_back('{');
            for(int j=0; j<br_kolona; j++)
            {
                stri+=std::to_string(int(elementi[i][j]));
                if(j!=br_kolona-1)
                {   
                    stri.push_back(',');
                }
                if(j==br_kolona-1)
                { 
                    stri.push_back('}');
                }
            }
            if(i!=br_redova-1)
            { 
                stri.push_back(',');
            }
        }
        stri.push_back('}');
        return stri;
    }
    void Unesi();
    void Ispisi(int sirina_ispisa) const;
    template <typename Tip2>
    friend Matrica<Tip2> ZbirMatrica(const Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
};

template <typename TipEl>
TipEl ** Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona)
{
    TipEl **elementi = new TipEl*[br_redova]{};
    try
    {
        for(int i = 0; i < br_redova; i++)
        {
            elementi[i] = new TipEl[br_kolona];
        }
    }
    catch(...)
    {
        DealocirajMemoriju(elementi, br_redova);
        throw;
    }
    return elementi;
}

template <typename TipEl>
void Matrica<TipEl>::DealocirajMemoriju(TipEl **elementi, int br_redova)
{
    for(int i = 0; i < br_redova; i++) 
    {
        delete[] elementi[i];
    }
    delete[] elementi;
}

template <typename TipEl>
void Matrica<TipEl>::KopirajElemente(TipEl **elementi)
{
    for(int i = 0; i < br_redova; i++)
    {
        for(int j = 0; j < br_kolona; j++)
        {
            Matrica::elementi[i][j] = elementi[i][j];
        }
    }
}

template <typename TipEl>
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime) : br_redova(br_redova), br_kolona(br_kolona), ime_matrice(ime),
elementi(AlocirajMemoriju(br_redova, br_kolona)) {}

template <typename TipEl>
Matrica<TipEl>::Matrica(const Matrica<TipEl> &m) : br_redova(m.br_redova), br_kolona(m.br_kolona), ime_matrice(m.ime_matrice),
elementi(AlocirajMemoriju(m.br_redova, m.br_kolona))
{
    KopirajElemente(m.elementi);
}

template<typename TipEl>
Matrica<TipEl>::Matrica(const char ime_datoteke[], bool binarna_dat)
{
    br_kolona=0;
    br_redova=0;
    elementi=nullptr;
    if(binarna_dat==true)
    {
        try
        {
            ObnoviIzBinarneDatoteke(ime_datoteke);
        }
        catch(...)
        {
            throw;
        }
    }
    else
    {
        try
        {
            ObnoviIzTekstualneDatoteke(ime_datoteke);
        }
        catch(...)
        {
            throw;
        }
    }
}

template <typename TipEl>
Matrica<TipEl>::Matrica(Matrica<TipEl> &&m) : br_redova(m.br_redova), br_kolona(m.br_kolona), elementi(m.elementi), ime_matrice(m.ime_matrice)
{
    m.br_redova = 0; m.elementi = nullptr;
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(const Matrica<TipEl> &m)
{
    if(br_redova < m.br_redova || br_kolona < m.br_kolona)
    {
        TipEl **novi_prostor = AlocirajMemoriju(m.br_redova, m.br_kolona);
        DealocirajMemoriju(elementi, br_redova);
        elementi = novi_prostor;
    }
    else if(br_redova > m.br_redova)
    {
        for(int i = m.br_redova; i < br_redova; i++) 
        {
            delete elementi[i];
        }
    }
    br_redova = m.br_redova; br_kolona = m.br_kolona;
    ime_matrice = m.ime_matrice; KopirajElemente(m.elementi);
    return *this;
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(Matrica<TipEl> &&m)
{
    std::swap(br_redova, m.br_redova);
    std::swap(br_kolona, m.br_kolona);
    std::swap(ime_matrice, m.ime_matrice);
    std::swap(elementi, m.elementi);
    return *this;
}
    
template <typename TipEl>
void Matrica<TipEl>::Unesi()
{
    for(int i = 0; i < br_redova; i++)
    {
        for(int j = 0; j < br_kolona; j++)
        {
            std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> elementi[i][j];
        }
    }
}

template <typename TipEl>
void Matrica<TipEl>::Ispisi(int sirina_ispisa) const
{
    for(int i = 0; i < br_redova; i++)
    {
        for(int j = 0; j < br_kolona; j++)
        {
            std::cout << std::setw(sirina_ispisa) << elementi[i][j];
        }
        std::cout << std::endl;
    }
}
    
template <typename TipEl>
Matrica<TipEl> ZbirMatrica(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
    {
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    }
    Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
    for(int i = 0; i < m1.br_redova; i++)
    {
        for(int j = 0; j < m1.br_kolona; j++)
        {
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        }
    }
    return m3;
}


int main()
{
    return 0;
}