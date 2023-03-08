/* 
    TP 16/17 (Tutorijal 12, Zadatak 1)
	Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: khodzic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <exception>
#include <iomanip>

class Sat {
    int sekunde;
    int minute;
    int sati;
public:
    static bool DaLiJeIspravno(int sa, int min, int sek) {
        if(sa>23 || sa<0 || min>59 || min<0 || sek>59 || sek<0) {
            return false;
        }
        return true;
    }
    void Postavi(int sa, int min, int sek) {
        if(DaLiJeIspravno(sa,min,sek)==false) { throw std::domain_error("Neispravno vrijeme"); }
        sekunde=sek; minute=min; sati=sa;
    }
    void PostaviNormalizirano(int sa, int min, int sek) {
        while(sek>59) { sek-=60; min++; }
        while(sek<0) { sek+=60; min--; }
        while(min>59) { min-=60; sa++; }
        while(min<0) { min+=60; sa--; }
        while(sa>23) { sa-=24; }
        while(sa<0) { sa+=24; }
        sekunde=sek; minute=min; sati=sa;
    }
    Sat(int sa=0, int min=0, int sek=0) {
        while(sek>59) { sek-=60; min++; }
        while(sek<0) { sek+=60; min--; }
        while(min>59) { min-=60; sa++; }
        while(min<0) { min+=60; sa--; }
        while(sa>23) { sa-=24; }
        while(sa<0) { sa+=24; }
        sekunde=sek; minute=min; sati=sa;
    }
    /*Sat &Sljedeci() {
        sekunde+=1;
        while(sekunde>59) { sekunde-=60; minute++; }
        while (minute>59) { minute-=60; sati++; }
        while (sati>23) { sati-=24; }
        return *this;
    }*/
    // operator prefiksni ++
    friend Sat &operator ++(Sat &sat) {
    	sat.sekunde+=1;
    	while(sat.sekunde>59) { sat.sekunde-=60; sat.minute++; }
    	while (sat.minute>59) { sat.minute-=60; sat.sati++; }
    	while (sat.sati>23) { sat.sati-=24; }
    	return sat;
    }
    friend Sat operator ++(Sat &sat,int) {
    	Sat s(sat.sati,sat.minute,sat.sekunde);
    	sat.sekunde+=1;
    	while(sat.sekunde>59) { sat.sekunde-=60; sat.minute++; }
    	while(sat.minute>59) { sat.minute-=60; sat.sati++; }
    	while(sat.sati>23) { sat.sati-=24; }
    	return s;
    }
    /*Sat &Prethodni() {
        sekunde-=1;
        while(sekunde<0) { sekunde+=60; minute--; }
        while(minute<0) { minute+=60; sati--; }
        while(sati<0) { sati+=24; }
        return *this;
    }*/
    friend Sat &operator --(Sat &sat) {
    	sat.sekunde-=1;
    	while(sat.sekunde<0) { sat.sekunde+=60; sat.minute--; }
    	while(sat.minute<0) { sat.minute+=60; sat.sati--; }
    	while(sat.sati<0) { sat.sati+=24; }
    	return sat;
    }
    friend Sat operator --(Sat &sat,int) {
    	Sat s(sat.sati,sat.minute,sat.sekunde);
    	sat.sekunde-=1;
    	while(sat.sekunde<0) { sat.sekunde+=60; sat.minute--; }
    	while(sat.minute<0) { sat.minute+=60; sat.sati--; }
    	while(sat.sati<0) { sat.sati+=24; }
    	return s;
    }
    Sat &PomjeriZa(int a) {
        sekunde+=a;
        int se=sekunde; int min=minute; int sa=sati;
        PostaviNormalizirano(sa,min,se);
        return *this;
    }
    friend Sat &operator +=(Sat &sat,const int &sat2) {
        sat.sekunde+=sat2;
        int se=sat.sekunde; int min=sat.minute; int sa=sat.sati;
        while(se>59) { se-=60; min++; }
        while(min>59) { min-=60; sa++; }
        while(sa>23) { sa-=24; }
        sat.sekunde=se; sat.minute=min; sat.sati=sa;
        return sat;
    }
    friend Sat &operator -=(Sat &sat,const int &sat2) {
        sat.sekunde-=sat2;
        int se=sat.sekunde; int min=sat.minute; int sa=sat.sati;
        while(se<0) { se+=60; min--; }
        while(min<0) { min+=60; sa--; }
        while(sa<0) { sa+=24; }
        sat.sekunde=se; sat.minute=min; sat.sati=sa;
        return sat;
    }
    friend Sat operator+(const Sat &s1, int n) {
        int se=s1.sekunde+n;
        int min=s1.minute;
        int sa=s1.sati;
        Sat s(sa,min,se);
        return s;
    }
    friend Sat operator-(const Sat &s1,int n) {
        int se=s1.sekunde-n;
        int min=s1.minute;
        int sa=s1.sati;
        Sat s(sa,min,se);
        return s;
    }
    void Ispisi() const {
        std::cout<<std::setw(2)<<std::setfill('0')<<sati<<":"
                 <<std::setw(2)<<std::setfill('0')<<minute<<":"
                 <<std::setw(2)<<std::setfill('0')<<sekunde;    
    }
    friend std::ostream &operator <<(std::ostream &tok,const Sat &sat) {
        tok <<std::setw(2)<<std::setfill('0')<<sat.sati<<":"
            <<std::setw(2)<<std::setfill('0')<<sat.minute<<":"
            <<std::setw(2)<<std::setfill('0')<<sat.sekunde;
        return tok;
    }
    int DajSate() const { return sati; }
    int DajMinute() const { return minute; }
    int DajSekunde() const { return sekunde; }
    static int Razmak(Sat a, Sat b) {
        int a1=a.sati*60*60+a.minute*60+a.sekunde;
        int b1=b.sati*60*60+b.minute*60+b.sekunde;
        return a1-b1;
    }
    friend int operator -(const Sat &sat1, const Sat &sat2) {
        int s1=sat1.sati*60*60+sat1.minute*60+sat1.sekunde;
        int s2=sat2.sati*60*60+sat2.minute*60+sat2.sekunde;
        return s1-s2;
    }
    friend int BrojSekundiIzmedju(Sat a, Sat b);
};

int BrojSekundiIzmedju(Sat a, Sat b) {
    int a1=a.sati*60*60+a.minute*60+a.sekunde;
    int b1=b.sati*60*60+b.minute*60+b.sekunde;
    return a1-b1;
}

int main ()
{
    Sat v1;
    Sat v2;
    v2.Postavi(10,10,10);
    v2.Ispisi();
    std::cout<<"\n";
    v1.PostaviNormalizirano(100,100,100);
    v1.Ispisi();
    //v1.Sljedeci();
    std::cout<<"\n";
    v1.Ispisi();
    std::cout<<"\n";
    //v2.Prethodni();
    v2.Ispisi();
    v1.PomjeriZa(120);
    std::cout<<"\n";
    v1.Ispisi();
    int sati=v1.DajSate();
    int minute=v1.DajMinute();
    int sekunde=v1.DajSekunde();
    std::cout<<"\n"<<sati<<" "<<minute<<" "<<sekunde;
    int razmak=Sat::Razmak(v1,v2);
    std::cout<<"\n"<<razmak;
    int razm=BrojSekundiIzmedju(v1,v2);
    std::cout<<"\n"<<razm;
	return 0;
}