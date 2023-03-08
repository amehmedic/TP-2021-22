// TP 2021/2022: Zadaća 1, Zadatak 3
#include <cmath>
#include <iostream>
#include <vector>

bool DaLiSeDameNapadaju(std::vector<std::vector<bool>> Ploca)
{
    for (int i = 0; i < Ploca.size(); i++)
    {
        for (int j = 0; j < Ploca.at(i).size(); j++)
        {
            if (Ploca.at(i).at(j) == true)
            {
                for (int k = 0; k < Ploca.size(); k++)
                {
                    for (int l = 0; l < Ploca.at(k).size(); l++)
                    {
                        if (k == i && j == l)
                        {
                            continue;
                        }
                        if (k == i && Ploca.at(k).at(l) == true)
                        {
                            return true;
                        }
                        if (l == j && Ploca.at(k).at(l) == true)
                        {
                            return true;
                        }
                        if (i - k == j - l && Ploca.at(k).at(l) == true)
                        {
                            return true;
                        }
                        if (i - k == (-1) * (j - l) && Ploca.at(k).at(l) == true)
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    std::vector<std::vector<bool>> Matrica;
    std::cout << "Unesite opis sahovske ploce:" << std::endl << "(Q za kraljicu, bilo sta drugo za prazno polje, ENTER naprazno za kraj unosa):";
    bool Pamti = false;
    int i = 0;
    char Unos = 0;
    std::vector<bool> BoolVektor;
    while (1 == 1 && Pamti == false)
    {
        Pamti = true;
        if (i >= Matrica.size())
        {
            Matrica.push_back(BoolVektor);
        }
        if (std::cin.peek() == '\n' || std::cin.peek() == ' ')
        {
            if (Unos != '\n')
            {
                Pamti = false;
            }
            Unos = std::cin.get();
        }
        else
        {
            std::cin >> Unos;
        }
        if (Unos == 'Q')
        {
            Matrica.at(i).push_back(true);
            Pamti = false;
            if (std::cin.peek() == '\n')
            {
                i++;
            }
            continue;
        }
        else if (Unos != '\n')
        {
            Matrica.at(i).push_back(false);
            Pamti = false;
            if (std::cin.peek() == '\n')
            {
                i++;
            }
            continue;
        }
    }
    std::cout << std::endl;
    if (DaLiSeDameNapadaju(Matrica) == true)
    {
        std::cout << "Dame se medjusobno napadaju.";
    }
    else
    {
        std::cout << "Dame se medjusobno ne napadaju.";
    }
    return 0;
}