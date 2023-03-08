/* 
    TP 16/17 (Tutorijal 9, Zadatak 3)
	
	Testove pisao Kenan Ekinovic. Za sva pitanja, sugestije
	i zalbe obratiti se na mail: kekinovic1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <cmath>

class Vektor3d
{
	double koordinate[3];
	mutable int brojac=0;
	public:
	void Postavi(double x, double y, double z)
	{
		koordinate[0]=x;
		koordinate[1]=y;
		koordinate[2]=z;
	}
	void Ocitaj(double &x, double &y, double &z) const
	{
		x=koordinate[0];
		y=koordinate[1];
		z=koordinate[2];
	}
	void Ispisi() const
	{
		std::cout << "{" << koordinate[0] << "," << koordinate[1] << "," << koordinate[2] << "}";
		brojac++;
	}
	double DajX() const {return koordinate[0];}
	double DajY() const {return koordinate[1];}
	double DajZ() const {return koordinate[2];}
	double DajDuzinu() const {return std::sqrt(koordinate[0]*koordinate[0]+koordinate[1]*koordinate[1]+koordinate[2]*koordinate[2]);}
	Vektor3d &PomnoziSaSkalarom(double s) {koordinate[0]*=s; koordinate[1]*=s; koordinate[2]*=s; return *this;}
	Vektor3d &SaberiSa(const Vektor3d &v) {koordinate[0]+=v.koordinate[0]; koordinate[1]+=v.koordinate[1]; koordinate[2]+=v.koordinate[2]; return *this;}
	void PostaviX(double X) {this->koordinate[0]=X;}
	void PostaviY(double Y) {this->koordinate[1]=Y;}
	void PostaviZ(double Z) {this->koordinate[2]=Z;}
	int DajBrojIspisa() const {return this->brojac;}
	friend Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2);
};

Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2)
{
	Vektor3d v3;
	v3.koordinate[0]=v1.koordinate[0]+v2.koordinate[0];
	v3.koordinate[1]=v1.koordinate[1]+v2.koordinate[1];
	v3.koordinate[2]=v1.koordinate[2]+v2.koordinate[2];
	return v3;
}
int main ()
{
	Vektor3d v1, v2;
	v1.Postavi(1,2,3);
	v2.PostaviX(4);
	v2.PostaviY(5);
	v2.PostaviZ(6);
	v1.Ispisi();
	std::cout << "\n";
	v2.Ispisi();
	std::cout << "\n";
	double a=v1.DajDuzinu();
	std::cout << a << "\n";
	Vektor3d v3=ZbirVektora(v1,v2);
	v3.Ispisi();
	double x,y,z;
	v3.Ocitaj(x,y,z);
	std::cout << "\n" << x << " " << y << " " << z;
	Vektor3d v5;
	v5=v3.SaberiSa(v1);
	v5.Ispisi();
	v5.PomnoziSaSkalarom(10);
	v5.Ispisi();
	double f=v5.DajX();
	double c;
	c=v5.DajZ();
	double b;
	b=v5.DajY();
	std::cout << "\n" << f << " " << b << " " << c;
	int l=v5.DajBrojIspisa();
	std::cout << "\n" << l;
	return 0;
}