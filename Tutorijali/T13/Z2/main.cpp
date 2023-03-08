/* 
    TP 16/17 (Tutorijal 13, Zadatak 2)
	Autotestove pisala Ivona Ivkovic. Sva pitanja, sugestije, prijave gresaka
	slati na mail iivkovic2@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <string>
#include <exception>

class ApstraktniStudent {
protected:
	std::string ime;
	std::string prezime;
	int br_indeksa;
	int br_polozenih;
	double prosjek;
public:
    ApstraktniStudent(std::string ime, std::string prezime, int br_ind) {
    	this->ime=ime; this->prezime=prezime;
    	br_indeksa=br_ind; this->br_polozenih=0; this->prosjek=5;
    }
    virtual ~ApstraktniStudent() {}
    std::string DajIme() const { return ime; }
    std::string DajPrezime() const { return prezime; }
    int DajBrojIndeksa() const { return br_indeksa; }
    int DajBrojPolozenih() const { return br_polozenih; }
    double DajProsjek() const { return prosjek; }
    void RegistrirajIspit(int ocjena) { 
    	if(ocjena<5 || ocjena>10) { throw std::domain_error("Neispravna ocjena"); }
    	if(ocjena!=5) {
    		prosjek=(prosjek*br_polozenih+ocjena)/(br_polozenih+1);
    		br_polozenih++;
    	}}
    void PonistiOcjene() { br_polozenih=0; prosjek=5; }
    virtual void IspisiPodatke() const {}
    virtual ApstraktniStudent* DajKopiju() { /*ApstraktniStudent a(ime,prezime,br_indeksa); a.br_polozenih=br_polozenih;
    a.prosjek=prosjek; 
    auto d=new ApstraktniStudent(a); 
    return *d;*/
     return new ApstraktniStudent(*this); }
};

class StudentBachelor: public ApstraktniStudent {
public:
	StudentBachelor(std::string ime, std::string prezime, int br_ind): 
	ApstraktniStudent(ime,prezime,br_ind) {}
	 ApstraktniStudent* DajKopiju() { return new StudentBachelor(*this); }
	 /*a.br_polozenih=br_polozenih;a.prosjek=prosjek;*/ 
	void IspisiPodatke() const { std::cout<<"Student bachelor studija "<<ime<<" "<<prezime<<", sa brojem indeksa "<<br_indeksa<<","<<"\n"<<"ima prosjek "
	<<prosjek<<".\n"; }
};

class StudentMaster: public ApstraktniStudent {
	int godina_prvi_stepen;
public:
    StudentMaster(std::string ime, std::string prezime, int br_ind,int god_prvi_step): 
    ApstraktniStudent(ime,prezime,br_ind), godina_prvi_stepen(god_prvi_step) {}
    void IspisiPodatke() const {
    	std::cout<<"Student master studija "<<ime<<" "<<prezime<<", "<<"sa brojem indeksa "<<br_indeksa<<","<<"\n"<<"zavrsio bachelor studij godine "
    	         <<godina_prvi_stepen<<",ima prosjek "<<prosjek<<".\n";
    }
    StudentMaster* DajKopiju()  {  /*auto m=DajKopiju(); m->godina_prvi_stepen=godina_prvi_stepen;
    m.br_polozenih=br_polozenih; m.prosjek=prosjek;*/ return new StudentMaster(*this); }
};
int main ()
{
	StudentBachelor Armin("Armin","B",1111);
	Armin.IspisiPodatke();
	std::cout<<"\n";
	StudentMaster Neko("Neko","Nek",121434,223244);
	Neko.IspisiPodatke();
	ApstraktniStudent *a;
	return 0;
}