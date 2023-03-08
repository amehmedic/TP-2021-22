//TP 2017/2018: Tutorijal 2, Zadatak 1
#include <iostream>
#include <vector>
#include <cmath>

bool DaLiJeProst(int n)
{
    if (n<2)
    {
        return false;
    }
    int i;
    for(i=2;i<=sqrt(n);i++)       
    {
        if (n%i==0)
        {
            return false;
        }
    }
    return true;
}
std::vector<int> ProstiBrojeviUOpsegu(int a, int b)
{
    std::vector<int> Prosti;
    if (a<0)
    {
        a=0;
    }
    for(;unsigned(a)<=b;a++)
    {
        if(DaLiJeProst(a)==true)
        {
            Prosti.push_back(a);
        }
    }
    return Prosti;
}

int main ()
{
    std::cout << "Unesite pocetnu i krajnju vrijednost: ";
    int a, b;
    std::cin >> a >> b;
    std::vector<int> Prosti=ProstiBrojeviUOpsegu(a, b);
    if (Prosti.size()==0)
    {
        std::cout << "Nema prostih brojeva u rasponu od " << a << " do " << b << "!";
        return 0;
    }
    std::cout << "Prosti brojevi u rasponu od " << a << " do " << b << " su: ";
    for(int i=0; i<Prosti.size(); i++)
    {
        if (i==Prosti.size()-1)
        {
            std::cout << Prosti[i] << "\n";
            return 0;
        }
        std::cout << Prosti[i] << ", ";
    }
	return 0;
}
