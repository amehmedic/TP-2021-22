//TP 2021/2022: Zadaća 5, Zadatak 1
#include <iostream>
#include <cmath>
#include <limits>
#include <sstream>
#include <string>  

bool ProvjeriSabiranje(long long int x, long long int y)
{
    auto M=std::numeric_limits<long long int>::max();
    auto m=std::numeric_limits<long long int>::min();
    if(y>=0)
    {
        if(x>(M-y))
        {
            return false;
        }
    }
    if(y<0)
    {
        if(x<(m-y))
        {
            return false; 
        }
    }
    return true;
}

bool ProvjeriOduzimanje(long long int x, long long int y)
{
    auto M=std::numeric_limits<long long int>::max();
    auto m=std::numeric_limits<long long int>::min();
    y=-y;
    if(y>=0)
    {
        if(x>(M-y))
        {
            return false;
        }
    }
    if(y<0)
    {
        if(x<(m-y))
        {
            return false; 
        }
    }
    return true;
}

bool ProvjeriMnozenje(long long int x, long long int y)
{
    auto M=std::numeric_limits<long long int>::max();
    auto m=std::numeric_limits<long long int>::min();
    if(y>=0)
    {
        if(x<(m/y) || x>(M/y))
        {
            return false; 
        }
    }
    if(y<0)
    {
        if(x==m || (-x)>(M/(-y)) || (-x)<(m/(-y)))  // OVO NISAM SIGURAN
        {
            return false;
        }
    }
    return true;
}

long long int NajveciZajednickiDjeltelj(long long int a, long long int b)
{
   if (b == 0)
   {
       return a;  
   }
   return NajveciZajednickiDjeltelj(b, a % b);
}

class Razlomak
{
    long long int Brojnik;
    long long int Nazivnik;
public:
    Razlomak(long long int brojnik, long long int nazivnik);
    Razlomak(long long int brojnik);
    Razlomak();
    friend Razlomak operator +(const Razlomak &a, const Razlomak &b);
    friend Razlomak operator -(const Razlomak &a, const Razlomak &b);
    friend Razlomak operator *(const Razlomak &a, const Razlomak &b);
    friend Razlomak operator /(const Razlomak &a, const Razlomak &b);
    friend Razlomak operator +(const Razlomak &a);
    friend Razlomak operator -(const Razlomak &a);
    friend Razlomak &operator +=(Razlomak &a, const Razlomak &b);
    friend Razlomak &operator -=(Razlomak &a, const Razlomak &b);
    friend Razlomak &operator *=(Razlomak &a, const Razlomak &b);
    friend Razlomak &operator /=(Razlomak &a, const Razlomak &b);
    friend Razlomak &operator ++(Razlomak &a);
    friend Razlomak &operator --(Razlomak &a);
    friend Razlomak operator ++(Razlomak &a, int);
    friend Razlomak operator --(Razlomak &a, int);
    friend bool operator <(const Razlomak &a, const Razlomak &b);
    friend bool operator >(const Razlomak &a, const Razlomak &b);
    friend bool operator <=(const Razlomak &a, const Razlomak &b);
    friend bool operator >=(const Razlomak &a, const Razlomak &b);
    friend bool operator ==(const Razlomak &a, const Razlomak &b);
    friend std::ostream &operator <<(std::ostream &tok, const Razlomak &a);
    friend std::istream &operator >>(std::istream &tok, Razlomak &a);
    operator long double() const;
    long long int DajBrojnik() const;
    long long int DajNazivnik() const;
};

Razlomak::Razlomak(long long int brojnik, long long int nazivnik)
{
    if(nazivnik==0)
    {
        throw std::logic_error("Nekorektan razlomak");
    }
    bool DaLiJeBrojnikBioNeg=false;
    bool DaLiJeNazivnikBioNeg=false;
    bool DaLiSuObaNeg=false;
    if(brojnik<0)
    {
        DaLiJeBrojnikBioNeg=true;
    }
    if(nazivnik<0)
    {
        DaLiJeNazivnikBioNeg=true;
    }
    if(DaLiJeBrojnikBioNeg==true && DaLiJeNazivnikBioNeg==true)
    {
        DaLiSuObaNeg=true;
    }
    brojnik=llabs(brojnik);
    nazivnik=llabs(nazivnik);
    auto NZD=NajveciZajednickiDjeltelj(brojnik, nazivnik);
    brojnik=brojnik/NZD;
    nazivnik=nazivnik/NZD;
    if(DaLiSuObaNeg==true)
    {
        Brojnik=brojnik;
        Nazivnik=nazivnik;
        return;
    }
    if(DaLiJeBrojnikBioNeg==true || DaLiJeNazivnikBioNeg==true)
    {
        Brojnik=brojnik*(-1);
        Nazivnik=nazivnik;
        return;
    }
    Brojnik=brojnik;
    Nazivnik=nazivnik;
}

Razlomak::Razlomak(long long int brojnik)
{
    Brojnik=brojnik;
    Nazivnik=1;
}

Razlomak::Razlomak()
{
    Brojnik=0;
    Nazivnik=1;
}

Razlomak operator +(const Razlomak &a, const Razlomak &b)
{
    auto r=NajveciZajednickiDjeltelj(a.Nazivnik,b.Nazivnik);
    if(ProvjeriMnozenje(a.Brojnik,(b.Nazivnik/r))==false)
    {
        throw::std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    if(ProvjeriMnozenje(b.Brojnik,(a.Nazivnik/r))==false)
    {
        throw::std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    if(ProvjeriMnozenje(a.Nazivnik,(b.Nazivnik/r))==false)
    {
        throw::std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    if(ProvjeriSabiranje((a.Brojnik*(b.Nazivnik/r)),(b.Brojnik*(a.Nazivnik/r)))==false)
    {
        throw::std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    return Razlomak(((a.Brojnik*(b.Nazivnik/r))+(b.Brojnik*(a.Nazivnik/r))),(a.Nazivnik*(b.Nazivnik/r)));
}

Razlomak operator -(const Razlomak &a, const Razlomak &b)
{
    auto r=NajveciZajednickiDjeltelj(a.Nazivnik,b.Nazivnik);
    if(ProvjeriMnozenje(a.Brojnik,(b.Nazivnik/r))==false)
    {
        throw::std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    if(ProvjeriMnozenje(b.Brojnik,(a.Nazivnik/r))==false)
    {
        throw::std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    if(ProvjeriMnozenje(a.Nazivnik,(b.Nazivnik/r))==false)
    {
        throw::std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    if(ProvjeriOduzimanje((a.Brojnik*(b.Nazivnik/r)),(b.Brojnik*(a.Nazivnik/r)))==false)
    {
        throw::std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    return Razlomak(((a.Brojnik*(b.Nazivnik/r))-(b.Brojnik*(a.Nazivnik/r))),(a.Nazivnik*(b.Nazivnik/r)));
}

Razlomak operator *(const Razlomak &a, const Razlomak &b)
{
    auto s=NajveciZajednickiDjeltelj(a.Brojnik,b.Nazivnik);
    auto t=NajveciZajednickiDjeltelj(b.Brojnik,a.Nazivnik);
    if(ProvjeriMnozenje((a.Brojnik/s),(b.Brojnik/t))==false)
    {
        throw::std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    if(ProvjeriMnozenje((a.Nazivnik/t),(b.Nazivnik/s))==false)
    {
        throw::std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    return Razlomak(((a.Brojnik/s)*(b.Brojnik/t)),((a.Nazivnik/t)*(b.Nazivnik/s)));
}

Razlomak operator /(const Razlomak &a, const Razlomak &b)
{
    auto r=NajveciZajednickiDjeltelj(a.Nazivnik,b.Nazivnik);
    auto u=NajveciZajednickiDjeltelj(a.Brojnik, b.Brojnik);
    if(ProvjeriMnozenje((a.Brojnik/u),(b.Nazivnik/r))==false)
    {
        throw::std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    if(ProvjeriMnozenje((a.Nazivnik/r),(b.Brojnik/u))==false)
    {
        throw::std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    return Razlomak(((a.Brojnik/u)*(b.Nazivnik/r)),((a.Nazivnik/r)*(b.Brojnik/u)));
}

Razlomak operator +(const Razlomak &a)
{
    return Razlomak(a.Brojnik,a.Nazivnik);
}

Razlomak operator -(const Razlomak &a)
{
    if(ProvjeriMnozenje(a.Brojnik,-1)==false)
    {
        throw::std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    return Razlomak(-a.Brojnik,a.Nazivnik);
}

Razlomak &operator +=(Razlomak &a, const Razlomak &b)
{
    a=a+b;
    return a;
}

Razlomak &operator -=(Razlomak &a, const Razlomak &b)
{
    a=a-b;
    return a;
}

Razlomak &operator *=(Razlomak &a, const Razlomak &b)
{
    a=a*b;
    return a;
}

Razlomak &operator /=(Razlomak &a, const Razlomak &b)
{
    a=a/b;
    return a;
}

Razlomak &operator ++(Razlomak &a)
{
    a=a+Razlomak(1);
    return a;
}

Razlomak &operator --(Razlomak &a)
{
    a=a-Razlomak(1);
    return a;
}

Razlomak operator ++(Razlomak &a, int)
{
    Razlomak pomocni = a;
    a=a+Razlomak(1);
    return pomocni;
}

Razlomak operator --(Razlomak &a, int)
{
    Razlomak pomocni = a;
    a=a-Razlomak(1);
    return pomocni;
}

bool operator <(const Razlomak &a, const Razlomak &b)
{
    long double arez;
    long double brojnik=a.Brojnik;
    long double nazivnik=a.Nazivnik;
    arez=(brojnik/nazivnik);
    long double brez;
    brojnik=b.Brojnik;
    nazivnik=b.Nazivnik;
    brez=(brojnik/nazivnik);
    if(arez<brez)
    {
        return true;
    }
    return false;
}

bool operator >(const Razlomak &a, const Razlomak &b)
{
    long double arez;
    long double brojnik=a.Brojnik;
    long double nazivnik=a.Nazivnik;
    arez=(brojnik/nazivnik);
    long double brez;
    brojnik=b.Brojnik;
    nazivnik=b.Nazivnik;
    brez=(brojnik/nazivnik);
    if(arez>brez)
    {
        return true;
    }
    return false;
}

bool operator <=(const Razlomak &a, const Razlomak &b)
{
    long double arez;
    long double brojnik=a.Brojnik;
    long double nazivnik=a.Nazivnik;
    arez=(brojnik/nazivnik);
    long double brez;
    brojnik=b.Brojnik;
    nazivnik=b.Nazivnik;
    brez=(brojnik/nazivnik);
    if(arez<=brez)
    {
        return true;
    }
    return false;
}

bool operator >=(const Razlomak &a, const Razlomak &b)
{
    long double arez;
    long double brojnik=a.Brojnik;
    long double nazivnik=a.Nazivnik;
    arez=(brojnik/nazivnik);
    long double brez;
    brojnik=b.Brojnik;
    nazivnik=b.Nazivnik;
    brez=(brojnik/nazivnik);
    if(arez>=brez)
    {
        return true;
    }
    return false;
}

bool operator ==(const Razlomak &a, const Razlomak &b)
{
    long double Eplsilon=0.00000001;
    long double arez;
    long double brojnik=a.Brojnik;
    long double nazivnik=a.Nazivnik;
    arez=(brojnik/nazivnik);
    long double brez;
    brojnik=b.Brojnik;
    nazivnik=b.Nazivnik;
    brez=(brojnik/nazivnik);
    if(fabsl(arez-brez)<Eplsilon)
    {
        return true;
    }
    return false;
}

std::ostream &operator <<(std::ostream &tok, const Razlomak &a)
{
    if(a.Nazivnik==1)
    {
        tok << a.Brojnik;
        return tok;
    }
    tok << a.Brojnik << "/" << a.Nazivnik;
    return tok;
}

std::istream &operator >>(std::istream &tok, Razlomak &a)
{
    tok >> std::ws;
    if(isdigit(tok.peek())==false)
    {
        tok.setstate(std::ios::failbit);
        return tok;
    }
    char znak=tok.peek();
    long long int brojnik;
    long long int nazivnik=1;
    tok >> brojnik;
    znak=tok.peek();
    if(tok.peek() == '\n' || tok.peek() == '\r' || tok.peek() == '\f' || tok.peek() == '\v' || tok.peek() == '\t' || tok.peek() == ' ')
    {
        Razlomak x(brojnik);
        a=x;
        return tok;
    }
    else
    {
        tok >> znak >> nazivnik;
        Razlomak x(brojnik,nazivnik);
        a=x;
        if(znak != '/')
        {
            tok.setstate(std::ios::failbit);
            return tok;
        }
    }
    if(tok.peek() != '\n' && tok.peek() != '\r' && tok.peek() != '\f' && tok.peek() != '\v' && tok.peek() != '\t' && tok.peek() != ' ')
    {
        tok.setstate(std::ios::failbit);
    }
    return tok;
}

Razlomak::operator long double() const
{
    long double rezultat;
    long double b=Brojnik;
    long double n=Nazivnik;
    rezultat=(b/n);
    return rezultat;
}

long long int Razlomak::DajBrojnik() const
{
    return Brojnik;
}

long long int Razlomak::DajNazivnik() const
{
    return Nazivnik;
}

int main ()
{
    return 0;
}
