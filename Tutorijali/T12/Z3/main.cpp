/* 
    TP 16/17 (Tutorijal 12, Zadatak 3)
	Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: khodzic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>

enum Dani {Ponedjeljak,Utorak,Srijeda,Cetvrtak,Petak,Subota,Nedjelja};

Dani &operator ++(Dani &d) {
	return d=Dani((int(d)+1)%7);
}
Dani operator ++(Dani &d,int) {
	Dani da(d); d=Dani((int(d)+1)%7);
	return da;
}

std::ostream &operator <<(std::ostream &tok, const Dani &dan) {
	switch(dan) {
		case Ponedjeljak: tok<<"Ponedjeljak"; break;
		case Utorak: tok<<"Utorak"; break;
		case Srijeda: tok<<"Srijeda"; break;
		case Cetvrtak: tok<<"Cetvrtak"; break;
		case Petak: tok<<"Petak"; break; 
		case Subota: tok<<"Subota"; break; 
		case Nedjelja: tok<<"Nedjelja"; break;
	}
	return tok;
}
int main ()
{
	for(Dani d=Ponedjeljak; d<=Petak; d++) { std::cout<<d<<"\n"; }
	//Dani m=Utorak;
	//std::cout<<m;
	//switch(m)
	std::cout<<"-------------------------------------\n";
	for(Dani d=Ponedjeljak; d<=Nedjelja; d++) { std::cout<<d<<"\n"; if(d==6) { break; } }
	return 0;
}