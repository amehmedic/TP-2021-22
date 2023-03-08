//TP 2021/2022: Zadaća 2, Zadatak 5
#include <iostream>
#include <cmath>
#include <vector>
#include <deque>
#include <functional>
#include <list>
#include <type_traits>

template <typename Iterator1, typename Iterator2, typename Tip>
auto GeneraliziraniSpoljasnjiProizvod(Iterator1 p, Iterator1 q, Iterator2 k, Iterator2 l, Tip funkcija)
{
    auto pamtip=p;
    auto pamtik=k;
    int dimenzijam=0;
    int dimenzijan=0;
    while(p!=q)
    {
        dimenzijam++;
        p++;
    }
    while(k!=l)
    {
        dimenzijan++;
        k++;
    }
    p=pamtip;
    k=pamtik;
    try
    {
        auto **Duplipokazivac=new std::remove_reference_t<decltype(funkcija(*pamtip,*pamtik))>*[dimenzijam]{}; // Od C++11 nadalje, zbog "{}"
        try
        {
            for(int i=0;i<dimenzijam;i++)
            {
                Duplipokazivac[i]=new std::remove_reference_t<decltype(funkcija(*pamtip,*pamtik))>[dimenzijan];
            }
        }
        catch(...)
        {
            for(int i=0;i<dimenzijam;i++)
            {
                delete[] Duplipokazivac[i];
            }
            delete[] Duplipokazivac;
            throw std::range_error("Nema dovoljno memorije!");
        }
        for(int i=0;i<dimenzijam;i++)
        {
            for(int j=0;j<dimenzijan;j++)
            {
                Duplipokazivac[i][j]=funkcija(*p,*k);
                k++;
            }
            k=pamtik;
            p++;
        }
    return Duplipokazivac;
    }
    catch(...)
    {
        throw std::range_error("Nema dovoljno memorije!");
    }
}

int main ()
{
    int duzinaA;
    std::cout << "Duzina prve sekvence: ";
    std::cin >> duzinaA;
    double broj;
    std::vector<double> Vektor;
    std::cout << "Elementi prve sekvence: ";
    for(int i=0;i<duzinaA;i++)
    {
        std::cin >> broj;
        Vektor.push_back(broj);
    }
    std::cout << "Duzina druge sekvence: ";
    int duzinaB;
    std::cin >> duzinaB;
    std::deque<double> Dek;
    std::cout << "Elementi druge sekvence: ";
    for(int i=0;i<duzinaB;i++)
    {
        std::cin >> broj;
        Dek.push_back(broj);
    }
    auto Matrica=GeneraliziraniSpoljasnjiProizvod(Vektor.begin(),Vektor.end(),Dek.begin(),Dek.end(),[](double x, double y) -> double {return x + (2*y);});
    std::cout << "Generalizirani spoljasnji proizvod uz f(x,y)=x+2y:\n";
    for(int i=0;i<duzinaA;i++)
    {
        for(int j=0;j<duzinaB;j++)
        {
            std::cout << Matrica[i][j] << " ";
        }
        std::cout << "\n";
    }
    for(int i=0;i<duzinaA;i++) 
    {  
        delete[] Matrica[i];
    }
    delete[] Matrica;
	return 0;
}
