/* 
    TP 16/17 (Tutorijal 11, Zadatak 3)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <iomanip>
#include <cstring>

class Tim
{
	char ime_tima[20];
	int broj_odigranih;
	int broj_pobjeda;
	int broj_nerijesenih;
	int broj_poraza;
	int broj_datih;
	int broj_primjljenih;
	int broj_poena;
	public:
	Tim(const char ime[]);
	void ObradiUtakmicu(int broj_datih, int broj_primljenih);
	const char *DajImeTima() const
	{
		return ime_tima;
	}
	int DajBrojPoena() const
	{
		return broj_poena;
	}
	int DajGolRazliku() const
	{
		return broj_datih-broj_primjljenih;
	}
	void IspisiPodatke() const;
};

Tim::Tim(const char ime[]):broj_odigranih(0), broj_pobjeda(0), broj_nerijesenih(0), broj_poraza(0), broj_datih(0), broj_primjljenih(0), broj_poena(0)
{
	if(std::strlen(ime)>20)
	{
		throw std::range_error("Predugacko ime tima");
	}
	std::strcpy(ime_tima,ime);
}

void Tim::ObradiUtakmicu(int broj_datih, int broj_primjljenih)
{
	if(broj_datih<0 || broj_primjljenih<0)
	{
		throw std::range_error("Neispravan broj golova");
	}
	int razlika=broj_datih-broj_primjljenih;
	Tim::broj_datih=Tim::broj_datih+broj_datih;
	Tim::broj_odigranih++;
	Tim::broj_primjljenih=Tim::broj_primjljenih+broj_primjljenih;
	if(razlika==0)
	{
		broj_nerijesenih++;
		broj_poena++;
	}
	else if(razlika<0)
	{
		broj_poraza++;
	}
	else if(razlika>0)
	{
		broj_pobjeda++;
		broj_poena=broj_poena+3;
	}
}

void Tim::IspisiPodatke() const
{
	std::cout << std::left << std::setw(20) << ime_tima << std::right << std::setw(4) << broj_odigranih << std::setw(4) << broj_pobjeda << std::setw(4) << broj_nerijesenih << std::setw(4) << broj_poraza << std::setw(4) << broj_datih << std::setw(4) << broj_primjljenih << std::setw(4) << broj_poena << "\n";
}
int main ()
{
	return 0;
}