//TP 2017/2018: Tutorijal 1, Zadatak 2
#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
    cout << "Unesite tri broja: ";
    double a, b, c;
    cin >> a >> b >> c;
    if (a+b<=c || a+c<=b || b+c<=a)
    {
        cout << "Ne postoji trougao cije su duzine stranica " << a << ", " << b << " i " << c << "!" << endl;
        return 0;
    }
    cout << "Obim trougla sa duzinama stranica " << a << ", " << b << " i " << c << " iznosi " << a+b+c << "." << endl;
    cout << "Njegova povrsina iznosi " << sqrt(((a+b+c)/2)*(((a+b+c)/2)-a)*(((a+b+c)/2)-b)*(((a+b+c)/2)-c)) << "." << endl;
    double najmanji;
    double alfa, beta, gama;
    alfa=acos(((a*a)+(b*b)-(c*c))/(2*a*b));
    beta=acos(((b*b)+(c*c)-(a*a))/(2*c*b));
    gama=acos(((c*c)+(a*a)-(b*b))/(2*c*a));
    if(alfa<=beta && alfa<=gama)
    {
        najmanji=alfa;
    }
    else if(beta<=alfa && beta<=gama)
    {
        najmanji=beta;
    }
    else if(gama<=alfa && gama<=beta)
    {
        najmanji=gama;
    }
    double stepeni, minuta, sekundi;
    stepeni=najmanji*(180/(4*atan(1)));
    minuta=(stepeni-int(stepeni))*60;
    sekundi=(minuta-int(minuta))*60;
    cout << "Njegov najmanji ugao ima " << int(stepeni) << " stepeni, " << int(minuta) << " minuta i " << int(sekundi) << " sekundi.";
	return 0;
}
