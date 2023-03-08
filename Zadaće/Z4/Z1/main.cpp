//TP 2021/2022: Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

double pi = 3.14159265358979323846;
double epsilon=(pow(10, -10));

bool Pomoc=true;
int Brojac=0;

class Kugla
{
    double KordinataX;
    double KordinataY;
    double KordinataZ;
    double Poluprecnik;
public:
    explicit Kugla(double r = 0);
    Kugla(double x, double y, double z, double r = 0);
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0);
    double DajX() const;
    double DajY() const;
    double DajZ() const;
    std::tuple<double, double, double> DajCentar() const;
    double DajPoluprecnik() const;
    double DajPovrsinu() const;
    double DajZapreminu() const;
    Kugla &PostaviX(double x);
    Kugla &PostaviY(double y);
    Kugla &PostaviZ(double z);
    Kugla &PostaviCentar(double x, double y, double z);
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar);
    Kugla &PostaviPoluprecnik(double r);
    void Ispisi() const;
    void Transliraj(double delta_x, double delta_y, double delta_z);
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const;
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};

Kugla::Kugla(double r)
{
    if(r<0)
    {
        throw std::domain_error("Ilegalan poluprecnik");
    }
    KordinataX=0;
    KordinataY=0;
    KordinataZ=0;
    Poluprecnik=r;
}

Kugla::Kugla(double x, double y, double z, double r)
{
    if(r<0)
    {
        throw std::domain_error("Ilegalan poluprecnik");
    }
    KordinataX=x;
    KordinataY=y;
    KordinataZ=z;
    Poluprecnik=r;
}

Kugla::Kugla(const std::tuple<double, double, double> &centar, double r)
{
    if(r<0)
    {
        throw std::domain_error("Ilegalan poluprecnik");
    } 
    KordinataX=std::get<0>(centar);
    KordinataY=std::get<1>(centar);
    KordinataZ=std::get<2>(centar);
    Poluprecnik=r;
}

double Kugla::DajX() const
{
    return KordinataX;
}

double Kugla::DajY() const
{
    return KordinataY;
}
double Kugla::DajZ() const
{
    return KordinataZ;
}

std::tuple<double, double, double> Kugla::DajCentar() const
{
    return std::make_tuple(KordinataX,KordinataY,KordinataZ);
}

double Kugla::DajPoluprecnik() const
{
    return Poluprecnik;
}
    double Kugla::DajPovrsinu() const
{
    return 4*pi*Poluprecnik*Poluprecnik;
}

double Kugla::DajZapreminu() const
{
    return (4.0*pi*Poluprecnik*Poluprecnik*Poluprecnik)/3.0;
}

Kugla &Kugla::PostaviX(double x)
{
    KordinataX=x;
    return *this;
}

Kugla &Kugla::PostaviY(double y)
{
    KordinataY=y;
    return *this;
}

Kugla &Kugla::PostaviZ(double z)
{
    KordinataZ=z;
    return *this;
}

Kugla &Kugla::PostaviCentar(double x, double y, double z)
{
    KordinataX=x;
    KordinataY=y;
    KordinataZ=z;
    return *this;
}

Kugla &Kugla::PostaviCentar(const std::tuple<double, double, double> &centar)
{
    KordinataX=std::get<0>(centar);
    KordinataY=std::get<1>(centar);
    KordinataZ=std::get<2>(centar);
    return *this;
}

Kugla &Kugla::PostaviPoluprecnik(double r)
{
    if(r<0)
    {
        throw std::domain_error("Ilegalan poluprecnik");
    }
    Poluprecnik=r;
    return *this;
}

void Kugla::Ispisi() const
{
    std::cout << "{(" << KordinataX << "," << KordinataY << "," << KordinataZ << ")," << Poluprecnik << "}\n";
}

void Kugla::Transliraj(double delta_x, double delta_y, double delta_z)
{
    KordinataX=KordinataX+delta_x;
    KordinataY=KordinataY+delta_y;
    KordinataZ=KordinataZ+delta_z;
}

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
    if(fabs(k1.KordinataX-k2.KordinataX)>epsilon*(fabs(k1.KordinataX)+fabs(k2.KordinataX)) || fabs(k1.KordinataY-k2.KordinataY)>epsilon*(fabs(k1.KordinataY)+fabs(k2.KordinataY)) || fabs(k1.KordinataZ-k2.KordinataZ)>epsilon*(fabs(k1.KordinataZ)+fabs(k2.KordinataZ)) || fabs(k1.Poluprecnik-k2.Poluprecnik)>epsilon*(fabs(k1.Poluprecnik)+fabs(k2.Poluprecnik)))
    {
        return false;
    }
    return true;
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    if(fabs(k1.Poluprecnik-k2.Poluprecnik)>epsilon*(fabs(k1.Poluprecnik)+fabs(k2.Poluprecnik)))
    {
        return false;
    }
    return true;
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    if(fabs(k1.KordinataX-k2.KordinataX)>epsilon*(fabs(k1.KordinataX)+fabs(k2.KordinataX)) || fabs(k1.KordinataY-k2.KordinataY)>epsilon*(fabs(k1.KordinataY)+fabs(k2.KordinataY)) || fabs(k1.KordinataZ-k2.KordinataZ)>epsilon*(fabs(k1.KordinataZ)+fabs(k2.KordinataZ)))
    {
        return false;
    }
    return true;
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    double Zbirpoluprecnika=k1.Poluprecnik+k2.Poluprecnik;
    if(fabs(Zbirpoluprecnika-RastojanjeCentara(k1,k2))<epsilon*(fabs(Zbirpoluprecnika)+fabs(RastojanjeCentara(k1,k2))))
    {
        return true;
    }
    return false;
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    double Apsolutnarazlikapoluprecnika=fabs(k1.Poluprecnik-k2.Poluprecnik);
    if(fabs(Apsolutnarazlikapoluprecnika-RastojanjeCentara(k1,k2))<epsilon*(fabs(Apsolutnarazlikapoluprecnika)+fabs(RastojanjeCentara(k1,k2))))
    {
        return true;
    }
    return false;
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
    double Zbirpoluprecnika=k1.Poluprecnik+k2.Poluprecnik;
    if(RastojanjeCentara(k1,k2)<Zbirpoluprecnika)
    {
        return true;
    }
    return false;
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
    double Apsolutnarazlikapoluprecnika=fabs(k1.Poluprecnik-k2.Poluprecnik);
    double Zbirpoluprecnika=k1.Poluprecnik+k2.Poluprecnik;
    if(RastojanjeCentara(k1,k2)<Zbirpoluprecnika && RastojanjeCentara(k1,k2)>Apsolutnarazlikapoluprecnika)
    {
        return true;
    }
    return false;
}

bool Kugla::DaLiSadrzi(const Kugla &k) const
{
    if((*this).Poluprecnik<k.Poluprecnik)
    {
        return false;
    }
    double Apsolutnarazlikapoluprecnika=fabs(k.Poluprecnik-(*this).Poluprecnik);
    if(RastojanjeCentara(k,*this)<=Apsolutnarazlikapoluprecnika)
    {
        return true;
    }
    return false;
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    return sqrt((k1.KordinataX-k2.KordinataX)*(k1.KordinataX-k2.KordinataX)+(k1.KordinataY-k2.KordinataY)*(k1.KordinataY-k2.KordinataY)+(k1.KordinataZ-k2.KordinataZ)*(k1.KordinataZ-k2.KordinataZ));
}

int main ()
{
    std::cout << "Unesite broj kugla: ";
    int BrojKugli;
    std::cin >> BrojKugli;
    std::vector<std::shared_ptr<Kugla>> Vektor;
    Vektor.resize(BrojKugli);
    for(int i=0;i<BrojKugli;i++)
    {
        try
        {
            std::cout << "Unesite centar " << i+1 << ". kugle: ";
            double x;
            double y;
            double z;
            std::cin >> x >> y >> z;
            std::cout << "Unesite poluprecnik " << i+1 <<". kugle: ";
            double r;
            std::cin >> r;
            std::shared_ptr<Kugla> p(new Kugla(x,y,z,r));
            Vektor.at(i)=p;
        }
        catch (std::domain_error error)
        {
            std::cout << error.what() << "\n";
            i--;
        }
    }
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double delta_x;
    double delta_y;
    double delta_z;
    std::cin >> delta_x >> delta_y >> delta_z;
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: ";
    transform(Vektor.begin(),Vektor.end(),Vektor.begin(), [delta_x,delta_y,delta_z] (std::shared_ptr<Kugla> k) { k->Transliraj(delta_x,delta_y,delta_z); return k; });
    sort(Vektor.begin(),Vektor.end(), [] (std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {return k1->DajZapreminu()<k2->DajZapreminu();});
    for_each(Vektor.begin(),Vektor.end(), [] (std::shared_ptr<Kugla> k) {std::cout << "\n"; k->Ispisi();});
    std::cout << "\nKugla sa najvecom povrsinom je: ";
    (*(*max_element(Vektor.begin(),Vektor.end(), [] (std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {return k1->DajPovrsinu()<k2->DajPovrsinu();}))).Ispisi();
    for_each(Vektor.begin(),Vektor.end(), [Vektor] (std::shared_ptr<Kugla> k)
    {
        for_each(Vektor.begin()+Brojac,Vektor.end(), [k] (std::shared_ptr<Kugla> kug) 
        {
            if(DaLiSeSijeku(*k,*kug)==1)
            {
                std::cout << "\nPresjecaju se kugle: ";
                k->Ispisi();
                std::cout << "\n";
                kug->Ispisi();
                Pomoc=false;
            }
        });
        Brojac++;
    });
    if(Pomoc==true)
    {
        std::cout << "\nNe postoje kugle koje se presjecaju!"; 
    }
    return 0;
}
