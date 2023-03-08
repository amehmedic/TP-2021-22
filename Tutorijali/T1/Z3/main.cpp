//TP 2016/2017: Tutorijal 1, Zadatak 3
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main ()
{
    cout << "Unesite pocetnu i krajnju vrijednost: \n";
    int a, b;
    cin >> a >> b;
    cout << "+---------+----------+----------+-----------+\n";
    cout << "| Brojevi | Kvadrati | Korijeni | Logaritmi |\n";
    cout << "+---------+----------+----------+-----------+\n";
    for(;a<=b;a++)
    {
        cout << "| ";
        cout.width(8); cout << left << a;
        cout << "|";
        cout.width(9); cout << right << a*a;
        cout << " |";
        cout.width(9); cout << fixed << setprecision(3) << right << sqrt(a);
        cout << " |";
        cout.width(10); cout << fixed << setprecision(5) << right << log(a);
        cout << " |\n";
    }
    cout << "+---------+----------+----------+-----------+\n";
	return 0;
}