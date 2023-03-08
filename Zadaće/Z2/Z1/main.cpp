//TP 2021/2022: Zadaća 2, Zadatak 1
#include <iostream>
#include <cmath>
#include <limits>
#include <vector>

bool Aktivan=true;
enum class Smjer {Nalijevo, Nadesno};
enum class Pravci {Sjever, Sjeveroistok, Istok, Jugoistok, Jug, Jugozapad, Zapad, Sjeverozapad};
enum class KodoviGresaka {PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};
enum class Komande {Aktiviraj, Deaktiviraj, Nalijevo, Nadesno, Idi, Kraj};


void AktivirajRobota()
{
    Aktivan=true;
}

void DeaktivirajRobota()
{
    Aktivan=false;
}

void Rotiraj(Pravci &orijentacija, Smjer na_koju_stranu)
{
    if(Aktivan==false)
    {
        return; 
    }
    if(na_koju_stranu==Smjer::Nalijevo)
    {
        if(orijentacija==Pravci::Zapad)
        {
            orijentacija=Pravci::Jugozapad;
        }
        else if(orijentacija==Pravci::Jugozapad)
        {
            orijentacija=Pravci::Jug;
        }
        else if(orijentacija==Pravci::Jug)
        {
            orijentacija=Pravci::Jugoistok;
        }
        else if(orijentacija==Pravci::Jugoistok)
        {
            orijentacija=Pravci::Istok;
        }
        else if(orijentacija==Pravci::Istok)
        {
            orijentacija=Pravci::Sjeveroistok;
        }
        else if(orijentacija==Pravci::Sjeveroistok)
        {
            orijentacija=Pravci::Sjever;
        }
        else if(orijentacija==Pravci::Sjever)
        {
            orijentacija=Pravci::Sjeverozapad;
        }
        else if(orijentacija==Pravci::Sjeverozapad)
        {
            orijentacija=Pravci::Zapad;
        }
    }
    if(na_koju_stranu==Smjer::Nadesno)
    {
        if(orijentacija==Pravci::Zapad)
        {
            orijentacija=Pravci::Sjeverozapad;
        }
        else if(orijentacija==Pravci::Jugozapad)
        {
            orijentacija=Pravci::Zapad;
        }
        else if(orijentacija==Pravci::Jug)
        {
            orijentacija=Pravci::Jugozapad;
        }
        else if(orijentacija==Pravci::Jugoistok)
        {
            orijentacija=Pravci::Jug;
        }
        else if(orijentacija==Pravci::Istok)
        {
            orijentacija=Pravci::Jugoistok;
        }
        else if(orijentacija==Pravci::Sjeveroistok)
        {
            orijentacija=Pravci::Istok;
        }
        else if(orijentacija==Pravci::Sjever)
        {
            orijentacija=Pravci::Sjeveroistok;
        }
        else if(orijentacija==Pravci::Sjeverozapad)
        {
            orijentacija=Pravci::Sjever;
        }
    }
}

void Idi(int &x, int &y, Pravci orijentacija, int korak)
{
    if(Aktivan==false)
    {
        return;
    }
    long long int pomocni=korak;
    long long int zbirx=x+pomocni;
    long long int zbiry=y+pomocni;
    long long int razlikax=x-pomocni;
    long long int razlikay=y-pomocni;
    if(orijentacija==Pravci::Sjever)
    {
        if(labs(zbiry)>std::numeric_limits<int>::max())
        {
            if(pomocni<0)
            {
                y=-std::numeric_limits<int>::max();
            }
            else
            {
                y=std::numeric_limits<int>::max();
            }
        }
        else
        {
            y=y+korak;
        }
    }
    else if(orijentacija==Pravci::Sjeveroistok)
    {
        if(labs(zbiry)>std::numeric_limits<int>::max())
        {
            if(pomocni<0)
            {
                y=-std::numeric_limits<int>::max();
            }
            else
            {
                y=std::numeric_limits<int>::max();
            }
        }
        else
        {
            y=y+korak;
        }
        if(labs(zbirx)>std::numeric_limits<int>::max())
        {
            if(pomocni<0)
            {
                x=-std::numeric_limits<int>::max();
            }
            else
            {
                x=std::numeric_limits<int>::max();   
            }
        }
        else
        {
            x=x+korak;
        }
    }
    else if(orijentacija==Pravci::Istok)
    {
        if(labs(zbirx)>std::numeric_limits<int>::max())
        {
            if(pomocni<0)
            {
                x=-std::numeric_limits<int>::max();
            }
            else
            {
                x=std::numeric_limits<int>::max();   
            }
        }
        else
        {
            x=x+korak;
        }
    }
    else if(orijentacija==Pravci::Jugoistok)
    {
        if(labs(zbirx)>std::numeric_limits<int>::max())
        {
            if(pomocni<0)
            {
                x=-std::numeric_limits<int>::max();
            }
            else
            {
                x=std::numeric_limits<int>::max();   
            }
        }
        else
        {
            x=x+korak;
        }
        if(labs(razlikay)>std::numeric_limits<int>::max())
        {
            if(pomocni<0)
            {
                y=std::numeric_limits<int>::max();
            }
            else
            {
                y=-std::numeric_limits<int>::max();
            }
        }
        else
        {
            y=y-korak;
        }        
    }
    else if(orijentacija==Pravci::Jug)
    {
        if(labs(razlikay)>std::numeric_limits<int>::max())
        {
            if(pomocni<0)
            {
                y=std::numeric_limits<int>::max();
            }
            else
            {
                y=-std::numeric_limits<int>::max();
            }
        }
        else
        {
            y=y-korak;
        }
    }
    else if(orijentacija==Pravci::Jugozapad)
    {
        if(labs(razlikay)>std::numeric_limits<int>::max())
        {
            if(pomocni<0)
            {
                y=std::numeric_limits<int>::max();
            }
            else
            {
                y=-std::numeric_limits<int>::max();
            }
        }
        else
        {
            y=y-korak;
        }
        if(labs(razlikax)>std::numeric_limits<int>::max())
        {
            if(pomocni<0)
            {
                x=std::numeric_limits<int>::max(); 
            }
            else
            {
                x=-std::numeric_limits<int>::max();  
            }
        }
        else
        {
            x=x-korak;
        }                
    }
    else if(orijentacija==Pravci::Zapad)
    {
        if(labs(razlikax)>std::numeric_limits<int>::max())
        {
            if(pomocni<0)
            {
                x=std::numeric_limits<int>::max(); 
            }
            else
            {
                x=-std::numeric_limits<int>::max();  
            }
        }
        else
        {
            x=x-korak;
        }
    }
    else if (orijentacija==Pravci::Sjeverozapad)
    {
        if(labs(razlikax)>std::numeric_limits<int>::max())
        {
            if(pomocni<0)
            {
                x=std::numeric_limits<int>::max(); 
            }
            else
            {
                x=-std::numeric_limits<int>::max();  
            }
        }
        else
        {
            x=x-korak;
        }
        if(labs(zbiry)>std::numeric_limits<int>::max())
        {
            if(pomocni<0)
            {
                y=-std::numeric_limits<int>::max();
            }
            else
            {
                y=std::numeric_limits<int>::max();
            }
        }
        else
        {
            y=y+korak;
        }        
    }
}

void IspisiPoziciju(int x, int y, Pravci orijentacija)
{
    std::string orijentacijaX;
    if(orijentacija==Pravci::Sjever)
    {
        orijentacijaX="sjever";
    }
    else if(orijentacija==Pravci::Sjeveroistok)
    {
        orijentacijaX="sjeveroistok";
    }
    else if(orijentacija==Pravci::Istok)
    {
        orijentacijaX="istok";
    }
    else if(orijentacija==Pravci::Jugoistok)
    {
        orijentacijaX="jugoistok";
    }
    else if(orijentacija==Pravci::Jug)
    {
        orijentacijaX="jug";
    }
    else if(orijentacija==Pravci::Jugozapad)
    {
        orijentacijaX="jugozapad";
    }
    else if(orijentacija==Pravci::Zapad)
    {
        orijentacijaX="zapad";
    }
    else if(orijentacija==Pravci::Sjeverozapad)
    {
        orijentacijaX="sjeverozapad";
    }
    if(Aktivan==true)
    {
        std::cout << "Robot je aktivan, nalazi se na poziciji (" << x << "," << y<< ") i gleda na " << orijentacijaX << ".\n";
    }
    if(Aktivan==false)
    {
        std::cout << "Robot je neaktivan, nalazi se na poziciji (" << x << "," << y<< ") i gleda na " << orijentacijaX << ".\n";
    }
}

void PrijaviGresku(KodoviGresaka kod_greske)
{
    if(kod_greske==KodoviGresaka::PogresnaKomanda)
    {
        std::cout << "Nerazumljiva komanda!\n";
    }
    if(kod_greske==KodoviGresaka::NedostajeParametar)
    {
        std::cout << "Komanda trazi parametar koji nije naveden!\n";
    }
    if(kod_greske==KodoviGresaka::NeispravanParametar)
    {
        std::cout << "Parametar komande nije ispravan!\n";
    }
    if(kod_greske==KodoviGresaka::SuvisanParametar)
    {
        std::cout << "Zadan je suvisan parametar nakon komande!\n";
    }    
}

void IzvrsiKomandu(Komande komanda, int parametar, int &x, int &y, Pravci &orijentacija)
{
    if(komanda==Komande::Aktiviraj)
    {
        AktivirajRobota();
    }
    if(komanda==Komande::Kraj)
    {
        std::cout << "Dovidjenja!";
    }
    if(Aktivan==true)
    {
        if(komanda==Komande::Deaktiviraj)
        {
            DeaktivirajRobota();
        }
        if(komanda==Komande::Nalijevo)
        {
            Rotiraj(orijentacija, Smjer::Nalijevo);
        }
        if(komanda==Komande::Nadesno)
        {
            Rotiraj(orijentacija, Smjer::Nadesno);
        }
        if(komanda==Komande::Idi)
        {
            Idi(x, y, orijentacija, parametar);
        }
    }
}

bool UnosKomande(Komande &komanda, int &parametar, KodoviGresaka &kod_greske)
{
    char c;
    while(std::cin.peek()==' ')
    {
        std::cin.get();
    }
    if(std::cin.peek()!='A' && std::cin.peek()!='L' && std::cin.peek()!='D' && std::cin.peek()!='I' && std::cin.peek()!='K' && std::cin.peek()!='\n')
    {
        kod_greske=KodoviGresaka::PogresnaKomanda;
        return false;
    }
    while(std::cin.peek()=='\n')
    {
        std::cin.clear();
        std::cin.ignore(10000,'\n');
    }
    c=std::cin.get();
    if(c=='A')
    {
        if(std::cin.peek()=='\n')
        {
            kod_greske=KodoviGresaka::PogresnaKomanda;
            return false;
        }
        char h;
        h=std::cin.get();
        if(h=='+')
        {
            if(std::cin.peek()!='\n')
            {
                char h;
                h=std::cin.get();
                if(h!=' ')
                {
                    kod_greske=KodoviGresaka::SuvisanParametar;
                    return false;
                }
                while(h==' ')
                {
                    if(std::cin.peek()=='\n')
                    {
                        komanda=Komande::Aktiviraj;
                        return true;
                    }
                    else if(std::cin.peek()!=' ')
                    {
                        kod_greske=KodoviGresaka::SuvisanParametar;
                        return false;
                    }
                    h=std::cin.get();
                }
            }
            komanda=Komande::Aktiviraj;
            return true;
        }
        else if(h=='-')
        {
            if(std::cin.peek()!='\n')
            {
                char h;
                h=std::cin.get();
                if(h!=' ')
                {
                    kod_greske=KodoviGresaka::SuvisanParametar;
                    return false;
                }
                while(h==' ')
                {
                    if(std::cin.peek()=='\n')
                    {
                        komanda=Komande::Deaktiviraj;
                        return true;
                    }
                    else if(std::cin.peek()!=' ')
                    {
                        kod_greske=KodoviGresaka::SuvisanParametar;
                        return false;
                    }
                    h=std::cin.get();
                }
            }
            komanda=Komande::Deaktiviraj;
            return true;
        }
        if(h!='+' && h!='-')
        {
            kod_greske=KodoviGresaka::PogresnaKomanda;
            return false;
        }
    }
    if(c=='L')
    {
        if(std::cin.peek()!='\n')
        {
            char h;
            h=std::cin.get();
            if(h!=' ')
            {
                kod_greske=KodoviGresaka::SuvisanParametar;
                return false;
            }
            while(h==' ')
            {
                if(std::cin.peek()=='\n')
                {
                    komanda=Komande::Nalijevo;
                    return true;
                }
                else if(std::cin.peek()!=' ')
                {
                    kod_greske=KodoviGresaka::SuvisanParametar;
                    return false;
                }
                h=std::cin.get();
            }
        }
        komanda=Komande::Nalijevo;
        return true;
    }
    if(c=='D')
    {
        if(std::cin.peek()!='\n')
        {
            char h;
            h=std::cin.get();
            if(h!=' ')
            {
                kod_greske=KodoviGresaka::SuvisanParametar;
                return false;
            }
            while(h==' ')
            {
                if(std::cin.peek()=='\n')
                {
                    komanda=Komande::Nadesno;
                    return true;
                }
                else if(std::cin.peek()!=' ')
                {
                    kod_greske=KodoviGresaka::SuvisanParametar;
                    return false;
                }
                h=std::cin.get();
            }
        }
        komanda=Komande::Nadesno;
        return true;
    }
    if(c=='I')
    {
        komanda=Komande::Idi;
        int mnozac=1;
        if(std::cin.peek()=='\n')
        {
            kod_greske=KodoviGresaka::NedostajeParametar;
            return false;
        }
        while(std::cin.peek()==' ')
        {
            std::cin.get();
        }
        if(std::cin.peek()!='\n')
        {
            char h;
            h=std::cin.get();
            if(h!=' ' && h!='-' && isdigit(h)!=true)
            {
                kod_greske=KodoviGresaka::NeispravanParametar;
                return false;
            }
            if(h=='-')
            {
                mnozac=-1;
                if(std::cin.peek()=='\n' || isdigit(std::cin.peek())==false)
                {
                    kod_greske=KodoviGresaka::NeispravanParametar;
                    return false;
                }
                h=std::cin.get();
            }
            parametar=(h-'0');
            long long int korak=parametar;
            int brojac=10;
            while(isdigit(std::cin.peek())==true)
            {
                h=std::cin.get();
                korak=(h-'0')+(brojac*korak);
                parametar=korak;
                komanda=Komande::Idi;
            }
            if(std::cin.peek()=='\n')
            {
                if(korak>std::numeric_limits<int>::max())
                {
                    parametar=std::numeric_limits<int>::max();
                }
                parametar=mnozac*parametar;
                return true;
            }
            if(std::cin.peek()!='\n' && std::cin.peek()!=' ')
            {
                kod_greske=KodoviGresaka::NeispravanParametar;
                return false;
            }
            if(std::cin.peek()==' ')
            {
                while(std::cin.peek()==' ')
                {
                    std::cin.get();
                    if(std::cin.peek()=='\n')
                    {
                        if(korak>std::numeric_limits<int>::max())
                        {
                            parametar=std::numeric_limits<int>::max();
                        }   
                        parametar=mnozac*parametar;
                        return true;
                    }
                    if(std::cin.peek()!='\n' && std::cin.peek()!=' ')
                    {
                        kod_greske=KodoviGresaka::NeispravanParametar;
                        return false;
                    }
                }
            }
        }
    }
    if(c=='K')
    {
        if(std::cin.peek()!='\n')
        {
            char h;
            h=std::cin.get();
            if(h!=' ')
            {
                kod_greske=KodoviGresaka::SuvisanParametar;
                return false;
            }
            while(h==' ')
            {
                if(std::cin.peek()=='\n')
                {
                    komanda=Komande::Kraj;
                    return true;
                }
                else if(std::cin.peek()!=' ')
                {
                    kod_greske=KodoviGresaka::SuvisanParametar;
                    return false;
                }
                h=std::cin.get();
            }
        }
        komanda=Komande::Kraj;
        return true;
    }
    return true;
}

int main ()
{
    Komande komanda=Komande::Aktiviraj;
    Pravci orijentacija=Pravci::Sjever;
    int x=0;
    int parametar=0;
    int y=0;
    KodoviGresaka kod_greske=KodoviGresaka::PogresnaKomanda;
    IspisiPoziciju(x, y, orijentacija);
    while(1!=0)
    {
        std::cout << "Unesi komandu: \n";
        if(UnosKomande(komanda, parametar, kod_greske)==true)
        {
            IzvrsiKomandu(komanda, parametar, x, y, orijentacija);
            if(komanda!=Komande::Kraj)
            {
                IspisiPoziciju(x, y, orijentacija);
            }
        }
        else
        {
            PrijaviGresku(kod_greske);
        }
        if (komanda==Komande::Kraj)
        {
            return 0;
        }
            std::cin.clear();
            std::cin.ignore(10000,'\n');
    }
}
