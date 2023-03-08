/* 
    TP 16/17 (Tutorijal 9, Zadatak 4)
	
	Testove pisao Kenan Ekinovic. Za sva pitanja, sugestije
	i zalbe obratiti se na mail: kekinovic1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <cmath>

class Sat
{
	int Sati;
	int Minute;
	int Sekunde;
	public:
	static bool DaLiJeIspravno(int Sati, int Minute, int Sekunde)
	{
		if(Sati>23 || Sati<0 || Minute>60 || Minute<0 || Sekunde>60 || Sekunde<0)
		{
			return false;
		}
		return true;
	}
	void Postavi(int x, int y, int z)
	{
		Sati=x;
		Minute=y;
		Sekunde=z;
		if(DaLiJeIspravno(Sati,Minute,Sekunde)==false)
		{
			throw std::domain_error("Neispravno vrijeme.");
		}
	}
	void PostaviNormalizirano(int x, int y, int z)
	{
		if(z>59)
		{
			y+=z/60;
			z=z%60;
		}
		if(z<0)
		{
			y+=(z/60)-1;
			z=60+z%60;
		}
		if(y>59)
		{
			x+=y/60;
			y=y%60;
		}
		if(y<0)
		{
			x+=(y/60)-1;
			y=60+y%60;
		}
		if(x>23)
		{
			x=x%24;
		}
		if(x<0)
		{
			x=24+x%24;
		}
		Sati=x;
		Minute=y;
		Sekunde=z;
	}
	Sat Sljedeci()
	{
		Sekunde++;
		PostaviNormalizirano(Sati, Minute, Sekunde);
		return *this;
	}
	Sat Prethodni()
	{
		Sekunde--;
		PostaviNormalizirano(Sati, Minute, Sekunde);
		return *this;
	}
	Sat PomjeriZa(int x)
	{
		Sekunde+=x;
		PostaviNormalizirano(Sati, Minute, Sekunde);
		return *this;
	}
	int DajSate() const {return Sati;}
	int DajMinute() const {return Minute;}
	int DajSekunde() const {return Sekunde;}
	void Ispisi() const
	{
		if(Sati<10)
		{
			std::cout << "0";
		}
		std::cout << Sati << ":";
		if(Minute<10)
		{
			std::cout << "0";
		} 
		std::cout << Minute << ":";
		if(Sekunde<10)
		{
			std::cout << "0";
		}
		std::cout << Sekunde;
	}
	static int Razmak(Sat s1, Sat s2)
	{
		int Sekunde_s1=s1.Sekunde+s1.Minute*60+s1.Sati*3600;
		int Sekunde_s2=s2.Sekunde+s2.Minute*60+s2.Sati*3600;
		return Sekunde_s1-Sekunde_s2;
	}
	friend int BrojSekundiIzmedju(Sat s1, Sat s2);
};

int BrojSekundiIzmedju(Sat s1, Sat s2)
{
	int Sekunde_s1=s1.Sekunde+s1.Minute*60+s1.Sati*3600;
	int Sekunde_s2=s2.Sekunde+s2.Minute*60+s2.Sati*3600;
	return Sekunde_s1-Sekunde_s2;
}
	
int main ()
{
	std::cout << "Unesite sate minute i sekunde prvog 'sata': ";
	int Sati;
	int Minute;
	int Sekunde;
	std::cin >> Sati >> Minute >> Sekunde;
	Sat s1;
	s1.PostaviNormalizirano(Sati,Minute,Sekunde);
	std::cout << "Prvi 'sat': ";
	s1.Ispisi();
	std::cout << "\nUnesite sate minute i sekunde drugog 'sata': ";
	int Sati2;
	int Minute2;
	int Sekunde2;
	std::cin >> Sati2 >> Minute2 >> Sekunde2;
	Sat s2;
	s2.PostaviNormalizirano(Sati2,Minute2,Sekunde2);
	std::cout << "Drugi 'sat': ";
	s2.Ispisi();
	std::cout << "\nBroj sekundi izmedju prvog i drugog 'sata': ";
	std::cout << BrojSekundiIzmedju(s1,s2);
	std::cout << "\nBroj sekundi izmedju drugog i prvog 'sata': ";
	std::cout << Sat::Razmak(s2,s1);
	std::cout << "\nSati prvog ";
	std::cout << s1.DajSate();
	std::cout << "\nMinute prvog ";
	std::cout << s1.DajMinute();
	std::cout << "\nSekunde prvog ";
	std::cout << s1.DajSekunde();
	std::cout << "\nSati drugog ";
	std::cout << s2.DajSate();
	std::cout << "\nMinute drugog ";
	std::cout << s2.DajMinute();
	std::cout << "\nSekunde drugog ";
	std::cout << s2.DajSekunde();
	std::cout << "\nPrvi pomjereni za jednu sekundu 'naprijed' a drugi jednu 'nazad'";
	s1=s1.Sljedeci();
	s2=s2.Prethodni();
	std::cout << "\n";
	s1.Ispisi();
	std::cout << "\n";
	s2.Ispisi();
	std::cout << "\nZa koliko pomjeramo? (prvi naprijed drugi nazad) ";
	int pomjeri;
	std::cin >> pomjeri;
	s1=s1.PomjeriZa(pomjeri);
	s2=s2.PomjeriZa(-1*pomjeri);
	std::cout << "\n";
	s1.Ispisi();
	std::cout << "\n";
	s2.Ispisi();
	return 0;
}