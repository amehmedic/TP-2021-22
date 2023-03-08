//TP 2017/2018: Tutorijal 2, Zadatak 2
#include <iostream>
#include <vector>

bool TestPerioda (std::vector<double> v, int p)
{
    if (p==0 || v.size()<=1 || p>=v.size())
    {
        return false;
    }
    for (int i=0;i<v.size();i++)
    {
        if ((i+p)<v.size())
        {
            if(v[i]!=v[i+p])
            {
                return false;
            }
            if(v[v.size()-1-i]!=v[v.size()-1-p-i])
            {
                return false;
            }
         }
     }
     return true;
}

int OdrediOsnovniPeriod (std::vector<double> v)
{
    for (int i=0;i<v.size();i++)
    {
        if (TestPerioda(v, i)==true)
        {
            return i;
        }
    }
    return 0;
}

int main ()
{
    std::cout << "Unesite slijed brojeva (0 za kraj): ";
    std::vector<double> v;
    double a;
    do
    {
        std::cin >> a;
        if(a==0)
        {
            continue;
        }
        v.push_back(a);
    }
    while(a!=0);
    if (OdrediOsnovniPeriod(v)==0)
    {
        std::cout << "Slijed nije periodican!";
    }
    else
    {
        std::cout << "Slijed je periodican sa osnovnim periodom " << OdrediOsnovniPeriod(v) << ".";
    }
	return 0;
}
