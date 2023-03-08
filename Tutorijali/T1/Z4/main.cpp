//TP 2016/2017: Tutorijal 1, Zadatak 4
#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
    double broj;
    do
    {
        cout << "Unesite prirodan broj ili 0 za kraj: ";
        cin >> broj;
        while (int(broj)!=broj || broj<0 || !cin )
        {
            cout << "Niste unijeli prirodan broj!\n";
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Unesite prirodan broj ili 0 za kraj: ";
            cin >> broj;
        }
        int cijelibroj=int(broj);
        if (cijelibroj==0)
        {
            cout << "Dovidjenja!" << endl;
            continue;
        }
        int broj2=0, i;
        for (i=1;i<cijelibroj;i++)
        {
            if (cijelibroj%i==0)
            {
                broj2+=i;
            }
        }
        if (broj2==cijelibroj)
        {
            cout << "Broj "<< cijelibroj << " je savrsen!" << endl;
            continue;
        }
        if (broj2>cijelibroj)
        {
            cout << "Broj "<< cijelibroj << " je obilan!" << endl;
            continue;
        }
        if (broj2<cijelibroj)
        {
            cout << "Broj "<< cijelibroj << " je manjkav!" << endl;
            continue;
        }
    }
    while (broj!=0);
	return 0;
}