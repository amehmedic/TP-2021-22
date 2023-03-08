//TP 2017/2018: Tutorijal 2, Zadatak 5
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
        double otpor, pomak;
        std::cout << "Z" << i+1 << " = ";
        std::cin >> otpor;
        std::cout << "fi" << i+1 << " = \n";
        std::cin >> pomak;
        z=std::polar(otpor, pomak*(180./(4*atan(1))));
        Impedansa+=1./z;
    }
    std::cout << "Paralelna veza ovih elemenata ima Z = " << abs(1./Impedansa) << " i fi = " << std::arg(1./Impedansa) << ".";
	return 0;
}
