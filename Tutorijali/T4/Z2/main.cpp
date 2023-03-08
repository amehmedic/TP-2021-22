//TP 2018/2019: Tutorijal 4, Zadatak 2
#include <iostream>
#include <string>
#include <algorithm> 

void IzvrniString(std::string &Recenica)
{
    for (int i=0;i<Recenica.length()/2;i++)
    {
        auto &pocetak=Recenica.at(i);
        auto &kraj=Recenica.at(Recenica.length()-(i+1));
        char pomocni=pocetak;
        pocetak=kraj;
        kraj=pomocni;
    } 
}

int main ()
{
    std::cout << "Unesi string: ";
    std::string Recenica;
    std::getline(std::cin, Recenica);
    IzvrniString(Recenica);
    std::cout<< "Izvrnuti string je: ";
    for(int i=0; i<Recenica.length();i++)
    {
        std::cout<< Recenica.at(i);
    }
	return 0;
}