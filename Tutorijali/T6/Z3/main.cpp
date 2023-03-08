/* 
    TP 2018/2019: Tutorijal 6, Zadatak 3
	
	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja 
	i sugestije saljite na mail: khodzic2@etf.unsa.ba
	
	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak
	
*/
#include <iostream>
#include <stdexcept>
#include <new>

int** KreirajTrougao(int n)
{
	if(n<=0)
	{
		throw std::domain_error("Broj redova mora biti pozitivan");
	}
	int** pok=new int* [n];
	for(int i=0;i<n;i++)
	{
		pok[i]=nullptr;
	}
	try
	{
		for(int i=0;i<n;i++)
		{
			pok[i]=new int[2*i+1];
			for(int j=0;j<2*i+1;j++)
			{
				if(j<=i)
				{
					pok[i][j]=i-j+1;
				}
				else 
				{
					pok[i][j]=j-i+1;
				}
			}
		}
	}
	catch(std::bad_alloc)
	{
		for(int i=0;i<n;i++)
		{
			delete[] pok[i];
		}
		delete [] pok;
		throw std::bad_alloc();
	}
	return pok;
}

int main ()
{
	std::cout << "Koliko zelite redova: ";
	int broj;
	std::cin >> broj;
	try
	{
		auto trokut=KreirajTrougao(broj);
		for(int i=0;i<broj;i++)
		{
			for(int j=0;j<2*i+1;j++)
			{
				std::cout << trokut[i][j] << " ";
			}
			std::cout << std::endl;
		}
		for(int i=0;i<broj;i++)
		{
			delete[] trokut[i];
		}
		delete [] trokut;
	}
	catch(std::domain_error izuzetak)
	{
		std::cout << "Izuzetak: " << izuzetak.what();
	}
	catch(std::bad_alloc)
	{
		std::cout << "Izuzetak: Nedovoljno memorije!";
	}
	return 0;
}