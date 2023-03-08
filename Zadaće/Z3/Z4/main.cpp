//TP 2021/2022: Zadaća 3, Zadatak 4
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <list>

int BrojSlovaiBrojeva(std::string String)
{
    int Broj=0;
    for(int i=0;i<String.length();i++)
    {
        if(isdigit(String.at(i))!=0)
        {
            Broj++;
        }
        if(isalpha(String.at(i))!=0)
        {
            Broj++;
        }
    }
    return Broj;
}


std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> Djeca, int BrojTimova)
{
    if(BrojTimova<1)
    {
        throw std::logic_error("Razvrstavanje nemoguce");
    }
    if(BrojTimova>Djeca.size())
    {
        throw std::logic_error("Razvrstavanje nemoguce");
    }
    std::vector<std::set<std::string>> Vektor(BrojTimova);
    int BrojVecihTimova=Djeca.size()%BrojTimova;
    int VelicinaTima=Djeca.size()/BrojTimova;
    std::list<std::string> ListaDjece;
    for(int i=0;i<Djeca.size();i++)
    {
        ListaDjece.push_back(Djeca.at(i));
    }
    auto p = ListaDjece.begin();
    auto q = ListaDjece.end();
    int Timporedu=0;
    int KolikoDjeceuTimu=0;
    std::string Ime;
    while(1!=0)
    {
        Ime=(*p);
        Vektor.at(Timporedu).insert(*p);
        p = ListaDjece.erase(p);
        q = ListaDjece.end();
        if(p==q)
        {
            p=ListaDjece.begin();
        }
        KolikoDjeceuTimu++;
        if(Timporedu>=BrojVecihTimova)
        {
            if(KolikoDjeceuTimu==VelicinaTima)
            {
                Timporedu++;
                KolikoDjeceuTimu=0;
            }
        }
        if(Timporedu<BrojVecihTimova)
        {
            if(KolikoDjeceuTimu==VelicinaTima+1)
            {
                Timporedu++;
                KolikoDjeceuTimu=0;
            }
        }
        if(Timporedu==BrojTimova)
        {
            break;
        }
        for(int i=0;i<BrojSlovaiBrojeva(Ime)-1;i++)
        {
            p++;
            if(p==q)
            {
                p=ListaDjece.begin();
                continue;
            }
        }
    }

    return Vektor;
}

void Ispis(std::set<std::string> Set)
{
    auto p = Set.begin();
    auto q = Set.end();
    while (p != q)
    {
        std::cout << *p;
        p++;
        if(p==q)
        {
            continue;
        }
        std::cout << ", ";
    }
}


int main ()
{
    std::cout << "Unesite broj djece: ";
    int BrojDjece;
    std::cin >> BrojDjece;
    std::cout << "\nUnesite imena djece: ";
    std::vector<std::string> Djeca;
    std::cin.ignore(10000, '\n');
    for(int i=0;i<BrojDjece;i++)
    {
        std::string Ime;
        std::getline(std::cin, Ime);
        Djeca.push_back(Ime);
    }
    std::cout << "\nUnesite broj timova: ";
    int BrojTimova;
    std::cin >> BrojTimova;
    std::vector<std::set<std::string>> VektorSkupova;
    try
    {
        VektorSkupova=Razvrstavanje(Djeca, BrojTimova);
    }
    catch (std::logic_error error)
        {
        std::cout << "Izuzetak: " << error.what();
        }
    for(int i=0;i<VektorSkupova.size();i++)
    {
        std::cout << "Tim " << i+1 << ": ";
        Ispis(VektorSkupova.at(i));
        std::cout << "\n";
    }
	return 0;
}
