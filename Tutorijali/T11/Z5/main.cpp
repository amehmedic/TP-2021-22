/* 
    TP 16/17 (Tutorijal 11, Zadatak 5)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <iomanip>
#include <cstring>
#include <new>
#include <algorithm>

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

class Liga
{
	std::vector<std::shared_ptr<Tim>> timovi;
public:
	explicit Liga(int velicina_lige) : max_broj_timova(velicina_lige), broj_timova(0), timovi(new Tim*[velicina_lige]{}) {} 
	explicit Liga(std::initializer_list<Tim> lista_timova);
	~Liga();
	Liga(const Liga &l);
	Liga(Liga &&l);
	Liga &operator =(const Liga &l);
	Liga &operator =(Liga &&l);
	void DodajNoviTim(const char ime_tima[]);
	void RegistrirajUtakmicu(const char tim1[], const char tim2[], int rezultat_1, int rezultat_2);
	void IspisiTabelu();
};

Liga::Liga(std::initializer_list<Tim> lista_timova) : max_broj_timova(lista_timova.size()), broj_timova(0)
{
	timovi=nullptr;
	timovi=new Tim*[lista_timova.size()];
	auto pocetak=lista_timova.begin();
	for(int i=0;i<lista_timova.size();i++)
	{
		timovi[i]=nullptr;
		timovi[i]=new Tim(*pocetak);
		pocetak++;
		broj_timova++;
	}
}

Liga::~Liga()
{
	for(int i=0;i<broj_timova;i++)
	{
		delete timovi[i];
	}
	delete [] timovi;
}

Liga::Liga(const Liga &l):max_broj_timova(l.max_broj_timova)
{
	if(max_broj_timova!=l.max_broj_timova)
	{
		throw std::range_error("Nesaglasni kapaciteti liga");
	}
	timovi=new Tim*[l.broj_timova];
	for(int i=0;i<l.broj_timova;i++)
	{
		timovi[i]=nullptr;
		Tim tim=*(l.timovi[i]);
		timovi[i]=new Tim(tim);
	}
	broj_timova=l.broj_timova;
}

Liga::Liga(Liga &&l):max_broj_timova(l.max_broj_timova)
{
	timovi=l.timovi;
	for(int i=0;i<l.broj_timova;i++)
	{
		timovi[i]=l.timovi[i];
		l.timovi[i]=nullptr;
	}
	l.timovi=nullptr;
	broj_timova=l.broj_timova;
}

Liga &Liga::operator =(const Liga &l)
{
	if(max_broj_timova<l.max_broj_timova)
	{
		throw std::logic_error("Nesaglasni kapaciteti liga");
	}
	if(l.broj_timova>broj_timova)
	{
		try
		{
			for(int i=broj_timova;i<l.broj_timova;i++)
			{
				timovi[i]=new Tim(*l.timovi[i]);
			}
		}
		catch(...)
		{
			for(int i=broj_timova;i<l.broj_timova;i++)
			{
				delete timovi[i];
				timovi[i]=nullptr;
			}
			throw;
		}
	}
	else
	{
		for(int i=l.broj_timova;i<broj_timova;i++)
		{
			delete timovi[i];
			timovi[i]=nullptr;
		}
	}
	broj_timova=l.broj_timova;
	for(int i=0;i<l.broj_timova;i++)
	{
		*timovi[i]=*l.timovi[i];
	}
	return *this;
}

Liga &Liga::operator=(Liga &&l)
{
	if(max_broj_timova<l.max_broj_timova)
	{
		throw std::logic_error("Nesaglasni kapaciteti liga");
	}
	timovi=l.timovi;
	for(int i=0;i<l.broj_timova;i++)
	{
		timovi[i]=l.timovi[i];
		l.timovi[i]=nullptr;
	}
	l.timovi=nullptr;
	broj_timova=l.broj_timova;
	return *this;
}

void Liga::DodajNoviTim(const char ime_tima[])
{
	if(broj_timova>=max_broj_timova)
	{			
		throw std::range_error ("Liga popunjena");
	}
	if(std::strlen(ime_tima)>20)
	{
		throw std::range_error("Predugacko ime tima");
	}
	Tim *tim=nullptr;
	tim=new Tim(ime_tima);
	timovi[broj_timova++]=tim;
}

void Liga::RegistrirajUtakmicu(const char tim1[], const char tim2[], int rezultat_1, int rezultat_2)
{
	int i=0; int j=0;
	if(rezultat_1<0 || rezultat_2<0)
	{
		throw std::range_error("Neispravan broj golova");
	}
	for(i=0;i<broj_timova;i++)
	{
		if(strcmp(timovi[i]->DajImeTima(),tim1)==0)
		{
			break;
		}
	}
	for(j=0;j<broj_timova;j++)
	{
		if(strcmp(timovi[j]->DajImeTima(),tim2)==0)
		{
			break;
		}
	}
	if(i==broj_timova || j==broj_timova)
	{
		throw std::logic_error ("Tim nije nadjen");
	}
	timovi[i]->ObradiUtakmicu(rezultat_1, rezultat_2);
	timovi[j]->ObradiUtakmicu(rezultat_2, rezultat_1);
}

void Liga::IspisiTabelu()
{
	std::sort(timovi,timovi+broj_timova, [] (Tim *a, Tim *b)
	{
		if(a->DajBrojPoena()!=b->DajBrojPoena())
		{
			return a->DajBrojPoena()>b->DajBrojPoena();
		}
		if(a->DajGolRazliku()!=b->DajGolRazliku())
		{
			return a->DajGolRazliku()>b->DajGolRazliku();
		}
		return strcmp(a->DajImeTima(),b->DajImeTima())<0;
	});
	for(int i=0;i<broj_timova;i++)
	{
		timovi[i]->IspisiPodatke();
	}
}

int main ()
{
	return 0;
}