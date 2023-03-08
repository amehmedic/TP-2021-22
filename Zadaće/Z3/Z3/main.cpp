//TP 2021/2022: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
#include <algorithm>


template <typename TipElemenata>
struct Matrica
{
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr; // VEOMA BITNA INICIJALIZACIJA!!!
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> &mat)
{
    if(!mat.elementi) return;
    for(int i = 0; i < mat.br_redova; i++)
    {   
        delete[] mat.elementi[i];
    }
    delete[] mat.elementi;
    mat.elementi = nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova]{};
    try
    {
        for(int i = 0; i < br_redova; i++)
        {
            mat.elementi[i] = new TipElemenata[br_kolona];
        }
    }
    catch(...)
    {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice,Matrica<TipElemenata> &mat)
{
    for(int i = 0; i < mat.br_redova; i++)
    {
        for(int j = 0; j < mat.br_kolona; j++)
        {
            std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false)
{
    for(int i = 0; i < mat.br_redova; i++)
    {
        for(int j = 0; j < mat.br_kolona; j++)
        {
            std::cout << std::setprecision(preciznost) << std::setw(sirina_ispisa)  << mat.elementi[i][j];
        }
        std::cout << std::endl;
    }
    auto Brisiga=mat;
    if(treba_brisati) UnistiMatricu(Brisiga);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3 = StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona);
    for(int i = 0; i < m1.br_redova; i++)
    {
        for(int j = 0; j < m1.br_kolona; j++)
        {
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        }
    }
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &mat1, const Matrica<TipElemenata> &mat2)
{
    if(mat1.br_kolona!=mat2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto Matrica=StvoriMatricu<TipElemenata>(mat1.br_redova,mat2.br_kolona);
    for(int i=0;i<mat1.br_redova;i++)
    {
        for(int j=0;j<mat2.br_kolona;j++)
        {
            TipElemenata Suma=TipElemenata();
            for(int k=0;k<mat1.br_kolona;k++)
            {
                Suma+=(mat1.elementi[i][k]*mat2.elementi[k][j]);
            }
            Matrica.elementi[i][j]=Suma;
        }
    }
    return Matrica;
}

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &mat, std::vector<double> koeficijenti)
{
    if(mat.br_redova!=mat.br_kolona)
    {
        throw std::domain_error("Matrica mora biti kvadratna");
    }
    auto m5=StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona);

    std::vector<Matrica<TipElemenata>> v(koeficijenti.size());
    std::vector<Matrica<TipElemenata>> v1(koeficijenti.size());
    
    auto nulaMatrica=StvoriMatricu<TipElemenata>(mat.br_kolona,mat.br_kolona);
    for(int i=0;i<mat.br_redova;i++)
    {
        for(int j=0;j<mat.br_kolona;j++)
        {
            nulaMatrica.elementi[i][j]=0;
        }
    }
    if(koeficijenti.size()<=0)
    {
        return nulaMatrica;
    }
    
    for(int i=0;i<koeficijenti.size();i++)
    {
        if(i==0) v.at(i)=StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona);
        if(i==0)
        {
            for(int j=0;j<mat.br_redova;j++)
            {
                for(int k=0;k<mat.br_kolona;k++)
                {
                    if(j==k)
                    v.at(i).elementi[j][k]=1;
                    else 
                    v.at(i).elementi[j][k]=0;
                }
            }
        }
    }

    for(int i=0;i<koeficijenti.size();i++)
    {
        if(i!=0) v.at(i)=ProduktMatrica(v.at(i-1),mat);
        for(int j=0;j<mat.br_redova;j++)
        {
            for(int k=0;k<mat.br_kolona;k++)
            {
                m5.elementi[j][k]=v.at(i).elementi[j][k]*koeficijenti.at(i);
            }
        }
        if(i==0)
        {
            v1.at(i)=ZbirMatrica(nulaMatrica,m5);
            UnistiMatricu(nulaMatrica);
        }
        else
        {
            v1.at(i)=ZbirMatrica(v1.at(i-1),m5);
        }
    }
    auto konacna=StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona);
    for(int i=0;i<mat.br_redova;i++)
    {
        for(int j=0;j<mat.br_kolona;j++)
        {
            konacna.elementi[i][j]=v1.at(int(koeficijenti.size())-1).elementi[i][j];
        }
    }
    UnistiMatricu(m5);
    for(int i=0;i<koeficijenti.size();i++)
    {
            UnistiMatricu(v1.at(i));
            UnistiMatricu(v.at(i));
    }
    return konacna;
}

int main ()
{
    Matrica<double> Matrica1;
    Matrica<double> Matrica2;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    int Dimenzija=0;
    std::cin >> Dimenzija;
    try
    {
        std::cout << "Unesite elemente matrice A: \n";
        Matrica1=StvoriMatricu<double>(Dimenzija, Dimenzija);
        UnesiMatricu('A', Matrica1);
        std::cout << "Unesite red polinoma: ";
        int RedPolinoma=0;
        std::cin >> RedPolinoma;
        std::cout << "Unesite koeficijente polinoma: ";
        std::vector<double> Vektor(RedPolinoma+1);
        for(int i=0;i<Vektor.size();i++)
        {
            std::cin >> Vektor.at(i);
        }
        Matrica2=MatricniPolinom(Matrica1,Vektor);
        IspisiMatricu(Matrica2, 10);
    }
    catch(std::bad_alloc)
    {
        std::cout << "Nema dovoljno memorije!";
    }
    catch(std::domain_error error)
    {
        std::cout << error.what();
    }
    UnistiMatricu(Matrica1);
    UnistiMatricu(Matrica2);
	return 0;
}