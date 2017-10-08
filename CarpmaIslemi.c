#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<locale.h>
#include<time.h>
#include<stdlib.h>

void yazdir(int);
void degerlendirme(int);

int main(){
	setlocale(LC_ALL, "Turkish");
	srand(time(NULL));
	int sayac=0,dogru=0,yanlis=0;
	int sayi1, sayi2, sonuc;
	do{
		sayi1 = rand() % 10;
		sayi2 = rand() % 10;
		printf("%d kere %d ka�t�r= ",sayi1,sayi2);
		scanf("%d", &sonuc);
		if (sonuc == (sayi1*sayi2)){
			yazdir(1);
			dogru++;
		}
		else
		{
			yazdir(0);
			yanlis++;
		}
		sayac++;
	} while (sayac<10);
	printf("%d tane do�ru %d tane yanl�� yapt�n�z.\n", dogru, yanlis);
	degerlendirme(yanlis);
	system("Pause");
	return 0;
}

void yazdir(int sonuc){
	srand(time(NULL));
	int sayi = rand() % 4;
	if (sonuc == 1){
		switch (sayi)
		{
			case 0:
				printf("�ok g�zel.\n");
				break;
			case 1:
				printf("M�kemmel.\n");
				break;
			case 2:
				printf("Aferin.\n");
				break;
			case 3:
				printf("B�yle devam et.\n");
				break;
		}
	}
	else{
		switch (sayi)
		{
		case 0:
			printf("Hay�r L�tfen Tekrar Deneyin.\n");
			break;
		case 1:
			printf("Yanl��.L�tfen bir daha deneyin.\n");
			break;
		case 2:
			printf("Pes etmein.\n");
			break;
		case 3:
			printf("Hay�r.Denemeye devam.\n");
			break;
		}

	}

}

void degerlendirme(int yanlis){
	if (yanlis > 2)
		printf("��retmeninden yard�m al\n");
}