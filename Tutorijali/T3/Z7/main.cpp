//TP 2017/2018: Tutorijal 3, Zadatak 7
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

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

std::vector<std::vector<int>> PascalovTrougao (int n)
{
    if (n==0)
    {
        return std::vector<std::vector<int>>(0, std::vector<int>(0));
    }
    if (n<0)
    {
        throw std::domain_error("Broj redova ne smije biti negativan");
    }
    std::vector<std::vector<int>> Matrica;
    Matrica.resize(n);
    for(int i=0;i<n;i++)
    {
        Matrica[i].resize(i+1);
    }
    for (int i=0;i<Matrica.size();i++)
    {
        for (int j=0;j<Matrica[i].size();j++)
        {
            if(j==0 || j==i)
            {
               Matrica.at(i).at(j)=1;
            }
            else
            {
               Matrica.at(i).at(j)=(Matrica.at(i-1).at(j-1)+Matrica.at(i-1).at(j)); 
            }
        }
    }
    return Matrica;
}

int main ()
{
    std::cout << "Unesite broj redova: ";
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> Matrica;
    Matrica.resize(n);
    for(int i=0; i<n; i++)
    {
        Matrica[i].resize(i+1);
    }
    Matrica=PascalovTrougao(n);
    int brojac=1;
    for(int i=0;i<n;i++)
    {
        std::cout << "\n";
        for(int j=0;j<brojac;j++)
        {
            std::cout << std::setw(NajvecaSirina(Matrica)+1) << std::right << Matrica.at(i).at(j);
        }
        brojac++;
    }
	return 0;
}
