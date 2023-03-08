/* 
    TP 16/17 (Tutorijal 10, Zadatak 1)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>

class StedniRacun
{
	double pocvrijednost;
	public:
	StedniRacun(double x=0){if(x<0) throw std::logic_error("Nedozvoljeno pocetno stanje"); pocvrijednost=x;}
	void Ulozi(double y){if(y+pocvrijednost<0) throw std::logic_error("Transakcija odbijena"); pocvrijednost+=y;};
	void Podigni(double y){if(y>pocvrijednost) throw std::logic_error("Transakcija odbijena"); pocvrijednost=pocvrijednost-y;};
	void ObracunajKamatu(double z){if(z<0) throw std::logic_error("Nedozvoljena kamatna stopa"); pocvrijednost=pocvrijednost+pocvrijednost*(z/100);}
	double DajStanje() const{return pocvrijednost;}
};

int main ()
{
	return 0;
}