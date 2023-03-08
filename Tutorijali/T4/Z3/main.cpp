//TP 2018/2019: Tutorijal 4, Zadatak 3
#include <iostream>
#include <vector>
#include <string>

void IzdvojiKrajnjeRijeci (std::vector<std::string> Rijeci, std::string &Prva_po_abecedi, std::string &Zadnja_po_abecedi)
{
    if (Rijeci.size()==0)
    {
        return;
    }
    Prva_po_abecedi=Rijeci.at(0);
    Zadnja_po_abecedi=Rijeci.at(0);
    for (int i=0;i<Rijeci.size();i++)
    {
        for (int j=0;j<Rijeci.at(i).size();j++)
        {
            if(j==Prva_po_abecedi.length())
            {
                break;
            }
            if(toupper(char(Rijeci.at(i).at(j)))>toupper(char(Prva_po_abecedi.at(j))))
            {
                break;
            }
            if(toupper(char(Rijeci.at(i).at(j)))==toupper(char(Prva_po_abecedi.at(j))) && j!=Rijeci.at(i).size()-1)
            {
                continue;
            }
            if(toupper(char(Rijeci.at(i).at(j)))<toupper(char(Prva_po_abecedi.at(j))))
            {
                Prva_po_abecedi=Rijeci.at(i);
                break;
            }
            Prva_po_abecedi=Rijeci.at(i);
        }
        for (int j=0;j<Rijeci.at(i).size();j++)
        {
            if(j==Zadnja_po_abecedi.length())
            {
                break;
            }
            if(toupper(char(Rijeci.at(i).at(j)))<toupper(char(Zadnja_po_abecedi.at(j))))
            {
                break;
            }
            if(toupper(char(Rijeci.at(i).at(j)))==toupper(char(Zadnja_po_abecedi.at(j))) && j!=Rijeci.at(i).size()-1)
            {
                continue;
            }
            if(toupper(char(Rijeci.at(i).at(j)))>toupper(char(Zadnja_po_abecedi.at(j))))
            {
                Zadnja_po_abecedi=Rijeci.at(i);
                break;
            }
            Zadnja_po_abecedi=Rijeci.at(i);
        }
    }
}

void ZadrziDuplikate (std::vector<std::string> &Rijeci)
{
    std::vector<std::string> DupleRijeci;
    for(int i=0;i<Rijeci.size();i++)
    {
        for(int j=0;j<Rijeci.size();j++)
        {
            if(i==j)
            {
                continue;
            }
            if(Rijeci.at(i)==Rijeci.at(j))
            {
                bool Jelimavec=false;
                for(int g=0;g<DupleRijeci.size();g++)
                {
                    if(Rijeci.at(j)==DupleRijeci.at(g))
                    {
                        Jelimavec=true;
                    }
                }
                if(Jelimavec==false)
                {
                    DupleRijeci.push_back(Rijeci.at(j));
                    break;
                }
            }
        }
    }
    Rijeci=DupleRijeci;
}

int main ()
{
    int Broj_Rijeci;
    std::cout << "Koliko zelite unijeti rijeci: ";
    std::cin >> Broj_Rijeci;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cout << "Unesite rijeci: ";
    std::vector<std::string> Rijeci(Broj_Rijeci);
    for(int i=0;i<Broj_Rijeci;i++)
    {
        std::cin >> Rijeci.at(i);
    }
    std::string Prva_po_abecedi, Zadnja_po_abecedi;
    IzdvojiKrajnjeRijeci(Rijeci, Prva_po_abecedi, Zadnja_po_abecedi);
    std::cout << "Prva rijec po abecednom poretku je: " << Prva_po_abecedi;
    std::cout << "\nPosljednja rijec po abecednom poretku je: " << Zadnja_po_abecedi;
    std::cout << "\nRijeci koje se ponavljaju su:";
    ZadrziDuplikate(Rijeci);
    for (int i=0;i<Rijeci.size();i++)
    {
        std::cout << " " << Rijeci.at(i);
    }
	return 0;
}