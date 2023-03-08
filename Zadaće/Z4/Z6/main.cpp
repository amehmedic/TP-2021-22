//TP 2021/2022: Zadaća 4, Zadatak 6
#include <iostream>
#include <cmath>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
#include <string>
#include <map>

struct Student
{
    int broj_indeksa;
    int godina_studija;
    std::string ime;
    std::string prezime;
    std::string adresa;
    std::string telefon;
};

class Knjiga
{
    std::string NaslovKnjige;
    std::string ImePisca;
    std::string Zanr;
    int GodinaIzdavanja;
    Student *Zaduzenje;
public:
    Knjiga(std::string naslovKnjige, std::string imePisca, std::string zanr, int godinaIzdavanja);
    std::string DajNaslov() const;
    std::string DajAutora() const;
    std::string DajZanr() const;
    int DajGodinuIzdavanja() const;
    void ZaduziKnjigu(Student &student);
    void RazduziKnjigu();
    bool DaLiJeZaduzena() const;
    Student &DajKodKogaJe() const;
    Student* DajPokKodKogaJe() const;
};

Knjiga::Knjiga(std::string naslovKnjige, std::string imePisca, std::string zanr, int godinaIzdavanja)
{
    NaslovKnjige=naslovKnjige;
    ImePisca=imePisca;
    Zanr=zanr;
    GodinaIzdavanja=godinaIzdavanja;
    Zaduzenje=nullptr;
}

std::string Knjiga::DajNaslov() const
{
    return NaslovKnjige;
}

std::string Knjiga::DajAutora() const
{
    return ImePisca;
}

std::string Knjiga::DajZanr() const
{
    return Zanr;
}

int Knjiga::DajGodinuIzdavanja() const
{
    return GodinaIzdavanja;
}

void Knjiga::ZaduziKnjigu(Student &student)
{
    if(Zaduzenje!=nullptr)
    {
        throw std::logic_error("Knjiga vec zaduzena");
    }
    Zaduzenje=&student;
}

void Knjiga::RazduziKnjigu()
{
    if(Zaduzenje==nullptr)
    {
        throw std::logic_error("Knjiga nije zaduzena");
    }
    Zaduzenje=nullptr;
}

bool Knjiga::DaLiJeZaduzena() const
{
    if(Zaduzenje==nullptr)
    {
        return false;
    }
    return true;
}

Student &Knjiga::DajKodKogaJe() const
{
    if(Zaduzenje==nullptr)
    {
        throw std::domain_error("Knjiga nije zaduzena");
    }
    return *Zaduzenje;
}

Student* Knjiga::DajPokKodKogaJe() const
{
    return Zaduzenje;
}

class Biblioteka
{
    std::map<int, std::shared_ptr<Student>> MapaKorisnika;
    std::map<int, std::shared_ptr<Knjiga>> MapaKnjiga;
public:
    Biblioteka();
    ~Biblioteka();
    Biblioteka(const Biblioteka &biblioteka);
    Biblioteka(Biblioteka &&biblioteka);
    Biblioteka &operator =(const Biblioteka &biblioteka);
    Biblioteka &operator =(Biblioteka &&biblioteka);
    void RegistrirajNovogStudenta(int broj_indeksa, std::string ime, std::string prezime, int godina_studija, std::string adresa, std::string telefon);
    void RegistrirajNovuKnjigu(int EvidencijskiBroj, std::string NaslovKnjige, std::string ImePisca, std::string Zanr, int GodinaIzdavanja);
    Student &NadjiStudenta(int broj_indeksa) const;
    Knjiga &NadjiKnjigu(int EvidencijskiBroj) const;
    void IzlistajStudente() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int EvidencijskiBroj, int broj_indeksa);
    void RazduziKnjigu(int EvidencijskiBroj);
    void PrikaziZaduzenja(int broj_indeksa) const;
};

Biblioteka::Biblioteka()
{
    std::map<int, std::shared_ptr<Student>> MapaKorisnika;
    std::map<int, std::shared_ptr<Knjiga>> MapaKnjiga;
}

Biblioteka::~Biblioteka()
{
    // Lol sta ce nam destruktor
}

Biblioteka::Biblioteka(const Biblioteka &biblioteka)
{
    auto p=biblioteka.MapaKorisnika.begin();
    auto q=biblioteka.MapaKorisnika.end();
    MapaKorisnika.clear();
    while(p!=q)
    {
        Student stud;
        auto student=std::make_shared<Student>(stud);
        (*student).broj_indeksa=(*p->second).broj_indeksa;
        (*student).godina_studija=(*p->second).godina_studija;
        (*student).ime=(*p->second).ime;
        (*student).prezime=(*p->second).prezime;
        (*student).adresa=(*p->second).adresa;
        (*student).telefon=(*p->second).telefon;
        MapaKorisnika.insert(std::pair<int,std::shared_ptr<Student>>((*p->second).broj_indeksa,student));
        p++;
    }
    auto k=biblioteka.MapaKnjiga.begin();
    auto l=biblioteka.MapaKnjiga.end();
    MapaKnjiga.clear();
    while(k!=l)
    {
        Knjiga knjig=Knjiga((*k->second).DajNaslov(), (*k->second).DajAutora(), (*k->second).DajZanr(), (*k->second).DajGodinuIzdavanja());
        auto knjiga=std::make_shared<Knjiga>(knjig);
        MapaKnjiga.insert(std::pair<int,std::shared_ptr<Knjiga>>(k->first,knjiga));
        k++;
    }
}

Biblioteka::Biblioteka(Biblioteka &&biblioteka)
{
    MapaKorisnika=biblioteka.MapaKorisnika;
    MapaKnjiga=biblioteka.MapaKnjiga;
    biblioteka.MapaKorisnika.clear();
    biblioteka.MapaKnjiga.clear();
}

Biblioteka &Biblioteka::operator =(const Biblioteka &biblioteka)
{
    if(MapaKorisnika==biblioteka.MapaKorisnika && MapaKnjiga==biblioteka.MapaKnjiga)
    {
        return *this;
    }
    auto p=biblioteka.MapaKorisnika.begin();
    auto q=biblioteka.MapaKorisnika.end();
    MapaKorisnika.clear();
    while(p!=q)
    {
        Student stud;
        auto student=std::make_shared<Student>(stud);
        (*student).broj_indeksa=(*p->second).broj_indeksa;
        (*student).godina_studija=(*p->second).godina_studija;
        (*student).ime=(*p->second).ime;
        (*student).prezime=(*p->second).prezime;
        (*student).adresa=(*p->second).adresa;
        (*student).telefon=(*p->second).telefon;
        MapaKorisnika.insert(std::pair<int,std::shared_ptr<Student>>((*p->second).broj_indeksa,student));
        p++;
    }
    auto k=biblioteka.MapaKnjiga.begin();
    auto l=biblioteka.MapaKnjiga.end();
    MapaKnjiga.clear();
    while(k!=l)
    {
        Knjiga knjig=Knjiga((*k->second).DajNaslov(), (*k->second).DajAutora(), (*k->second).DajZanr(), (*k->second).DajGodinuIzdavanja());
        auto knjiga=std::make_shared<Knjiga>(knjig);
        MapaKnjiga.insert(std::pair<int,std::shared_ptr<Knjiga>>(k->first,knjiga));
        k++;
    }
    return *this;
}

Biblioteka &Biblioteka::operator =(Biblioteka &&biblioteka)
{
    std::swap(MapaKorisnika, biblioteka.MapaKorisnika);
    std::swap(MapaKnjiga, biblioteka.MapaKnjiga);
    return *this;
}

void Biblioteka::RegistrirajNovogStudenta(int broj_indeksa, std::string ime, std::string prezime, 
int godina_studija, std::string adresa, std::string telefon)
{
    auto p=MapaKorisnika.begin();
    auto q=MapaKorisnika.end();
    while(p!=q)
    {
        if(p->first==broj_indeksa)
        {
            throw std::logic_error("Vec postoji student s tim brojem indeksa");
        }
        p++;
    }
    Student stud;
    auto student=std::make_shared<Student>(stud);
    (*student).broj_indeksa=broj_indeksa;
    (*student).godina_studija=godina_studija;
    (*student).ime=ime;
    (*student).prezime=prezime;
    (*student).adresa=adresa;
    (*student).telefon=telefon;
    MapaKorisnika.insert(std::pair<int,std::shared_ptr<Student>>(broj_indeksa,student));
}

void Biblioteka::RegistrirajNovuKnjigu(int EvidencijskiBroj, std::string NaslovKnjige, std::string ImePisca, 
std::string Zanr, int GodinaIzdavanja)
{
    auto p=MapaKnjiga.begin();
    auto q=MapaKnjiga.end();
    while(p!=q)
    {
        if(p->first==EvidencijskiBroj)
        {
            throw std::logic_error("Knjiga s tim evidencijskim brojem vec postoji");
        }
        p++;
    }
    Knjiga knjig=Knjiga(NaslovKnjige, ImePisca, Zanr, GodinaIzdavanja);
    auto knjiga=std::make_shared<Knjiga>(knjig);
    MapaKnjiga.insert(std::pair<int,std::shared_ptr<Knjiga>>(EvidencijskiBroj,knjiga));
}

Student &Biblioteka::NadjiStudenta(int broj_indeksa) const
{
    auto p=MapaKorisnika.begin();
    auto q=MapaKorisnika.end();
    while(p!=q)
    {
        if(p->first==broj_indeksa)
        {
            return *(p->second);  
        }
        p++;
    }  
    throw std::logic_error("Student nije nadjen");
}

Knjiga &Biblioteka::NadjiKnjigu(int EvidencijskiBroj) const
{
    auto p=MapaKnjiga.begin();
    auto q=MapaKnjiga.end();
    while(p!=q)
    {
        if(p->first==EvidencijskiBroj)
        {
            return *(p->second);  
        }
        p++;
    }  
    throw std::logic_error("Knjiga nije nadjena");
}

void Biblioteka::IzlistajStudente() const
{
    auto p=MapaKorisnika.begin();
    auto q=MapaKorisnika.end();
    while(p!=q)
    {
        std::cout << "Broj indeksa: " << p->first << "\n";
        std::cout << "Ime i prezime: " << (*(p->second)).ime << " " << (*(p->second)).prezime << "\n";
        std::cout << "Godina studija: " << (*(p->second)).godina_studija << "\n";
        std::cout << "Adresa: " << (*(p->second)).adresa << "\n";
        std::cout << "Broj telefona: " << (*(p->second)).telefon << "\n";
        p++;
    }
}

void Biblioteka::IzlistajKnjige() const
{
    auto p=MapaKnjiga.begin();
    auto q=MapaKnjiga.end();
    while(p!=q)
    {
        std::cout << "Evidencijski broj: " << p->first << "\n";
        std::cout << "Naslov: " << (*(p->second)).DajNaslov() << "\n";
        std::cout << "Pisac: " << (*(p->second)).DajAutora() << "\n";
        std::cout << "Zanr: " << (*(p->second)).DajZanr() << "\n";
        std::cout << "Godina izdavanja: " << (*(p->second)).DajGodinuIzdavanja() << "\n";
        if((*(p->second)).DaLiJeZaduzena()==true)
        {
            std::cout << "Zaduzena kod studenta: " << (*(p->second)).DajKodKogaJe().ime << " " << (*(p->second)).DajKodKogaJe().prezime << " (" << (*(p->second)).DajKodKogaJe().broj_indeksa << ")" << "\n";
        }
        p++;
    }
}

void Biblioteka::ZaduziKnjigu(int EvidencijskiBroj, int broj_indeksa)
{
    NadjiKnjigu(EvidencijskiBroj);
    NadjiStudenta(broj_indeksa);
    NadjiKnjigu(EvidencijskiBroj).ZaduziKnjigu(NadjiStudenta(broj_indeksa));
}

void Biblioteka::RazduziKnjigu(int EvidencijskiBroj)
{
    NadjiKnjigu(EvidencijskiBroj).RazduziKnjigu();
}

void Biblioteka::PrikaziZaduzenja(int broj_indeksa) const
{
    auto p=MapaKorisnika.begin();
    auto q=MapaKorisnika.end();
    Student korisnik;
    while(p!=q)
    {
        korisnik=NadjiStudenta(broj_indeksa);
        p++;
    }
    auto k=MapaKnjiga.begin();
    auto l=MapaKnjiga.end();
    int brojac=0;
    while(k!=l)
    {
        auto pok=&korisnik;
        auto pok2=(*(k->second)).DajPokKodKogaJe();
        if(pok2!=nullptr && (*pok).broj_indeksa==(*pok2).broj_indeksa)
        {
            std::cout << "Evidencijski broj: " << k->first << "\n";
            std::cout << "Naslov: " << (*(k->second)).DajNaslov() << "\n";
            std::cout << "Pisac: " << (*(k->second)).DajAutora() << "\n";
            std::cout << "Zanr: " << (*(k->second)).DajZanr() << "\n";
            std::cout << "Godina izdavanja: " << (*(k->second)).DajGodinuIzdavanja() << "\n";
            brojac++;
        }
        k++;
    }
    if(brojac==0)
    {
        std::cout << "Nema zaduzenja za tog studenta!";
    }
}

int main ()
{
	return 0;
}
