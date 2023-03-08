//TP 2017/2018: Tutorijal 3, Zadatak 8
#include <iostream>
#include <string>
#include <stdexcept>

std::string IzdvojiRijec(std::string Recenica, int broj_rijeci)
{
    if(broj_rijeci<=0)
    {
        throw std::range_error("IZUZETAK: Pogresan redni broj rijeci!");
    }
    std::string Rijec;
    int brojac=0;
    bool razmak=true;
    for (char c: Recenica)
    {
        if (c==' ' && razmak==true)
        {
            continue;
        }
        
        if(c!=' ' && razmak==true)
        {
            brojac++;
        }
        
        if (c==' ' && razmak==false)
        {
            razmak=true;
            continue;
        }
        if (c!=' ' && brojac!=broj_rijeci)
        {
            razmak=false;
            continue;
        }
        if (c!=' ' && brojac==broj_rijeci)
        {
            Rijec.push_back(c);
            razmak=false;
            continue;
        }
        if (c==' ' && brojac==broj_rijeci && razmak==false)
        {
            break;
        }
    }
    if(broj_rijeci>brojac)
    {
        throw std::range_error("IZUZETAK: Pogresan redni broj rijeci!");       
    }
    return Rijec;
}

int main ()
{
    try
    {
        std::cout << "Unesite redni broj rijeci: ";
        int broj_rijeci;
        std::cin >> broj_rijeci;
        std::cin.ignore(10000, '\n');
        std::string Recenica;
        std::cout << "Unesite recenicu: ";
        std::getline(std::cin, Recenica);
        std::string Rijec=IzdvojiRijec(Recenica, broj_rijeci);
        std::cout << "Rijec na poziciji " << broj_rijeci << " je " << Rijec;
    }
    catch(std::range_error izuzetak)
    {
        std::cout << izuzetak.what();
    }
	return 0;
}
