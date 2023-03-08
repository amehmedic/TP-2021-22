//TP 2021/2022: Zadaća 3, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <functional>
#include <utility>
#include <string>
#include <iomanip>

double funkcijazamain (double x)
{
    return x * x + std::sin(x);
}

std::vector<double> Pomocna(const std::vector<std::pair<double, double>>& cvorovi, int x)
{
    int help=cvorovi.size();
    std::vector<double> Vektor(cvorovi.size());
    for (int i=0;i<help;++i)
    {
        int max=i;
        if(i>=help-x)
        {
            max=help-x-1;
        }
        int min=std::max(i-x, 0);
        double pomoc = 1;
        if (min%2==1)
        {
            pomoc=-1;
        }
        double suma = 0.0;
        for (int j=min;j<=max;++j)
        {
            int maxx=std::min(j+x, help-1);
            double pomocni = 1.0;
            for(int k=j;k<=maxx;++k)
            {
                if(k==i)
                {
                    continue;
                }
                pomocni *= (cvorovi.at(i).first - cvorovi.at(k).first);
            }
            pomocni = pomoc / pomocni;
            pomoc = -pomoc;
            suma += pomocni;
        }
        Vektor.at(i)=suma;
    }
    return Vektor;
}

double PomocnaFunkcija(double x, const std::vector<std::pair<double, double>>&  cvorovi, const std::vector<double>& Vektor)
{
    double num = 0.0;
    double denom = 0.0;
    for(int i=0;i<cvorovi.size();++i)
    {
        double epsilon = 0.000001;
        if (fabs(x-cvorovi.at(i).first)<epsilon)
        {
            return cvorovi.at(i).second;
        } 
        auto pomoc = Vektor.at(i) / (x-cvorovi.at(i).first);
        num += pomoc * cvorovi.at(i).second;
        denom += pomoc;
    }
    return num / denom;
}

auto BaricentricnaInterpolacija(std::vector<std::pair<double, double>> cvorovi, int RI)
{
    if (RI<0)
    {
        throw std::domain_error("Nedozvoljen red");
    }
    if (RI>=cvorovi.size())
    {
        throw std::domain_error("Nedozvoljen red");
    }

    for(int i=0;i<cvorovi.size();i++)
    {
        for(int j=0;j<cvorovi.size();j++)
        {
            if(j==i)
            {
                continue;
            }
            if(fabs(cvorovi.at(i).first-cvorovi.at(j).first)<0.00001)
            {
                throw std::domain_error("Neispravni cvorovi");
            }
        }
    }
    for (int i=0;i<RI;i++)
    {
        for (int j=i+1;j<RI;j++)
        {
            double epsilon = 0.000001;
            if(fabs(cvorovi.at(j).first-cvorovi.at(i).first)<epsilon)
            {
                throw std::domain_error("Nekorektni parametri");
            }
        }
    }
    auto Vektor=Pomocna(cvorovi, RI);
    return [cvorovi, Vektor](double RI) { return PomocnaFunkcija(RI, cvorovi, Vektor); };
}

auto BaricentricnaInterpolacija(std::function<double(double)> funkcija, double xmin, double xmax, double pomak, int RI)
{
    if(pomak <=0)
    {
        throw std::domain_error("Nekorektni parametri");
    }
    if(xmin>xmax)
    {
        throw std::domain_error("Nekorektni parametri");
    }
    std::vector<std::pair<double, double>> cvorovi;
    std::pair<double, double> Par;
    while(xmin<=xmax)
    {
        Par.first=xmin;
        Par.second=funkcija(xmin);
        xmin=xmin+pomak;
        cvorovi.push_back(Par);
    }
        return BaricentricnaInterpolacija(cvorovi,RI);
}

bool IsAnumber(std::string str)
{
    for(int i = 0; i < str.size(); i++)
    {
        if(isdigit(str.at(i))==true || str.at(i)=='.' || str.at(i)=='-')
        {
            continue;
        }
        return false;
    }
    return true;
}

int main ()
{
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int Opcija;
    std::cin >> Opcija;
    if(Opcija==1)
    {
        try
        {
            std::cout << "Unesite broj cvorova: ";
            int BrojCvorova;
            std::cin >> BrojCvorova;
            std::vector<std::pair<double,double>> Vektor;
            std::cout << "Unesite cvorove kao parove x y: ";
            for(int i=0;i<BrojCvorova;i++)
            {
                std::pair<double,double> Par;
                std::cin >> Par.first >> Par.second;
                Vektor.push_back(Par);
            }
            std::cout << "Unesite red interpolacije: ";
            int RedInterpolacije;
            std::cin >> RedInterpolacije;
            while(1!=0)
            {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::string Unos;
                std::cin >> Unos;
                if(IsAnumber(Unos)==false)
                {
                    break;
                }
                double help = stod(Unos);
                std::cout << "f(" << Unos << ") = ";
                std::cout << BaricentricnaInterpolacija(Vektor, RedInterpolacije)(help) << "\n";
            }
        }
        catch (std::domain_error error)
        {
        std::cout << error.what();
        }
    }
    if(Opcija==2)
    {
        try
        {
            std::cout << "Unesite krajeve intervala i korak: ";
            double xmin, xmax, pomak;
            std::cin >> xmin >> xmax >> pomak;
            std::cout << "Unesite red interpolacije: ";
            int RedInterpolacije;
            std::cin >> RedInterpolacije;
            if(xmin>xmax)
            {
                throw std::domain_error("Nekorektni parametri");
            }
            if(fabs(xmax/xmin)<RedInterpolacije)
            {
                throw std::domain_error("Nekorektni parametri");
            }
            while(1!=0)
            {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::string Unos;
                std::cin >> Unos;
                if(IsAnumber(Unos)==false)
                {
                    break;
                }
                double help = stod(Unos);
                std::cout << "f(" << Unos << ") = ";
                std::cout << funkcijazamain(help);
                std::cout << " fapprox(" << Unos << ") = ";
                std::cout << BaricentricnaInterpolacija(funkcijazamain,xmin,xmax,pomak,RedInterpolacije)(help) << "\n";
            }
        }
        catch (std::domain_error error)
        {
        std::cout << error.what();
        }
    }
	return 0;
}
