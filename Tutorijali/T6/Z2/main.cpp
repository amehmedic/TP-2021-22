/* 
    TP 2018/2019: Tutorijal 6, Zadatak 2
	
	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja 
	i sugestije saljite na mail: khodzic2@etf.unsa.ba
	
	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <new>

template <typename Tip>
auto KreirajIzvrnutiNiz(Tip p1, Tip p2) -> typename std::remove_reference<decltype(*p1)>::type*
{
	int n=0;
	Tip pa=p1;
	Tip pb=p2;
	while(pa!=pb)
	{
		n++;
		pa++;
	}
	typename std::remove_reference<decltype(*p1)>::type *pok;
	try
	{
		pok=new typename std::remove_reference<decltype(*p1)>::type[n];
	}
	catch(std::bad_alloc)
	{
		throw std::bad_alloc();
	}
	typename std::remove_reference<decltype(*p1)>::type *niz=pok;
	for(int i=n-1;i>=0;i--)
	{
		niz[i]=*p1;
		p1++;
	}
	return pok;
}

int main ()
{
	try
	{
		std::cout << "Koliko zelite elemenata: ";
		int broj;
		std::cin >> broj;
		std::vector<double> Vektor(broj);
		std::cout << "Unesite elemente: ";
		for(int i=0;i<broj;i++)
		{
			std::cin >> Vektor[i];
		}
		double* obrnuti=KreirajIzvrnutiNiz(Vektor.begin(),Vektor.end());
		std::cout << "Kreirani niz:";
		for(int i=0;i<broj;i++)
		{
			std::cout << " " << obrnuti[i];
		}
		delete[] obrnuti;
	}
	catch(std::bad_alloc izuzetak)
	{
		std::cout << "Nedovoljno memorije!";
	}
	return 0;
}