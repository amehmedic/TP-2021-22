/* 
    TP 2018/2019: Tutorijal 6, Zadatak 4
	
	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja 
	i sugestije saljite na mail: khodzic2@etf.unsa.ba
	
	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak
	
*/
#include <iostream>
#include <stdexcept>
#include <new>

template <typename TipElemenata>
void UnistiMatricu(TipElemenata **mat, int br_redova)
{
	if(!mat)
	{
		return;
	}
	delete[] mat[0];
	delete[] mat; 
}

int BrojClanova(int n)
{
	int broj=0;
	for(int i=0;i<n;i++)
	{
		broj=broj+2*i+1;
	}
	return broj;
}

int** KreirajTrougao(int n)
{
	if(n<=0)
	{
		throw std::domain_error("Broj redova mora biti pozitivan");
	}
	int** a=new int* [n];
	try
	{
		a[0]=nullptr;
		a[0]=new int [BrojClanova(n)];
		for(int i=1;i<n;i++)
		{
			a[i]=a[0]+BrojClanova(i);
		}
	}
	catch(...)
	{
		delete []a;
		throw;
	}
	for(int i=0;i<n;i++)
	{
		a[i][i]=1;
		int broj=i+1;
		for(int j=0;j<i;j++)
		{
			a[i][j]=broj;
			broj--;
		}
		broj=2;
		for(int j=i+1;j<2*i+1;j++)
		{
			a[i][j]=broj;
			broj++;
		}
	}
	return a;
}

int main ()
{
	std::cout << "Koliko zelite redova: ";
	int broj;
	std::cin >> broj;
	int **trokut=nullptr;
	try
	{
		trokut=KreirajTrougao(broj);
		for(int i=0;i<broj;i++)
		{
			for(int j=0;j<2*i+1;j++)
			{
				std::cout << trokut[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	catch(std::domain_error izuzetak)
	{
		std::cout << "Izuzetak: " << izuzetak.what();
	}
	catch(std::bad_alloc)
	{
		std::cout << "Izuzetak: Nedovoljno memorije!";
	}
	UnistiMatricu(trokut,broj);
	return 0;
}