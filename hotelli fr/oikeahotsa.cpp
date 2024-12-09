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

int kysy�idenM��r�();
int l�yd�VapaaHuone(vector<bool>huone); 


struct Varaus //varauksen tiedot
{
	string varaajanNimi;
	int varausNumero;
	int huoneNumero;
	int �idenM��r�;
	double summa;
};

int main() 
{
	setlocale(LC_ALL, "fi-FI");
	string varaajanNimi;
	vector<Varaus> varaukset;

	srand(time(NULL));
	int huoneM��r� = rand() % 40 + 30;
	int varausNumero = rand() % 90000 + 10000;

	int k�ytt�j�nVaraamat = 0;
	vector<bool>huoneet(huoneM��r�);
	int hintaPerY� = rand() % 20 + 80;


	cout << "--Hotellinvaraus--" << endl;
	cout << "Hei, ja tervetuloa varaamaan Hotellihuonetta! Mik� on nimesi: ";
	getline(cin, varaajanNimi);

	bool haluatkoLis��Huoneita = true;

	while (haluatkoLis��Huoneita) 
	{
		int huoneNumero = l�yd�VapaaHuone(huoneet);

		huoneet[huoneNumero] = true;

		int �idenM��r� = kysy�idenM��r�();

		double summa = �idenM��r� * hintaPerY�;

		if (summa <= 0 || summa > 10000)
		{
			cout << " ";
			cout << " Ole hyv� ja yrit� uudestaan...";
			system("PAUSE");
			system("cls");
			return 1;
		}


		Varaus uusiVaraus = { varaajanNimi, varausNumero, huoneNumero + 1, �idenM��r�, summa };
		varaukset.push_back(uusiVaraus);

		cout << "Huone " << huoneNumero + 1 << " on nyt varattu. Varauksesi hinta: " << summa << endl;
		cout << "Varauksesi numero on: " << varausNumero << "." << endl;

		char vastaus;
		cout << " " << endl;
		cout << "Haluaisitko varata toisen huoneen? (k/e): ";
		cin >> vastaus;

		if (vastaus == 'e' || vastaus == 'E') 
		{
			haluatkoLis��Huoneita = false;
		}
	}
	
	cout << "Varauksesi tiedot, ole hyv�!" << endl;
	for (const auto& Varaus : varaukset) 
	{
		cout << "Varaajan nimi: " << Varaus.varaajanNimi << endl;
		cout << "Varausnumero: " << Varaus.varausNumero << endl;
		cout << "Huone: " << Varaus.huoneNumero << endl;
		cout << "Y�t: " << Varaus.�idenM��r� << endl;
		cout << "Hinta: " << Varaus.summa <<  " euroa." << endl;

	}
	cout << "Kiitos varauksesta!" << endl;

	return 0;

}

int l�yd�VapaaHuone(vector<bool>huoneet) 
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

int kysy�idenM��r�() 
{
	int �idenM��r�;
	cout << "Montako y�t� tahdot varata: ";
	cin >> �idenM��r�;
	if (cin.fail()) 
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Virheellinen sy�te.";
	}else 
	{
		return �idenM��r�;
	}
	
}
