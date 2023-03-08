//TP 2021/2022: Zadaća 5, Zadatak 3
#include <iostream>
#include <cmath>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include <functional>
#include <fstream>

class Spremnik
{
protected:
    double TezinaSpremnika;
    std::string NazivSadrzaja;
public:
    Spremnik(double Tezina, std::string Naziv)
    {
        TezinaSpremnika=Tezina;
        NazivSadrzaja=Naziv;
    }
    virtual ~Spremnik() {}
    double DajTezinu() const
    {
        return TezinaSpremnika;
    }
    virtual double DajUkupnuTezinu() const=0;
    virtual void Ispisi() const=0;
    //virtual std::shared_ptr<Spremnik> DajKopiju() const=0;
    virtual Spremnik *DajKopiju() const=0;
};

class Sanduk : public Spremnik
{
    std::vector<double> TezinePredmeta;
public:
    Sanduk(double TezinaSanduka, std::string NazivSadrzajaSanduka, std::vector<double> TezinePredmetaSanduka)
    : Spremnik(TezinaSanduka,NazivSadrzajaSanduka), TezinePredmeta(TezinePredmetaSanduka) {}
    double DajUkupnuTezinu() const override
    {
        double Zbir=TezinaSpremnika;
        for(int i=0;i<TezinePredmeta.size();i++)
        {
            Zbir+=TezinePredmeta.at(i);
        }
        return Zbir;
    }
    void Ispisi() const override
    {
        std::cout << "Vrsta spremnika: Sanduk\n";
        std::cout << "Sadrzaj: " << NazivSadrzaja << "\n";
        std::cout << "Tezine predmeta: ";
        for(int i=0;i<TezinePredmeta.size();i++)
        {
            std::cout << TezinePredmeta.at(i) << " ";
        }
        std::cout << "(kg)\n";
        std::cout << "Vlastita tezina: " << TezinaSpremnika << " (kg)\n";
        std::cout << "Ukupna tezina: " << (*this).DajUkupnuTezinu() << " (kg)\n";
    }
    //std::shared_ptr<Spremnik> DajKopiju() const override
    //{
    //   return std::shared_ptr<Sanduk>(new Sanduk(*this));
    //}
    Spremnik *DajKopiju() const override
    {
        Spremnik *pok=nullptr;
        pok=new Sanduk(*this);
        return pok;
    }
};

class Vreca : public Spremnik
{
    double TezinaMaterije;
public:
    Vreca(double TezinaVrece, std::string NazivSadrzajaVrece, double TezinaMaterijeVrece)
    : Spremnik(TezinaVrece,NazivSadrzajaVrece), TezinaMaterije(TezinaMaterijeVrece) {}
    double DajUkupnuTezinu() const override
    {
        double Zbir=TezinaSpremnika+TezinaMaterije;
        return Zbir;
    }
    void Ispisi() const override
    {
        std::cout << "Vrsta spremnika: Vreca\n";
        std::cout << "Sadrzaj: " << NazivSadrzaja << "\n";
        std::cout << "Vlastita tezina: " << TezinaSpremnika << " (kg)\n";
        std::cout << "Tezina pohranjene materije: " << TezinaMaterije << " (kg)\n";
        std::cout << "Ukupna tezina: " << (*this).DajUkupnuTezinu() << " (kg)\n";
    }
    //std::shared_ptr<Spremnik> DajKopiju() const override
    //{
    //   return std::shared_ptr<Vreca>(new Vreca(*this));
    //}
    Spremnik *DajKopiju() const override
    {
        Spremnik *pok=nullptr;
        pok=new Vreca(*this);
        return pok;
    }
};

class Bure : public Spremnik
{
    double GustinaTecnosti;
    double ZapreminaTecnosti;
public:
    Bure(double TezinaBureta, std::string NazivSadrzajaBureta, double GustinaTecnostiBureta, double ZapreminaTecnostiBureta)
    : Spremnik(TezinaBureta,NazivSadrzajaBureta), GustinaTecnosti(GustinaTecnostiBureta), ZapreminaTecnosti(ZapreminaTecnostiBureta) {}
    double DajUkupnuTezinu() const override
    {
        double Zbir=TezinaSpremnika;
        Zbir+=(GustinaTecnosti*ZapreminaTecnosti*0.001);
        return Zbir;
    }
    void Ispisi() const override
    {
        std::cout << "Vrsta spremnika: Bure\n";
        std::cout << "Sadrzaj: " << NazivSadrzaja << "\n";
        std::cout << "Vlastita tezina: " << TezinaSpremnika << " (kg)\n";
        std::cout << "Specificna tezina tecnosti: " << GustinaTecnosti << " (kg/m^3)\n";
        std::cout << "Zapremina tecnosti: " << ZapreminaTecnosti << " (l)\n";
        std::cout << "Ukupna tezina: " << (*this).DajUkupnuTezinu() << " (kg)\n";
    }
    //std::shared_ptr<Spremnik>DajKopiju() const override
    //{
    //   return std::shared_ptr<Bure>(new Bure(*this));
    //}
    Spremnik *DajKopiju() const override
    {
        Spremnik *pok=nullptr;
        pok=new Bure(*this);
        return pok;
    }
};

class Skladiste
{
    std::vector<std::shared_ptr<Spremnik>> Spremnici;
public:
    Skladiste() {}
    ~Skladiste();
    Skladiste(const Skladiste &skladiste);
    Skladiste(Skladiste &&skladiste);
    Skladiste &operator =(const Skladiste &skladiste);
    Skladiste &operator =(Skladiste &&skladiste);
    Spremnik *DodajSanduk(double TezinaSanduka, std::string NazivSadrzajaSanduka, std::vector<double> TezinePredmetaSanduka);
    Spremnik *DodajVrecu(double TezinaVrece, std::string NazivSadrzajaVrece, double TezinaMaterijeVrece);
    Spremnik *DodajBure(double TezinaBureta, std::string NazivSadrzajaBureta, double GustinaTecnostiBureta, double ZapreminaTecnostiBureta);
    Spremnik *DodajSpremnik(Spremnik *Spremnik, bool trueorfalse);
    void BrisiSpremnik(Spremnik *Adresa);
    const Spremnik &DajNajlaksi() const =delete;
    const Spremnik &DajNajtezi() const =delete;
    Spremnik &DajNajtezi();
    Spremnik &DajNajlaksi();
    int BrojPreteskih(int NovaTezina) const;
    void IzlistajSkladiste() const;
    void UcitajIzDatoteke(std::string string);
};

Skladiste::~Skladiste()
{
    for(int i=0;i<Spremnici.size();i++)
    {
        Spremnici.at(i)=nullptr;
        Spremnici.resize(0);
    }
}

Skladiste::Skladiste(const Skladiste &skladiste)
{
    for(int i=0;i<skladiste.Spremnici.size();i++)
    {
        auto p=std::shared_ptr<Spremnik>(skladiste.Spremnici.at(i)->DajKopiju());
        //Spremnici.push_back(skladiste.Spremnici.at(i)->DajKopiju());
        Spremnici.push_back(p);
    }
}

Skladiste::Skladiste(Skladiste &&skladiste)
{
    Spremnici=skladiste.Spremnici;
    skladiste.Spremnici.resize(0);
}

Skladiste &Skladiste::operator =(const Skladiste &skladiste)
{
    std::vector<std::shared_ptr<Spremnik>> Novi;
    for(int i=0;i<skladiste.Spremnici.size();i++)
    {
        auto p=std::shared_ptr<Spremnik>(skladiste.Spremnici.at(i)->DajKopiju());
        //Novi.push_back(skladiste.Spremnici.at(i)->DajKopiju());
        Novi.push_back(p);
    }
    Spremnici=Novi;
    return *this;
}

Skladiste &Skladiste::operator =(Skladiste &&skladiste)
{
    std::swap(Spremnici,skladiste.Spremnici);
    skladiste.Spremnici.resize(0);
    return*this;
}

Spremnik *Skladiste::DodajSanduk(double TezinaSanduka, std::string NazivSadrzajaSanduka, std::vector<double> TezinePredmetaSanduka)
{
    Spremnici.push_back(std::make_shared<Sanduk>(TezinaSanduka,NazivSadrzajaSanduka,TezinePredmetaSanduka));
    return (*Spremnici.rbegin()).get();
}

Spremnik *Skladiste::DodajVrecu(double TezinaVrece, std::string NazivSadrzajaVrece, double TezinaMaterijeVrece)
{
    Spremnici.push_back(std::make_shared<Vreca>(TezinaVrece,NazivSadrzajaVrece,TezinaMaterijeVrece));
    return (*Spremnici.rbegin()).get();
}

Spremnik *Skladiste::DodajBure(double TezinaBureta, std::string NazivSadrzajaBureta, double GustinaTecnostiBureta, double ZapreminaTecnostiBureta)
{
    Spremnici.push_back(std::make_shared<Bure>(TezinaBureta,NazivSadrzajaBureta,GustinaTecnostiBureta,ZapreminaTecnostiBureta));
    return (*Spremnici.rbegin()).get();
}

Spremnik *Skladiste::DodajSpremnik(Spremnik *spremnik, bool trueorfalse)
{
    if(trueorfalse==true)
    {
        Spremnici.push_back(std::shared_ptr<Spremnik>(spremnik));
        return (*Spremnici.rbegin()).get();
    }
    auto p=std::shared_ptr<Spremnik>(spremnik->DajKopiju());
    //Spremnici.push_back(spremnik->DajKopiju());
    Spremnici.push_back(p);
    return (*Spremnici.rbegin()).get();
}

void Skladiste::BrisiSpremnik(Spremnik *Adresa)
{
    for(auto it=Spremnici.begin();it!=Spremnici.end();it++)
    {
        if(it->get()==Adresa)
        {
            Spremnici.erase(it);
            it--;
        }
    }
}

Spremnik &Skladiste::DajNajtezi()
{
    if(Spremnici.size()==0)
    {
        throw std::range_error("Skladiste je prazno");
    }
    return *(*(std::max_element(Spremnici.begin(),Spremnici.end(),[](std::shared_ptr<Spremnik> Spremnika, std::shared_ptr<Spremnik> Spremnikb)
    {
        return Spremnika->DajTezinu()<Spremnikb->DajTezinu();
    })));
}

Spremnik &Skladiste::DajNajlaksi()
{
    if(Spremnici.size()==0)
    {
        throw std::range_error("Skladiste je prazno");
    }
    return *(*(std::min_element(Spremnici.begin(),Spremnici.end(),[](std::shared_ptr<Spremnik> Spremnika, std::shared_ptr<Spremnik> Spremnikb)
    {
        return Spremnika->DajTezinu()<Spremnikb->DajTezinu();
    })));
}

int Skladiste::BrojPreteskih(int NovaTezina) const
{
    return std::count_if(Spremnici.begin(), Spremnici.end(), [NovaTezina] (std::shared_ptr<Spremnik> Spremnika)
    {
        return Spremnika->DajUkupnuTezinu()>NovaTezina;
    });
}

void Skladiste::IzlistajSkladiste() const
{
    Skladiste Pomocni(*this);
    std::sort(Pomocni.Spremnici.begin(),Pomocni.Spremnici.end(), [] (std::shared_ptr<Spremnik> Spremnika, std::shared_ptr<Spremnik> Spremnikb)
    {
        return Spremnika->DajUkupnuTezinu()>Spremnikb->DajUkupnuTezinu();
    });
    auto p=Pomocni.Spremnici.begin();
    auto q=Pomocni.Spremnici.end();
    while(p!=q)
    {
        (*p)->Ispisi();
        p++;
    }
}

void Skladiste::UcitajIzDatoteke(std::string String)
{
    std::ifstream UlazniTok(String);
    if(!UlazniTok)
    {
        throw std::logic_error("Trazena datoteka ne postoji");
    }
    for(int i=0;i<Spremnici.size();i++)
    {
        Spremnici.at(i)=nullptr;
    }
    Spremnici.resize(0);
    char Oznaka;
    std::string Ime;
    while((Oznaka=UlazniTok.get())!=EOF)
    {
        if(Oznaka!='V' && Oznaka!='B' && Oznaka!='S')
        {
            UlazniTok.setstate(std::ios::failbit);
            break;
        }
        char Razmak=UlazniTok.get();
        if(Razmak!=' ')
        {
            UlazniTok.setstate(std::ios::failbit);
            break;
        }
        std::getline(UlazniTok,Ime);
        double Tezinaa;
        UlazniTok>>Tezinaa;
        if(!UlazniTok)
        {
            break;
        }
        if(Oznaka=='S')
        {
            int Duzina;
            UlazniTok>>Duzina;
            if(!UlazniTok)
            {
                break;
            }
            std::vector<double> Duzine(Duzina);
            for(int i=0;i<Duzina;i++)
            {
                UlazniTok>>Duzine.at(i);
            }
            DodajSanduk(Tezinaa,Ime,Duzine);
        }
        if(Oznaka=='V')
        {
            double TezinaMaterije;
            UlazniTok>>TezinaMaterije;
            DodajVrecu(Tezinaa,Ime,TezinaMaterije);
        }
        if(Oznaka=='B')
        {
            double Gustina,Zapremina;
            UlazniTok>>Gustina>>Zapremina;
            DodajBure(Tezinaa,Ime,Gustina,Zapremina);
        }
        if(!UlazniTok) 
        {
            break;
        }
        if(UlazniTok.get()==EOF)
        {
            return;
        }
    }
    if(UlazniTok.bad()==true)
    {
        throw std::logic_error("Problemi pri citanju datoteke");
    }
    else
    {
        throw std::logic_error("Datoteka sadrzi besmislene podatke");
    }
}

int main ()
{
    try
    {
        Skladiste ETF;
        ETF.UcitajIzDatoteke("ROBA.TXT");
        ETF.IzlistajSkladiste();
    }
    catch(std::logic_error ERROR)
    {
        std::cout<<ERROR.what();
    }
	return 0;
}
