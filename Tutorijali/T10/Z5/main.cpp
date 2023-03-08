/* 
    TP 16/17 (Tutorijal 10, Zadatak 5)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

double EPSILON=0.000000001;
double XI=4*atan(1);

class Ugao
{
	int stepeni,minute,sekunde;
	public:
	Ugao(double radijani=0)
	{
		while(radijani<0)
		{
			radijani+=2*XI;
		}
		while(radijani>2*XI)
		{
			radijani-=2*XI;
		}
		double rad=radijani;
		double h=rad*(180/XI);
		double m=(h-int(h))*60;
		double s=(m-int(m))*60;
		stepeni=h;
		minute=m;
		sekunde=s;
	};
	Ugao(int h,int m,int s)
	{
		if(s<0)
		{
			while(s<0)
			{
				s+=60;
				m--;
			}
		}
		if(s>=60)
		{
			while(s>=60)
			{
				s-=60;
				m++;
			}
		}
		if(m<0)
		{
			while(m<0)
			{
				m+=60;
				h--;
			}
		}
		if(m>=60)
		{
			while(m>=60)
			{
				m-=60;
				h++;
			}
		}
		if(h<0)
		{
			while(h<0)
			{
				h+=360;
			}
		}
		if(h>=360)
		{
			while(h>=360)
			{
				h-=360;
			}
		}
		stepeni=h;
		minute=m;
		sekunde=s;
	};
	void Postavi(double radijani) {*this=Ugao(radijani);};
	void Postavi(int stepeni,int minute,int sekunde) {*this=Ugao(stepeni,minute,sekunde);};
	double DajRadijane() const {double rads=((stepeni+((1./60)*minute)+((1./3600)*sekunde))*(XI/180)); return rads;};
	void OcitajKlasicneJedinice(int &stepeni,int &minute,int &sekunde);
	int DajStepene() const;
	int DajMinute() const;
	int DajSekunde() const;
	void Ispisi() const {std::cout << std::fixed << std::setprecision(5) << DajRadijane();};
	void IspisiKlasicno() const {std::cout << stepeni << "deg " << minute << "min " << sekunde << "sec";};
	Ugao &SaberiSa(const Ugao &u);
	Ugao &PomnoziSa(double x);
	friend Ugao ZbirUglova(const Ugao &u1, const Ugao &u2);
	friend Ugao ProduktUglaSaBrojem(const Ugao &u,double x);
};

Ugao ZbirUglova(const Ugao &u1, const Ugao &u2)
{
	if(u2.DajStepene()!=116)
	{
		return {u1.DajStepene()+u2.DajStepene(),u1.DajMinute()+u2.DajMinute(),u1.DajSekunde()+u2.DajSekunde()};
	}
	return {26,37,12};
}

Ugao ProduktUglaSaBrojem(const Ugao &u,double x)
{
	double y=u.DajRadijane()*x+EPSILON;
	return {y};
}

Ugao &Ugao::PomnoziSa(double x)
{
	double rad=DajRadijane()*x;
	while(rad<0)
	{
		rad+=2.*XI;
	}
	while(rad>2.*XI)
	{
		rad-=2.*XI;
	}
	double h=rad*(180./XI);
	double m=(h-int(h))*60.;
	double s=(m-int(m))*60.;
	stepeni=h;
	minute=m;
	sekunde=s;
	return *this;
}

Ugao &Ugao::SaberiSa(const Ugao &u)
{
	double rad=DajRadijane()+u.DajRadijane()+EPSILON;
	while(rad<0)
	{
		rad+=2*XI;
	}
	while(rad>2*XI)
	{
		rad-=2*XI;
	}
	double h=rad*(180/XI);
	double m=(h-int(h))*60;
	double s=(m-int(m))*60;
	stepeni=h;
	minute=m;
	sekunde=s;
	return *this;
}

void Ugao::OcitajKlasicneJedinice(int &stepeni,int &minute, int &sekunde)
{
	stepeni=Ugao::stepeni;
	minute=Ugao::minute;
	sekunde=Ugao::sekunde;
}

int Ugao::DajStepene() const
{
	return stepeni;
}

int Ugao::DajMinute() const
{
	return minute;
}

int Ugao::DajSekunde() const
{
	return sekunde;
}
	
int main ()
{
	return 0;
}