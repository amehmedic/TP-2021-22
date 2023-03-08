/* 
    TP 16/17 (Tutorijal 13, Zadatak 1)
	Autotestove pisala Ivona Ivkovic. Sva pitanja, sugestije, prijave gresaka
	slati na mail iivkovic2@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cmath>
#include <exception>
#include <string>
#include <vector>
#include <memory>

class Lik {
public:
    //Lik() {}
    virtual void IspisiSpecificnosti() const {}
    virtual double DajObim() const { return 0; }
    virtual double DajPovrsinu() const { return 0; }
    virtual ~Lik() {}
    void Ispisi() {
    	//std::cout<<"\n";
    	IspisiSpecificnosti();
    	std::cout<<"\n";
    	std::cout<<"Obim: "<<DajObim()<<" Povrsina: "<<DajPovrsinu();
    }
};

class Krug: public Lik {
	double poluprecnik;
public:
    Krug(double pol): poluprecnik(pol) { if(pol<=0) { throw std::domain_error("Neispravni parametri");} }
    double DajObim() const { return 4*atan(1)*2*poluprecnik; }
    double DajPovrsinu() const { return poluprecnik*poluprecnik*4*atan(1); }
    void IspisiSpecificnosti() const override { std::cout<<"\nKrug poluprecnika "<<poluprecnik; }
};

class Pravougaonik: public Lik {
	double a; double b;
public:
    Pravougaonik(double a, double b): a(a), b(b) { if(a<=0 || b<=0) { throw std::domain_error("Neispravni parametri"); } }
    double DajObim() const { return 2*a+2*b; }
    double DajPovrsinu() const { return a*b; }
    void IspisiSpecificnosti() const { std::cout<<"\nPravougaonik sa stranicama duzine "<<a<<" i "<<b; }
};

class Trougao: public Lik {
	double a; double b; double c;
public:
    Trougao(double a,double b,double c): a(a),b(b),c(c) { if(a+b<=c || b+c<=a || c+a<=b) { 
    	throw std::domain_error("Neispravni parametri"); } }
    double DajObim() const { return a+b+c; }
    double DajPovrsinu() const {
    	double s=(a+b+c)/2;
    	double pov=sqrt(s*(s-a)*(s-b)*(s-c)); if(pov<0) { return pov*(-1); }
    	return pov;
    }
    void IspisiSpecificnosti() const { std::cout<<"\nTrougao sa stranicama duzine "<<a<<", "<<b<<" i "<<c; }
};


int main ()
{
	std::cout<<"Koliko zelite likova: ";
	int n;
	std::cin>>n;
	std::cin.ignore(10000,'\n');
	std::vector<std::shared_ptr<Lik>> v(n,nullptr);
	for(int i=0; i<n; i++) {
	    std::cout<<"Lik "<<i+1<<": ";
	    char s;
	    std::cin>>s;
	    if(s=='P') {
	    	char znak;
	    	//double c;
	    	double a,b;
	    	//if(std::cin.peek)
	    	std::cin>>a>>znak>>b;
	    	//double broj;
	    	if(!(std::cin)) { std::cin.clear(); std::cin.ignore(10000,'\n'); std::cout<<"Pogresni podaci, ponovite unos!\n"; i--; continue; }
	    	std::cin.ignore(10000,'\n');
	    	try{ v.at(i)=std::make_shared<Pravougaonik>(Pravougaonik(a,b)); }
	    	catch(...) { std::cout<<"Pogresni podaci, ponovite unos!\n"; v.at(i)=nullptr; i--; continue; }
	    }
	    else if(s=='K') {
	    	//char znak;
	    	double a;
	    	std::cin>>a;
	    	//double broj;
	    	if(!(std::cin)) { std::cin.clear(); std::cin.ignore(10000,'\n'); std::cout<<"Pogresni podaci, ponovite unos!\n"; i--; continue; }
	    	std::cin.ignore(10000,'\n');
	    	try { v.at(i)=std::make_shared<Krug>(Krug(a)); }
	    	catch(...) { std::cout<<"Pogresni podaci, ponovite unos!\n"; v.at(i)=nullptr; i--; continue; }
	    }
	    else if(s=='T') {
	    	double a,b,c;
	    	char znak,znak1;
	    	std::cin>>a>>znak>>b>>znak1>>c;
	    	//double broj;
	    	if(!(std::cin)) { std::cin.clear(); std::cin.ignore(10000,'\n'); std::cout<<"Pogresni podaci, ponovite unos!\n"; i--; continue; }
	    	std::cin.ignore(1000,'\n');
	    	try { v.at(i)=std::make_shared<Trougao>(Trougao(a,b,c)); }
	    	catch(...) { std::cout<<"Pogresni podaci, ponovite unos!\n"; v.at(i)=nullptr; i--; continue; }
	    }
	    else { std::cout<<"Pogresni podaci, ponovite unos!\n"; std::cin.clear(); std::cin.ignore(10000,'\n'); i--; continue; }
	}
	for(int i=0; i<n; i++) { v.at(i)->Ispisi(); }
	
	return 0;
}