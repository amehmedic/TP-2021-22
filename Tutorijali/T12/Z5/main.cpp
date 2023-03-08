/* 
    TP 16/17 (Tutorijal 12, Zadatak 5)
	Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: khodzic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>


int main ()
{
	std::cout<<"Koliko zelite elemenata: ";
	int n;
	std::cin>>n;
	std::vector<double> v(n);
	std::cout<<"Unesite elemente: ";
	for(int i=0; i<n; i++) {
		double a;
		std::cin>>a;
		v.at(i)=a; 
	}
	std::transform(std::begin(v),std::end(v),std::begin(v),std::bind(std::divides<double>(),1,std::placeholders::_1));
	
	std::cout<<"Transformirani elementi: ";
	for(auto x: v) { std::cout<<x<<" "; }
	return 0;
}
