#include<iostream>
#include <map>
#include<list>

using namespace std;
class Aliment {
	string nume;
	float pret;
public:
	Aliment() {
		this->nume = " Aliment";
		this->pret = 0;

	}
	Aliment( string nume, string pret){
		this->nume = nume;
		this->pret = pret;

	}
	void afisareDescriere() {
		cout << nume <<"=>" << pret;
	}
};
int main()
{
	map< string, float> preturi;

	preturi.insert(pair<string, float>("Lapte", 23));
	preturi.insert(pair<string, float>("paine", 7));
	preturi.insert(pair<string, float>("oua", 16));
	preturi.insert(pair<string, float>("Lapte", 35));

	preturi[" Lapte"] = 67;
	map<string, float> ::iterator it;
	it = preturi.begin();
	int suma = 0;
	while (it != preturi.end()) {
		suma += it->second;
		it++;
		cout << "suma:" << suma << endl;
	}
	it = preturi.begin();
	while (it != preturi.end())\
	{
		cout << it->first << "=>" << it->second << endl;
		it++;
	}
	list<Aliment> alimente; 
	alimente.push_back(Aliment());
	alimente.push_back(Aliment("lapte", 20));
	alimente.push_front(Aliment("paine", 10));
	alimente.push_front(Aliment("oua", 16));
	cout << endl << "lista:" << endl;
   list< Aliment > ::iterator iter = alimente.begin();
   while (iter != alimente.end()) {
	   iter->afisareDescriere();
	   iter++;
   }
	return 1;


}
