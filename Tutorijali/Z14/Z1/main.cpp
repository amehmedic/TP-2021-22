//TP 2018/2019: Tutorijal 14, Zadatak 1
#include <iostream>
#include <new>
#include <memory>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>
#include <iomanip>
#include <fstream>

class Temp
{
    int Dan;
    int Mjesec;
    int Godina;
    std::string Komentar;
    std::vector<double> Temperature;
public:
    void Ispisi(std::ofstream& tok) const
    {
        tok << Komentar << "\n";
        for(int i=0;i<Komentar.length();i++)
        {
            tok << "-";
        }
        tok << "\nDatum mjerenja: " << Dan << "/" << Mjesec << "/" << Godina;
        double Min=*std::min_element(Temperature.begin(),Temperature.end());
        tok << "\nMinimalna temperatura: " << Min;
        double Max=*std::max_element(Temperature.begin(),Temperature.end());
        tok << "\nMaksimalna temperatura: " << Max;
        double Zbir=std::accumulate(Temperature.begin(),Temperature.end(),0);
        double Prosjecna=Zbir/Temperature.size(); 
        tok << std::fixed << std::setprecision(2) << "\nProsjecna temperatura: " << Prosjecna << "\n\n";
        tok.unsetf(std::ios::floatfield);
        tok.flush();
    }
    Temp(int dan, int mjesec, int godina, std::string komentar, std::vector<double> temperature)
    {
        Dan=dan;
        Mjesec=mjesec;
        Godina=godina;
        Komentar=komentar;
        Temperature=temperature;
    }
    int DajDan() const
    {
        return Dan;
    }
    int DajMjesec() const
    {
        return Mjesec;
    }
    int DajGodina() const
    {
        return Godina;
    }
    double DajProsjek() const
    {
        double Zbir=std::accumulate(Temperature.begin(),Temperature.end(),0);
        double Prosjecna=Zbir/Temperature.size();
        return Prosjecna;
    }
};

int main ()
{
    std::vector<Temp> VektorTempova;
    std::ifstream ulazni_tok("TEMPERATURE.TXT");
    
    if(!ulazni_tok)
        {
            std::cout << "Datoteka TEMPERATURE.TXT ne postoji!" << "\n";
            return 0;
        }
    
    while(ulazni_tok)
    {
        int Dan;
        int Mjesec;
        int Godina;
        char Znak;
        std::string Komentar;
        std::vector<double> Temperature;
        ulazni_tok >> Dan >> Znak;
        if(!ulazni_tok || Znak!='/')
        {
            std::cout << "Problemi pri citanju datoteke TEMPERATURE.TXT" << "\n";
            return 0;
        }
        ulazni_tok >> Mjesec >> Znak;
        if(!ulazni_tok || Znak!='/')
        {
            std::cout << "Problemi pri citanju datoteke TEMPERATURE.TXT" << "\n";
        }
        ulazni_tok >> Godina;
        Znak=ulazni_tok.get();
        if(!ulazni_tok || Znak!='\n')
        {
            std::cout << "Problemi pri citanju datoteke TEMPERATURE.TXT" << "\n";
        }
        std::getline(ulazni_tok, Komentar);
        
        if(!ulazni_tok)
        {
            std::cout << "Problemi pri citanju datoteke TEMPERATURE.TXT" << "\n";
            return 0;
        }

        while(1!=0)
        {
            double Temperatura;
            ulazni_tok >> Temperatura;
            Znak=ulazni_tok.get();
            if((Znak!=',' && Znak!='\n' && Znak!=EOF))
            {
                std::cout << "Problemi pri citanju datoteke TEMPERATURE.TXT" << "\n";
                return 0;
            }
            Temperature.push_back(Temperatura);
            if(Znak=='\n' || Znak==EOF)
            {
                break;
            }
        }
        VektorTempova.push_back(Temp(Dan,Mjesec,Godina,Komentar,Temperature));
        Temperature.resize(0);
    }
    std::sort(VektorTempova.begin(),VektorTempova.end(),[](Temp a, Temp b){
        if(a.DajGodina()<b.DajGodina())
        {
            return true;
        }
        else if(a.DajGodina()>b.DajGodina())
        {
            return false;
        }
        if(a.DajMjesec()<b.DajMjesec())
        {
            return true;
        }
        if(a.DajMjesec()>b.DajMjesec())
        {
            return false;
        }
        if(a.DajDan()<b.DajDan())
        {
            return true;
        }
        if(a.DajDan()>b.DajDan())
        {
            return false;
        }
        if(a.DajProsjek()<b.DajProsjek())
        {
            return true;
        }
        return false;
    });
    std::ofstream izlazni_tok("IZVJESTAJ.TXT");
    for(int i=0;i<VektorTempova.size();i++)
    {
        VektorTempova.at(i).Ispisi(izlazni_tok);
    }
	return 0;
}
