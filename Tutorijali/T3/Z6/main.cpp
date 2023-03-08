//TP 2017/2018: Tutorijal 3, Zadatak 6
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

std::vector<std::vector<int>> KroneckerovProizvod (std::vector<int> a, std::vector<int> b)
{
    std::vector<std::vector<int>> m(a.size(), std::vector<int>(b.size()));
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<b.size();j++)
        {
            m.at(i).at(j)=(a.at(i)*b.at(j));
        }
    }
    return m;
}

int NajvecaSirina (std::vector<std::vector<int>> m)
{
    int max=0;
    int brojac=0;
    for(int i=0;i<m.size();i++)
    {
        for(int j=0;j<m[i].size();j++)
        {
            if(m.at(i).at(j)<0)
            {
                while(abs(m.at(i).at(j))/1!=0)
                {
                    m.at(i).at(j)=(m.at(i).at(j)/10);
                    brojac++;
                }
                if (brojac>(max-1))
                {
                    max=brojac+1;
                }
                brojac=0;
                continue;
            }
            while(m.at(i).at(j)/1!=0)
            {
                m.at(i).at(j)=(m.at(i).at(j)/10);
                brojac++;
            }
            if (brojac>max)
            {
                max=brojac;
            }
            brojac=0;
        }
    }
    return max;
}

int main ()
{
    std::cout << "Unesite broj elemenata prvog vektora: ";
    int n;
    std::cin >> n;
    std::cout << "Unesite elemente prvog vektora: ";
    std::vector<int> a;
    for(int i=0;i<n;i++)
    {
        int broj;
        std::cin >> broj;
        a.push_back(broj);
    }
    std::cout << "Unesite broj elemenata drugog vektora: ";
    int m;
    std::cin >> m;
    std::cout << "Unesite elemente drugog vektora: ";
    std::vector<int> b;
    for(int i=0;i<m;i++)
    {
        int broj;
        std::cin >> broj;
        b.push_back(broj);
    }
        std::vector<std::vector<int>> Matrica(n, std::vector<int>(m));
        Matrica=KroneckerovProizvod(a,b);
    for(int i=0;i<n;i++)
    {
        std::cout << "\n";
        for(int j=0;j<m;j++)
        {
            std::cout << std::setw(NajvecaSirina(Matrica)+1) << std::right << Matrica.at(i).at(j);
        }
    }
	return 0;
}
