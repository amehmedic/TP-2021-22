//TP 2017/2018: Tutorijal 2, Zadatak 3
#include <iostream>
#include <complex>

int main ()
{
    int broj_elemenata;
    std::cout << "Unesite broj elemenata: \n";
    std::cin >> broj_elemenata;
    std::complex<double> Impedansa = {0,0};
    for (int i=0;i<broj_elemenata;i++)
    {
        std::complex<double> z;
        std::cout << "Z_" << i+1 << " = ";
        std::cin >> z;
        Impedansa+=1./z;
    }
    std::cout << "\nParalelna veza ovih elemenata ima impedansu Z_ = " << 1./Impedansa << ".";
	return 0;
}
