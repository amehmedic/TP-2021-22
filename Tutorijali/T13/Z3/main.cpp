/* 
    TP 16/17 (Tutorijal 13, Zadatak 3)
	Autotestove pisala Ivona Ivkovic. Sva pitanja, sugestije, prijave gresaka
	slati na mail iivkovic2@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <algorithm>

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


class Fakultet {
	std::vector<ApstraktniStudent*> kolekcija;
public:
    Fakultet() {}
    ~Fakultet() { 
    	for(int i=0; i<kolekcija.size(); i++) {
    	    delete kolekcija[i]; }
    	    kolekcija.resize(0);
    }
    Fakultet(const Fakultet &f) {
    	kolekcija.resize(f.kolekcija.size());
    	try {
    		for(int i=0; i<kolekcija.size(); i++) {
    		    kolekcija.at(i)=f.kolekcija.at(i)->DajKopiju();
    		}
    	}
    	catch(...) {
    		for(int i=0; i<kolekcija.size(); i++) {
    			delete kolekcija.at(i);
    		}
    		kolekcija.resize(0);
    		throw;
    	}
    }
    Fakultet &operator =(const Fakultet &f) {
    	std::swap(kolekcija,f.kolekcija);
    	return *this;
    }
    Fakultet(Fakultet &&f):
        //kolekcija.resize(f.kolekcija.size());
                kolekcija(std::move(f.kolekcija)) {                     
    }
    Fakultet &operator =(Fakultet &&f) {
        std::swap(kolekcija,f.kolekcija);
        return *this;
    }
    void UpisiStudenta(std::string ime, std::string prezime, int br_indeksa) {
        for(int i=0; i<kolekcija.size(); i++) { if(kolekcija.at(i)->DajBrojIndeksa()==br_indeksa) {
        throw std::logic_error("Student sa zadanim brojem indeksa vec postoji"); } }
        //StudentBachelor b(ime,prezime,br_indeksa);
         //StudentBachelor* a= new StudentBachelor(b);
         kolekcija.push_back(new StudentBachelor(ime,prezime,br_indeksa));
    }
    void UpisiStudenta(std::string ime, std::string prezime, int br_indeksa, int god) {
        for(int i=0; i<kolekcija.size(); i++) { if(kolekcija.at(i)->DajBrojIndeksa()==br_indeksa) {
            throw std::logic_error("Student sa zadanim brojem indeksa vec postoji"); }
        }
        //StudentMaster b(ime,prezime,br_indeksa,god);
        //StudentMaster* a=new StudentMaster(ime);
        kolekcija.push_back(new StudentMaster(ime,prezime,br_indeksa,god));
    }
    void ObrisiStudenta(int br_indeksa) {
        bool postoji=false;
        for(int i=0; i<kolekcija.size(); i++) { 
            if(kolekcija.at(i)->DajBrojIndeksa()==br_indeksa) {
                postoji=true;
                delete kolekcija.at(i);
                kolekcija.erase(std::begin(kolekcija)+i);
                break;
            }
        }
        if(!postoji) { throw std::logic_error("Student sa zadanim brojem indeksa ne postoji"); }
    }
   const ApstraktniStudent &operator [](int indeks) const {
        for(int i=0; i<kolekcija.size(); i++) { 
            if(kolekcija.at(i)->DajBrojIndeksa()==indeks) {
                return *(kolekcija.at(i));
            }
        }
        throw std::logic_error("Student sa zadanim brojem indeksa ne postoji"); 
    }
    ApstraktniStudent &operator [](int indeks) {
        for(int i=0; i<kolekcija.size(); i++) {
            if(kolekcija.at(i)->DajBrojIndeksa()==indeks) {
                return *(kolekcija.at(i));
            }
        }
        throw std::logic_error("Student sa zadanim brojem indeksa ne postoji");
    }
    void IspisiSveStudente() const {
        std::vector<ApstraktniStudent*> k(kolekcija);
        std::sort(std::begin(k),std::end(k), [] (ApstraktniStudent* a, ApstraktniStudent* b)->bool {
            if(a->DajProsjek()!=b->DajProsjek()) { return a->DajProsjek()>b->DajProsjek(); }
            else { return a->DajBrojIndeksa()<b->DajBrojIndeksa(); }
        });
        for(int i=0; i<k.size(); i++) {
            k.at(i)->IspisiPodatke();
        }
    }
    
    
};
int main ()
{
  Fakultet f;
  f.UpisiStudenta("Hamo","Hamic",12343);
  f.UpisiStudenta("Mr","Gospodin",23412);
  f.ObrisiStudenta(23412);
  f.IspisiSveStudente();
  
	return 0;
}