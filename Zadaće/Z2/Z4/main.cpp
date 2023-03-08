//TP 2021/2022: Zadaća 2, Zadatak 4
#include <iostream>
#include <cmath>
#include <vector>
#include <deque>
#include <algorithm>
#include <string>

template <typename Tip>
bool Kriterij (std::vector<Tip> Kontejner1, std::vector<Tip> Kontejner2)
{
    std::remove_reference_t<decltype(Kontejner1.at(0))> sum1{};
    std::remove_reference_t<decltype(Kontejner2.at(0))> sum2{};
    for(int i=0;i<Kontejner1.size();i++)
    {
        sum1=sum1+Kontejner1.at(i);
    }
    for(int i=0;i<Kontejner2.size();i++)
    {
        sum2=sum2+Kontejner2.at(i);
    }
    if(sum1>sum2)
    {
        return true;
    }
    return false;
}

template <typename Tip>
void SortirajPoSumiRedova (Tip &Matrica)
{
    std::sort(Matrica.begin(), Matrica.end(), Kriterij<std::remove_reference_t<decltype(Matrica.at(0).at(0))>>);
}

std::vector<int> Nadjibrojeveizstringa (std::string Red)
{
    std::string pomocnistring;
    std::vector<int> Vektor;
    bool Dalijeproslibiocifra=false;
    for(int i=0;i<Red.length();i++)
    {
        if(Red.at(i)=='-')
        {
            pomocnistring.push_back(Red.at(i));  
        }
        else if(isdigit(Red.at(i))==true && Dalijeproslibiocifra==false)
        {
            pomocnistring.push_back(Red.at(i));
            Dalijeproslibiocifra=true;
        }
        else if(isdigit(Red.at(i))==true && Dalijeproslibiocifra==true)
        {
            pomocnistring.push_back(Red.at(i));
        }
        else if(isdigit(Red.at(i))==false && Dalijeproslibiocifra==true)
        {
            Vektor.push_back(std::stoi(pomocnistring));
            pomocnistring="";
            Dalijeproslibiocifra=false;
            continue;
        }
        else if(isdigit(Red.at(i))==false && Dalijeproslibiocifra==false)
        {
            continue;
        }
    }
    return Vektor;
}

int main ()
{
    std::vector<std::vector<int>> Matrica;
    std::vector<int> intVektor;
    std::string Red;
    std::cout << "Unesi elemente (* za kraj reda, * na pocetku reda za kraj unosa):\n";
    while(Red.length()!=1)
    {
        std::getline(std::cin, Red, '*');
        Matrica.push_back(Nadjibrojeveizstringa(Red)); 
    }
    SortirajPoSumiRedova(Matrica);
    std::cout << "Matrica nakon sortiranja:\n";
    for(int i=0;i<Matrica.size();i++)
    {
        for(int j=0;j<Matrica.at(i).size();j++)
        {
            std::cout << Matrica.at(i).at(j) << " ";
        }
        std::cout << "\n";
    }
	return 0;
}
