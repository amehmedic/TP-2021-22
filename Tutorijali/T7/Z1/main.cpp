/* 
    TP 16/17 (Tutorijal 7, Zadatak 1)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <algorithm>
#include <new>
#include <cstring>

template <typename Tip>
void BubbleSort(Tip Recenice, int broj)
{
	for(int i=0;i<broj-1;i++)
	{
		for(int j=0;j<broj-1;j++)
		{
			if(std::strcmp(Recenice[j], Recenice[j+1])>0)
			{
				auto pomocni=Recenice[j];
				Recenice[j]=Recenice[j+1];
				Recenice[j+1]=pomocni;
			}
		}
	}
}

int main ()
{
	char** Recenice=nullptr;
	int broj;
	std::cout << "Koliko zelite recenica: ";
	std::cin >> broj;
	std::cin.ignore(1000, '\n');
	std::cout << "Unesite recenice: ";
	try
	{
		char** Recenice= new char*[broj];
		for(int i=0;i<broj;i++)
		{
			char radni_prostor[1000];
			std::cin.getline(radni_prostor, sizeof radni_prostor);
			Recenice[i]=new char[std::strlen(radni_prostor)+1];
			std::strcpy(Recenice[i],radni_prostor);
		}
		BubbleSort(Recenice, broj);
		std::cout << "\nSortirane recenice:" << "\n";
		for (int i=0;i<broj;i++)
		{
			std::cout << Recenice[i] << "\n";
		}
		for (int i=0;i<broj;i++)
		{
			delete[] Recenice[i];
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