// Jenny Toivonen, Hotellinvaraus-ohjelma

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <limits>
#include <chrono>

using namespace std;

const int MAX_HUONEET = 10;

int kysyÖidenMäärä();
int löydäVapaaHuone(vector<bool>huone); 


struct Varaus //varauksen tiedot
{
	string varaajanNimi;
	int varausNumero;
	int huoneNumero;
	int öidenMäärä;
	double summa;
};

int main() 
{
	setlocale(LC_ALL, "fi-FI");
	string varaajanNimi;
	vector<Varaus> varaukset;

	srand(time(NULL));
	int huoneMäärä = rand() % 40 + 30;
	int varausNumero = rand() % 90000 + 10000;

	int käyttäjänVaraamat = 0;
	vector<bool>huoneet(huoneMäärä);
	int hintaPerYö = rand() % 20 + 80;


	cout << "--Hotellinvaraus--" << endl;
	cout << "Hei, ja tervetuloa varaamaan Hotellihuonetta! Mikä on nimesi: ";
	getline(cin, varaajanNimi);

	bool haluatkoLisääHuoneita = true;

	while (haluatkoLisääHuoneita) 
	{
		int huoneNumero = löydäVapaaHuone(huoneet);

		huoneet[huoneNumero] = true;

		int öidenMäärä = kysyÖidenMäärä();

		double summa = öidenMäärä * hintaPerYö;

		if (summa <= 0 || summa > 10000)
		{
			cout << " ";
			cout << " Ole hyvä ja yritä uudestaan...";
			system("PAUSE");
			system("cls");
			return 1;
		}


		Varaus uusiVaraus = { varaajanNimi, varausNumero, huoneNumero + 1, öidenMäärä, summa };
		varaukset.push_back(uusiVaraus);

		cout << "Huone " << huoneNumero + 1 << " on nyt varattu. Varauksesi hinta: " << summa << endl;
		cout << "Varauksesi numero on: " << varausNumero << "." << endl;

		char vastaus;
		cout << " " << endl;
		cout << "Haluaisitko varata toisen huoneen? (k/e): ";
		cin >> vastaus;

		if (vastaus == 'e' || vastaus == 'E') 
		{
			haluatkoLisääHuoneita = false;
		}
	}
	
	cout << "Varauksesi tiedot, ole hyvä!" << endl;
	for (const auto& Varaus : varaukset) 
	{
		cout << "Varaajan nimi: " << Varaus.varaajanNimi << endl;
		cout << "Varausnumero: " << Varaus.varausNumero << endl;
		cout << "Huone: " << Varaus.huoneNumero << endl;
		cout << "Yöt: " << Varaus.öidenMäärä << endl;
		cout << "Hinta: " << Varaus.summa <<  " euroa." << endl;

	}
	cout << "Kiitos varauksesta!" << endl;

	return 0;

}

int löydäVapaaHuone(vector<bool>huoneet) 
{
	int vapaaHuone = -1;

	while (vapaaHuone == -1) 
	{
		int random = rand() % (huoneet.size() - 1);
		if (!huoneet[random]) 
		{
			vapaaHuone = random;
		}

	}
	return vapaaHuone;
}

int kysyÖidenMäärä() 
{
	int öidenMäärä;
	cout << "Montako yötä tahdot varata: ";
	cin >> öidenMäärä;
	if (cin.fail()) 
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Virheellinen syöte.";
	}else 
	{
		return öidenMäärä;
	}
	
}
