#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<locale.h>
#include<ctype.h>
#define BOYUT 10
void menu(int []);
void rezervasyon(int,int []);
int kontrol(int, int[]);
int main(){
	setlocale(LC_ALL, "Turkish");
	printf("\t\tDUDE HAVA YOLLARI ��RKET�NE HO�GELD�N�Z.\n");
	int koltuk[BOYUT] = { 0 };
	menu(koltuk);
}
void menu(int dizi[]){
	int  durum;
	printf("\nSigara i�ilen b�l�mden rezervasyon yapmak i�in 1'e bas�n�z.\n");
	printf("Sigara i�ilmeyen b�l�mden rezervasyon yapmak i�in 2'ye bas�n�z. ");
	scanf("%d", &durum);
	rezervasyon(durum,dizi);
}

void rezervasyon(int durum,int koltuk[]){
	int kont = kontrol(durum, koltuk);
	if (kont == -1){
		char karakter;
		if (durum == 1){
			printf("Sigaral� b�l�mde bo� yerimiz kalmam��. Sigars�z b�l�mden bilet almak ister misiniz.(E/H)");
			karakter = getch();
			if (karakter == 'H' || karakter == 'h')
				printf("B�r sonraki u�u� 3 saat sonra. �yi g�nler dileriz.");
			else if (karakter == 'E' || karakter == 'e')
				menu(koltuk);
		}
		else{
			printf("Sigaras�z b�l�mde bo� yerimiz kalmam��. Sigaral� b�l�mden bilet almak ister misiniz.(E/H)");
			karakter = getch();
			if (karakter == 'H' || karakter == 'h')
				printf("B�r sonraki u�u� 3 saat sonra. �yi g�nler dileriz.\n");
			else if (karakter == 'E' || karakter == 'e')
				menu(koltuk);

		}
		
	}
	else
		{
			koltuk[kont] = 1;
			if (durum == 1){
				printf("Sigaral� b�l�mden %d nolu koltu�u rezervasyon yapt�n�z.\n", kont+1);
			}
			else
			{
				printf("Sigaras�z b�l�mden %d nolu koltu�u rezervasyon yapt�n�z.\n", kont + 1);
			}
			menu(koltuk);
		}

}
int kontrol(int durum, int koltuk[]){
	if (durum == 1){
		int i = 0;
		while (koltuk[i] != 0 && i<BOYUT){
			i++;
		}
		if (i < BOYUT/2)
			return i;
		else
			return -1;
	}
	else{
		int j = BOYUT-1;
		while (koltuk[j] != 0 && j > BOYUT/3){
			j--;
		}
		if (j >= BOYUT/2)
			return j;
		else
			return -1;
	}
}


