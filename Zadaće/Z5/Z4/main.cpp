//TP 2021/2022: Zadaća 5, Zadatak 4
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
    //    return std::shared_ptr<Sanduk>(new Sanduk(*this));
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

class PolimorfniSpremnik
{
    Spremnik* Pomocni;
    //std::shared_ptr<Spremnik> Pomocni;
    void Test() const
    {
        if(!Pomocni)
        {
            throw std::logic_error("Nespecificiran spremnik");
        }
    }
public:
    PolimorfniSpremnik()
    {
        Pomocni=nullptr;
    }
    ~PolimorfniSpremnik()
    {
        if(Pomocni!=nullptr)
        {
            delete Pomocni;
        }
    }
    PolimorfniSpremnik(const Spremnik &spremnik)
    //Pomocni(std::shared_ptr<Spremnik>(spremnik.DajKopiju())) 
    {
        auto help=spremnik.DajKopiju();
        Pomocni=help;
        help=nullptr;
    }
    PolimorfniSpremnik(const PolimorfniSpremnik &spremnik)
    {
        if(!spremnik.Pomocni)
        {
            Pomocni=nullptr;
        }
        else
        {
            //Pomocni=std::shared_ptr<Spremnik>(spremnik.Pomocni->DajKopiju());
            Pomocni=spremnik.Pomocni->DajKopiju();
        }
    }
    PolimorfniSpremnik(PolimorfniSpremnik &&spremnik)
    {
        Pomocni=spremnik.Pomocni;
        spremnik.Pomocni=nullptr;
    }
    PolimorfniSpremnik &operator =(const PolimorfniSpremnik &spremnik)
    {
        //std::shared_ptr<Spremnik> Novi(nullptr);
        delete Pomocni;
        Spremnik* Novi(nullptr);
        if(spremnik.Pomocni)
        {
            //Novi=std::shared_ptr<Spremnik>(spremnik.Pomocni->DajKopiju());
            Novi=spremnik.Pomocni->DajKopiju();
        }
        Pomocni=Novi;
        return *this;
    }
    PolimorfniSpremnik &operator =(PolimorfniSpremnik &&spremnik)
    {
        std::swap(Pomocni,spremnik.Pomocni);
        return *this;
    }
    void Ispisi() const
    {
        Test();
        Pomocni->Ispisi();
    }
    double DajTezinu() const
    {
        Test();
        return Pomocni->DajTezinu();
    }
    double DajUkupnuTezinu() const
    {
        Test();
        return Pomocni->DajUkupnuTezinu();
    }
};


int main ()
{
	return 0;
}
