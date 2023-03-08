/* 
    TP 16/17 (Tutorijal 7, Zadatak 3)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <algorithm>
#include <new>
#include <cstring>

int main ()
{
	std::string** Recenice=nullptr;
	int broj;
	std::cout << "Koliko zelite recenica: ";
	std::cin >> broj;
	std::cin.ignore(1000, '\n');
	std::cout << "Unesite recenice: ";
	try
	{
		std::string** Recenice= new std::string*[broj];
		for(int i=0;i<broj;i++)
		{
			Recenice[i]=new std::string;
			std::getline(std::cin, *Recenice[i]);
		}
		std::sort(Recenice,Recenice+broj,[](std::string* s1, std::string* s2){if(*s1<*s2) return true; return false;});
		std::cout << "\nSortirane recenice:" << "\n";
		for (int i=0;i<broj;i++)
		{
			std::cout << *Recenice[i] << "\n";
		}
		for (int i=0;i<broj;i++)
		{
			delete Recenice[i];
		}
		delete[] Recenice;
	}
	catch(...)
	{
		std::cout << "\nProblemi s memorijom!";
		delete[] Recenice;
	}
	return 0;
}