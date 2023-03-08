//TP 2021/2022: Zadaća 5, Zadatak 6
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <fstream>

template <typename TipElemenata>
int DajBrojElemenata(std::fstream& tok)
{
    tok.seekg(0,std::ios::end);
    return tok.tellg()/sizeof(TipElemenata);
}

template <typename TipElemenata>
TipElemenata DajElement(int Pozicija, std::fstream& tok)
{
    if(Pozicija<0 || Pozicija>=DajBrojElemenata<TipElemenata>(tok))
    {
        throw std::range_error("Neispravna pozicija");
    }
    int TrenutnaPozicija=tok.tellg();
    tok.seekg(Pozicija*sizeof(TipElemenata),std::ios::beg);
    TipElemenata s;
    tok.read(reinterpret_cast<char *>(&s), sizeof(TipElemenata));
    if(!tok)
    {
        throw std::logic_error("Problemi prilikom pristupa datoteci");
    }
    tok.seekg(TrenutnaPozicija,std::ios::beg);
    return s;
}


template <typename TipElemenata>
void SortirajBinarnuDatoteku(const char ime_datoteke[], std::function<bool(TipElemenata, TipElemenata)> kriterij= std::less<TipElemenata>())
{
    std::fstream tok;
    tok.open(ime_datoteke,std::ios::in | std::ios::binary);
    if(!tok)
    {
        throw std::logic_error("Datoteka ne postoji");
    }
    tok.close();
    tok.open(ime_datoteke,std::ios::in | std::ios::out | std::ios::binary);
    for(int i=0;i<DajBrojElemenata<TipElemenata>(tok);i++)
    {
        for(int j=i+1;j<DajBrojElemenata<TipElemenata>(tok);j++)
        {
            TipElemenata Prvi=DajElement<TipElemenata>(i,tok);
            TipElemenata Drugi=DajElement<TipElemenata>(j,tok);
            if(!kriterij(Prvi,Drugi))
            {
                tok.seekp(i*sizeof(TipElemenata), std::ios::beg);
                tok.write(reinterpret_cast<char *>(&Drugi), sizeof(Drugi));
                tok.seekp(j*sizeof(TipElemenata), std::ios::beg);
                tok.write(reinterpret_cast<char *>(&Prvi), sizeof(Prvi));
            }
        }
    }
}      

int main ()
{
	return 0;
}
