#include<stdio.h>
#include<locale.h>
#define BOY 100
void simple(int [],int [],int);

int main(){
	setlocale(LC_ALL,"Turkish");
	int hafiza[BOY]={0},komutlar[BOY],komutSayici=0;
	printf("\t***Simletrona Hosgeldiniz!***\n\t\t***L�tfen her seferinde bir komut ya da***\n");
	printf("\t***(bir word veri) giriniz.Haf�za konumuna***\n");
	printf("\t\t***ve soru i�aretini(?) ekrana yazdiraca��m.***\n\tSiz daha sonra o konum i�in word'� girin ***\n");
	printf("***Program�n�z� girmeyi sonland�rmak i�in -99999***\n");
	do{
		
		printf("%d ? ",komutSayici);
		scanf("%d",&komutlar[komutSayici]);
		
	}
	while(komutlar[komutSayici++] != -99999);{
		printf("***Program y�klemesi bitti***\n***Program �al��t�r�l�yor***\n");
		simple(hafiza,komutlar,komutSayici);
	}
	
}

void simple(int wHafiza[],int wKomutlar[],int komSayici){
	void GC(int [],int,int);
	void YS(int [],int *,int,int);
	void aritmetik(int [],int *,int,int);
//	void kontrol(int *,int *,int);
	int isletimKodu,operand,komutRegister,*akumulator,i;
	for(i=0;i<komSayici;i++){
		isletimKodu=wKomutlar[i]/100;
		operand=wKomutlar[i]%100;
		if(isletimKodu==10 || isletimKodu==11)
			GC(wHafiza,isletimKodu,operand);
		else if(isletimKodu==20 || isletimKodu==21)
			YS(wHafiza,&akumulator,isletimKodu,operand);
		else if(isletimKodu==31 || isletimKodu==32 || isletimKodu==33 || isletimKodu==30)
			aritmetik(wHafiza,&akumulator,isletimKodu,operand);
	
	}
}

void GC(int aHafiza[],int kod,int ope){
	if(kod==10)
		scanf("%d",&aHafiza[ope]);
	else
		printf("%d\n",aHafiza[ope]);
}

void YS(int yHafiza[],int *akuptr,int kod,int ope){
	if(kod==20)
		*akuptr=yHafiza[ope];
	else
		yHafiza[ope]=*akuptr;
}

void aritmetik(int aHafiza[],int *akuptr,int kod,int ope){
	if(kod==30)
		*akuptr+=aHafiza[ope];
	else if(kod==31)
		*akuptr-=aHafiza[ope];
	else if(kod==32){
		if(aHafiza[ope]==0)
			printf("S�f�ra b�lmeye �al���ld�.");
		else
			*akuptr=*akuptr/aHafiza[ope];
	}
	else
		*akuptr*=aHafiza[ope];

}

