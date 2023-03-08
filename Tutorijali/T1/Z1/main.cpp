//TP 2016/2017: Tutorijal 1, Zadatak 1
#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
    cout << "Unesite duzinu, sirinu i dubinu bazena u metrima: ";
    int duzina, sirina, dubina;
    cin >> duzina >> sirina >> dubina;
    cout << "Unesite sirinu plocice u centimetrima: ";
    int plocica;
    cin >> plocica;
    if (duzina*100%plocica!=0 || sirina*100%plocica!=0 || dubina*100%plocica!=0)
    {
        cout << "\nPoplocavanje bazena dimenzija " << duzina << "x" << sirina << "x" << dubina << "m sa plocicama dimenzija " << plocica << "x" << plocica << "cm";
        cout << "\nnije izvodljivo bez lomljenja plocica!";
        return 0;
    }
    cout << "\nZa poplocavanje bazena dimenzija " << duzina << "x" << sirina << "x" << dubina << "m sa plocicama dimenzija " << plocica << "x" << plocica << "cm\npotrebno je " << (((duzina*sirina)+(duzina*dubina*2)+(sirina*dubina*2))*10000)/(plocica*plocica) << " plocica.";
	return 0;
}