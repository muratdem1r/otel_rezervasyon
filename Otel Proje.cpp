#include <iostream>
using namespace std;

class otel{
	
	string *musteri_adi[100],*soyadi[100];
	int toplam,sayac,sayac2;
	
	enum statu{
		bos,dolu
	}odalar[45];
	
	public:
		otel();
		void oda_isletmesi();
		void oda_rezervasyonu();
		void oda_bosaltma();
		void musterilerin_sayisi();
		void yatak_odasi_raporu();
		void seminer_odasi_raporu();
		void gelir();
	
};

otel::otel(){
	sayac=0;
	sayac2=0;
	toplam=0;
	
	oda_isletmesi();
}

void otel::oda_isletmesi(){
	
	for(int a=1; a<46; a++){
		odalar[a]=bos;
	}
	
	int sayi;
	
	do{
		cout<<endl<<"		---  MURAT OTEL ---"<<endl<<endl;
		cout<<"1.Oda Rezarvasyonu"<<endl;
		cout<<"2.Oda Bosaltma"<<endl;
		cout<<"3.Dolu Oda Sayisi"<<endl;
		cout<<"4.Yatak Odasi Raporu"<<endl;
		cout<<"5.Seminer Odasi Raporu"<<endl;
		cout<<"6.Gunluk Toplam Gelir"<<endl;
		cout<<"7.Cikis Yap.."<<endl;
		cin>>sayi;
		
		switch(sayi){
			
			case 1:
				oda_rezervasyonu();
				break;
			case 2:
				oda_bosaltma();
				break;
			case 3:
				musterilerin_sayisi();
				break;
			case 4:
				yatak_odasi_raporu();
				break;
			case 5:
				seminer_odasi_raporu();
				break;
			case 6:
				gelir();
				break;
			case 7:
				exit(1);
				break;
			default:
				cout<<"Yanlis bir deger girdiniz.. Lutfen tekrar deneyiniz.."<<endl;
			
		}
		
	}while(sayi!=7);
	
}

void otel::oda_rezervasyonu(){
	
	int sayi,x2,i=1,j=6,k=16;
	string ad,o_ad;
	
	cout<<endl<<"-Lutfen bir oda tipi seciniz"<<endl;
	cout<<"1. 1 kisilik oda (40 TL)"<<endl;
	cout<<"2. 2 kisilik oda (60 TL)"<<endl;
	cout<<"3. seminer odasi (300 TL)"<<endl;
	cin>>sayi;
	
	switch(sayi){
		
		case 1:
			for(; j<16 ; j++){
				
				if(odalar[j]!=dolu){
					odalar[j]=dolu;
					cout<<"Adiniz: ";
					cin>>ad;
					cout<<"Soyadiniz:";
					cin>>o_ad;
					cout<<"Kac gun kalacaksiniz? :";
					cin>>x2;
					toplam+=x2*40;
					sayac2++;
					
					musteri_adi[j] = new string;
					*musteri_adi[j] = ad;
					soyadi[j] = new string;
					*soyadi[j]= o_ad;
					break;
				}
			}
				if(j==16)
				cout<<"Maalesef butun 1 kisilik odalar dolu."<<endl;
				break;
		
		case 2:
			for(; k<46 ; k++){
				
				if(odalar[k]!=dolu){
					odalar[k]=dolu;
					cout<<"Adiniz: ";
					cin>>ad;
					cout<<"Soyadiniz:";
					cin>>o_ad;
					cout<<"Kac gun kalacaksiniz? :";
					cin>>x2;
					toplam+=x2*60;
					sayac2++;
					
					musteri_adi[k] = new string;
					*musteri_adi[k] = ad;
					soyadi[k] = new string;
					*soyadi[k]= o_ad;
					break;
				}
			}
				if(k==46)
				cout<<"Maalesef butun 2 kisilik odalar dolu."<<endl;
				break;
		
		case 3:
			for(; i<6 ; i++){
				
				if(odalar[i]!=dolu){
					odalar[i]=dolu;
					cout<<"Adiniz: ";
					cin>>ad;
					cout<<"Soyadiniz:";
					cin>>o_ad;
					cout<<"Kac gun kalacaksiniz? :";
					cin>>x2;
					toplam+=x2*300;
					sayac2++;
					
					musteri_adi[i] = new string;
					*musteri_adi[i] = ad;
					soyadi[i] = new string;
					*soyadi[i]= o_ad;
					break;
				}
			}
				if(i==6)
				cout<<"Maalesef butun seminer odalari dolu."<<endl;
				break;
		
		default:
			cout<<"Lutfen dogru basiniz."<<endl;
	}
}

void otel::oda_bosaltma(){
	
	cout<<"Bosaltacaginiz oda numarasi:";
	int sayi;
	cin>>sayi;
	
	if(odalar[sayi]==dolu){
		if(sayi>0 && sayi<6){
			
			odalar[sayi]=bos;
			delete musteri_adi[sayi];
			delete soyadi[sayi];
			sayac--;
			cout<<"Oda silindi!!"<<endl;
		}
		else if(sayi>5 && sayi<46){
			odalar[sayi]=bos;
			delete musteri_adi[sayi];
			delete soyadi[sayi];
			sayac2--;
			cout<<"Oda silindi!!"<<endl;			
		}
		
	}
	else
	cout<<"Lutfen dogru giris yapiniz.."<<endl;
}

void otel::musterilerin_sayisi(){
	cout<<"Dolu Oda Sayisi: "<<sayac+sayac2<<endl;
	
}

void otel::yatak_odasi_raporu(){
	if (sayac2==0){
		cout<<"Butun odalar bos"<<endl;
	}
	else{
		cout<<"Oda Numarasi	-	Musteri Adi	-	Musteri Soyadi"<<endl;
		cout<<"==============================================="<<endl;
		for(int i=6; i<46; i++){
			if(odalar[i]==dolu){
				cout<<i<<"	"<<*musteri_adi[i]<<"	"<<*soyadi[i]<<endl;
			}
		}
	}
	
}

void otel::seminer_odasi_raporu(){
	
	if(sayac!=6){
		
		for(int i=1; i<6; i++){
			if(odalar[i]==dolu){
				cout<<"Oda numarasi:"<<i<<endl;
			}
		}
	}
	else{
		cout<<"Butun seminer odalari bos"<<endl;
	}
}

void otel::gelir(){
	cout<<"Gelir: "<<toplam;
}


int main (){
	otel a;
	return 0;
}
