// TP 2021/2022: Zadaća 1, Zadatak 1
#include <cmath>
#include <iostream>
#include <vector>

int CiklickaPermutacija(std::vector<int> A, std::vector<int> B)
{
    // Ako vektori nisu iste veličine vrati -1
    if (A.size() != B.size())
    {
        return -1;
    }
    if (A.size()>0 && B.size()>0)
    {
        bool Trigger=false;
        int Pomak = 0;
        for (int i = 0; i < A.size(); i++) 
        {
            if(Trigger==true)
            {
                return Pomak;
            }
            if (A.at(i) != B.at(0))
            {
                Pomak=i+1;
            }
            if (A.at(i) == B.at(0))
            {
                Trigger=true;
                for (int j = 0; j < B.size(); j++)
                {
                    if (j + Pomak < A.size())
                    {
                        if (B.at(j) == A.at(j + Pomak))
                        {
                            continue;
                        } 
                        else
                        {
                            Pomak++;
                            Trigger=false;
                            break;
                        }
                    }
                    if (j + Pomak >= A.size())
                    {
                        if (B.at(j) == A.at(Pomak-A.size()+j))
                        {
                            continue;
                        } 
                        else
                        {
                            Pomak++;
                            Trigger=false;
                            break;
                        }
                    }
                }
            }
        }
        if(Trigger==true)
        {
            return Pomak;
        }
        return -1;
    }
}

int main()
{
    std::cout << "Prva sekvenca: ";
    std::vector<int> v1;
    while (1 == 1)
    {
        int broj;
        std::cin >> broj;
        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(9999999, '\n');
            break;
        }
        v1.push_back(broj);
    }
    std::cout << "Druga sekvenca: ";
    std::vector<int> v2;
    while (1 == 1)
    {
        int broj;
        std::cin >> broj;
        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(9999999, '\n');
            break;
        }
        v2.push_back(broj);
    }
    int Ispitaj=CiklickaPermutacija(v1, v2);
    if(Ispitaj==-1)
    {
        std::cout << "Druga sekvenca nije ciklicka permutacija prve.";
    }
    else
    {
       std::cout << "Druga sekvenca je ciklicka permutacija prve s pomakom " << Ispitaj << "."; 
    }
    return 0;
}
