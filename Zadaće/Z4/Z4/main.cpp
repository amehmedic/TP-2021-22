//TP 2021/2022: Zadaća 4, Zadatak 4
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
    std::vector<std::shared_ptr<Polazak>> Vektor;
    friend class Polazak;
public:
    explicit RedVoznje();
    RedVoznje(std::initializer_list<Polazak> lista_polazaka);
    ~RedVoznje();
    RedVoznje(const RedVoznje &red_voznje);
    RedVoznje(RedVoznje &&red_voznje);
    RedVoznje &operator =(const RedVoznje &red_voznje);
    RedVoznje &operator =(RedVoznje &&red_voznje);
    void RegistrirajPolazak(std::string odrediste, int broj_voza, bool brzi_voz, int broj_perona, int sat_polaska, int minute_polaska, int trajanje_voznje);
    void RegistrirajPolazak(std::shared_ptr<Polazak> polazak);
    int DajBrojPolazaka() const;
    int DajBrojPolazakaKojiKasne() const;
    int DajProsjecnoTrajanjeVoznji() const;
    Polazak &DajPrviPolazak() const;
    Polazak &DajPosljednjiPolazak() const;
    void IsprazniRedVoznje();
    void Ispisi(int sati, int minute) const;
};

RedVoznje::RedVoznje()
{
    std::vector<std::shared_ptr<Polazak>> Vektor;
}

RedVoznje::RedVoznje(std::initializer_list<Polazak> lista_polazaka)
{
    auto p=lista_polazaka.begin();
    auto q=lista_polazaka.end();
    while(p!=q)
    {
        Vektor.push_back(std::make_shared<Polazak>(*p));
        p++;
    }
}

RedVoznje::~RedVoznje()
{

}

RedVoznje::RedVoznje(const RedVoznje &red_voznje)
{
    RedVoznje::Vektor.resize(red_voznje.Vektor.size(),nullptr);
    for(int i=0;i<RedVoznje::Vektor.size();i++)
    {
        RedVoznje::Vektor.at(i)=std::make_shared<Polazak>((*red_voznje.Vektor.at(i)).NazivOdredista, (*red_voznje.Vektor.at(i)).BrojVoza
        , (*red_voznje.Vektor.at(i)).BrojPerona, (*red_voznje.Vektor.at(i)).BrziDaNe, (*red_voznje.Vektor.at(i)).VrijemePolaskaSat, 
        (*red_voznje.Vektor.at(i)).VrijemePolaskaMinute, (*red_voznje.Vektor.at(i)).TrajanjeVoznje);
        (*(RedVoznje::Vektor.at(i))).Kasnjenje=(*(red_voznje.Vektor.at(i))).Kasnjenje;
    }
}

RedVoznje::RedVoznje(RedVoznje &&red_voznje)
{
    RedVoznje::Vektor=red_voznje.Vektor;
}

RedVoznje &RedVoznje::operator =(const RedVoznje &red_voznje)
{
    if(red_voznje.Vektor.size()>RedVoznje::Vektor.size())
    {
        for(int i=RedVoznje::Vektor.size(); i<red_voznje.Vektor.size(); i++)
        {
            RedVoznje::Vektor.emplace_back(red_voznje.Vektor.at(i));
        }
    }
    else
    {
        RedVoznje::Vektor.resize(red_voznje.Vektor.size());
    }
    for(int i=0; i<RedVoznje::Vektor.size(); i++)
    {
        (*(RedVoznje::Vektor.at(i))).NazivOdredista=(*(red_voznje.Vektor.at(i))).NazivOdredista;
        (*(RedVoznje::Vektor.at(i))).BrojVoza=(*(red_voznje.Vektor.at(i))).BrojVoza;
        (*(RedVoznje::Vektor.at(i))).BrojPerona=(*(red_voznje.Vektor.at(i))).BrojPerona;
        (*(RedVoznje::Vektor.at(i))).BrziDaNe=(*(red_voznje.Vektor.at(i))).BrziDaNe;
        (*(RedVoznje::Vektor.at(i))).VrijemePolaskaSat=(*(red_voznje.Vektor.at(i))).VrijemePolaskaSat;
        (*(RedVoznje::Vektor.at(i))).VrijemePolaskaMinute=(*(red_voznje.Vektor.at(i))).VrijemePolaskaMinute;
        (*(RedVoznje::Vektor.at(i))).TrajanjeVoznje=(*(red_voznje.Vektor.at(i))).TrajanjeVoznje;
        (*(RedVoznje::Vektor.at(i))).Kasnjenje=(*(red_voznje.Vektor.at(i))).Kasnjenje;
    }
    return *this;
}

RedVoznje &RedVoznje::operator =(RedVoznje &&red_voznje)
{
    RedVoznje::Vektor.resize(red_voznje.Vektor.size(),nullptr);
    std::swap(RedVoznje::Vektor,red_voznje.Vektor);
    return *this;
}

void RedVoznje::RegistrirajPolazak(std::string odrediste, int broj_voza, bool brzi_voz, int broj_perona, int sat_polaska, int minute_polaska, int trajanje_voznje)
{
    Polazak polzk = Polazak(odrediste, broj_voza, broj_perona, brzi_voz, sat_polaska, minute_polaska, trajanje_voznje);
    auto a = std::make_shared<Polazak>(polzk);
    Vektor.push_back(a);
}

void RedVoznje::RegistrirajPolazak(std::shared_ptr<Polazak> polazak)
{
    Vektor.push_back(polazak);
}

int RedVoznje::DajBrojPolazaka() const
{
    return Vektor.size();
}

int RedVoznje::DajBrojPolazakaKojiKasne() const
{
    return std::count_if(Vektor.begin(),Vektor.end(),[](auto p)
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
    for(int i=0;i<Vektor.size();i++)
    {
        Suma=Suma+Vektor.at(i)->DajTrajanjeVoznje() ;
    }
    return Suma/Vektor.size();
}

Polazak &RedVoznje::DajPrviPolazak() const
{
    if(Vektor.size()<=0)
    {
        throw std::domain_error("Nema registriranih polazaka");
    }
    auto Vracaj=(std::min_element(Vektor.begin(), Vektor.end() , [] (auto p, auto q)
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
    if(Vektor.size()<0)
    {
        throw std::domain_error("Nema registriranih polazaka");
    }
    auto Vracaj=(max_element(Vektor.begin(), Vektor.end() , [] (auto p, auto q)
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
    Vektor.clear();
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
    std::vector<std::shared_ptr<Polazak>> Novi(Vektor);
    std::sort(Novi.begin(),Novi.end(), [] (std::shared_ptr<Polazak> p, std::shared_ptr<Polazak> q)
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
    for(int i=0;i<Vektor.size();i++)
    {
        int Size=0;
        auto Par = (*(Novi.at(i))).DajOcekivanoVrijemePolaska();
        Size=(Par.first*60)+Par.second;
        if(Size>((sati*60)+minute))
        {
            Novi.at(i)->Ispisi();  
        }
    }
}

int main ()
{
    return 0;
}
