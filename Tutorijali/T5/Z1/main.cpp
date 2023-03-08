/* 
    TP 2018/2019: Tutorijal 5, Zadatak 1
	
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


int main ()
{
	char niz[1000];
	std::cout << "Unesite recenicu: ";
	std::cin.getline(niz, sizeof niz);
	char* p=niz;
	char* pocetakbezprve;
	bool jesmolnarijeci=false;
	int brojac=0;
	while(*p!='\0')
	{
		if(*p!=' ' && jesmolnarijeci==false)
		{
			jesmolnarijeci=true;
			brojac++;
		}
		if(*p==' ')
		{
			jesmolnarijeci=false;
		}
		if(brojac==2)
		{
			pocetakbezprve=p;
			break;
		}
		p++;
	}
	std::cout << "Recenica bez prve rijeci glasi: ";
	if(brojac<2)
	{
		return 0;
	}
	while(*pocetakbezprve!='\0')
	{
		std::cout << *pocetakbezprve;
		pocetakbezprve++;
	}
	std::cout << "\n";
	return 0;
}