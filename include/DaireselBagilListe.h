/**        
* @file  DaireselBagilListe.h 
* @description Çift yönlü dairesel bağıl listenin class'ı ve tanımlanmış elemanları.  
* @course  1.Öğretim A Grubu  
* @assignment  2.Ödev   
* @date  27.11.2018 
* @author  Burak Bayram E-posta: burakbyrm99@gmail.com  */ 
class DaireselBagilListe
{
private:
	Dugum *pSimdiki = new Dugum();
	int elemanSayisi;
public:
	DaireselBagilListe();
	bool isEmpty();
	int Length();
	void Ekle(int veri);
	void SagaHareketEt();
	void SolaHareketEt();
	void DurumYaz(int konum);
	void TumDurumlariYaz();
	void DugumleriveStackleriSil();
	~DaireselBagilListe();
};
