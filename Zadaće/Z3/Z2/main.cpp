// TP 2021/2022: Zadaća 3, Zadatak 2
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>

bool Aretheydigitsorletters(char c)
{
    if (isalpha(c) != 0)
    {
        return true;
    }
    if (isdigit(c) != 0)
    {
        return true;
    }
    return false;
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string String)
{
    std::map<std::string, std::set<int>> Mapa;
    bool waslastalpha = false;
    int startofword = 0;
    std::string Rijec;
    for (int i = 0; i < String.length(); i++)
    {
        auto znak = String.at(i);
        if (waslastalpha == false && Aretheydigitsorletters(znak) == true)
        {
            startofword = i;
            waslastalpha = true;
            Rijec.push_back(tolower(znak));
            if (i == String.length() - 1)
            {
                auto it = Mapa.find(Rijec);
                if(it != Mapa.end())
                {
                    Mapa.find(Rijec)->second.insert(startofword);
                }
                else
                {
                    std::set<int> Set;
                    Mapa.insert({Rijec, Set});
                    it = Mapa.find(Rijec);
                    it->second.insert(startofword);
                }
            }
            continue;
        }
        if (waslastalpha == true && Aretheydigitsorletters(znak) == true)
        {
            Rijec.push_back(tolower(znak));
            waslastalpha = true;
            if (i == String.length() - 1)
            {
                auto it = Mapa.find(Rijec);
                if(it != Mapa.end())
                {
                    Mapa.find(Rijec)->second.insert(startofword);
                }
                else
                {
                    std::set<int> Set;
                    Mapa.insert({Rijec, Set});
                    it = Mapa.find(Rijec);
                    it->second.insert(startofword);
                }
            }
            continue;
        }
        if (waslastalpha == true && Aretheydigitsorletters(znak) == false)
        {
            auto it = Mapa.find(Rijec);
            if(it != Mapa.end())
            {
                Mapa.find(Rijec)->second.insert(startofword);
            }
            else
            {
                std::set<int> Set;
                Mapa.insert({Rijec, Set});
                it = Mapa.find(Rijec);
                it->second.insert(startofword);
            }
            waslastalpha = false;
            Rijec = "";
            continue;
        }
        if (waslastalpha == false && Aretheydigitsorletters(znak) == false)
        {
            waslastalpha = false;
            continue;
        }
    }
    return Mapa;
}

std::set<int> PretraziIndeksPojmova(std::string Rijec, std::map<std::string, std::set<int>> Mapa)
{
    for(int i=0;i<Rijec.length();i++)
    {
        Rijec.at(i)=tolower(Rijec.at(i));
    }
    auto it = Mapa.find(Rijec);
    if (it == Mapa.end())
    {
        throw std::logic_error("Pojam nije nadjen");
    }
    return it->second;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> Mapa)
{
    auto p = Mapa.begin();
    auto q = Mapa.end();
    while (p != q)
    {
        std::cout << p->first << ": ";
        auto k = p->second.begin();
        auto l = p->second.end();
        while (k != l)
        {
            std::cout << *k;
            k++;
            if(k!=l)
            {
                std::cout << ",";
            }
        }
        std::cout << "\n";
        p++;
    }
}

int main()
{
    std::cout << "Unesite tekst: ";
    std::string String;
    std::getline(std::cin, String);
    std::map<std::string, std::set<int>> IndeksPojmova;
    IndeksPojmova=KreirajIndeksPojmova(String);
    IspisiIndeksPojmova(IndeksPojmova);
    while (1 != 0)
    {
        std::cout << "Unesite rijec: ";
        std::string Rijec;
        std::getline(std::cin, Rijec);
        try
        {
            if (Rijec == ".")
            {
                break;
            }
            std::set<int> Set;
            Set=PretraziIndeksPojmova(Rijec, IndeksPojmova);
            auto p=Set.begin();
            auto q=Set.end();
            while(p!=q)
            {
                std::cout << *p << " ";
                p++;
            }
            std::cout << "\n";
        }
        catch (...)
        {
            std::cout << "Unesena rijec nije nadjena!\n";
        }
    }
    return 0;
}
