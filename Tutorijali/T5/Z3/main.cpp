/* 
    TP 2018/2019: Tutorijal 5, Zadatak 3
	
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
#include <algorithm>
#include <cmath>

bool DaLiJeTrocifren(int x)
{
	return(x>99 && x<999);
}

bool DaLiJeKvadrat(int x)
{
	return(int(abs(x))==sqrt(x*x));
}


int main ()
{
	
	std::cout << "Unesite broj elemenata (max. 1000): ";
	int BrojElemenata;
	std::cin >> BrojElemenata;
	int niz[1000];
	std::cout << "\nUnesite elemente: ";
	std::for_each(std::begin(niz),std::end(niz), [](int& x) {int broj; std::cin >> broj; x=broj});
	std::cout << "\nNajveci element niza je " << max_element(niz.begin(),niz.end());
	std::cout << "Najmanji element niza se pojavljuje " << count(niz.begin(),niz.end(),min_element(niz.begin(),niz.end())) << " puta u nizu"
	std::cout << "U nizu ima  brojeva koji su potpuni kvadrati" << count_if(niz.begin(),niz.end(),DaLiJeKvadrat());
	std::cout << "Prvi element sa najmanjim brojem cifara je ";
	std::cout << "Elementi koji nisu trocifreni su: ";
	return 0;
}