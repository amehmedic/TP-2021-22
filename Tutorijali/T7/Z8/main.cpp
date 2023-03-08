/* 
    TP 16/17 (Tutorijal 7, Zadatak 8)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <algorithm>

std::string IzvrniBezRazmaka(std::string String)
{
	std::string Pomoc;
	std::remove_copy(String.rbegin(),String.rend(),std::back_inserter(Pomoc),' ');
	return Pomoc;
}

int main ()
{
	std::cout << "Unesite string: ";
	std::string String;
	std::getline(std::cin, String);
	std::cout << "Izvrnuto bez razmaka: ";
	String=IzvrniBezRazmaka(String);
	std::cout << String;
	return 0;
}