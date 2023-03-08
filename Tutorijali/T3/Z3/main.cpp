//TP 2017/2018: Tutorijal 3, Zadatak 3
#include <iostream>
#include <deque>

std::deque<int> IzdvojiElemente(std::deque<int> v, bool istinitost)
{
    std::deque<int> NoviVektor;
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
    std::deque<int> a, b, c;
    std::cout << "Unesite elemente: ";
    for (int i=0;i<n;i++)
    {
        int broj;
        std::cin >> broj;
        a.push_back(broj);
    }
    b=IzdvojiElemente(a, true);
    for (int i=0;i<b.size();i++)
    {
        if (i==b.size()-1)
        {
            std::cout << b[i];
            break;
        }
        std::cout << b[i] << ",";
    }
    std::cout << "\n";
    c=IzdvojiElemente(a, false);
    for (int i=0;i<c.size();i++)
    {
        if (i==c.size()-1)
        {
            std::cout << c[i];
            break;
        }
        std::cout << c[i] << ",";
    }
	return 0;
}