/* 
    TP 16/17 (Tutorijal 7, Zadatak 4)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <memory>
#include <algorithm>
#include <new>
#include <cstring>

int main ()
{
	int broj;
	std::cout << "Koliko zelite recenica: ";
	std::cin >> broj;
	std::cin.ignore(1000, '\n');
	typedef std::shared_ptr<std::string> Shared;
	std::cout << "Unesite recenice: ";
	try
	{
		std::unique_ptr<Shared[]> p(new Shared[broj]);
		for(int i=0;i<broj;i++)
		{
			p[i]=std::make_shared<std::string>();
			std::getline(std::cin, *p[i].get());
		}
		std::sort(p.get(),p.get()+broj,[](Shared s1,Shared s2){if(*s1<*s2) return true; return false;});
		std::cout<<"\nSortirane recenice:" << "\n";
		for(int i=0;i<broj;i++)
		{
			std::cout<< *p[i] << "\n";
		}
	}
	catch(...)
	{
		std::cout << "\nProblemi s memorijom!";
	}
	return 0;
}