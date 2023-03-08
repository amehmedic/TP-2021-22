//TP 2018/2019: Tutorijal 4, Zadatak 1
#include <iostream>
#include <cmath>

int Cifre(long long int broj, int &c_min, int &c_max)
{
    if (broj==0)
    {
        c_max=0;
        c_min=0;
        return 1;
    }
    c_min=abs(broj%10);
    c_max=abs(broj%10);
    int brojac=0;
    while(broj/1!=0)
    {
        if(abs(broj%10)>c_max)
        {
            c_max=abs(broj%10);
        }
        if(abs(broj%10)<c_min)
        {
            c_min=abs(broj%10);
        }
        broj=(broj/10);
        brojac++;
    }
    return brojac;
}

int main ()
{
    long long int n;
    std::cout << "Unesite broj: ";
    std::cin >> n;
    int Najveci, Najmanji;
    int e=Cifre(n, Najmanji, Najveci);
    std::cout << "Broj " << n << " ima " << e << " cifara, najveca je " << Najveci << " a najmanja " << Najmanji << ".";
	return 0;
}