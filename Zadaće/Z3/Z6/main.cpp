//TP 2021/2022: Zadaća 3, Zadatak 6
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <new>
#include <memory>

struct Dijete
{
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> VektorStringova, int brojtimova)
{
    if(brojtimova<1 || brojtimova>VektorStringova.size())
    {
        throw std::logic_error("Razvrstavanje nemoguce");
    }
    int Ostatak=VektorStringova.size()%brojtimova;
    int DonjaVelicinaTima=VektorStringova.size()/brojtimova;
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
    std::shared_ptr<Dijete> pocetak=nullptr;
    std::shared_ptr<Dijete> prethodni;
    for(int i=0;i<VektorStringova.size();i++)
    {
        std::shared_ptr<Dijete> novi(new Dijete); // Kreiranje novog čvora
        novi->ime=VektorStringova.at(i);;
        novi->sljedeci=nullptr;
        if(!pocetak)
        {
            pocetak = novi; // Prvi čvor...
        }
        else
        {
            prethodni->sljedeci = novi; // Svi osim prvog...
        }
        prethodni = novi;
    }
    prethodni->sljedeci=pocetak;
    int BrojDijeteova=VektorStringova.size();
    std::vector<std::set<std::string>> VektorSetovaStringovaKojiVracamo;
    VektorSetovaStringovaKojiVracamo.resize(brojtimova);
    int brojac=0;
    for(int k=0;k<VektorStringova.size();k++)
    {
        VektorSetovaStringovaKojiVracamo.at(brojac).insert(pocetak->ime);
        if(k==VektorStringova.size()-1)
        {
            pocetak->sljedeci=nullptr;
            break;
        }
        if(VektorSetovaStringovaKojiVracamo.at(brojac).size()==VelicineTimova.at(brojac))
        {
            brojac++;
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
    }
    return VektorSetovaStringovaKojiVracamo;
}

int main ()
{
    std::cout << "Unesite broj djece: ";
    int BrojDjece;
    std::cin >> BrojDjece;
    std::vector<std::string> Djeca;
    std::cout << "Unesite imena djece: ";
    std::cin.clear();
    std::cin.ignore(10000,'\n');
    for(int i=0;i<BrojDjece;i++)
    {
        std::string Dijete;
        std::getline(std::cin, Dijete);
        Djeca.push_back(Dijete);
    }
    std::cout << " \nUnesite broj timova: ";
    int BrojTimova;
    std::cin >> BrojTimova;
    std::vector<std::set<std::string>> Timovi;
    try
    {
        Timovi=Razvrstavanje(Djeca, BrojTimova);
    }
    catch(std::logic_error izuzetak)
    {
        std::cout << "Izuzetak: " << izuzetak.what();
    }
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
	return 0;
}