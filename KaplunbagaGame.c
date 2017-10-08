#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

#define BOYUT 50
void hareketEt(int[][BOYUT],int,int,int,int);
void yazdir(const int[][BOYUT]);
int konumX = 0, konumY = 0;
int main(){
	setlocale(LC_ALL, "Turkish");
	float secim;
	int yer[BOYUT][BOYUT] = { 0 };
	int kontrol=0,sag=0,sol=0,yurume;
	printf("\t\tKAPLUNBA�A S�M�LASYON OYUNUNA HO�GELD�N�Z\n");
	printf("%s %20s\n", "Emir", "Anlam�");
	printf("%4s %23s\n", "1", "Kalem Yukar�");
	printf("%4s %22s\n", "2", "Kalem A�a��");
	printf("%4s %19s\n", "3", "Sa�a D�n");
	printf("%4s %19s\n", "4", "Sola D�n"); 
	printf("%4s %47s\n", "5,10", "�leri 10 Ad�m At(ya da 10'dan b�y�k)");
	printf("%4s %17s\n", "6", "Yazd�r");
	printf("%4s %28s\n", "7", "Similasyonun Sonu");
	printf("\nHareket alan� 50*50 d�r. Ba�lang�� noktas� 0,0 noktas�d�r.\n\n");
	do
	{
		printf("Se�iminiz: ");
		scanf("%f",&secim);
		if (secim == 1)
			kontrol = 0;
		else if (secim == 2)
			kontrol = 1;
		else if (secim == 3)
			sag++;
		else if (secim == 4)
			sol++;
		else if (secim == 7)
			exit(1);
		else if (secim == 6)
			yazdir(yer);
		else{
			secim = 1 - (secim - 5);
			yurume = 100 - (secim * 100);
			hareketEt(yer,yurume,kontrol,sag,sol);
		}
			
	} while (1);
}

void hareketEt(int yer[][BOYUT],int komut,int kontrol,int sag,int sol){
	sag = sag % 4;
	sol = sol % 4;
	printf("sag=%d   sol=%d   konumX=%d   konumY=%d\n", sag, sol, konumX, konumY);
	if (kontrol == 1){
		if (sol == 0 && sag == 0 || sol == 1 && sag == 1 || sol == 2 && sag == 2 || sol == 3 && sag == 3){
			for (int i = 0; i <= komut; i++){
				yer[konumX++][konumY] = 1;
			}
		}
		else if (sol == 0 && sag == 1 || sol == 1 && sag == 2 || sol == 2 && sag == 3 || sol == 3 && sag == 0){
			for (int i = 0; i <= komut; i++){
				yer[konumX][konumY++] = 1;
			}

		}
		else if (sol == 0 && sag == 2 || sol == 1 && sag == 3 || sol == 2 && sag == 0 || sol == 3 && sag == 1){
			for (int i = 0; i <= komut; i++){
				yer[konumX--][konumY] = 1;
			}

		}
		else if (sol == 0 && sag == 3 || sol == 1 && sag == 0 || sol == 2 && sag == 1 || sol == 3 && sag == 2){
			for (int i = 0; i <= komut; i++){
				yer[konumX][konumY--] = 1;
			}
		}
	}

	else{
		if (sol == 0 && sag == 0 || sol == 1 && sag == 1 || sol == 2 && sag == 2 || sol == 3 && sag == 3){
			for (int i = 0; i <= komut; i++){
				yer[konumX][konumY++] = 0;
			}
		}
		else if (sol == 0 && sag == 1 || sol == 1 && sag == 2 || sol == 2 && sag == 3 || sol == 3 && sag == 0){
			for (int i = 0; i <= komut; i++){
				yer[konumX++][konumY] = 0;
			}

		}
		else if (sol == 0 && sag == 2 || sol == 1 && sag == 3 || sol == 2 && sag == 0 || sol == 3 && sag == 1){
			for (int i = 0; i <= komut; i++){
				yer[konumX][konumY--] = 0;
			}

		}
		else if (sol == 0 && sag == 3 || sol == 1 && sag == 0 || sol == 2 && sag == 1 || sol == 3 && sag == 2){
			for (int i = 0; i <= komut; i++){
				yer[konumX--][konumY] = 0;
			}
		}
	}
}

void yazdir(const int dizi[][BOYUT]){
	for (int i = 0; i < BOYUT; i++){
		for (int j = 0; j < BOYUT; j++){
			if (dizi[i][j] == 1)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}