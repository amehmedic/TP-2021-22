/* 
    TP 2018/2019: Tutorijal 5, Zadatak 6
	
	Autotestove pisala Nina Slamnik. Prijave gresaka, sugestije i pitanja
	mozete slati na mail nslamnik1@etf.unsa.ba.
	
	NAPOMENA: Tutorijal 5 sadrzi veliki broj ZABRANA, tipa zabrana
			  da se koristi indeksiranje niz[i] ili simulacija indeksiranja
			  npr. *(niz + i); dalje, da su zabranjene for petlje i slicno.
			  
			  To ce tutori rucno pregledati u toku tutorijala te ako
			  student bude PREKRSIO BAREM JEDNU ZABRANU, smatrace se da
			  za taj zadatak NIJE PROSAO NITI JEDAN AUTOTEST!
*/
#include <iostream>
#include <vector>
#include <algorithm>


int suma(int n)
{
	
}
bool Sortiraj(int x, int y)
{
	if(suma(x)==suma(y))
	{
		return x<y;
	}
	return suma(x)<suma(y);
}

int main ()
{
	std::cout << "Unesite broj elemenata: ";
	int BrojElemenata;
	std::cin >> BrojElemenata;
	std::cout << "Unesite elemente: ";
	std::vector<int> Vektor;
	std::for_each(std::begin(Vektor),std::end(Vektor),[](int& x) {int broj; std::cin >> broj; x=broj});
	std::cout << "Niz sortiran po sumi cifara glasi: " << ;
	std::cout << "Unesite broj koji trazite: ";
	int BrojKojiTrazim;
	std::cin >> BrojKojiTrazim;
	std::cout << "Trazeni broj nalazi se na poziciji " << find(Vektor.begin(),Vektor.end(),BrojKojiTrazim);
	return 0;
}