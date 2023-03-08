/* 
    TP 2018/2019: Tutorijal 5, Zadatak 5
	
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
#include <iomanip>

double TrapeznoPravilo(double f(double), double a, double b, int n)
{
	double suma(0);
	for(int i=1;i<n;i++)
	{
		suma+=f(a+((b-a)/n)*i);
	}
	return(((b-a)/double(n))*((1./2)*f(a)+(1./2)*f(b)+suma));
}


int main ()
{
	double pi=4*std::atan(1);
	std::cout << "Unesite broj podintervala: ";
	int BrojPodintervala;
	std::cin >> BrojPodintervala;
	std::cout << "Za taj broj podintervala priblizne vrijednosti integrala iznose:";
	std::cout << "\n- Za funkciju sin x na intervalu (0,pi): " << std::fixed << std::setprecision(5) << TrapeznoPravilo(sin, 0, pi, BrojPodintervala);
	std::cout << "\n- Za funkciju x^3 na intervalu (0,10): " << std::fixed << std::setprecision(2) << TrapeznoPravilo([](double x){return x*x*x;}, double(0),double(10),BrojPodintervala);
	std::cout << "\n- Za funkciju 1/x na intervalu (1,2): " << std::fixed << std::setprecision(5) << TrapeznoPravilo([](double x){return 1./x;}, double(1),double(2),BrojPodintervala);
	return 0;
}