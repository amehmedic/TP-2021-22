//TP 2017/2018: Tutorijal 2, Zadatak 4
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
        double re, im;
        std::cout << "R" << i+1 << " = ";
        std::cin >> re;
        std::cout << "X" << i+1 << " = \n";
        std::cin >> im;
        z={re,im};
        Impedansa+=1./z;
    }
    std::cout << "\nParalelna veza ovih elemenata ima R = " << real(1./Impedansa) << " i X = " << imag(1./Impedansa) << ".";
	return 0;
}
