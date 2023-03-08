//TP 2021/2022: Zadaća 2, Zadatak 2
#include <iostream>
#include <cmath>
#include <vector>


// Funkcija koja ispituje da li je neki broj prost
bool dalijeprost (int n)
{
    for(int i=2;i<=n/2;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    if(n==1) 
    {
        return false;
    }
    return true;
}

// Funkcija koja pronalazi sve proste brojeve manje od zadanog broja
std::vector<int> nadjiproste (int n)
{
    std::vector<int> sviprosti;
    for(int i=1;i<=n;i++)
    {
        if(dalijeprost(i)==true)
        {
            sviprosti.push_back(i);
        }
    }
    return sviprosti;
}

void Goldbach (int n, int &p, int &q)
{
    std::vector<int> prosti=nadjiproste(n);

    for(int i=0;i<prosti.size();i++)
    {
        for(int j=0;j<prosti.size();j++)
        {
            if(j==i)
            {
                continue;
            }
            if(prosti.at(i)+prosti.at(j)==n)
            {
                p=prosti.at(i);
                q=prosti.at(j);
                return;
            }
        }
    }
    throw std::logic_error("Rastava ne postoji");
}

int main ()
{
    std::cout << "Unesi broj: \n";
    int broj;
    std::cin >> broj;
    int p, q;
    try
    {
        Goldbach(broj, p, q);
        std::cout << broj << " je zbir prostih brojeva " << p << " i " << q;
    }
    catch(...)
    {
        std::cout << broj << " nije zbir dva prosta broja!";
    }
	return 0;
}
