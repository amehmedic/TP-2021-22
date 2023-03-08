/* 
    TP 16/17 (Tutorijal 7, Zadatak 9)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <functional>

std::function<double(double)> plus2(double x)
{
	return [x](double y){return x+y;};
}

std::function<std::function<double(double)>(double)> plus3(double x)
{
	return [x](double y){return [x,y](double z){return y+x+z;};};
}

int main ()
{
	std::cout << "Unesite x, y i z ";
	int x, y, z;
	std::cin >> x >> y >> z;
	std::cout << "\n";
	std::cout << plus2(x)(y);
	std::cout << "\n";
	std::cout << plus3(x)(y)(z);
	return 0;
}