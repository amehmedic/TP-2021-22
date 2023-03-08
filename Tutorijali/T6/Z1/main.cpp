/* 
    TP 2018/2019: Tutorijal 6, Zadatak 1
	
	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja 
	i sugestije saljite na mail: khodzic2@etf.unsa.ba
	
	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak
	
*/
#include <iostream>
#include <new>
#include <cmath>
#include <limits>
#include <stdexcept>


template <typename Tip>
Tip* GenerirajStepeneDvojke(int n)
{
	if(n<=0)
	{
		throw std::domain_error("Broj elemenata mora biti pozitivan");
	}
	if((powl(Tip(2),n-1))>std::numeric_limits<Tip>::max())
	{
		throw std::overflow_error("Prekoracen dozvoljeni opseg");
	}
	Tip* pok=nullptr;
	try
	{
		pok=new Tip[n];
	}
	catch(...)
	{
		throw std::runtime_error("Alokacija nije uspjela");
	}
	Tip* pok2=pok;
	for(int i=0;i<n;i++)
	{
		pok2[i]=pow(2,i);
	}
	return pok;
}

int main ()
{
	try
	{
		std::cout << "Koliko zelite elemenata: ";
		int n;
		std::cin >> n;
		int* niz=GenerirajStepeneDvojke<int>(n);
		for(int i=0;i<n;i++)
		{
			std::cout << niz[i] << " ";
		}
		delete[] niz;
	}
	catch(std::domain_error izuzetak)
	{
		std::cout << "Izuzetak: " << izuzetak.what();
	}
	catch(std::overflow_error izuzetak)
	{
		std::cout << "Izuzetak: " << izuzetak.what();
	}
	catch(std::runtime_error izuzetak)
	{
		std::cout << "Izuzetak: " << izuzetak.what();
	}
	catch(std::bad_alloc)
	{
		std::cout << "Alokacija nije uspjela";
	}
	return 0;
}