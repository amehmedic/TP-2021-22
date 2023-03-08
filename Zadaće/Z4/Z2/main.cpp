//TP 2021/2022: Zadaća 4, Zadatak 2
#include <clocale>
#include <iostream>
#include <cmath>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
#include <iomanip>

double pi = 3.14159265358979323846;
double epsilon=(pow(10, -10));

class NepreklapajucaKugla
{
    double KordinataX;
    double KordinataY;
    double KordinataZ;
    double Poluprecnik;
    NepreklapajucaKugla * Pokazivac;
    bool Preklapanje(double x1, double y1, double z1, double r1, double x2, double y2, double z2, double r2) const;
public:
    explicit NepreklapajucaKugla(double r = 0);
    NepreklapajucaKugla(double x, double y, double z, double r = 0);
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0);
    double DajX() const;
    double DajY() const;
    double DajZ() const;
    std::tuple<double, double, double> DajCentar() const;
    double DajPoluprecnik() const;
    double DajPovrsinu() const;
    double DajZapreminu() const;
    NepreklapajucaKugla &PostaviX(double x);
    NepreklapajucaKugla &PostaviY(double y);
    NepreklapajucaKugla &PostaviZ(double z);
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z);
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar);
    NepreklapajucaKugla &PostaviPoluprecnik(double r);
    void Ispisi() const;
    void Transliraj(double delta_x, double delta_y, double delta_z);
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
    NepreklapajucaKugla (const NepreklapajucaKugla &k) = delete; // Zabrana kopiranja
    NepreklapajucaKugla  &operator =(const NepreklapajucaKugla  &k) = delete;
    ~NepreklapajucaKugla();
};

NepreklapajucaKugla * GlobalniPokazivac=nullptr;

bool NepreklapajucaKugla::Preklapanje(double x1, double y1, double z1, double r1, double x2, double y2, double z2, double r2) const
{
    double Udaljenost=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
    double Zbirpoluprecnika=r1+r2;
    if(Udaljenost<=Zbirpoluprecnika+epsilon)
    {
        return true;
    }
    return false;

}
NepreklapajucaKugla::NepreklapajucaKugla(double r)
{
    if(r<0)
    {
        throw std::domain_error("Ilegalan poluprecnik");
    }
    auto p=GlobalniPokazivac;
    while(p!=nullptr)
    {
        if(Preklapanje(p->KordinataX,p->KordinataY,p->KordinataZ,p->Poluprecnik,0,0,0,r)==true)
        {
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        p=p->Pokazivac;
    }
    KordinataX=0;
    KordinataY=0;
    KordinataZ=0;
    Poluprecnik=r;
    Pokazivac=GlobalniPokazivac;
    GlobalniPokazivac=this;
}

NepreklapajucaKugla::NepreklapajucaKugla(double x, double y, double z, double r)
{
    if(r<0)
    {
        throw std::domain_error("Ilegalan poluprecnik");
    }
    auto p=GlobalniPokazivac;
    while(p!=nullptr)
    {
        if(Preklapanje(p->KordinataX,p->KordinataY,p->KordinataZ,p->Poluprecnik,x,y,z,r)==true)
        {
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        p=p->Pokazivac;
    }
    KordinataX=x;
    KordinataY=y;
    KordinataZ=z;
    Poluprecnik=r;
    Pokazivac=GlobalniPokazivac;
    GlobalniPokazivac=this;
}

NepreklapajucaKugla::NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r)
{
    if(r<0)
    {
        throw std::domain_error("Ilegalan poluprecnik");
    }
    auto p=GlobalniPokazivac;
    while(p!=nullptr)
    {
        if(Preklapanje(p->KordinataX,p->KordinataY,p->KordinataZ,p->Poluprecnik,std::get<0>(centar),std::get<1>(centar),std::get<2>(centar),r)==true)
        {
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        p=p->Pokazivac;
    }
    KordinataX=std::get<0>(centar);
    KordinataY=std::get<1>(centar);
    KordinataZ=std::get<2>(centar);
    Poluprecnik=r;
    Pokazivac=GlobalniPokazivac;
    GlobalniPokazivac=this;
}

double NepreklapajucaKugla::DajX() const
{
    return KordinataX;
}

double NepreklapajucaKugla::DajY() const
{
    return KordinataY;
}
double NepreklapajucaKugla::DajZ() const
{
    return KordinataZ;
}

std::tuple<double, double, double> NepreklapajucaKugla::DajCentar() const
{
    return std::make_tuple(KordinataX,KordinataY,KordinataZ);
}

double NepreklapajucaKugla::DajPoluprecnik() const
{
    return Poluprecnik;
}
    double NepreklapajucaKugla::DajPovrsinu() const
{
    return 4*pi*Poluprecnik*Poluprecnik;
}

double NepreklapajucaKugla::DajZapreminu() const
{
    return (4.0*pi*Poluprecnik*Poluprecnik*Poluprecnik)/3.0;
}

NepreklapajucaKugla &NepreklapajucaKugla::PostaviX(double x)
{
    auto p=GlobalniPokazivac->Pokazivac;
    while(p!=nullptr)
    {
        if(p==this)
        {   
            p=p->Pokazivac;
            continue;
        }
        if(Preklapanje(p->KordinataX,p->KordinataY,p->KordinataZ,p->Poluprecnik,x,KordinataY,KordinataZ,Poluprecnik)==true)
        {
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        p=p->Pokazivac;
    }
    KordinataX=x;
    return *this;
}

NepreklapajucaKugla &NepreklapajucaKugla::PostaviY(double y)
{
    auto p=GlobalniPokazivac->Pokazivac;
    while(p!=nullptr)
    {
        if(p==this)
        {   
            p=p->Pokazivac;
            continue;
        }
        if(Preklapanje(p->KordinataX,p->KordinataY,p->KordinataZ,p->Poluprecnik,KordinataX,y,KordinataZ,Poluprecnik)==true)
        {
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        p=p->Pokazivac;
    }
    KordinataY=y;
    return *this;
}

NepreklapajucaKugla &NepreklapajucaKugla::PostaviZ(double z)
{
    auto p=GlobalniPokazivac->Pokazivac;
    while(p!=nullptr)
    {
        if(p==this)
        {   
            p=p->Pokazivac;
            continue;
        }
        if(Preklapanje(p->KordinataX,p->KordinataY,p->KordinataZ,p->Poluprecnik,KordinataX,KordinataY,z,Poluprecnik)==true)
        {
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        p=p->Pokazivac;
    }
    KordinataZ=z;
    return *this;
}

NepreklapajucaKugla &NepreklapajucaKugla::PostaviCentar(double x, double y, double z)
{
    auto p=GlobalniPokazivac->Pokazivac;
    while(p!=nullptr)
    {
        if(p==this)
        {   
            p=p->Pokazivac;
            continue;
        }
        if(Preklapanje(p->KordinataX,p->KordinataY,p->KordinataZ,p->Poluprecnik,x,y,z,Poluprecnik)==true)
        {
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        p=p->Pokazivac;
    }
    KordinataX=x;
    KordinataY=y;
    KordinataZ=z;
    return *this;
}

NepreklapajucaKugla &NepreklapajucaKugla::PostaviCentar(const std::tuple<double, double, double> &centar)
{
    auto p=GlobalniPokazivac->Pokazivac;
    while(p!=nullptr)
    {
        if(p==this)
        {   
            p=p->Pokazivac;
            continue;
        }
        if(Preklapanje(p->KordinataX,p->KordinataY,p->KordinataZ,p->Poluprecnik,std::get<0>(centar),std::get<1>(centar),std::get<2>(centar),Poluprecnik)==true)
        {
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        p=p->Pokazivac;
    }
    KordinataX=std::get<0>(centar);
    KordinataY=std::get<1>(centar);
    KordinataZ=std::get<2>(centar);
    return *this;
}

NepreklapajucaKugla &NepreklapajucaKugla::PostaviPoluprecnik(double r)
{
    if(r<0)
    {
        throw std::domain_error("Ilegalan poluprecnik");
    }
    auto p=GlobalniPokazivac->Pokazivac;
    while(p!=nullptr)
    {
        if(p==this)
        {   
            p=p->Pokazivac;
            continue;
        }
        if(Preklapanje(p->KordinataX,p->KordinataY,p->KordinataZ,p->Poluprecnik,KordinataX,KordinataY,KordinataZ,r)==true)
        {
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        p=p->Pokazivac;
    }
    Poluprecnik=r;
    return *this;
}

void NepreklapajucaKugla::Ispisi() const
{
    std::cout << "{(" << KordinataX << "," << KordinataY << "," << KordinataZ << ")," << Poluprecnik << "}\n";
}

void NepreklapajucaKugla::Transliraj(double delta_x, double delta_y, double delta_z)
{
    auto p=GlobalniPokazivac->Pokazivac;
    while(p!=nullptr)
    {
        if(p==this)
        {   
            p=p->Pokazivac;
            continue;
        }
        if(Preklapanje(p->KordinataX,p->KordinataY,p->KordinataZ,p->Poluprecnik,KordinataX+delta_x,KordinataY+delta_y,KordinataZ+delta_z,Poluprecnik)==true)
        {
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        p=p->Pokazivac;
    }
    KordinataX=KordinataX+delta_x;
    KordinataY=KordinataY+delta_y;
    KordinataZ=KordinataZ+delta_z;
}

double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
{
    return sqrt((k1.KordinataX-k2.KordinataX)*(k1.KordinataX-k2.KordinataX)+(k1.KordinataY-k2.KordinataY)*(k1.KordinataY-k2.KordinataY)+(k1.KordinataZ-k2.KordinataZ)*(k1.KordinataZ-k2.KordinataZ));
}

NepreklapajucaKugla::~NepreklapajucaKugla()
{
    if(GlobalniPokazivac==this && this->Pokazivac==nullptr)
    {
        GlobalniPokazivac=nullptr;
    }
    else if(GlobalniPokazivac==this && this->Pokazivac!=nullptr)
    {
        auto p1=this->Pokazivac;
        GlobalniPokazivac=p1; 
    }
    else
    {
        auto p1=GlobalniPokazivac;
        auto p2=p1->Pokazivac;
        while(p2!=this)
        {
            p1=p2;
            p2=p2->Pokazivac;
        }
        p2=p2->Pokazivac;
        p1->Pokazivac=p2;
    }
}

int main ()
{  
    bool pomagaj=true;
    std::cout << "Unesite broj kugli: ";
    int BrojKugli;
    while(pomagaj==true)
    {
        std::cin >> BrojKugli;
        if(BrojKugli<=0)
        {
            std::cout << "Neispravan broj kugli, unesite ponovo!\n";
            continue;
        }
        pomagaj=false;
    }
    std::vector<std::shared_ptr<NepreklapajucaKugla>> Vektor;
    Vektor.resize(BrojKugli);
    for(int i=0;i<BrojKugli;i++)
    {
        double x;
        double y;
        double z;
        try
        {
            pomagaj=true;
            std::cout << "Unesite centar za " << i+1 << ". kuglu: ";
            while(pomagaj==true)
            {
                std::cin >> x >> y >> z;
                if (!std::cin)
                {
                    std::cin.clear();
                    std::cin.ignore(9999999, '\n');
                    std::cout << "Neispravan centar, unesite ponovo:\n";
                    continue;
                }
                pomagaj=false;
            }
            std::cout << "Unesite poluprecnik: ";
            pomagaj=true;
            while(pomagaj==true)
            {
                try
                {
                    double r;
                    std::cin >> r;
                    if(!std::cin)
                    {
                        std::cin.clear();
                        std::cin.ignore(9999999, '\n');
                        std::cout << "Neispravan poluprecnik, unesite ponovo: \n";
                        continue;
                    }
                    std::shared_ptr<NepreklapajucaKugla> p(new NepreklapajucaKugla(x,y,z,r));
                    Vektor.at(i)=p;
                }
                catch (std::domain_error error1)
                {
                    std::cout << "Neispravan poluprecnik, unesite ponovo: \n";
                    continue;
                }
                pomagaj=false;
            }
        }
        catch (std::logic_error error2)
        {
            std::cout << error2.what() << "\n";
            i--;
        }
    }
    sort(Vektor.begin(),Vektor.end(), [] (std::shared_ptr<NepreklapajucaKugla> k1, std::shared_ptr<NepreklapajucaKugla> k2) {return k1->DajZapreminu()<k2->DajZapreminu();});
    std::cout << "\nKugle nakon obavljenog sortiranja: ";
    for_each(Vektor.begin(),Vektor.end(), [] (std::shared_ptr<NepreklapajucaKugla> k) {std::cout << "\n"; k->Ispisi();});
    return 0;
}
