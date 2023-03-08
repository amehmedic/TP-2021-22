//TP 2018/2019: Tutorijal 8, Zadatak 6
#include <iostream>

template <typename TipElementa>
struct Cvor
{
    TipElementa element;
    Cvor<TipElementa> *veza;
};

template <typename TipElementa>
Cvor<TipElementa> *KreirajPovezanuListu(TipElementa zavrsni)
{
    Cvor<TipElementa>* pocetak=nullptr,*prethodni;
    while(1)
    {
        TipElementa podatak;
        std::cin >> podatak;
        if(podatak==zavrsni)
        {
            break;
        }
        Cvor<TipElementa>* novi=new Cvor<TipElementa> {podatak,nullptr};
        if(!pocetak)
        {
            pocetak=novi;
        }
        else
        {
            prethodni->veza=novi;
        }
        prethodni=novi;
    }
    return pocetak;
}

template <typename TipElementa>
int BrojElemenata(Cvor<TipElementa> *pocetak)
{
    int c=0;
    for(auto p=pocetak;p!=nullptr;p=p->veza)
    {
        c++;
    }
    return c;
}

template <typename TipElementa>
TipElementa SumaElemenata(Cvor<TipElementa> *pocetak)
{
    TipElementa suma=0;
    for(auto p=pocetak;p!=nullptr;p=p->veza)
    {
        suma+=p->element;
    }
    return suma;
}

template <typename TipElementa>
int BrojVecihOd(Cvor<TipElementa> *pocetak, TipElementa prag)
{
    int c=0;
    for(auto p=pocetak;p!=nullptr;p=p->veza)
    {
        if(p->element>prag)
        {
            c++;
        }
    }
    return c;
}

template <typename TipElementa>
void UnistiListu(Cvor<TipElementa> *pocetak)
{
    Cvor<TipElementa>* iduci;
    while(pocetak!=nullptr)
    {
        iduci=pocetak->veza;
        delete pocetak;
        pocetak=iduci;
    }
}

template <typename TipElementa>
void UnistiListuReq(Cvor<TipElementa> *pocetak)
{
    Cvor<TipElementa>* iduci;
    if(pocetak!=nullptr)
    {
        iduci=pocetak->veza;
        delete pocetak;
        UnistiListuReq(iduci);
    }
}

int main ()
{
    std::cout << "Unesite slijed brojeva (0 za kraj): ";
    auto a=KreirajPovezanuListu(0.0);
    double aritm=SumaElemenata(a)/BrojElemenata(a);
    std::cout << "U slijedu ima " << BrojVecihOd(a,aritm) << " brojeva vecih od njihove aritmeticke sredine";
	UnistiListuReq(a);
	return 0;
}