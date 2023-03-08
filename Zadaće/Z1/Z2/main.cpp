//TP 2021/2022: Zadaća 1, Zadatak 2
#include <iostream>
#include <cmath>
#include <vector>
#include <array>

std::vector<std::vector<double>> MnozenjeMatrica (std::vector<std::vector<double>> A, std::vector<std::vector<double>> B)
{
    // Provjeravamo da li su matrice saglanse za mnozenje
    if(A.size()>0 || B.size()>0)
    {
        if(A.size()<=0 || A.at(0).size()!=B.size() ) 
        {
            throw std::domain_error("Matrice nisu saglasne za mnozenje!");
        }
    }

    // Provjeravamo da matrice nisu kvrgave
    for(int i=0;i<A.size();i++)
    {
        if(A.at(i).size()!=A.at(0).size())
        {
            throw std::domain_error("Neispravna matrica!");
        }
    }
    for(int i=0;i<B.size();i++)
    {
        if(B.at(i).size()!=B.at(0).size())
        {
            throw std::domain_error("Neispravna matrica!");
        }
    }

	// Kreiranje prazne matrice odgovarajucih dimenzija
	std::vector<std::vector<double>> Rezultat;
    Rezultat.resize(A.size());
    for(int i=0;i<Rezultat.size();i++)
    {
        Rezultat.at(i).resize(B.at(0).size());
    }
	
	// Racunanje proizvoda matrica
    for(int i=0;i<Rezultat.size();i++)
    {
        for(int j=0;j<Rezultat.at(i).size();j++)
        {
            for(int k=0;k<A.at(0).size();k++)
            {
                for(int l=0;l<B.size();l++)
                {
                    if(k==l)
                    {
                        Rezultat.at(i).at(j)+=0+(A.at(i).at(k)*B.at(l).at(j));
                    }
                }
            }
        }
    }
    return Rezultat;
}

std::array<std::vector<std::vector<double>>, 2> DoolittleLU(std::vector<std::vector<double>> H)
{
    // Kreiramo moderni niz koji vracamo na kraju funkcije
    std::array<std::vector<std::vector<double>>, 2> Rezultat;
    Rezultat.at(0).resize(H.size());
    Rezultat.at(1).resize(H.size());
    for(int i=0;i<H.size();i++)
    {
        Rezultat.at(0).at(i).resize(H.size());
        Rezultat.at(1).at(i).resize(H.size());
    }

    // Provjeravamo da li je matrica kvadratna
    if(H.size()>0)
    {
        if(H.size()!=H.at(0).size())
        {
            throw std::domain_error("Matrica mora biti kvadratna!");
        }
    }

    // Provjeravamo da matrica nije kvrgava
    for(int i=0;i<H.size();i++)
    {
        if(H.at(i).size()>0)
        {
            if(H.at(i).size()!=H.at(0).size())
            {
                throw std::domain_error("Neispravna matrica!");
            }
        }
    }

    // Racunamo hard part
    for(int i=0;i<H.size();i++)
    {
        for(int k=i;k<H.size();k++)
        {
            double Suma=0;
            for(int j=0;j<i;j++)
            {
                Suma+=(Rezultat.at(0).at(i).at(j)*Rezultat.at(1).at(j).at(k));
            }
            Rezultat.at(1).at(i).at(k)=H.at(i).at(k)-Suma;
        }
        for(int k=i;k<H.size();k++)
        {
            if(fabs(Rezultat.at(1).at(i).at(i)) < 1/(pow(10, 10)))
            {
                throw std::domain_error("Matrica je singularna!");
            }
            if(i==k)
            {
                Rezultat.at(0).at(i).at(i)=1;
            }
            else
            {
                double Suma=0;
                for(int j=0;j<i;j++)
                {
                    Suma+=(Rezultat.at(0).at(k).at(j)*Rezultat.at(1).at(j).at(i));
                }
                Rezultat.at(0).at(k).at(i)=(H.at(k).at(i)-Suma)/Rezultat.at(1).at(i).at(i);
            }
        }
    }
    return Rezultat;
}

bool ProvjeriFaktorizaciju(std::vector<std::vector<double>> H, std::array<std::vector<std::vector<double>>, 2> TriDMatrica)
{
    // Provjeravamo dimenzija matrica
    if(H.size()!=TriDMatrica.at(0).size() || H.size()!=TriDMatrica.at(1).size() || TriDMatrica.at(1).size()!=TriDMatrica.at(0).size())
    {
        return false;
    }

    // Provjeravamo funkciju DoolittleLU
    std::array<std::vector<std::vector<double>>, 2> Provjera=DoolittleLU(H);
    for(int i=0;i<Provjera.at(0).size();i++)
    {
        for(int j=0;j<Provjera.at(0).size();j++)
        {
            if(fabs(Provjera.at(0).at(i).at(j)-TriDMatrica.at(0).at(i).at(j)) > (1/pow(10, 10)))
            {
                return false;
            }
        }
    }
    for(int i=0;i<Provjera.at(1).size();i++)
    {
        for(int j=0;j<Provjera.at(1).size();j++)
        {
            if(fabs(Provjera.at(1).at(i).at(j)-TriDMatrica.at(1).at(i).at(j)) > (1/pow(10, 10)))
            {
                return false;
            }
        }
    }

    //Provjeravamo funkciju MnozenjeMatrica
    std::vector<std::vector<double>> Umnozak=MnozenjeMatrica(TriDMatrica.at(0), TriDMatrica.at(1));
    for(int i=0;i<Umnozak.size();i++)
    {
        for(int j=0;j<Umnozak.size();j++)
        {
            if(fabs(H.at(i).at(j)-Umnozak.at(i).at(j)) > (1/pow(10, 10)))
            {
                return false;
            }
        }
    }
    return true;
}

int main ()
{
    std::vector<std::vector<double>> Matrica;
    int Dimenzija=0;
    std::cout << "Broj redova/kolona matrice: ";
    std::cin >> Dimenzija;
    Matrica.resize(Dimenzija);
    for(int i=0;i<Dimenzija;i++)
    {
        Matrica.at(i).resize(Dimenzija);
    }
    std::cout << "Elementi matrice: ";
    for(int i=0;i<Dimenzija;i++)
    {
        for(int j=0;j<Dimenzija;j++)
        {
            std::cin >> Matrica.at(i).at(j);
        }
    }
    std::cout << std::endl << std::endl;
    std::array<std::vector<std::vector<double>>, 2> Obradi;
    try
    {
        Obradi=DoolittleLU(Matrica);
    }
    catch(...)
    {
        std::cout << "LU faktorizacija ne postoji, jer je matrica singularna!";
        return 0;
    }
    std::cout << "Matrica L: " << std::endl;
    for(int i=0;i<Obradi.at(0).size();i++)
    {
        for(int j=0;j<Obradi.at(0).size();j++)
        {
            std::cout << Obradi.at(0).at(i).at(j) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Matrica U: " << std::endl;
    for(int i=0;i<Obradi.at(1).size();i++)
    {
        for(int j=0;j<Obradi.at(1).size();j++)
        {
            std::cout << Obradi.at(1).at(i).at(j) << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
