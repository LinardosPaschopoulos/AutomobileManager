#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>
#define size 100 
#define numb_xrom 13
#define numb_comp 67

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
		else//if(strlen(Car[i].marka)<24)
		printf("%d		%s		%s	%d\n",Car[i].pinakida,Car[i].xroma,Car[i].marka,Car[i].etos);		
	
}

void arithmos(oximata *Car,int noc)
{
int arithmos,i;
char anisotita;
FILE *fle;

printf("Sign\n____\n\n");
printf("Please enter the car sign: ");
scanf("%d",&arithmos);
getchar();
if(arithmos<1001||arithmos>9999)
	while(arithmos<1001||arithmos>9999)
		{
		system("cls");
		printf("Sign\n____\n\n");
		Beep(550,650);
		system("pause");
		printf("Enter the car sign. Must be between 1001 and 9999 and not used by another vehicle: ");
		scanf("%d",&arithmos);
		getchar();
		}
system("cls");
printf("Sign\n____\n\n");	
printf("Chose '<' to show all listings\nmanufactured before the year of your choice or '>' to show\nthe listings manufactured after the year of your choice: ");
scanf("%c",&anisotita);
getchar();
if(anisotita!='<'&&anisotita!='>')
	while(anisotita!='<'&&anisotita!='>')
		{
		system("cls");
		printf("Sign\n____\n\n");
		Beep(550,650);
		system("pause");
		printf("Chose '<' to show all listings\nmanufactured before the year of your choice or '>' to show\nthe listings manufactured after the year of your choice: ");
		scanf("%c",&anisotita);
		getchar();
		}
system("cls");
fle=fopen("Cars.txt","r");
printf("SIGN		COLOR		MANUFACTURER		YEAR\n____________________________________________________________\n");
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

printf("Search based on color\n_____________________\n\n");
fle=fopen("BasicColors.txt","r");
for(i=0;i<numb_xrom;i++)
	{
	fscanf(fle,"%s",Color[i]);
	}
for(i=0;i<numb_xrom;i++)
	{
	for(j=0;j<noc;j++)
		if(strcmp(Color[i],Car[j].xroma)==0)
			{
			printf("%s\n",Color[i]);
			break;
			}
	}
fclose(fle);
printf("\nPlease choose among the following colors: ");
scanf("%s",A);
getchar();
for(i=0;i<strlen(A);i++)
	A[i]=toupper(A[i]);
system("cls");
fle=fopen("Cars.txt","r");
printf("SIGN		COLOR		MANUFACTURER		YEAR\n____________________________________________________________\n");
for(i=0;i<noc;i++)
	{
	if(i%5==0)
		printf("\n");
	if(strncmp(Car[i].xroma,A,strlen(A))==0)
		my_print(Car,i);
	}
printf("\n\n");
fclose(fle);
}

void kataskeuastis(oximata *Car,int *noc) 
{
char A[32],Company[numb_comp][32];
int i,j;
FILE *fle;

printf("Search based on manufacturer\n____________________________\n\n");
fle=fopen("Companies.txt","r");
for(i=0;i<numb_comp;i++)
	{
	fscanf(fle,"%s",Company[i]);
	}
for(i=0;i<numb_comp;i++)
	{
	for(j=0;j<noc;j++)
		if(strcmp(Company[i],Car[j].marka)==0)
			{
			printf("%s\n",Company[i]);
			break;
			}
	}
fclose(fle);
printf("\nPlease choose among the following companies: ");
scanf("%s",toupper(A));
getchar();
for(i=0;i<strlen(A);i++)
	A[i]=toupper(A[i]);
fle=fopen("Cars.txt","r");
system("cls");
printf("SIGN		COLOR		MANUFACTURER		YEAR\n____________________________________________________________\n");
for(i=0;i<noc;i++)
	{
	if(i%5==0)
		printf("\n");
	if(strncmp(Car[i].marka,A,strlen(A))==0)
		my_print(Car,i);	
	}
printf("\n\n");
fclose(fle);
}

void etos(oximata *Car,int *noc)
{
int etos,i;
char anisotita;
FILE *fle;

printf("Year of production\n__________________\n\n");
printf("Please enter the year of production: ");
scanf("%d",&etos);
getchar();
if(etos<1960||etos>2019)
	while(etos<1960||etos>2019)
		{
		system("cls");
		printf("Year of production\n__________________\n\n");
		Beep(550,650);
		system("pause");
		printf("Please enter the year of production.\nMust be between 1960 and 2019: ");
		scanf("%d",&etos);
		getchar();
		}
system("cls");
printf("Year of production\n__________________\n\n");	
printf("Chose '<' to show all listings\nmanufactured before the year of your choice or '>' to show\nthe listings manufactured after the year of your choice: ");
scanf("%c",&anisotita);
getchar();
if(anisotita!='<'&&anisotita!='>')
	while(anisotita!='<'&&anisotita!='>')
		{
		system("cls");
		printf("Year of production\n__________________\n\n");
		Beep(550,650);
		system("pause");
		printf("Chose '<' to show all listings\nmanufactured before the year of your choice or '>' to show\nthe listings manufacturedafter the year of your choice: ");
		scanf("%c",&anisotita);
		getchar();
		}
system("cls");
fle=fopen("Cars.txt","r");
printf("SIGN		COLOR		MANUFACTURER		YEAR\n____________________________________________________________\n");
for(i=0;i<noc;i++)
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

void emfanisi(oximata *Car,int *noc)
{
int i;
FILE *fle;

printf("Show All\n________\n\n");
fle=fopen("Cars.txt","r");
printf("SIGN		COLOR		MANUFACTURER		YEAR\n____________________________________________________________\n");
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

void eisagogi(oximata *Car,oximata *Change,int *noc,int *flag)
{
int i=0,j,Etos,Arithmos;
char Company[numb_comp][32],Color[numb_xrom][32];
oximata Neo;
FILE *fle;

printf("Add new listing\n_______________\n\nEnter the car sign. Must be between 1001 and 9999 and not used by another vehicle: ");
fle=fopen("Cars.txt","r");
scanf("%d",&Neo.pinakida);
for(i=0;i<*noc;i++)
	{
	if(Neo.pinakida<1001||Neo.pinakida>9999||Neo.pinakida==Car[i].pinakida)
		{
		system("cls");
		printf("Add new listing\n_______________\n\nINVALID CHOICE!\nPlease try again.\n\nDose ton arithmo pinakidas. Prepei na einai metaksi 1001 kai 9999 kai fisika na min anikei idi se allo autokinito: ");
		Beep(550,650);
		scanf("%d",&Neo.pinakida);
		i=0;
		}
	}
fclose(fle);
fle=fopen("Companies.txt","r");
system("cls");
printf("Add new listing\n_______________\n\n");
for(i=0;i<numb_comp;i++)
	{
	fscanf(fle,"%s",Company[i]);
	printf("\n%s",Company[i]);
	}
printf("\nPlease choose among the following companies: ");
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
		printf("Add new listing\n_______________\n\n");
		for(j=0;j<numb_comp;j++)
			{
			fscanf(fle,"%s",Company[j]);
			printf("\n%s",Company[j]);
			}
		printf("\nThis manufacturer does not exist!\nPlease choose among the following companies: ");
		scanf("%s",Neo.marka);
		for(j=0;j<strlen(Neo.marka);j++)
			Neo.marka[j]=toupper(Neo.marka[j]);
		}
	}
fclose(fle);
fle=fopen("BasicColors.txt","r");
system("cls");
printf("Add new listing\n_______________\n\n");
for(i=0;i<numb_xrom;i++)
	{
	fscanf(fle,"%s",Color[i]);
	printf("\n%s",Color[i]);
	}
printf("\n\nPlease choose among the following colors: ");
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
		printf("Add new listing\n_______________\n\n");
		for(j=0;j<numb_xrom;j++)
			{
			fscanf(fle,"%s",Color[j]);
			printf("\n%s",Color[j]);
			}
		printf("\n\n\nInvalid color!\nPlease choose among the following colors: ");
		scanf("%s",Neo.xroma);
		for(j=0;j<strlen(Neo.xroma);j++)
			Neo.xroma[j]=toupper(Neo.xroma[j]);
		}
	}
fclose(fle);
system("cls");
printf("Add new listing\n_______________\n\n\n\nPlease enter the year of production: ");
scanf("%d",&Neo.etos);
if(Neo.etos<1960||Neo.etos>2019)
	do
	{
	system("cls");
	Beep(550,650);	
	printf("Add new listing\n_______________\n\nThe year of production must be between 1960 and 2019.\nPlease enter the year of production: ");
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
	printf("Delete listing\n______________\n\n");	
	for(i=0;i<*noc;i++)
	printf("%d\n",Car[i].pinakida);
	printf("\n\n\nChose the car sign you wish to delete\nfrom the following: ");
	scanf("%d",&Change[1].pinakida);
	for(i=0;i<*noc;i++)
		if(Change[1].pinakida==Car[i].pinakida)
			break;
	if(i<=*noc-1)
		break;
	Beep(550,650);
	printf("INVALID CHOICE!\nPlease try again.\n\n\n\n");
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
	printf("Listing update\n______________\n\n");
	for(i=0;i<*noc;i++)
	printf("%d\n",Car[i].pinakida);
	printf("\n\n\nChose the car sign you wish to update\nfrom the following: ");
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
	printf("INVALID CHOICE!\nPlease try again.\n\n\n\n");
	system("pause");
	system("cls");
	}
printf("Listing update\n______________\n\nEnter the car sign (%d). Must be between 1001 and 9999 and not used by another vehicle: ",Change[0].pinakida);
fle=fopen("Cars.txt","r");
scanf("%d",&Neo.pinakida);
for(i=0;i<*noc;i++)
	{
	if(Neo.pinakida==temp)
		break;
	if(Neo.pinakida<1001||Neo.pinakida>9999||Neo.pinakida==Car[i].pinakida)
		{
		system("cls");
		printf("Listing update\n_________________\n\nINVALID CHOICE!\nPlease try again.\n\nEnter the car sign (%d). Must be between 1001 and 9999 and not used by another vehicle: ",Change[0].pinakida);
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
printf("Listing update\n_________________\n\n");
for(i=0;i<numb_comp;i++)
	{
	fscanf(fle,"%s",Company[i]);
	printf("\n%s",Company[i]);
	}
printf("\nPlease choose among the following companies (%s): ",Change[0].marka);
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
		printf("Listing update\n______________\n\n");
		for(j=0;j<numb_comp;j++)
			{
			fscanf(fle,"%s",Company[j]);
			printf("\n%s",Company[j]);
			}
		printf("\nThis manufacturer does not exist!\nPlease choose among the following companies (%s): ",Change[0].marka);
		scanf("%s",Neo.marka);
		for(j=0;j<strlen(Neo.marka);j++)
			Neo.marka[j]=toupper(Neo.marka[j]);
		}
	}
fclose(fle);
fle=fopen("BasicColors.txt","r");
system("cls");
printf("Listing update\n______________\n\n");
for(i=0;i<numb_xrom;i++)
	{
	fscanf(fle,"%s",Color[i]);
	printf("\n%s",Color[i]);
	}
printf("\n\nPlease choose among the following colors (%s): ",Change[0].xroma);
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
		printf("Listing update\n______________\n\n");
		for(j=0;j<numb_xrom;j++)
			{
			fscanf(fle,"%s",Color[j]);
			printf("\n%s",Color[j]);
			}
		printf("\n\n\nInvalid color!\nPlease choose among the following colors (%s): ",Change[0].xroma);
		scanf("%s",Neo.xroma);
		for(j=0;j<strlen(Neo.xroma);j++)
			Neo.xroma[j]=toupper(Neo.xroma[j]);
		}
	}
fclose(fle);
system("cls");
printf("Listing update\n______________\n\nYear of production must be between 1960 and 2019.\nPlease enter the year of production(%d): ",Change[0].etos);
scanf("%d",&Neo.etos);
if(Neo.etos<1960||Neo.etos>2019)
	do
	{
	system("cls");
	Beep(550,650);	
	printf("Listing update\n______________\n\nYear of production must be between 1960 and 2019.\nPlease enter the year of production(%d): ",Change[0].etos);
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

printf("Search\n______\n\n1. Search by number\n2. Search by color\n3. Search by manufacturer\n4. Search by production year\n0. Back to basic menu\n\nEpilekste apo 0 eos 4 gia mia apo tis parapano energeies: ");
scanf(" %[^\t\n]s",&A);
system("cls");
if (A[0]!='0'&&A[0]!='1'&&A[0]!='2'&&A[0]!='3'&&A[0]!='4'||A[1]!=NULL)
    do
    {
    system("cls");
    printf("INVALID CHOICE!\nPlease try again.\n\n\n\n");
    Beep(550,650);
	system("pause");
	system("cls");
	printf("Search\n______\n\n1. Search by number\n2. Search by color\n3. Search by manufacturer\n4. Search by production year\n0. Back to basic menu\n\nEpilekste apo 0 eos 4 gia mia apo tis parapano energeies: ");
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
printf("Database update\n_______________\n\n");
if (*flag==2)
	{
	*noc+=1;
	Car[*noc-1]=Change[1];
	printf("\nListing added!\n");
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
	printf("\nListing deleted!\n");
	}
if (*flag==4)
	{
	for(i=0;i<*noc;i++)
		if(Change[0].pinakida==Car[i].pinakida)
			{
			Car[i]=Change[1];
			break;
			}
	printf("\nDatabase updated!\n");
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
int i,noc=0,flag=0;
FILE *fle;

fle=fopen("Cars.txt","r");
for(i=0;i<size;i++)
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
    printf("BASIC MENU\n__________\n\n1. Display all listings\n2. Create new listing\n3. Delete listing\n4. Update listing\n5. Search\n6. Update database\n0. Exit program\n\nChoose 0 to 6: ");
    scanf(" %[^\t\n]s",&A);
    system("cls");
    if (A[0]!='1'&&A[0]!='2'&&A[0]!='3'&&A[0]!='4'&&A[0]!='5'&&A[0]!='6'&&A[0]!='0'||A[1]!=NULL)
        do
        {
        system("cls");
    	printf("INVALID CHOICE!\nPlease try again.\n\n\n\n");
    	Beep(550,750);
		system("pause");
		system("cls");
        printf("BASIC MENU\n__________\n\n1. Display all listings\n2. Create new listing\n3. Delete listing\n4. Update listing\n5. Search\n6. Update database\n0. Exit program\n\nChoose 0 to 6: ");
		scanf(" %[^\t\n]s",&A);
        }
        while (A[0]!='1'&&A[0]!='2'&&A[0]!='3'&&A[0]!='4'&&A[0]!='5'&&A[0]!='6'&&A[0]!='0'||A[1]!=NULL);
    if (A[0]=='1')
        {
        system("cls");
        emfanisi(Car,&noc);
        }
	else if (A[0]=='2')
        {
        system("cls");
        eisagogi(Car,Change,&noc,&flag);
        }
    else if (A[0]=='3')
        {
        system("cls");
        diagrafi(Car,Change,&noc,&flag);
        }
    else if (A[0]=='4')
        {
        system("cls");
        ananeosi(Car,Change,&noc,&flag);
        }
    else if (A[0]=='5')
        {
        system("cls");
        anazitisi(Car,&noc);
        }
    else
        {
        system("cls");
        enimerosi(Car,Change,&noc,&flag);
        }
    }
while (A[0]!='0');
}

