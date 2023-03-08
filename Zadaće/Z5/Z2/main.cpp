//TP 2021/2022: Zadaća 5, Zadatak 2
#include <iostream>
#include <cmath>
#include <vector>
#include <limits>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <iterator>

class Berza
{
    std::vector<int> Vektor;
    int MaksimalnaCijena;
    int MinimalnaCijena;
public:
    Berza(int a, int b);
    explicit Berza(int Max);
    void RegistrirajCijenu(int Cijena);
    int DajBrojRegistriranihCijena() const;
    void BrisiSve();
    int DajMinimalnuCijenu() const;
    int DajMaksimalnuCijenu() const;
    friend bool operator !(const Berza &a);
    int DajBrojCijenaVecihOd(int n) const;
    void Ispisi() const;
    int operator [](int indeks) const;
    friend Berza &operator ++(Berza &a);
    friend Berza &operator --(Berza &a);
    friend Berza operator ++(Berza &a, int);
    friend Berza operator --(Berza &a, int);
    friend Berza operator -(const Berza &a);
    friend Berza operator +(const Berza &a, const int b);
    friend Berza operator -(const Berza &a, const int b);
    friend Berza operator +(const int b, const Berza &a);
    friend Berza operator -(const int b, const Berza &a);
    friend Berza operator -(const Berza &a, const Berza &b);
    friend Berza &operator +=(Berza &a, const int b);
    friend Berza &operator +=(const int b, Berza &a);
    friend Berza &operator -=(Berza &a, const int b);
    //friend Berza &operator -=(const int b, const Berza &a);
    friend Berza &operator -=(Berza &a, const Berza &b);
    friend bool operator ==(const Berza &a, const Berza &b);
    friend bool operator !=(const Berza &a, const Berza &b);
};

Berza::Berza(int a, int b)
{
    if(a<0 || b<0)
    {
        throw std::range_error("Ilegalne granicne cijene");
    }
    std::vector<int> Vektor;
    if(a>=b)
    {
        MaksimalnaCijena=a;
        MinimalnaCijena=b;
    }
    if(a<b)
    {
        MaksimalnaCijena=b;
        MinimalnaCijena=a;
    }
}
Berza::Berza(int Max)
{
    if(Max<0)
    {
        throw std::range_error("Ilegalne granicne cijene");
    }
    std::vector<int> Vektor;
    MaksimalnaCijena=Max;
    MinimalnaCijena=0;   
}

void Berza::RegistrirajCijenu(int Cijena)
{
    if(Cijena<MinimalnaCijena || Cijena>MaksimalnaCijena)
    {
        throw std::range_error("Ilegalna cijena");
    }
    Vektor.push_back(Cijena);
}

int Berza::DajBrojRegistriranihCijena() const
{
    return Vektor.size();
}

void Berza::BrisiSve()
{
    Vektor.clear();
}

int Berza::DajMinimalnuCijenu() const
{
    if(Vektor.size()==0)
    {
        throw std::range_error("Nema registriranih cijena");
    }
    return *(std::min_element(Vektor.begin(),Vektor.end()));
}

int Berza::DajMaksimalnuCijenu() const
{
    if(Vektor.size()==0)
    {
        throw std::range_error("Nema registriranih cijena");
    }
    return *(std::max_element(Vektor.begin(),Vektor.end()));
}

bool operator !(const Berza &a)
{
    if(a.Vektor.size()==0)
    {
        return true;
    }
    return false;
}

int Berza::DajBrojCijenaVecihOd(int n) const
{
    if(Vektor.size()==0)
    {
        throw std::range_error("Nema registriranih cijena");
    }
    return std::count_if(Vektor.begin(), Vektor.end(), std::bind(std::greater<int>(), std::placeholders::_1, n));
}

void Berza::Ispisi() const
{
    std::vector<double> PomocniVektor(Vektor.begin(),Vektor.end());
    sort(PomocniVektor.begin(), PomocniVektor.end(), std::bind(std::greater<int>(), std::placeholders::_1, std::placeholders::_2));
    std::transform(PomocniVektor.begin(), PomocniVektor.end(),PomocniVektor.begin(),std::bind(std::divides<double>(), std::placeholders::_1, 100));
    std::cout.precision(2);
    std::cout.setf(std::ios::fixed);
    std::ostream_iterator<double> ispis (std::cout,"\n");
    std::copy(PomocniVektor.begin(),PomocniVektor.end(),ispis);
}

int Berza::operator [](int indeks) const
{
    if(indeks>Vektor.size() || indeks<1)
    {
        throw std::range_error("Neispravan indeks");
    }
    return Vektor[indeks - 1];
}

Berza &operator ++(Berza &a)
{
    Berza failsafe=a;  
    std::transform(a.Vektor.begin(), a.Vektor.end(), a.Vektor.begin(), std::bind(std::plus<int>(), std::placeholders::_1,100));
    if(std::none_of(a.Vektor.begin(), a.Vektor.end(), std::bind(std::greater<int>(), std::placeholders::_1, a.MaksimalnaCijena))==false)
    {
        a=failsafe;
        throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    }
    if(std::none_of(a.Vektor.begin(), a.Vektor.end(), std::bind(std::less<int>(), std::placeholders::_1, a.MinimalnaCijena))==false)
    {
        a=failsafe;
        throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    }
    return a;
}

Berza &operator --(Berza &a)
{
    Berza failsafe=a;  
    std::transform(a.Vektor.begin(), a.Vektor.end(), a.Vektor.begin(), std::bind(std::minus<int>(), std::placeholders::_1,100));
    if(std::none_of(a.Vektor.begin(), a.Vektor.end(), std::bind(std::greater<int>(), std::placeholders::_1, a.MaksimalnaCijena))==false)
    {
        a=failsafe;
        throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    }
    if(std::none_of(a.Vektor.begin(), a.Vektor.end(), std::bind(std::less<int>(), std::placeholders::_1, a.MinimalnaCijena))==false)
    {
        a=failsafe;
        throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    }
    return a;
}

Berza operator ++(Berza &a, int)
{
    Berza pomocni=a;
    std::transform(a.Vektor.begin(), a.Vektor.end(), a.Vektor.begin(), std::bind(std::plus<int>(), std::placeholders::_1,100));
    if(std::none_of(a.Vektor.begin(), a.Vektor.end(), std::bind(std::greater<int>(), std::placeholders::_1, a.MaksimalnaCijena))==false)
    {
        a=pomocni;
        throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    }
    if(std::none_of(a.Vektor.begin(), a.Vektor.end(), std::bind(std::less<int>(), std::placeholders::_1, a.MinimalnaCijena))==false)
    {
        a=pomocni;
        throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    }
    return pomocni;
}

Berza operator --(Berza &a, int)
{
    Berza pomocni=a;
    std::transform(a.Vektor.begin(), a.Vektor.end(), a.Vektor.begin(), std::bind(std::minus<int>(), std::placeholders::_1,100));
    if(std::none_of(a.Vektor.begin(), a.Vektor.end(), std::bind(std::greater<int>(), std::placeholders::_1, a.MaksimalnaCijena))==false)
    {
        a=pomocni;
        throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    }
    if(std::none_of(a.Vektor.begin(), a.Vektor.end(), std::bind(std::less<int>(), std::placeholders::_1, a.MinimalnaCijena))==false)
    {
        a=pomocni;
        throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    }
    return pomocni;
}

Berza operator -(const Berza &a)
{
    Berza Pomocni=a;
    auto Zbir=Pomocni.MaksimalnaCijena+Pomocni.MinimalnaCijena;
    std::transform(Pomocni.Vektor.begin(), Pomocni.Vektor.end(), Pomocni.Vektor.begin(), std::bind(std::minus<int>(),Zbir, std::placeholders::_1));
    return Pomocni;
}

Berza operator +(const Berza &a, const int b)
{
    Berza Pomocni=a;
    std::transform(Pomocni.Vektor.begin(), Pomocni.Vektor.end(), Pomocni.Vektor.begin(), std::bind(std::plus<int>(), std::placeholders::_1, b));
    if(std::none_of(Pomocni.Vektor.begin(), Pomocni.Vektor.end(), std::bind(std::greater<int>(), std::placeholders::_1, a.MaksimalnaCijena))==false)
    {
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    }
    if(std::none_of(Pomocni.Vektor.begin(), Pomocni.Vektor.end(), std::bind(std::less<int>(), std::placeholders::_1, a.MinimalnaCijena))==false)
    {
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    }
    return Pomocni;
}

Berza operator -(const Berza &a, const int b)
{
    Berza Pomocni=a;
    std::transform(Pomocni.Vektor.begin(), Pomocni.Vektor.end(), Pomocni.Vektor.begin(), std::bind(std::minus<int>(), std::placeholders::_1, b));
    if(std::none_of(Pomocni.Vektor.begin(), Pomocni.Vektor.end(), std::bind(std::greater<int>(), std::placeholders::_1, a.MaksimalnaCijena))==false)
    {
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    }
    if(std::none_of(Pomocni.Vektor.begin(), Pomocni.Vektor.end(), std::bind(std::less<int>(), std::placeholders::_1, a.MinimalnaCijena))==false)
    {
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    }
    return Pomocni;
}

Berza operator +(const int b, const Berza &a)
{
    Berza Pomocni=a;
    std::transform(Pomocni.Vektor.begin(), Pomocni.Vektor.end(), Pomocni.Vektor.begin(), std::bind(std::plus<int>(), std::placeholders::_1, b));
    if(std::none_of(Pomocni.Vektor.begin(), Pomocni.Vektor.end(), std::bind(std::greater<int>(), std::placeholders::_1, a.MaksimalnaCijena))==false)
    {
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    }
    if(std::none_of(Pomocni.Vektor.begin(), Pomocni.Vektor.end(), std::bind(std::less<int>(), std::placeholders::_1, a.MinimalnaCijena))==false)
    {
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    }
    return Pomocni;
}

Berza operator -(const int b, const Berza &a)
{
    Berza Pomocni=a;
    std::transform(Pomocni.Vektor.begin(), Pomocni.Vektor.end(), Pomocni.Vektor.begin(), std::bind(std::minus<int>(), b, std::placeholders::_1));
    if(std::none_of(Pomocni.Vektor.begin(), Pomocni.Vektor.end(), std::bind(std::greater<int>(), std::placeholders::_1, a.MaksimalnaCijena))==false)
    {
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    }
    if(std::none_of(Pomocni.Vektor.begin(), Pomocni.Vektor.end(), std::bind(std::less<int>(), std::placeholders::_1, a.MinimalnaCijena))==false)
    {
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    }
    return Pomocni;
}

Berza operator -(const Berza &a, const Berza &b)
{
    if(a.Vektor.size()!=b.Vektor.size() || a.MaksimalnaCijena!=b.MaksimalnaCijena || a.MinimalnaCijena!=b.MinimalnaCijena)
    {
        throw std::domain_error("Nesaglasni operandi");
    }
    Berza Pomocni(a.MaksimalnaCijena,a.MinimalnaCijena);
    Pomocni.Vektor.resize(a.Vektor.size());
    std::transform(a.Vektor.begin(),a.Vektor.end(),b.Vektor.begin(),Pomocni.Vektor.begin(),std::minus<int>());
    if(std::none_of(Pomocni.Vektor.begin(), Pomocni.Vektor.end(), std::bind(std::greater<int>(), std::placeholders::_1, a.MaksimalnaCijena))==false)
    {
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    }
    if(std::none_of(Pomocni.Vektor.begin(), Pomocni.Vektor.end(), std::bind(std::less<int>(), std::placeholders::_1, a.MinimalnaCijena))==false)
    {
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    }
    return Pomocni;
}

Berza &operator +=(Berza &a, const int b)
{
    auto failsafe=a;
    std::transform(a.Vektor.begin(), a.Vektor.end(), a.Vektor.begin(), std::bind(std::plus<int>(), std::placeholders::_1, b));
    if(std::none_of(a.Vektor.begin(), a.Vektor.end(), std::bind(std::greater<int>(), std::placeholders::_1, a.MaksimalnaCijena))==false)
    {
        a=failsafe;
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    }
    if(std::none_of(a.Vektor.begin(), a.Vektor.end(), std::bind(std::less<int>(), std::placeholders::_1, a.MinimalnaCijena))==false)
    {
        a=failsafe;
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    }
    return a;
}

Berza &operator +=(const int b, Berza &a)
{
    auto failsafe=a;
    std::transform(a.Vektor.begin(), a.Vektor.end(), a.Vektor.begin(), std::bind(std::plus<int>(), std::placeholders::_1, b));
    if(std::none_of(a.Vektor.begin(), a.Vektor.end(), std::bind(std::greater<int>(), std::placeholders::_1, a.MaksimalnaCijena))==false)
    {
        a=failsafe;
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    }
    if(std::none_of(a.Vektor.begin(), a.Vektor.end(), std::bind(std::less<int>(), std::placeholders::_1, a.MinimalnaCijena))==false)
    {
        a=failsafe;
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    }
    return a;
}

Berza &operator -=(Berza &a, const int b)
{
    auto failsafe=a;
    std::transform(a.Vektor.begin(), a.Vektor.end(), a.Vektor.begin(), std::bind(std::minus<int>(), std::placeholders::_1, b));
    if(std::none_of(a.Vektor.begin(), a.Vektor.end(), std::bind(std::greater<int>(), std::placeholders::_1, a.MaksimalnaCijena))==false)
    {
        a=failsafe;
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    }
    if(std::none_of(a.Vektor.begin(), a.Vektor.end(), std::bind(std::less<int>(), std::placeholders::_1, a.MinimalnaCijena))==false)
    {
        a=failsafe;
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    }
    return a;
}

/* Mislim da ovo nema smisla
Berza &operator -=(const int b, const Berza &a)
{
    // Mislim da ovdje nema smisla;
}
*/

Berza &operator -=(Berza &a, const Berza &b)
{
    if(a.Vektor.size()!=b.Vektor.size() || a.MaksimalnaCijena!=b.MaksimalnaCijena || a.MinimalnaCijena!=b.MinimalnaCijena)
    {
        throw std::domain_error("Nesaglasni operandi");
    }
    Berza failsafe=a;
    failsafe.Vektor.resize(a.Vektor.size());
    std::transform(a.Vektor.begin(),a.Vektor.end(),b.Vektor.begin(),a.Vektor.begin(),std::minus<int>());
    if(std::none_of(a.Vektor.begin(), a.Vektor.end(), std::bind(std::greater<int>(), std::placeholders::_1, a.MaksimalnaCijena))==false)
    {
        a=failsafe;
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    }
    if(std::none_of(a.Vektor.begin(), a.Vektor.end(), std::bind(std::less<int>(), std::placeholders::_1, a.MinimalnaCijena))==false)
    {
        a=failsafe;
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    }
    return a;
    a.Vektor.size();
}

bool operator ==(const Berza &a, const Berza &b)
{
    if(a.Vektor.size()!=b.Vektor.size())
    {
        return false;
    }
    auto pair=std::mismatch(a.Vektor.begin(),a.Vektor.end(),b.Vektor.begin(),std::equal_to<int>());
    if(pair.first==a.Vektor.end() && pair.second==b.Vektor.end())
    {
        return true;
    }
    return false;
}

bool operator !=(const Berza &a, const Berza &b)
{
    if(a.Vektor.size()!=b.Vektor.size())
    {
        return true;
    }
    auto pair=std::mismatch(a.Vektor.begin(),a.Vektor.end(),b.Vektor.begin(),std::equal_to<int>());
    if(pair.first==a.Vektor.end() && pair.second==b.Vektor.end())
    {
        return false;
    }
    return true;
}

int main ()
{
    return 0;
}