#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>

void islemYapt�r(int, int);
void kontrol(int, int);
void menu();

int main(){
	setlocale(LC_ALL, "Turkish");
	printf("\t �lk��retim 1. ve 2. S�n�flar ��lemler Program� \n");
	menu();

}
void menu(){
	int seviye, islem;
	printf("\n1. Seviye Tek basamakl� i�lemler.\n2. Seviye iki basamakl� i�lemler.\nL�tfen seviyeyi se�iniz:");
	scanf("%d", &seviye);
	printf("\n1. Toplama\n2. ��karma\n3. �arpma\n4. B�lme\n5. Kar���k i�lemeler\n");
	printf("L�tfen yapmak istedi�iniz i�lemi se�iniz:");
	scanf("%d", &islem);
	printf("\n\n");
	islemYapt�r(seviye, islem);
}

void islemYapt�r(int seviye, int islem){
	srand(time(NULL));
	int sayi1, sayi2, rastgele, sonuc;
	if (seviye == 1){
		sayi1 = rand() % 10;
		sayi2 = rand() % 10;
		switch (islem)
		{
		case 1:
			printf("%d + %d = ", sayi1,sayi2);
			scanf("%d", &sonuc);
			kontrol((sayi1 + sayi2), sonuc);
			break;
		case 2:
			printf("%d - %d = ", sayi1, sayi2);
			scanf("%d", &sonuc);
			kontrol((sayi1 - sayi2), sonuc);
			break;
		case 3:
			printf("%d * %d = ", sayi1, sayi2);
			scanf("%d", &sonuc);
			kontrol((sayi1 * sayi2), sonuc);
			break;
		case 4:
			if (sayi1 > sayi2){
				printf("%d / %d = ", sayi1, sayi2);
				scanf("%d", &sonuc);
				kontrol((sayi1 / sayi2), sonuc);
			}
			else
			{
				printf("%d / %d = ", sayi2, sayi1);
				scanf("%d", &sonuc);
				kontrol((sayi2 / sayi1), sonuc);
			}
			
			break;
		case 5:
			rastgele = 1 + rand() % 4;
			islemYapt�r(seviye, rastgele);
			break;
		}
	}
	else{
		sayi1 = 10 + rand() % 90;
		sayi2 = 10 + rand() % 90;
		switch (islem)
		{
		case 1:
			printf("%d + %d = ", sayi1, sayi2);
			scanf("%d", &sonuc);
			kontrol((sayi1 + sayi2), sonuc);
			break;
		case 2:
			printf("%d - %d = ", sayi1, sayi2);
			scanf("%d", &sonuc);
			kontrol((sayi1 - sayi2), sonuc);
			break;
		case 3:
			printf("%d * %d = ", sayi1, sayi2);
			scanf("%d", &sonuc);
			kontrol((sayi1 * sayi2), sonuc);
			break;
		case 4:
			if (sayi1 > sayi2){
				printf("%d / %d = ", sayi1, sayi2);
				scanf("%d", &sonuc);
				kontrol((sayi1 / sayi2), sonuc);
			}
			else
			{
				printf("%d / %d = ", sayi2, sayi1);
				scanf("%d", &sonuc);
				kontrol((sayi2 / sayi1), sonuc);
			}
			
			break;
		case 5:
			rastgele = 1 + rand() % 4;
			islemYapt�r(seviye, rastgele);
			break;
		}
	}
}

void kontrol(int cevap, int sonuc){
	int tekrar;
	while (cevap != sonuc)
	{
		printf("Yanl�� cevap l�tfen tekrar deneyiniz: ");
		scanf("%d", &sonuc);
	}
	printf("Tebrikler do�ru bildiniz.  Yeniden soru ��zmek istermisin?\n");
	printf("Devam etmek i�in herhangi bir tu�a bas ��kmak i�in -1'e bas.");
	scanf("%d", &tekrar);
	if (tekrar == -1)
		return 0;
	else
		menu();

}