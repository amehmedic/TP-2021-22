/* 
    TP 16/17 (Tutorijal 11, Zadatak 1)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>

class NeobicnaKlasa
{
	int broj;
	public:
	explicit NeobicnaKlasa(int x)
	{
		broj=x;
		std::cout << "Direktna inicijalizacija\n";
	}
	NeobicnaKlasa(double x)
	{
		broj=x;
		std::cout << "Kopirajuca inicijalizacija\n";
	}
};

int main ()
{
	return 0;
}