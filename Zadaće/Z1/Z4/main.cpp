//TP 2021/2022: Zadaća 1, Zadatak 4
#include <iostream>
#include <cmath>
#include <vector>
#include <array>


std::array<std::vector<std::string>, 100> RazvrstajRijeciPoDuzini(std::string String)
{
    std::array<std::vector<std::string>, 100> Vracamo;
    bool JelRijec=false;
    std::string Rijec;
    for(int i=0;i<String.length();i++)
    {
        if(isalpha(String.at(i))!=0 || isdigit(String.at(i))!=0)
        {
            JelRijec=true;
            Rijec.push_back(toupper(String.at(i)));
            if(i==String.length()-1)
            {
                if(Rijec.length()>99)
                {
                    throw std::range_error("Predugacka rijec!");
                }
                Vracamo.at(Rijec.length()).push_back(Rijec);
                Rijec.resize(0);
            }
            continue;
        }
        if(isalpha(String.at(i))==0 && isdigit(String.at(i))==0)
        {
            if(JelRijec==true)
            {
                if(Rijec.length()>99)
                {
                    throw std::range_error("Predugacka rijec!");
                }
                Vracamo.at(Rijec.length()).push_back(Rijec);
                Rijec.resize(0);
            }
            JelRijec=false;
            continue;
        }
    }
    return Vracamo;
}

int main ()
{
    std::string String;
    std::cout << "Unesite recenicu: ";
    std::getline(std::cin, String);
    std::array<std::vector<std::string>, 100> Niz;
    try
    {
        Niz=RazvrstajRijeciPoDuzini(String);  
    }
    catch(...)
    {
        std::cout << "Greska: Recenica sadrzi predugacku rijec!";
        return 0;
    }
    for(int i=0;i<100;i++)
    {
        if(Niz.at(i).size()>0)
        {
            std::cout << "Duzina " << i << ": ";
            for(int j=0;j<Niz.at(i).size();j++)
            {
                std::cout << Niz.at(i).at(j) << " ";
            }
            std::cout << std::endl;
        }
    }
	return 0;
}
