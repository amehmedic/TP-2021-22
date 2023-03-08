//TP 2021/2022: Zadaća 4, Zadatak 3
#include <iostream>
#include <cmath>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

class Polazak
{
    std::string NazivOdredista;
    int BrojVoza;
    int BrojPerona;
    bool BrziDaNe;
    int VrijemePolaskaSat;
    int VrijemePolaskaMinute;
    int TrajanjeVoznje;
    int Kasnjenje;
    friend class RedVoznje;
public:
    Polazak(std::string odrediste, int broj_voza, int broj_perona, bool brzi_voz, int sat_polaska, int minute_polaska, int trajanje_voznje);
    void PostaviKasnjenje(int kasnjenje);
    bool DaLiKasni() const;
    int DajTrajanjeVoznje() const;
    std::pair<int, int> DajOcekivanoVrijemePolaska() const;
    std::pair<int, int> DajOcekivanoVrijemeDolaska() const;
    void Ispisi() const;
};

Polazak::Polazak(std::string odrediste, int broj_voza, int broj_perona, bool brzi_voz, int sat_polaska, int minute_polaska, int trajanje_voznje)
{
    if(sat_polaska<0 || sat_polaska>23)
    {
        throw std::domain_error("Ilegalni sati");  
    }
    if(minute_polaska<0 || minute_polaska>59)
    {
        throw std::domain_error("Ilegalne minute");  
    }
    if(broj_voza>99999 || broj_voza<0)
    {
        throw std::domain_error("Ilegalan broj voza");
    }
    if(broj_perona<1 || broj_perona>6)
    {
        throw std::domain_error("Ilegalan broj voza");
    }
    if(trajanje_voznje<=0)
    {
        throw std::domain_error("Ilegalan broj voza");
    }
    NazivOdredista=odrediste;
    BrojVoza=broj_voza;
    BrojPerona=broj_perona;
    BrziDaNe=brzi_voz;
    VrijemePolaskaSat=sat_polaska;
    VrijemePolaskaMinute=minute_polaska;
    TrajanjeVoznje=trajanje_voznje;
    Kasnjenje=0;
}

void Polazak::PostaviKasnjenje(int kasnjenje)
{
    Kasnjenje=kasnjenje;
}

bool Polazak::DaLiKasni() const
{
    if (Kasnjenje>0)
    {
        return true;
    }
    return false;
}

int Polazak::DajTrajanjeVoznje() const
{
    return TrajanjeVoznje;
}

std::pair<int, int> Polazak::DajOcekivanoVrijemePolaska() const
{
    std::pair<int,int> Par;
    int Minute=(VrijemePolaskaMinute+Kasnjenje);
    int PrenosSati=(Minute/60);
    Minute=(Minute%60);
    int Sati=(VrijemePolaskaSat+PrenosSati);
    Sati=(Sati%24);
    Par.first=Sati;
    Par.second=Minute;
    return Par;
}
    
std::pair<int, int> Polazak::DajOcekivanoVrijemeDolaska() const
{
    std::pair<int,int> Par;
    int Minute=(VrijemePolaskaMinute+TrajanjeVoznje+Kasnjenje);
    int PrenosSati=(Minute/60);
    Minute=(Minute%60);
    int Sati=(VrijemePolaskaSat+PrenosSati);
    Sati=(Sati%24);
    Par.first=Sati;
    Par.second=Minute;
    return Par;
}
    
void Polazak::Ispisi() const
{
    if(Kasnjenje==0)
    {
        if(BrziDaNe==false)
        {
            std::cout << "Lokalni voz broj ";
        }
        else
        {
            std::cout << "Brzi voz broj ";
        }
        std::cout << BrojVoza << ", odrediste " << NazivOdredista << ", polazi sa perona " << BrojPerona << " u ";
        if(VrijemePolaskaSat<10)
        {
            std::cout << "0" << VrijemePolaskaSat << ":";
        }
        else
        {
            std::cout << VrijemePolaskaSat << ":"; 
        }
        if(VrijemePolaskaMinute<10)
        {
            std::cout << "0" << VrijemePolaskaMinute << ", a na odrediste stize u ";
        }
        else
        {
            std::cout << VrijemePolaskaMinute << ", a na odrediste stize u ";
        }
        if(((this->DajOcekivanoVrijemeDolaska()).first)<10)
        {
            std::cout << "0" <<  (this->DajOcekivanoVrijemeDolaska()).first << ":";
        }
        else
        {
            std::cout <<  (this->DajOcekivanoVrijemeDolaska()).first << ":";   
        }
        if(((this->DajOcekivanoVrijemeDolaska()).second)<10)
        {
            std::cout << "0" << (this->DajOcekivanoVrijemeDolaska()).second << ". Putnicima i voznom osoblju zelimo ugodno putovanje.";
        }
        else
        {
            std::cout << (this->DajOcekivanoVrijemeDolaska()).second << ". Putnicima i voznom osoblju zelimo ugodno putovanje.";
        }
    }
    else
    {
        if(BrziDaNe==false)
        {
            std::cout << "Lokalni voz broj ";
        }
        else
        {
            std::cout << "Brzi voz broj ";
        }
        std::cout << BrojVoza << ", odrediste " << NazivOdredista << ", sa predvidjenim vremenom polaska u ";
        if(VrijemePolaskaSat<10)
        {
            std::cout << "0" << VrijemePolaskaSat << ":";
        }
        else
        {
            std::cout << VrijemePolaskaSat << ":"; 
        }
        if(VrijemePolaskaMinute<10)
        {
            std::cout << "0" << VrijemePolaskaMinute << ", kasni oko " << Kasnjenje << " minuta, te ce poci oko ";
        }
        else
        {
            std::cout << VrijemePolaskaMinute << ", kasni oko " << Kasnjenje << " minuta, te ce poci oko ";
        }
        if(((this->DajOcekivanoVrijemePolaska()).first)<10)
        {
            std::cout << "0" <<  (this->DajOcekivanoVrijemePolaska()).first << ":";
        }
        else
        {
            std::cout <<  (this->DajOcekivanoVrijemePolaska()).first << ":";   
        }
        if(((this->DajOcekivanoVrijemePolaska()).second)<10)
        {
            std::cout << "0" << (this->DajOcekivanoVrijemePolaska()).second << ". Ocekuje se da voz stigne na odrediste oko ";
        }
        else
        {
            std::cout << (this->DajOcekivanoVrijemePolaska()).second << ". Ocekuje se da voz stigne na odrediste oko ";
        }
        if(((this->DajOcekivanoVrijemeDolaska()).first)<10)
        {
            std::cout << "0" <<  (this->DajOcekivanoVrijemeDolaska()).first << ":";
        }
        else
        {
            std::cout <<  (this->DajOcekivanoVrijemeDolaska()).first << ":";   
        }
        if(((this->DajOcekivanoVrijemeDolaska()).second)<10)
        {
            std::cout << "0" << (this->DajOcekivanoVrijemeDolaska()).second << ". Izvinjavamo se putnicima zbog eventualnih neugodnosti.";
        }
        else
        {
            std::cout << (this->DajOcekivanoVrijemeDolaska()).second << ". Izvinjavamo se putnicima zbog eventualnih neugodnosti.";
        }
    }
    std::cout << "\n";
}

class RedVoznje
{
    int MaxBrojPolazaka=0;
    int BrojPolazaka=0;
    Polazak **Polasci=nullptr;
    friend class Polazak;
public:
    explicit RedVoznje(int max_broj_polazaka);
    RedVoznje(std::initializer_list<Polazak> lista_polazaka);
    ~RedVoznje();
    RedVoznje(const RedVoznje &red_voznje);
    RedVoznje(RedVoznje &&red_voznje);
    RedVoznje &operator =(const RedVoznje &red_voznje);
    RedVoznje &operator =(RedVoznje &&red_voznje);
    void RegistrirajPolazak(std::string odrediste, int broj_voza, bool brzi_voz, int broj_perona, int sat_polaska, int minute_polaska, int trajanje_voznje);
    void RegistrirajPolazak(Polazak *polazak);
    int DajBrojPolazaka() const;
    int DajBrojPolazakaKojiKasne() const;
    int DajProsjecnoTrajanjeVoznji() const;
    Polazak &DajPrviPolazak() const;
    Polazak &DajPosljednjiPolazak() const;
    void IsprazniRedVoznje();
    void Ispisi(int sati, int minute) const;
};

RedVoznje::RedVoznje(int max_broj_polazaka)
{
    MaxBrojPolazaka=max_broj_polazaka;
    BrojPolazaka=0;
    Polasci=new Polazak*[max_broj_polazaka]{};
}

RedVoznje::RedVoznje(std::initializer_list<Polazak> lista_polazaka)
{
    MaxBrojPolazaka=lista_polazaka.size();
    BrojPolazaka=lista_polazaka.size();
    Polasci=new Polazak*[lista_polazaka.size()]{};
    auto it=lista_polazaka.begin();
    for(int i=0;i<BrojPolazaka;i++)
    {
        Polasci[i]=new Polazak(*it);
        it++;
    }
}

RedVoznje::~RedVoznje()
{
    for(int i=0;i<BrojPolazaka;i++)
    {
        delete Polasci[i];  
    }
    delete[] Polasci;
}

RedVoznje::RedVoznje(const RedVoznje &red_voznje)
{
    if(Polasci!=red_voznje.Polasci && Polasci!=nullptr)
    {
        for(int i=0;i<BrojPolazaka;i++)
        {
            delete Polasci[i];  
        }
        delete[] Polasci;
    }
    Polazak** Novi;
    Novi=new Polazak*[red_voznje.MaxBrojPolazaka]{};
    for(int i=0;i<red_voznje.BrojPolazaka;i++)
    {
        std::string s=(*(red_voznje.Polasci[i])).NazivOdredista;
        Polazak smallhelp=(*(red_voznje.Polasci[i]));
        Polazak *polazak=new Polazak(smallhelp.NazivOdredista, smallhelp.BrojVoza, smallhelp.BrojPerona, smallhelp.BrziDaNe, smallhelp.VrijemePolaskaSat, smallhelp.VrijemePolaskaMinute, smallhelp.TrajanjeVoznje);
        polazak->Kasnjenje=smallhelp.Kasnjenje;
        Novi[i]=polazak;
    }
    BrojPolazaka=red_voznje.BrojPolazaka;
    MaxBrojPolazaka=red_voznje.MaxBrojPolazaka;
    Polasci=Novi;
}

RedVoznje::RedVoznje(RedVoznje &&red_voznje) : MaxBrojPolazaka(red_voznje.MaxBrojPolazaka),
BrojPolazaka(red_voznje.BrojPolazaka), Polasci(red_voznje.Polasci) 
{
    red_voznje.BrojPolazaka=0;
    red_voznje.MaxBrojPolazaka=0;
    red_voznje.Polasci=nullptr;

}

RedVoznje &RedVoznje::operator =(const RedVoznje &red_voznje)
{
    if(Polasci==red_voznje.Polasci)
    {
        return *this;
    }
    for(int i=0;i<BrojPolazaka;i++)
    {
        delete Polasci[i];  
    }
    delete[] Polasci;
    Polazak** Novi;
    Novi=new Polazak*[red_voznje.MaxBrojPolazaka]{};
    for(int i=0;i<red_voznje.BrojPolazaka;i++)
    {
        std::string s=(*(red_voznje.Polasci[i])).NazivOdredista;
        Polazak smallhelp=(*(red_voznje.Polasci[i]));
        Polazak *polazak=new Polazak(smallhelp.NazivOdredista, smallhelp.BrojVoza, smallhelp.BrojPerona, smallhelp.BrziDaNe, smallhelp.VrijemePolaskaSat, smallhelp.VrijemePolaskaMinute, smallhelp.TrajanjeVoznje);
        polazak->Kasnjenje=smallhelp.Kasnjenje;
        Novi[i]=polazak;
    }
    BrojPolazaka=red_voznje.BrojPolazaka;
    MaxBrojPolazaka=red_voznje.MaxBrojPolazaka;
    Polasci=Novi;
    return *this;
}

RedVoznje &RedVoznje::operator =(RedVoznje &&red_voznje)
{
    std::swap(Polasci, red_voznje.Polasci);
    std::swap(MaxBrojPolazaka, red_voznje.MaxBrojPolazaka);
    std::swap(BrojPolazaka, red_voznje.BrojPolazaka);
    return *this;
}

void RedVoznje::RegistrirajPolazak(std::string odrediste, int broj_voza, bool brzi_voz, int broj_perona, int sat_polaska, int minute_polaska, int trajanje_voznje)
{
    if(BrojPolazaka>=MaxBrojPolazaka)
    {
        throw std::range_error("Dostignut maksimalni broj polazaka");
    }
    Polazak *polazak=nullptr;
    polazak=new Polazak(odrediste, broj_voza, broj_perona, brzi_voz, sat_polaska, minute_polaska, trajanje_voznje);
    Polasci[BrojPolazaka++]=polazak;
}

void RedVoznje::RegistrirajPolazak(Polazak *polazak)
{
    if(BrojPolazaka>=MaxBrojPolazaka)
    {
        throw std::range_error("Dostignut maksimalni broj polazaka");
    }
    Polazak *p=nullptr;
    p=new Polazak((*polazak).NazivOdredista, (*polazak).BrojVoza, (*polazak).BrojPerona, (*polazak).BrziDaNe, (*polazak).VrijemePolaskaSat, (*polazak).VrijemePolaskaMinute, (*polazak).TrajanjeVoznje);
    (*p).Kasnjenje=(*polazak).Kasnjenje;
    delete polazak;
    Polasci[BrojPolazaka++]=p;
}

int RedVoznje::DajBrojPolazaka() const
{
    return BrojPolazaka;
}

int RedVoznje::DajBrojPolazakaKojiKasne() const
{
    return std::count_if(Polasci,Polasci+BrojPolazaka,[](Polazak *p)
    {
        if((*p).DaLiKasni()==true)
        {
            return true;
        }
        return false;
    });
}

int RedVoznje::DajProsjecnoTrajanjeVoznji() const
{
    int Suma=0;
    for(int i=0;i<BrojPolazaka;i++)
    {
        Suma=Suma+Polasci[i]->DajTrajanjeVoznje() ;
    }
    return Suma/BrojPolazaka;
}

Polazak &RedVoznje::DajPrviPolazak() const
{
    if(BrojPolazaka<=0)
    {
        throw std::domain_error("Nema registriranih polazaka");
    }
    auto Vracaj=(std::min_element(Polasci, Polasci+BrojPolazaka , [] (auto p, auto q)
    {
        int Psize=0;
        int Qsize=0;
        auto ParP = (*p).DajOcekivanoVrijemePolaska();
        auto ParQ = (*q).DajOcekivanoVrijemePolaska();
        Psize=(ParP.first*60)+ParP.second;
        Qsize=(ParQ.first*60)+ParQ.second;
        if(Psize<Qsize)
        {
            return true;
        }
        return false;
    }));
    return **Vracaj;
}

Polazak &RedVoznje::DajPosljednjiPolazak() const
{
    if(BrojPolazaka<=0)
    {
        throw std::domain_error("Nema registriranih polazaka");
    }
    auto Vracaj=(std::max_element(Polasci, Polasci+BrojPolazaka , [] (auto p, auto q)
    {
        int Psize=0;
        int Qsize=0;
        auto ParP = (*p).DajOcekivanoVrijemePolaska();
        auto ParQ = (*q).DajOcekivanoVrijemePolaska();
        Psize=(ParP.first*60)+ParP.second;
        Qsize=(ParQ.first*60)+ParQ.second;
        if(Psize<Qsize)
        {
            return true;
        }
        return false;
    }));
    return **Vracaj;
}

void RedVoznje::IsprazniRedVoznje()
{
    for(int i=0;i<BrojPolazaka;i++)
    {
        delete Polasci[i];
        Polasci[i]=nullptr;
    }
    BrojPolazaka=0;
}

void RedVoznje::Ispisi(int sati, int minute) const
{
    if(sati<0 || sati>23)
    {
        throw std::domain_error("Ilegalni sati");  
    }
    if(minute<0 || minute>59)
    {
        throw std::domain_error("Ilegalne minute");  
    }
    RedVoznje Novi=*this;
    std::sort(Novi.Polasci, Novi.Polasci+BrojPolazaka, [] (Polazak *p, Polazak *q)
    {
        int Psize=0;
        int Qsize=0;
        auto ParP = (*p).DajOcekivanoVrijemePolaska();
        auto ParQ = (*q).DajOcekivanoVrijemePolaska();
        Psize=(ParP.first*60)+ParP.second;
        Qsize=(ParQ.first*60)+ParQ.second;
        if(Psize<Qsize)
        {
            return true;
        }
        return false;
    });
    for(int i=0;i<BrojPolazaka;i++)
    {
        int Size=0;
        auto Par = (*(Novi.Polasci[i])).DajOcekivanoVrijemePolaska();
        Size=(Par.first*60)+Par.second;
        if(Size>=((sati*60)+minute))
        {
            Novi.Polasci[i]->Ispisi();  
        }
    }
}

int main ()
{
    return 0;
}

