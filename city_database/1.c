#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#define n 30

struct miasta ///BAZA DANYCH
{
    char nazwa[20];
    char wojewodztwo[20];
    char rodzaj[20];
    int liczba_mieszkancow;
    int sredni_wiek;
    int liczba_mlodziezy;
    char uwagi[100],*proba;
}miasto[n],schowek;

int ilosc_miast=0;


void pobierz_dane_z_pliku()
{
    char linia[255];
    int i=0,licznik=0,a,pom,dlugosc;
    FILE* plik=fopen("danemiast2.txt","r");
    while(fgets(linia,255,plik)!=NULL)
    {
        a=(licznik%7)+1;
        switch(a)
        {
            case 1:
                strcpy(miasto[i].nazwa,linia);
                dlugosc=strlen(miasto[i].nazwa);
                printf("%d\n",dlugosc);
                miasto[i].nazwa[dlugosc-1]="";
                break;
            case 2:
                strcpy(miasto[i].wojewodztwo,linia);
                dlugosc=strlen(miasto[i].wojewodztwo);
                miasto[i].wojewodztwo[dlugosc-1]="";
                break;
            case 3:
                strcpy(miasto[i].rodzaj,linia);
                dlugosc=strlen(miasto[i].rodzaj);
                miasto[i].rodzaj[dlugosc-1]="";
                break;
            case 4:
                miasto[i].liczba_mieszkancow=atoi(linia);
                break;
            case 5:
                miasto[i].sredni_wiek=atoi(linia);;
                break;
            case 6:
                miasto[i].liczba_mlodziezy=atoi(linia);
                break;
            case 7:
                strcpy(miasto[i].uwagi,linia);
                dlugosc=strlen(miasto[i].uwagi);
                break;
        }
        licznik++;
        if(a==7)i++;
    }

    fclose(plik);
    ilosc_miast=i;///wpisanie liczby miast

}


void wyswietl_dane()
{
    int i;
    for(i=0;i<ilosc_miast;i++)
    {
        printf("Nazwa: %s | Wojewodztwo: %s | Rodzaj: %s | Liczba lud.: %d | Sredni wiek: %d | Liczba mlo.: %d | Uwagi: %s \n\n",miasto[i].nazwa,miasto[i].wojewodztwo,miasto[i].rodzaj,miasto[i].liczba_mieszkancow,miasto[i].sredni_wiek,miasto[i].liczba_mlodziezy,miasto[i].uwagi);
    }
}

void wprowadz_dane()
{
    int j=1,i=ilosc_miast;
    printf("Podaj nazwe miasta ");
    scanf("%s",miasto[i].nazwa);
    miasto[i].nazwa[0]=toupper(miasto[i].nazwa[0]);///zwiekszanie pierwszej litery
    while(isalpha(miasto[i].nazwa[j]))
    {
        miasto[i].nazwa[j]=tolower(miasto[i].nazwa[j]);///zmniejszanie pozosta lych lietr
        j++;
    }
    printf("Podaj wojewodztwo ");
    scanf("%s",miasto[i].wojewodztwo);
    printf("Podaj rodzaj miasta ");
    scanf("%s",miasto[i].rodzaj);
    printf("Podaj liczbe mieszkancow ");
    scanf("%d",&miasto[i].liczba_mieszkancow);
    printf("Podaj sredni wiek ");
    scanf("%d",&miasto[i].sredni_wiek);
    printf("Podaj liczba mlodziezy  ");
    scanf("%d",&miasto[i].liczba_mlodziezy);
    printf("Podaj uwagi (100 znakow)");
    scanf("%s",miasto[i].uwagi);
    ilosc_miast+=1;///zwiekszenie liczby miast o 1
}

void sortowanie_po_nazwie()
{
    int zamiana,i,j=0,pom=0;
     do
    {
        zamiana=0;///przed każdym "przejazdem" pętli for zmienna zamiana jest zerowana
       for ( i=0; i<ilosc_miast-1; i++)
        {
            if (strcmp(miasto[i].nazwa,miasto[i+1].nazwa)>0)/// jesli element tablicy jest wiekszy od nastepnego elementu
            {
                zamiana=zamiana+1; ///jesli jestzmiana, to zmienne zamiana powieksza wartosc
                schowek=miasto[i];///spis[i] jest kopiowana do schowka
                miasto[i]=miasto[i+1];///spis[i] przyjmuje wartosc nastepnego elementu, gdyż jest on mniejszy
                miasto[i+1]=schowek;///kolejny element tablicy przejmuje wczesniejsza wartosc poprzedniego elementu
            }
        }
    }
    while(zamiana!=0);

    printf("WYPISANIE PO NAZWIE MIASTA\n");
    wyswietl_dane();
}

void sortowanie_po_wojewodztwie()
{
    int zamiana,i,j=0,pom=0;
     do
    {
        zamiana=0;///przed ka�dym "przejazdem" p�tli for zmienna zamiana jest zerowana
       for ( i=0; i<ilosc_miast-1; i++)
        {
            if (strcmp(miasto[i].wojewodztwo,miasto[i+1].wojewodztwo)>0)/// jesli element tablicy jest wiekszy od nastepnego elementu
            {
                zamiana=zamiana+1; ///jesli jestzmiana, to zmienne zamiana powieksza wartosc
                schowek=miasto[i];///spis[i] jest kopiowana do schowka
               miasto[i]=miasto[i+1];///spis[i] przyjmuje wartosc nastepnego elementu, gdy� jest on mniejszy
                miasto[i+1]=schowek;///kolejny element tablicy przejmuje wczesniejsza wartosc poprzedniego elementu
            }
        }
    }
    while(zamiana!=0);

    printf("WYPISANIE PO WOJEWODZTWIE\n");
    wyswietl_dane();
}

void sortowanie_po_rodzaju()
{
    int zamiana,i,j=0,pom=0;
     do
    {
        zamiana=0;///przed ka�dym "przejazdem" p�tli for zmienna zamiana jest zerowana
       for ( i=0; i<ilosc_miast-1; i++)
        {
            if (strcmp(miasto[i].rodzaj,miasto[i+1].rodzaj)>0)/// jesli element tablicy jest wiekszy od nastepnego elementu
            {
                zamiana=zamiana+1; ///jesli jestzmiana, to zmienne zamiana powieksza wartosc
                schowek=miasto[i];///spis[i] jest kopiowana do schowka
                miasto[i]=miasto[i+1];///spis[i] przyjmuje wartosc nastepnego elementu, gdy� jest on mniejszy
                miasto[i+1]=schowek;///kolejny element tablicy przejmuje wczesniejsza wartosc poprzedniego elementu
            }
        }
    }
    while(zamiana!=0);

    printf("WYPISANIE PO RODZAJU MIASTA\n");
    wyswietl_dane();
}

void wyswietlanie_po_nazwie()
{
        int pom=0,i,indeks;
        char wprowadzona_nazwa[30];
        printf("Podaj nazwe miasta: ");
        fflush(stdin);
        gets(wprowadzona_nazwa);
        ///strcat(wprowadzona_nazwa," ");
        i=0;
        do
        {
            pom=0;


                if (strcmp(wprowadzona_nazwa,miasto[i].nazwa)==0)
                {
                pom=1;
                indeks=i;
                }
                i++;
            }while(pom==0);
        printf("Nazwa: %s | Wojewodztwo: %s | Rodzaj: %s | Liczba lud.: %d | Sredni wiek: %d | Liczba mlo.: %d \n\n",miasto[indeks].nazwa,miasto[indeks].wojewodztwo,miasto[indeks].rodzaj,miasto[indeks].liczba_mieszkancow,miasto[indeks].sredni_wiek,miasto[indeks].liczba_mlodziezy);
}

void wyswietlanie_po_literze()
{
    char litera;
    int i,pom=0;
    printf("podaj litere");
    scanf("%c",&litera);
    litera=toupper(litera);
    for(i=0;i<ilosc_miast;i++)
    {
        if(litera==miasto[i].nazwa[0])
        {
            printf("%s %s %s %d %d %d \n",miasto[i].nazwa,miasto[i].wojewodztwo,miasto[i].rodzaj,miasto[i].liczba_mieszkancow,miasto[i].sredni_wiek,miasto[i].liczba_mlodziezy,miasto[i].uwagi);
        }
        else
        {
            pom=1;
        }
    }
    if(pom==0)
    {
        printf("brak takich miast na taka litere %c ",litera);
    }
}


int main()
{
    pobierz_dane_z_pliku();
    int wybor;
    char wprowadzona_nazwa[20];
    do
    {
            printf("\n                              BAZA MIAST");
            printf("\n_______________________________________________________________________");
            printf("\n\nCo chcesz zrobic?\n");
            printf("1 - modyfikacja danych \n2 - wyswietlanie miast posortowanych po nazwie \n3 - wyswietlanie miast posortowanych po wojewodztwie \n4 - wyswietlanie miast po rodzaju \n5 - wyswietlanie danego miasta z pelna informacja \n6 - wyszukiwanie miasta po pierwszej literze nazwy  \n");
            scanf("%d",&wybor);
            switch(wybor)
            {
                case 1:
                    system("cls");
                    wprowadz_dane();
                    break;
                case 2:
                    system("cls");
                    sortowanie_po_nazwie();

                    break;
                case 3:
                    system("cls");
                    sortowanie_po_wojewodztwie();
                    break;
                case 4:
                    system("cls");
                    sortowanie_po_rodzaju();
                    break;
                case 5:
                    system("cls");
                    wyswietlanie_po_nazwie();
                    break;
                case 6:
                    system("cls");
                    wyswietlanie_po_literze();
                    break;
            }

    }
    while(wybor!=99);

    return 0;

}

