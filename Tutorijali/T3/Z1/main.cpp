//TP 2017/2018: Tutorijal 3, Zadatak 1
#include <iostream>
#include <vector>

std::vector<int> IzdvojiElemente(std::vector<int> v, bool istinitost)
{
    std::vector<int> NoviVektor;
    if (istinitost==true)
    {
        for(int i: v)
        {
            int suma=0, n=i;
            while(n!=0)
            {
               suma+=(n%10);
               n=n/10;
            }
            if(suma%2==0)
            {
                NoviVektor.push_back(i);
            }
        }
        return NoviVektor;
    }
    if (istinitost==false)
    {
        for(int i: v)
        {
            int suma=0, n=i;
            while(n!=0)
            {
               suma+=(n%10);
               n=n/10;
            }
            if(suma%2!=0)
            {
                NoviVektor.push_back(i);
            }
        }
        return NoviVektor;
    }
}

int main ()
{
    std::cout << "Koliko zelite unijeti elemenata: ";
    int n;
    std::cin >> n;
    if (n<1)
    {
        std::cout <<"Broj elemenata mora biti veci od 0!";
        return 0;
    }
    std::vector<int> a, b, c;
    std::cout << "Unesite elemente: ";
    for (int i=0;i<n;i++)
    {
        int broj;
        std::cin >> broj;
        a.push_back(broj);
    }
    b=IzdvojiElemente(a, true);
    for (int i: b)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
    c=IzdvojiElemente(a, false);
    for (int i: c)
    {
        std::cout << i << " ";
    }
	return 0;
}
