/* 
    TP 16/17 (Tutorijal 7, Zadatak 6)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <list>

template <typename Tip>
std::list<Tip> SortirajListu(std::list<Tip> &Lista)
{
	auto pocetak=Lista.begin();
	auto kraj=Lista.end();
	while(pocetak!=kraj)
	{
		auto pomoc=pocetak;
		while(pomoc!=kraj)
		{
			if(*pomoc<*pocetak)
			{
				auto zamjenski=*pomoc;
				*pomoc=*pocetak;
				*pocetak=zamjenski;
			}
			pomoc++;
		}
		pocetak++;
	}
	return Lista;
}

int main ()
{
	std::cout << "Koliko ima elemenata: ";
	int broj;
	std::cin >> broj;
	std::cout << "Unesite elemente: ";
	std::list<int> Lista;
	for(auto i=0;i<broj;i++)
	{
		int Broj;
		std::cin>> Broj;
		Lista.push_back(Broj);
	}
	Lista=SortirajListu(Lista);
	std::cout << "Sortirana lista: ";
	for(auto i : Lista)
	{
		std::cout << i << " ";
	}
	return 0;
}