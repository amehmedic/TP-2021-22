/* 
    TP 16/17 (Tutorijal 11, Zadatak 2)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>

class StedniRacun
{
	double stanje;
	static int brojk;
	static int broja;
	public:
	StedniRacun(double stanje1=0)
	{
		if(stanje1<0)
		{
			throw std::logic_error("Nedozvoljeno pocetno stanje");
		}
		stanje=stanje1;
		brojk++;
		broja++;
	}
	StedniRacun(const StedniRacun &racun)
	{
		stanje=racun.stanje;
		brojk++;
		broja++;
	}
	~StedniRacun()
	{
		broja--;
	}
	void Ulozi(double x)
	{
		if(x+stanje<0)
		{
			throw std::logic_error("Transakcija odbijena");
		}
		stanje=stanje+x;
	}
	void Podigni(double x)
	{
		if(x>stanje)
		{
			throw std::logic_error("Transakcija odbijena");
		}
		stanje=stanje-x;
	}
	double DajStanje() const
	{
		return stanje;
	}
	void ObracunajKamatu(double x)
	{
		if(x<0)
		{
			throw std::logic_error("Nedozvoljena kamatna stopa");
		}
		stanje=stanje+stanje*(x/100);
	}
	static int DajBrojKreiranih()
	{
		return StedniRacun::brojk;
	}
	static int DajBrojAktivnih()
	{
		return StedniRacun::broja;
	}
};

int StedniRacun::broja=0;
int StedniRacun::brojk=0;

int main ()
{
	return 0;
}