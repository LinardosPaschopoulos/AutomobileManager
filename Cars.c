#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>
#define size 100 //should be greater than the number of cars
#define numb_xrom 13 //the number of colors
#define numb_comp 67 //the number of companies

typedef struct
{
int pinakida,etos;
char xroma[32],marka[32];
}
oximata;

void my_print(oximata *Car,int i)
{
if(strlen(Car[i].marka)<8)
printf("%d		%s		%s			%d\n",Car[i].pinakida,Car[i].xroma,Car[i].marka,Car[i].etos);
	else if(strlen(Car[i].marka)<16)
	printf("%d		%s		%s		%d\n",Car[i].pinakida,Car[i].xroma,Car[i].marka,Car[i].etos);
		else
		printf("%d		%s		%s	%d\n",Car[i].pinakida,Car[i].xroma,Car[i].marka,Car[i].etos);

}

void arithmos(oximata *Car,int noc) //auti i sinartisi kaleitai otan o xristis kanei anazitisi vasi arithmou
{
int arithmos,i;
char anisotita;
FILE *fle;

printf("Sign\n________\n\n");
printf("Please enter the number of sign: ");
scanf("%d",&arithmos);
getchar();
if(arithmos<1001||arithmos>9999)
	while(arithmos<1001||arithmos>9999)
		{
		system("cls");
		printf("Sign\n________\n\n");
		Beep(550,650);
		system("pause");
		printf("Please enter the number of sign.\nShould be between 9.999 and 1.001: ");
		scanf("%d",&arithmos);
		getchar();
		}
system("cls");
printf("Sign\n________\n\n");
printf("Please select '<' to display cars\nwith sign smaller than the chosen or '>' to display\nthe listings with sign greater than the chosen: ");
scanf("%c",&anisotita);
getchar();
if(anisotita!='<'&&anisotita!='>')
	while(anisotita!='<'&&anisotita!='>')
		{
		system("cls");
		printf("Sign\n________\n\n");
		Beep(550,650);
		system("pause");
		printf("Please select '<' to display cars\nwith sign smaller than the chosen or '>' to display\nthe listings with sign greater than the chosen: ");
		scanf("%c",&anisotita);
		getchar();
		}
system("cls");
fle=fopen("Cars.txt","r");
printf("SIGN	COLOR		MANUFACTURER			YEAR\n____________________________________________________________\n");
for(i=0;i<noc;i++)
	{
	if(i%5==0)
		printf("\n");
	fscanf(fle,"%d %s %s %d",&Car[i].pinakida,Car[i].xroma,Car[i].marka,&Car[i].etos);
	if(anisotita=='>')
		if(Car[i].pinakida>=arithmos)
			my_print(Car,i);
	if(anisotita=='<')
		if(Car[i].pinakida<=arithmos)
			my_print(Car,i);
	}
printf("\n\n");
fclose(fle);
}

void xroma(oximata *Car,int *noc)
{
char A[32],Color[numb_xrom][32];
int i,j;
FILE *fle;

printf("Search based on color\n__________________________\n\n");
fle=fopen("BasicColors.txt","r");
for(i=0;i<numb_xrom;i++)
	{
	fscanf(fle,"%s",Color[i]);
	}
for(i=0;i<numb_xrom;i++)
	{
	for(j=0;j<*noc;j++)
		if(strcmp(Color[i],Car[j].xroma)==0)
			{
			printf("%s\n",Color[i]);
			break;
			}
	}
fclose(fle);
printf("\nPlease select the color: ");
scanf("%s",A);
getchar();
for(i=0;i<strlen(A);i++)
	A[i]=toupper(A[i]);
system("cls");
fle=fopen("Cars.txt","r");
printf("\n\nSIGN	COLOR		MANUFACTURER			YEAR\n____________________________________________________________\n");
for(i=0;i<*noc;i++)
	{
	if(i%5==0)
		printf("\n");
	if(strncmp(Car[i].xroma,A,strlen(A))==0)//sigkrino ton arithmo (strlen(A)) ton xaraktiron tou string pou edose o pelatis
		my_print(Car,i);
	}
printf("\n\n");
fclose(fle);
}

void kataskeuastis(oximata *Car,int *noc) //auti i sinartisi kaleitai otan o xristis kanei anazitisi vasi kataskeuasti
{
char A[32],Company[numb_comp][32];
int i,j;
FILE *fle;

printf("Search based on manufacturer\n_________________________________\n\n");
fle=fopen("Companies.txt","r");
for(i=0;i<numb_comp;i++)
	{
	fscanf(fle,"%s",Company[i]);
	}
for(i=0;i<numb_comp;i++)
	{
	for(j=0;j<*noc;j++)
		if(strcmp(Company[i],Car[j].marka)==0)
			{
			printf("%s\n",Company[i]);
			break;
			}
	}
fclose(fle);
printf("\nPlease select manufacturer: ");
scanf("%s",toupper(A));
getchar();
for(i=0;i<strlen(A);i++)
	A[i]=toupper(A[i]);
fle=fopen("Cars.txt","r");
system("cls");
printf("\n\nSIGN	COLOR		MANUFACTURER			YEAR\n____________________________________________________________\n");
for(i=0;i<*noc;i++)
	{
	if(i%5==0)
		printf("\n");
	if(strncmp(Car[i].marka,A,strlen(A))==0)
		my_print(Car,i);
	}
printf("\n\n");
fclose(fle);
}

void etos(oximata *Car,int *noc) //auti i sinartisi kaleitai otan o xristis kanei anazitisi vasi etous kataskeuis
{
int etos,i;
char anisotita;
FILE *fle;

printf("Year of manufacture\n_______________\n\n");
printf("Please enter manufacture year: ");
scanf("%d",&etos);
getchar();
if(etos<1960||etos>2019)
	while(etos<1960||etos>2019)
		{
		system("cls");
		printf("Manufacture year\n_______________\n\n");
		Beep(550,650);
		system("pause");
		printf("Please enter manufacture year.\nIt should be between 2019 and 1960: ");
		scanf("%d",&etos);
		getchar();
		}
system("cls");
printf("Year of manufacture\n_______________\n\n");
printf("Please enter '<' to display cars\nmanufactured before the chosen date or '>' to display cars manufactured after the chosen date: ");
scanf("%c",&anisotita);
getchar();
if(anisotita!='<'&&anisotita!='>')
	while(anisotita!='<'&&anisotita!='>')
		{
		system("cls");
		printf("Manufacture year\n_______________\n\n");
		Beep(550,650);
		system("pause");
		printf("Please enter '<' to display cars\nmanufactured before the chosen date or '>' to display cars manufactured after the chosen date: ");
		scanf("%c",&anisotita);
		getchar();
		}
system("cls");
fle=fopen("Cars.txt","r");
printf("\n\nSIGN	COLOR		MANUFACTURER			YEAR\n____________________________________________________________\n");
for(i=0;i<*noc;i++)
	{
	if(i%5==0)
		printf("\n");
	fscanf(fle,"%d %s %s %d",&Car[i].pinakida,Car[i].xroma,Car[i].marka,&Car[i].etos);
	if(anisotita=='>')
		if(Car[i].etos>=etos)
			my_print(Car,i);
	if(anisotita=='<')
		if(Car[i].etos<=etos)
			my_print(Car,i);
	}
printf("\n\n");
fclose(fle);
}

void emfanisi(oximata *Car,int *noc) //auti i sinartisi kaleitai otan o xristis epileksei emfanisi olon ton kataxoriseon
{
int i;
FILE *fle;

printf("Show all cars\n_____________\n\n");
fle=fopen("Cars.txt","r");
printf("\n\nSIGN	COLOR		MANUFACTURER			YEAR\n____________________________________________________________\n");
for(i=0;i<*noc;i++)
	{
	if(i%5==0)
	printf("\n");
	fscanf(fle,"%d %s %s %d",&Car[i].pinakida,Car[i].xroma,Car[i].marka,&Car[i].etos);
	my_print(Car,i);
	}
printf("\n\n");
fclose(fle);

system("pause");
}

void eisagogi(oximata *Car,oximata *Change,int *noc,int *flag) //auti i sinartisi kaleitai otan o xristis epileksei na eisagei mia nea kataxorisi
{
int i=0,j,Etos,Arithmos;
char Company[numb_comp][32],Color[numb_xrom][32];
oximata Neo;
FILE *fle;

printf("New entry\n______________________\n\nDose ton arithmo pinakidas. Prepei na einai metaksi 1001 kai 9999 kai fisika na min anikei idi se allo autokinito: ");
fle=fopen("Cars.txt","r");
scanf("%d",&Neo.pinakida);
for(i=0;i<*noc;i++)
	{
	if(Neo.pinakida<1001||Neo.pinakida>9999||Neo.pinakida==Car[i].pinakida)
		{
		system("cls");
		printf("Eisagogi neas eggrafis\n______________________\n\nMI EGKIRI EPILOGI!\nParakalo dokimaste ksana.\n\nDose ton arithmo pinakidas. Prepei na einai metaksi 1001 kai 9999 kai fisika na min anikei idi se allo autokinito: ");
		Beep(550,650);
		scanf("%d",&Neo.pinakida);
		i=0;
		}
	}
fclose(fle);
fle=fopen("Companies.txt","r");
system("cls");
printf("Eisagogi neas eggrafis\n______________________\n\n");
for(i=0;i<numb_comp;i++)
	{
	fscanf(fle,"%s",Company[i]);
	printf("\n%s",Company[i]);
	}
printf("\nEpelekse mia apo tis parapano etaireies: ");
scanf("%s",Neo.marka);
for(i=0;i<strlen(Neo.marka);i++)
	Neo.marka[i]=toupper(Neo.marka[i]);
for(i=0;i<numb_comp;i++)
	{
	if(strcmp(Neo.marka,Company[i])==0)
		break;
	if(i==numb_comp-1)
		{
		system("cls");
		Beep(550,650);
		i=0;
		printf("Eisagogi neas eggrafis\n______________________\n\n");
		for(j=0;j<numb_comp;j++)
			{
			fscanf(fle,"%s",Company[j]);
			printf("\n%s",Company[j]);
			}
		printf("\nDEN IPARXEI AUTI I ETAIREIA!\nEpelekse mia apo tis parapano etaireies: ");
		scanf("%s",Neo.marka);
		for(j=0;j<strlen(Neo.marka);j++)
			Neo.marka[j]=toupper(Neo.marka[j]);
		}
	}
fclose(fle);
fle=fopen("BasicColors.txt","r");
system("cls");
printf("Eisagogi neas eggrafis\n______________________\n\n");
for(i=0;i<numb_xrom;i++)
	{
	fscanf(fle,"%s",Color[i]);
	printf("\n%s",Color[i]);
	}
printf("\n\nEpelekse ena apo ta parapano xromata: ");
scanf("%s",Neo.xroma);
for(i=0;i<strlen(Neo.xroma);i++)
	Neo.xroma[i]=toupper(Neo.xroma[i]);
for(i=0;i<numb_xrom;i++)
	{
	if(strcmp(Neo.xroma,Color[i])==0)
		break;
	if(i==numb_xrom-1)
		{
		system("cls");
		Beep(550,650);
		i=0;
		printf("Eisagogi neas eggrafis\n______________________\n\n");
		for(j=0;j<numb_xrom;j++)
			{
			fscanf(fle,"%s",Color[j]);
			printf("\n%s",Color[j]);
			}
		printf("\n\n\nDEN IPARXEI AUTO TO XROMA!\nEpelekse ena apo ta parapano xromata: ");
		scanf("%s",Neo.xroma);
		for(j=0;j<strlen(Neo.xroma);j++)
			Neo.xroma[j]=toupper(Neo.xroma[j]);
		}
	}
fclose(fle);
system("cls");
printf("Eisagogi neas eggrafis\n______________________\n\n\n\nParakalo pliktrologiste to etos kataskeuis tou oximatos: ");
scanf("%d",&Neo.etos);
if(Neo.etos<1960||Neo.etos>2019)
	do
	{
	system("cls");
	Beep(550,650);
	printf("Eisagogi neas eggrafis\n______________________\n\nTo etos kataskeuis tou oximatos prepei na einai apo to 1960 eos kai to 2019.\nParakalo pliktrologiste to etos kataskeuis tou oximatos: ");
	scanf("%d",&Neo.etos);
	}
	while(Neo.etos<1960||Neo.etos>2019);
Change[1]=Neo;
*flag=2;

system("pause");
}

void diagrafi(oximata *Car,oximata *Change,int *noc,int *flag)
{
int temp,i,j;
FILE *fle;

for(i=0;i<*noc-1;i++)
	for(j=0;j<*noc-1-i;j++)
		if(Car[j].pinakida<Car[j+1].pinakida)
			{
			Change[0]=Car[j];
			Car[j]=Car[j+1];
			Car[j+1]=Change[0];
			}
while(1)
	{
	printf("Diagrafi eggrafis\n_________________\n\n");
	for(i=0;i<*noc;i++)
	printf("%d		",Car[i].pinakida);
	printf("\n\n\nEpilekste ton arithmo pinakidas pou\nthelete na diagrapsete apo tous parapano: ");
	scanf("%d",&Change[1].pinakida);
	for(i=0;i<*noc;i++)
		if(Change[1].pinakida==Car[i].pinakida)
			break;
	if(i<=*noc-1)
		break;
	Beep(550,650);
	printf("MI EGKIRI EPILOGI!\nParakalo dokimaste ksana.\n\n\n\n");
	system("pause");
	system("cls");
	}
*flag=3;

system("pause");
}

void ananeosi(oximata *Car,oximata *Change,int *noc,int *flag)
{
int i=0,j,temp,Etos,Arithmos;
char Company[numb_comp][32],Color[numb_xrom][32];
oximata Neo;
FILE *fle;

for(i=0;i<*noc-1;i++)
	for(j=0;j<*noc-1-i;j++)
		if(Car[j].pinakida<Car[j+1].pinakida)
			{
			Change[0]=Car[j];
			Car[j]=Car[j+1];
			Car[j+1]=Change[0];
			}
while(1)
	{
	printf("Ananeosi eggrafis\n_________________\n\n");
	for(i=0;i<*noc;i++)
	printf("%d		",Car[i].pinakida);
	printf("\n\n\nEpilekste ton arithmo pinakidas pou\nthelete na tropopoiisete apo tous parapano: ");
	scanf("%d",&temp);
	for(i=0;i<*noc;i++)
		if(temp==Car[i].pinakida)
			{
			Change[0]=Car[i];
			break;
			}
	if(i<=*noc-1)
		break;
	Beep(550,650);
	printf("MI EGKIRI EPILOGI!\nParakalo dokimaste ksana.\n\n\n\n");
	system("pause");
	system("cls");
	}
printf("Ananeosi eggrafis\n_________________\n\nDose ton arithmo pinakidas (%d). Prepei na einai metaksi 1001 kai 9999 kai fisika na min anikei idi se allo autokinito: ",Change[0].pinakida);
fle=fopen("Cars.txt","r");
scanf("%d",&Neo.pinakida);
for(i=0;i<*noc;i++)
	{
	if(Neo.pinakida==temp)
		break;
	if(Neo.pinakida<1001||Neo.pinakida>9999||Neo.pinakida==Car[i].pinakida)
		{
		system("cls");
		printf("Ananeosi eggrafis\n_________________\n\nMI EGKIRI EPILOGI!\nParakalo dokimaste ksana.\n\nDose ton arithmo pinakidas (%d). Prepei na einai metaksi 1001 kai 9999 kai fisika na min anikei idi se allo autokinito: ",Change[0].pinakida);
		Beep(550,650);
		scanf("%d",&Neo.pinakida);
		i=0;
		}
	if(Neo.pinakida==temp)
		break;
	}
fclose(fle);
fle=fopen("Companies.txt","r");
system("cls");
printf("Ananeosi eggrafis\n_________________\n\n");
for(i=0;i<numb_comp;i++)
	{
	fscanf(fle,"%s",Company[i]);
	printf("\n%s",Company[i]);
	}
printf("\nEpelekse mia apo tis parapano etaireies (%s): ",Change[0].marka);
scanf("%s",Neo.marka);
for(i=0;i<strlen(Neo.marka);i++)
	Neo.marka[i]=toupper(Neo.marka[i]);
for(i=0;i<numb_comp;i++)
	{
	if(strcmp(Neo.marka,Company[i])==0)
		break;
	if(i==numb_comp-1)
		{
		system("cls");
		Beep(550,650);
		i=0;
		printf("Ananeosi eggrafis\n_________________\n\n");
		for(j=0;j<numb_comp;j++)
			{
			fscanf(fle,"%s",Company[j]);
			printf("\n%s",Company[j]);
			}
		printf("\nDEN IPARXEI AUTI I ETAIREIA!\nEpelekse mia apo tis parapano etaireies (%s): ",Change[0].marka);
		scanf("%s",Neo.marka);
		for(j=0;j<strlen(Neo.marka);j++)
			Neo.marka[j]=toupper(Neo.marka[j]);
		}
	}
fclose(fle);
fle=fopen("BasicColors.txt","r");
system("cls");
printf("Ananeosi eggrafis\n_________________\n\n");
for(i=0;i<numb_xrom;i++)
	{
	fscanf(fle,"%s",Color[i]);
	printf("\n%s",Color[i]);
	}
printf("\n\nEpelekse ena apo ta parapano xromata (%s): ",Change[0].xroma);
scanf("%s",Neo.xroma);
for(i=0;i<strlen(Neo.xroma);i++)
	Neo.xroma[i]=toupper(Neo.xroma[i]);
for(i=0;i<numb_xrom;i++)
	{
	if(strcmp(Neo.xroma,Color[i])==0)
		break;
	if(i==numb_xrom-1)
		{
		system("cls");
		Beep(550,650);
		i=0;
		printf("Ananeosi eggrafis\n_________________\n\n");
		for(j=0;j<numb_xrom;j++)
			{
			fscanf(fle,"%s",Color[j]);
			printf("\n%s",Color[j]);
			}
		printf("\n\n\nDEN IPARXEI AUTO TO XROMA!\nEpelekse ena apo ta parapano xromata (%s): ",Change[0].xroma);
		scanf("%s",Neo.xroma);
		for(j=0;j<strlen(Neo.xroma);j++)
			Neo.xroma[j]=toupper(Neo.xroma[j]);
		}
	}
fclose(fle);
system("cls");
printf("Ananeosi eggrafis\n_________________\n\n\n\nParakalo pliktrologiste to etos kataskeuis tou oximatos (%d): ",Change[0].etos);
scanf("%d",&Neo.etos);
if(Neo.etos<1960||Neo.etos>2019)
	do
	{
	system("cls");
	Beep(550,650);
	printf("Ananeosi eggrafis\n_________________\n\nTo etos kataskeuis tou oximatos prepei na einai apo to 1960 eos kai to 2019.\nParakalo pliktrologiste to etos kataskeuis tou oximatos (%d): ",Change[0].etos);
	scanf("%d",&Neo.etos);
	}
	while(Neo.etos<1960||Neo.etos>2019);
Change[1]=Neo;
*flag=4;

system("pause");
}

void anazitisi(oximata *Car,int *noc)
{
char A[256];

printf("Anazitisi\n_________\n\n1. Me basi ton arithmo\n2. Me basi to xroma\n3. Me basi ton kataskeuasti\n4. Me basi to etos kataskeuis\n0. Epistrofi sto basiko menou\n\nEpilekste apo 0 eos 4 gia mia apo tis parapano energeies: ");
scanf(" %[^\t\n]s",&A);
system("cls");
if (A[0]!='0'&&A[0]!='1'&&A[0]!='2'&&A[0]!='3'&&A[0]!='4'||A[1]!=NULL)
    do
    {
    system("cls");
    printf("MI EGKIRI EPILOGI!\nParakalo dokimaste ksana.\n\n\n\n");
    Beep(550,650);
	system("pause");
	system("cls");
	printf("Anazitisi\n_________\n\n1. Me basi ton arithmo\n2. Me basi to xroma\n3. Me basi ton kataskeuasti\n4. Me basi to etos kataskeuis\n0. Epistrofi sto basiko menou\n\nEpilekste apo 0 eos 4 gia mia apo tis parapano energeies: ");
	scanf(" %[^\t\n]s",&A);
    }
    while(A[0]!='0'&&A[0]!='1'&&A[0]!='2'&&A[0]!='3'&&A[0]!='4'||A[1]!=NULL);
if (A[0]=='1')
    {
    system("cls");
    arithmos(Car,*noc);

	system("pause");
	}
if (A[0]=='2')
    {
    system("cls");
    xroma(Car,*noc);

	system("pause");
	}
if (A[0]=='3')
    {
    system("cls");
    kataskeuastis(Car,*noc);

	system("pause");
	}
if (A[0]=='4')
    {
    system("cls");
    etos(Car,*noc);

	system("pause");
	}
}

void enimerosi(oximata *Car,oximata *Change,int *noc,int *flag)
{
int i;
FILE *fle;

fle=fopen("Cars.txt","w");
printf("Enimerosi vasis\n_______________\n\n");
if (*flag==2)
	{
	*noc+=1;
	Car[*noc-1]=Change[1];
	printf("\nepitixis eggrafi!\n");
	}
if (*flag==3)
	{
	for(i=0;i<*noc;i++)
		{
		if(Change[1].pinakida==Car[i].pinakida)
			{
			Car[i]=Car[*noc-1];
			break;
			}
		}
	*noc-=1;
	printf("\nepitixis diagrafi!\n");
	}
if (*flag==4)
	{
	for(i=0;i<*noc;i++)
		if(Change[0].pinakida==Car[i].pinakida)
			{
			Car[i]=Change[1];
			break;
			}
	printf("\nepitixis ananeosi!\n");
	}
for(i=0;i<*noc;i++)
	{
	if(strlen(Car[i].marka)<8)
	fprintf(fle,"%d		%s		%s			%d\n",Car[i].pinakida,Car[i].xroma,Car[i].marka,Car[i].etos);
		else if(strlen(Car[i].marka)<16)
		fprintf(fle,"%d		%s		%s		%d\n",Car[i].pinakida,Car[i].xroma,Car[i].marka,Car[i].etos);
			else if(strlen(Car[i].marka)<24)
			fprintf(fle,"%d		%s		%s	%d\n",Car[i].pinakida,Car[i].xroma,Car[i].marka,Car[i].etos);
	}
fclose(fle);
*flag=0;

system("pause");
}

int main()
{
oximata Car[size],Change[2];
char A[256];
int i,noc=0,flag=0;//noc=number of cars
FILE *fle;

fle=fopen("Cars.txt","r");
for(i=0;i<size;i++)//auti tin loopa tin xreiazomai gia na mou dosei ton sinoliko arithmo ton oximaton
	{
	fscanf(fle,"%d %s %s %d",&Car[i].pinakida,Car[i].xroma,Car[i].marka,&Car[i].etos);
	if(strcmp(Car[i].xroma,"BLACK")!=0&&strcmp(Car[i].xroma,"BLUE")!=0&&strcmp(Car[i].xroma,"BROWN")!=0&&strcmp(Car[i].xroma,"GOLD")!=0&&strcmp(Car[i].xroma,"GRAY")!=0&&strcmp(Car[i].xroma,"GREEN")!=0&&strcmp(Car[i].xroma,"ORANGE")!=0&&strcmp(Car[i].xroma,"PINK")!=0&&strcmp(Car[i].xroma,"PURPLE")!=0&&strcmp(Car[i].xroma,"RED")!=0&&strcmp(Car[i].xroma,"SILVER")!=0&&strcmp(Car[i].xroma,"WHITE")!=0&&strcmp(Car[i].xroma,"YELLOW")!=0)
		break;
	noc+=1;
	}
fclose(fle);
do
    {
    system("cls");
    printf("BASIKO MENOU\n____________\n\n1. Emfanisi olon\n2. Eisagogi neas eggrafis\n3. Diagrafi eggrafis\n4. Ananeosi eggrafis\n5. Anazitisi\n6. Enimerosi vasis\n0. Eksodos\n\nEpilekste apo 0 eos 6 gia mia apo tis parapano energeies: ");
    scanf(" %[^\t\n]s",&A);/*me auti tin parametro sto scan tou string dexetai kai 'space'. kalei tin antistoixi sinartisi me akeraio apo 1 eos kai 6 eno me 0 sinexizetai i main kai termatizei to programma*/
    system("cls");
    if (A[0]!='1'&&A[0]!='2'&&A[0]!='3'&&A[0]!='4'&&A[0]!='5'&&A[0]!='6'&&A[0]!='0'||A[1]!=NULL)/*mpainei se loop an o protos xaraktiras den einai akeraios apo 0 eos kai 6 H an iparxei kai deuteros xaraktiras*/
        do
        {
        system("cls");
    	printf("MI EGKIRI EPILOGI!\nParakalo dokimaste ksana.\n\n\n\n");
    	Beep(550,750);
		system("pause");
		system("cls");
        printf("BASIKO MENOU\n____________\n\n1. Emfanisi olon\n2. Eisagogi neas eggrafis\n3. Diagrafi eggrafis\n4. Ananeosi eggrafis\n5. Anazitisi\n6. Enimerosi vasis\n0. Eksodos\n\nEpilekste apo 0 eos 6 gia mia apo tis parapano energeies: ");
		scanf(" %[^\t\n]s",&A);
        }
        while (A[0]!='1'&&A[0]!='2'&&A[0]!='3'&&A[0]!='4'&&A[0]!='5'&&A[0]!='6'&&A[0]!='0'||A[1]!=NULL);
    if (A[0]=='1')
        {
        system("cls");
        emfanisi(Car,&noc);
        }
    if (A[0]=='2')
        {
        system("cls");
        eisagogi(Car,Change,&noc,&flag);//xreiazomai ton sinoliko arithmo ton kataxoriseon etsi oste i eisagogi na mpei sto telos
        }
    if (A[0]=='3')
        {
        system("cls");
        diagrafi(Car,Change,&noc,&flag);
        }
    if (A[0]=='4')
        {
        system("cls");
        ananeosi(Car,Change,&noc,&flag);
        }
    if (A[0]=='5')
        {
        system("cls");
        anazitisi(Car,&noc);
        }
    if (A[0]=='6')
        {
        system("cls");
        enimerosi(Car,Change,&noc,&flag);
        }
    }
while (A[0]!='0');
}

