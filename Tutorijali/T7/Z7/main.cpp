/* 
    TP 16/17 (Tutorijal 7, Zadatak 7)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <set>

template <typename Tip>
std::set<Tip> Unija(std::set<Tip> Set1, std::set<Tip> Set2)
{
	std::set<Tip> Set3;
	for(auto i : Set1)
	{
		Set3.insert(i);
	}
	for(auto i : Set2)
	{
		Set3.insert(i);
	}
	return Set3;
}

template <typename Tip>
std::set<Tip> Presjek(std::set<Tip> Set1, std::set<Tip> Set2)
{
	std::set<Tip> Set3;
	auto pocetak1=Set1.begin();
	while(pocetak1!=Set1.end())
	{
		auto pocetak2=Set2.begin();
		while(pocetak2!=Set2.end())
		{
			if(*pocetak2==*pocetak1)
			{
				Set3.insert(*pocetak1);
			}
			pocetak2++;
		}
		pocetak1++;
	}
	return Set3;
}

int main ()
{
	std::cout << "Broj rijeci prvog skupa: ";
	int BrojRijeciPrvogSkupa;
	std::cin >> BrojRijeciPrvogSkupa;
	std::cout << "Unesite rijeci prvog skupa: ";
	std::set<std::string> Set1;
	for(int i=0;i<BrojRijeciPrvogSkupa;i++)
	{
		std::string Rijec;
		std::cin >> Rijec;
		Set1.insert(Rijec);
		
	}
	std::cout << "Broj rijeci drugog skupa: ";
	int BrojRijeciDrugogSkupa;
	std::cin >> BrojRijeciDrugogSkupa;
	std::cout << "Unesite rijeci drugog skupa: ";
	std::set<std::string> Set2;
	for(int i=0;i<BrojRijeciDrugogSkupa;i++)
	{
		std::string Rijec;
		std::cin >> Rijec;
		Set2.insert(Rijec);
		
	}
	auto SetPresjek=Presjek(Set1, Set2);
	auto SetUnija=Unija(Set1, Set2);
	std::cout << "Unija je: ";
	for(auto i : SetUnija)
	{
		std::cout << i << " ";
	}
	std::cout << "\nPresjek je: ";
	for(auto i : SetPresjek)
	{
		std::cout << i << " ";
	}
	return 0;
}