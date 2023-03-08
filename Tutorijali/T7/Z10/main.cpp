/* 
    TP 16/17 (Tutorijal 7, Zadatak 10)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <functional>

std::function<int(int)> IteriranaFunkcija(std::function<int(int)> funkcija, int n)
{
	return [funkcija, n](int x)
	{
		for(int i=0;i<n;i++)
		{
			x=funkcija(x);
		}
		return x;
	};
}

int Faktorijel(int x)
{
	int Faktorijel=1;
	for(int i=x;i>0;i--)
	{
		Faktorijel=Faktorijel*i;
	}
	return Faktorijel;
}

int main ()
{
	// Test za faktorijel
	std::cout << "Unesite broj koji hocete faktorijelat: ";
	int broj;
	std::cin >> broj;
	std::cout << "Koliko puta? ";
	int Puta;
	std::cin >> Puta;
	std::cout << Faktorijel(broj) << "\n";
	std::cout << IteriranaFunkcija(Faktorijel, Puta)(broj);
	return 0;
}