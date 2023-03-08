//TP 2018/2019: Tutorijal 4, Zadatak 5
#include <iostream>
#include <vector>
#include <string>

template <typename NekiVektor>
NekiVektor Presjek(NekiVektor v1, NekiVektor v2)
{
    NekiVektor Presjek;
    for(int i=0;i<v1.size();i++)
    {
        for(int j=0;j<v2.size();j++)
        {
            if(v1.at(i)==v2.at(j))
            {
                bool Imaligavec=false;
                for(int g=0;g<Presjek.size();g++)
                {
                    if(v1.at(i)==Presjek.at(g))
                    {
                        Imaligavec=true;
                        break;
                    }
                }
                if(Imaligavec==false)
                {
                    Presjek.push_back(v1.at(i));
                }
            }
        }
    }
    return Presjek;
}


int main ()
{
    std::cout << "Test za realne brojeve...\n";
    std::cout << "Unesite broj elemenata prvog vektora: ";
    int brojelemenatav1;
    std::cin >> brojelemenatav1;
    std::cout << "Unesite elemente prvog vektora: ";
    std::vector<int> v1, v2;
    for(int i=0;i<brojelemenatav1;i++)
    {
        int elementv1;
        std::cin >> elementv1;
        v1.push_back(elementv1);
    }
    std::cout << "Unesite broj elemenata drugog vektora: ";
    int brojelemenatav2;
    std::cin >> brojelemenatav2;
    std::cout << "Unesite elemente drugog vektora: ";
    for(int i=0;i<brojelemenatav2;i++)
    {
        int elementv2;
        std::cin >> elementv2;
        v2.push_back(elementv2);
    }
    std::vector<int> presjek=Presjek(v1,v2);
    std::cout << "Zajednicki elementi su: ";
    for(int i=0;i<presjek.size();i++)
    {
        std::cout << presjek.at(i) << " ";
    }
    
    std::cout << "\n\nTest za stringove...\n";
    std::cout << "Unesite broj elemenata prvog vektora: ";
    int brojelemenatav3;
    std::cin >> brojelemenatav3;
    std::cout << "Unesite elemente prvog vektora (ENTER nakon svakog unosa): ";
    std::vector<std::string> v3, v4;
    for(int i=0;i<brojelemenatav3;i++)
    {
        std::cin >> std::ws;
        std::string elementv3;
        std::getline(std::cin, elementv3);
        v3.push_back(elementv3);
    }
    std::cout << "Unesite broj elemenata drugog vektora: ";
    int brojelemenatav4;
    std::cin >> brojelemenatav4;
    std::cout << "Unesite elemente drugog vektora (ENTER nakon svakog unosa): ";
    for(int i=0;i<brojelemenatav4;i++)
    {
        std::cin >> std::ws;
        std::string elementv4;
        std::getline(std::cin, elementv4);
        v4.push_back(elementv4);
    }
    std::vector<std::string> presjek2=Presjek(v3,v4);
    std::cout << "Zajednicki elementi su: ";
    for(int i=0;i<presjek2.size();i++)
    {
        std::cout << "\n" << presjek2.at(i);
    }
	return 0;
}