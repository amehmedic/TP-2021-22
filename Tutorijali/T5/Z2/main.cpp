/* 
    TP 2018/2019: Tutorijal 5, Zadatak 2
	
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

template <typename Itertip1, typename Itertip2>
Itertip2 RazmijeniBlokove(Itertip1 pocetak1, Itertip1 kraj1, Itertip2 pocetak2)
{
	while(pocetak1!=kraj1)
	{
		auto pomocni=*pocetak1;
		*pocetak1=*pocetak2;
		*pocetak2=pomocni;
		pocetak1++;
		pocetak2++;
	}
	return pocetak2;
}


int main ()
{
	return 0;
}