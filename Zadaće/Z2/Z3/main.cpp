//TP 2021/2022: Zadaća 2, Zadatak 3
#include <iostream>
#include <cmath>
#include <vector>
#include <deque>
#include <type_traits>
#include <string>
#include <list>
#include <array>
#include <forward_list>

template <typename Tip1, typename Tip2>
auto ZbirKontejnera(Tip1 A, Tip2 B)
{
    std::remove_reference_t<decltype(*(A.begin()))> pomoc1{};
    std::remove_reference_t<decltype(*(B.begin()))> pomoc2{};
    std::vector<decltype((*(A.begin()))+(*(B.begin())))> Vektor;
    auto p=A.begin();
    auto q=A.end();
    auto k=B.begin(); 
    auto l=B.end();
    while(1!=0)
    {
        if(k==l && p==q)
        {
            break;
        }
        if(p==q)
        {
            Vektor.push_back(*k+pomoc1);
        }
        else if(k==l)
        {
            Vektor.push_back(*p+pomoc2);
        }
        else
        {
            Vektor.push_back(*p+*k);
        }
        if(p!=q)
        {
            p++;
        }
        if(k!=l)
        {
            k++;
        }
        if(k==l && p==q)
        {
            break;
        }
    }
    return Vektor;
}

int main ()
{
    std::cout << "Duzina prvog kontejnera: ";
    int duzinaA;
    std::cin >> duzinaA;
    std::vector<double> A;
    std::cout << "Elementi prvog kontejnera: ";
    int broj;
    for(int i=0;i<duzinaA;i++)
    {
        std::cin >> broj;
        A.push_back(broj);
    }
    std::cout << "Duzina drugog kontejnera: ";
    int duzinaB;
    std::cin >> duzinaB;
    std::vector<double> B;
    std::cout << "Elementi drugog kontejnera: ";
    for(int i=0;i<duzinaB;i++)
    {
        std::cin >> broj;
        B.push_back(broj);
    }

    auto Vektor=ZbirKontejnera(A, B);
    std::cout << "Zbir kontejnera: ";
    for(int i=0;i<Vektor.size();i++)
    {
        std::cout << Vektor.at(i) << " ";
    }
	return 0;
}
