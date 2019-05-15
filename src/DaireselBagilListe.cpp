/**        
* @file  DaireselBagilListe.cpp
* @description DaireselBagilListe class'ının içindeki tanımlanmış fonksiyonların gövdeleri. 
* @course  1.Öğretim A Grubu  
* @assignment  2.Ödev   
* @date  27.11.2018 
* @author  Burak Bayram E-posta: burakbyrm99@gmail.com  */ 
#include "Dugum.cpp"
#include "DaireselBagilListe.h"

DaireselBagilListe::DaireselBagilListe()
{
	elemanSayisi=0;
}

bool DaireselBagilListe::isEmpty()
{
	return elemanSayisi == 0;
}
int DaireselBagilListe::Length()
{
	return elemanSayisi;
}
void DaireselBagilListe::Ekle(int veri)
{
	Dugum *yeniDugum = new Dugum();
	Dugum *temp = pSimdiki;
	int yedekSayi;
	
	for (yedekSayi = elemanSayisi;yedekSayi>0;yedekSayi--)
		temp = temp->next;

	temp->next = yeniDugum;
	pSimdiki->prev=yeniDugum;
	yeniDugum->next = pSimdiki;
	yeniDugum->prev = temp;		
	yeniDugum->stack = new Stack();
	yeniDugum->stack->push(veri);

	elemanSayisi++;
}
void DaireselBagilListe::SagaHareketEt()
{
	Dugum *temp = pSimdiki;
	Dugum *temp2 = pSimdiki;

	for (int yedekSayi = elemanSayisi;yedekSayi>1;yedekSayi--)
	{
		temp->next->stack->push(temp->next->next->stack->top());
		temp = temp->next;
	}
	
	int tempSayi = temp2->next->stack->top();
	temp2->next->stack->pop();
	temp->next->stack->push(temp2->next->stack->top());
	temp2->next->stack->push(tempSayi);	
}
void DaireselBagilListe::SolaHareketEt()
{
	Dugum *temp = pSimdiki;
	Dugum *temp2 = pSimdiki;
	
	for (int yedekSayi = elemanSayisi;yedekSayi>1;yedekSayi--)
	{
		temp->prev->stack->push(temp->prev->prev->stack->top());
		temp = temp->prev;
	}
	
	int tempSayi = temp2->prev->stack->top();
	temp2->prev->stack->pop();
	temp->prev->stack->push(temp2->prev->stack->top());
	temp2->prev->stack->push(tempSayi);
}
void DaireselBagilListe::DurumYaz(int konum)
{
	Dugum *temp = pSimdiki;
	Dugum* temp1 = pSimdiki;

	int sayac;
	for (sayac = 0;sayac != konum;sayac++)
	{
		temp = temp->next;
	}
	Stack *StackTemp = new Stack();

	int indeks;
	for (indeks = 0;temp1 != NULL && konum != indeks;indeks++)
	{
		temp1 = temp1->next;
	}
	cout << temp->stack->top() << "	:	";
	while (!temp->stack->isEmpty())
	{
		cout << temp->stack->top() << "	";
		StackTemp->push(temp->stack->top());
		temp->stack->pop();
	}
	while (!StackTemp->isEmpty())
	{
		temp->stack->push(StackTemp->top());
		StackTemp->pop();
	}
	cout << endl;
}
void DaireselBagilListe::TumDurumlariYaz()
{
	for (int i = 1; i < elemanSayisi+1; i++)
	{
		Dugum *temp = pSimdiki;
		Dugum *temp1 = pSimdiki;

		int sayac;
		for (sayac = 0;sayac != i;sayac++)
		{
			temp = temp->next;
		}
		Stack *StackTemp = new Stack();

		int indeks;
		for (indeks = 0;temp1 != NULL && i != indeks;indeks++)
		{
			temp1 = temp1->next;
		}		
		
		cout << temp1->stack->top() << "	:	";
		while (!temp->stack->isEmpty())
		{
			cout << temp->stack->top() << "	";
			StackTemp->push(temp->stack->top());
			temp->stack->pop();
		}
		while (!StackTemp->isEmpty())
		{
			temp->stack->push(StackTemp->top());
			StackTemp->pop();
		}
		cout << endl;
		delete StackTemp;
	}
	
}
void DaireselBagilListe::DugumleriveStackleriSil()
{
	Dugum *sil = pSimdiki;
	int yedekSayi;
	for (yedekSayi = elemanSayisi;yedekSayi>1;yedekSayi--)
	{
		delete sil->prev->stack;
		delete sil->prev;
		sil = sil->next;
	}
}
DaireselBagilListe::~DaireselBagilListe()
{
	DugumleriveStackleriSil();
	delete pSimdiki;
}

