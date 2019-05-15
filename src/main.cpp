/**        
* @file  main.cpp
* @description Dosya okuma ve menü işlemleri yapılır. 
* @course  1.Öğretim A Grubu  
* @assignment  2.Ödev   
* @date  27.11.2018 
* @author  Burak Bayram E-posta: burakbyrm99@gmail.com  */ 
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include "DaireselBagilListe.cpp"
using namespace std;

int a = 0;
int DosyadanElemanSayisiDondur()
{
	string satir;
	ifstream dosyaOku;
	dosyaOku.open("Sayi.txt", ios::in);
	while (getline(dosyaOku, satir))
	{
		for (int i = 0; i < satir.length(); i++)
		{
			if (isdigit(satir[i])) {
				while (isdigit(satir[i])) {
					i++;
				}
				i--;
				a++;
			}
		}
		if (dosyaOku.eof())	break;
		dosyaOku.close();
	}
	return a;
}

int *sayi = new int[DosyadanElemanSayisiDondur()];

void DosyaOku()
{
	a = 0;
	int tempSayi;
	string satir;
	ifstream dosyaOku;
	dosyaOku.open("Sayi.txt", ios::in);

	while (getline(dosyaOku, satir))
	{
		for (int i = 0; i < satir.length(); i++)
		{
			string tempSatir;
			if (isdigit(satir[i])) {
				while (isdigit(satir[i])) {
					tempSatir += satir[i];
					i++;
				}
				i--;
				tempSayi = stoi(tempSatir);
				sayi[a] = tempSayi;
				a++;
			}
		}
		if (dosyaOku.eof())	break;
		dosyaOku.close();
	}
}

int main()
{
	DosyaOku();
	
	DaireselBagilListe *liste = new DaireselBagilListe();
	int sec;
	int sayi1;
	
	for (int i = 0; i < a; i++)
	{
		liste->Ekle(sayi[i]);
	}
	
	do{
		system("cls");
		cout << "1-Sola Hareket" << endl;
		cout << "2-Saga Hareket" << endl;
		cout << "3-Bir Dugumun Durumlarini Yaz" << endl;
		cout << "4-Tum Durumlari Yaz" << endl;
		cout << "5-Cikis" << endl;
		cout << "=> ";
		cin >> sec;

		if(sec == 1) liste->SolaHareketEt();
		else if(sec == 2) liste->SagaHareketEt();
		else if(sec == 3)
		{
			cout << "Dugum indeksi giriniz: ";
			cin >> sayi1;
			liste->DurumYaz(sayi1);
			system("pause");
		}
		else if(sec == 4)
		{
			liste->TumDurumlariYaz();
			system("pause");
		}
		else if(sec == 5)break;
	}while(sec!=5);
	
	delete liste;
	return 0;
}



