//TP 2021/2022: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <new>

struct Dijete
{
    std::string ime;
    Dijete *sljedeci;
};

void Testiraj(int n, int brojtimova)
{
    if(brojtimova<1)
    {
        throw std::logic_error("Razvrstavanje nemoguce");
    }
    if(brojtimova>n)
    {
         throw std::logic_error("Razvrstavanje nemoguce");  
    } 
}

std::vector<int> VelTimovaFunk(int n, int brojtimova)
{
    int Ostatak=n%brojtimova;
    int DonjaVelicinaTima=n/brojtimova;
    std::vector<int> VelicineTimova;
    for(int i=0;i<brojtimova;i++)
    {
        if(Ostatak>0)
        {
            VelicineTimova.push_back(DonjaVelicinaTima+1);
            Ostatak--;
            continue;
        }
        VelicineTimova.push_back(DonjaVelicinaTima);
    }
    return VelicineTimova; 
}

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> VektorStringova, int brojtimova)
{
    int n=VektorStringova.size();
    Testiraj(n,brojtimova);
    auto VelicineTimova=VelTimovaFunk(n,brojtimova);
    Dijete *pocetak = nullptr;
    Dijete *prethodni = nullptr;
    for(int i=0;i<VektorStringova.size();i++)
    {
        auto ime=VektorStringova.at(i);
        Dijete *novi = new Dijete{ime, nullptr}; // Kreiranje novog čvora
        if(!pocetak)
        {
            pocetak = novi; // Prvi čvor...
            prethodni = novi;
            continue;
        }
        prethodni->sljedeci = novi; // Svi osim prvog...
        prethodni = novi;
    }
    prethodni->sljedeci=pocetak; // kruzni lanac
    int BrojDijeteova=n;
    std::vector<std::set<std::string>> VektorSetovaStringovaKojiVracamo;
    VektorSetovaStringovaKojiVracamo.resize(VelicineTimova.size());
    int brojac=0;
    for(int k=0;k<n;k++)
    {
        VektorSetovaStringovaKojiVracamo.at(brojac).insert(pocetak->ime);
        if(VektorSetovaStringovaKojiVracamo.at(brojac).size()==VelicineTimova.at(brojac))
        {
            brojac++;
        }
        if(brojac==VektorSetovaStringovaKojiVracamo.size())
        {
            delete pocetak;
            break;
        }
        auto Stringic=pocetak->ime;
        int BrojiSlovaOdnosnoCifre=0;
        for(auto i : Stringic)
        {
            if(isalpha(i) || isdigit(i))
            {
                BrojiSlovaOdnosnoCifre++;
            }
        }
        auto Pomjeranje=BrojiSlovaOdnosnoCifre;
        for(int i=0;i<BrojDijeteova-1;i++)
        {
            pocetak=pocetak->sljedeci;
        }
        auto pamtimepameobrisi=pocetak->sljedeci;
        pocetak->sljedeci=pocetak->sljedeci->sljedeci;
        BrojDijeteova--;
        for(int i=0;i<Pomjeranje;i++)
        {
            pocetak=pocetak->sljedeci;
        }
        delete pamtimepameobrisi;
    }
    return VektorSetovaStringovaKojiVracamo;
}

int main ()
{
    std::cout << "Unesite broj djece: ";
    int BrojDjece;
    std::cin >> BrojDjece;
    std::vector<std::string> Djeca;
    std::cout << "\nUnesite imena djece: ";
    std::cin.ignore(10000,'\n');
    for(int i=0;i<BrojDjece;i++)
    {
        std::string Dijete;
        std::getline(std::cin, Dijete);
        Djeca.push_back(Dijete);
    }
    std::cout << "\nUnesite broj timova: ";
    int BrojTimova=0;
    std::cin >> BrojTimova;
    try
    {
        auto Timovi=Razvrstavanje(Djeca, BrojTimova);
        for(int i=0;i<Timovi.size();i++)
        {
            int brojac=0;
            std::cout << "Tim " << i+1 << ": ";
            for(auto j : Timovi.at(i))
            {
                std::cout << j;
                if(brojac!=Timovi.at(i).size()-1)
                {
                    std::cout << ", ";
                }
                brojac++;
            }
            std::cout << "\n";
        }
    }
    catch(std::logic_error izuzetak)
    {
        std::cout << "Izuzetak: " << izuzetak.what();
    }
	return 0;
}