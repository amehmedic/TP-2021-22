/* 
    TP 16/17 (Tutorijal 12, Zadatak 2)
	Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: khodzic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <utility>

template <typename Tip> 
std::set<Tip> operator +(const std::set<Tip> &s1, const std::set<Tip> &s2) {
	std::set<Tip> s3;
	for(Tip x: s1) {
		s3.insert(x);
	}
	for(Tip x: s2) {
		s3.insert(x);
	}
	return s3;
}

template <typename Tip>
std::set<Tip> &operator +=(std::set<Tip> &s1, const std::set<Tip> &s2) {
	std::set<Tip> s3;
	for(Tip x: s1) {
		s3.insert(x);
	}
	for(Tip x: s2) {
		s3.insert(x);
	}
	s1=s3;
	return s1;
}

template <typename Tip>
std::set<Tip> operator *(const std::set<Tip> &s1, const std::set<Tip> &s2) {
	std::set<Tip> s3;
	for(Tip x: s1) {
		for(Tip y: s2) {
			if(x==y) {
				s3.insert(x);
			}
		}
	}
	return s3;
}

template <typename Tip>
std::set<Tip> operator *=(std::set<Tip> &s1, const std::set<Tip> &s2) {
	std::set<Tip> s3;
	for(Tip x: s1) {
		for(Tip y: s2) {
			if(x==y) { 
				s3.insert(x);
			}
		}
	}
	s1=s3;
	return s1;
}

template <typename Tip>
std::ostream &operator <<(std::ostream &tok, const std::set<Tip> &s) {
	//auto a=max_element(std::begin(s),std::end(s));
	std::vector<Tip> v;
	tok <<"{";
	for(auto x: s) { v.push_back(x); }
	for(int i=0; i<v.size(); i++) {
		if(i<v.size()-1) { tok << v.at(i)<<","; }
		else { tok<<v.at(i); }
	}
	tok <<"}";
	return tok;
}

template <typename Tip1, typename Tip2>
std::set<std::pair<Tip1,Tip2>> operator %(const std::set<Tip1> &s1, const std::set<Tip2> &s2) {
	std::set<std::pair<Tip1,Tip2>> v;
	for(auto x: s1) {
		for(auto y: s2) {
			std::pair<Tip1,Tip2> p=std::make_pair(x,y);
			v.insert(p);
		}
	}
	return v;
}


template <typename Tip1, typename Tip2>
std::ostream &operator <<(std::ostream &tok, const std::pair<Tip1,Tip2> &p) {
	tok <<"("<<p.first<<","<<p.second<<")";
	return tok;	
}
int main ()
{
	std::set<int> s1{3,5,1,2,8};
	std::set<int> s2{7,2,8,4};
	std::cout<< s1%s2<<"\n";	
	return 0;
}