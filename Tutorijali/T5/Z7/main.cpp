/* 
    TP 2018/2019: Tutorijal 5, Zadatak 7
	
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

template <typename Itertip>
auto SumaBloka(Itertip pocetak, Itertip kraj) -> decltype(*pocetak+*kraj)
{
	if(pocetak==kraj)
	{
		throw std::range_error ("Blok je prazan");
	}
	auto Suma=*pocetak;
	pocetak++;
	while(pocetak!=kraj)
	{
		Suma+=*pocetak;
		pocetak++;
	}
	return Suma;
}

int main ()
{
	return 0;
}