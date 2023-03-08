//TP 2018/2019: Tutorijal 4, Zadatak 4
#include <iostream>
#include <cmath>

template <typename NekiBroj>
void UnosBroja(std::string prompt, std::string upozorenje, NekiBroj &broj)
{
    std::cout << prompt;
    while(!(std::cin>>broj) || std::cin.peek()!='\n')
    {
        std::cout << "\n" << upozorenje << "\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << prompt;
    }
}

template <typename Tip1, typename Tip2>
Tip1 Kvadriraj(Tip1 baza, Tip2 eksponent)
{
    Tip1 Rezultat=1;
    if(eksponent>0)
    {
        for(int i=0;i<eksponent;i++)
        {
            Rezultat*=baza;
        }
    }
    if(eksponent<0)
    {
        for(int i=0;i<abs(eksponent);i++)
        {
            Rezultat*=(1./baza);
        }
    }
    return Rezultat;
}

int main ()
{
    double baza;
    int eksponent;
    UnosBroja("Unesite bazu: ", "Neispravan unos, pokusajte ponovo...", baza);
    std::cout << "\n\n";
    UnosBroja("Unesite cjelobrojni eksponent: ", "Neispravan unos, pokusajte ponovo...", eksponent);
    std::cout << "\n\n";
    std::cout << baza << " na " << eksponent << " iznosi " << Kvadriraj(baza,eksponent);
    return 0;
}
