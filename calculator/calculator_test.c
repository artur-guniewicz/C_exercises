#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <string.h>

char tab[8][3];
char tab_pom[8][20];
HANDLE kolor;

float suma(float a, float b)
{
    return a+b;
}
float roznica(float a, float b)
{
    return a-b;
}
float iloczyn(float a, float b)
{
    return a*b;
}
float iloraz(float a, float b)
{
    if(b!=0)
    {
        return a/b;
    }
    else printf("\nnan\n");

}
float potenga(float a, float b)
{
    return pow(a,b);
}
float pierwiastek(float a)
{
    if(a>=0)
    {
            return sqrt(a);
    }
    else
    {
            return -1;
    }
}
float procentowanie(float a,float b)
{
    float wynik;
    wynik=((b*a)/100);
    return wynik;
}
float druga_liczba()
{
    float liczba;
    printf("\nPodaj liczbe druga: ");
    scanf("%f",&liczba);
    return liczba;
}
void menu()
{
    kolor = GetStdHandle( STD_OUTPUT_HANDLE );
    int i,j;
    printf("|");
    SetConsoleTextAttribute( kolor, 10 );
    printf("MENU");
    SetConsoleTextAttribute( kolor, 7 );
    printf("|\n");
    for(i=0;i<8;i++)
    {
        if(tab[i][0]=='*')
        {
            printf("| ");
            SetConsoleTextAttribute( kolor, 112 );
            printf("%c",tab[i][1]);
            SetConsoleTextAttribute( kolor, 7 );
            printf("  | %s\n",tab_pom[i]);
        }
        else
        {
            printf("| ");
            printf("%c",tab[i][1]);
            printf("  |%s\n",tab_pom[i]);
        }
    }
    printf("|----|\n W/S \r");
}
int main()
  {
      int i,j,poly=0;
      char znak;
      char pom,a;
      int p=0;

      tab[0][1]='+';
      tab[1][1]='-';
      tab[2][1]='*';
      tab[3][1]='/';
      tab[4][1]='^';
      tab[5][1]='s';
      tab[6][1]='p';
      tab[7][1]='k';
      tab[0][0]='*';
      strcpy(tab_pom[0],"dodawnie");
      strcpy(tab_pom[1],"odejmowanie");
      strcpy(tab_pom[2],"mnozenie");
      strcpy(tab_pom[3],"dzielenie");
      strcpy(tab_pom[4],"potegowanie");
      strcpy(tab_pom[5],"pierwiastkowanie");
      strcpy(tab_pom[6],"procent z liczby");
      strcpy(tab_pom[7],"koniec");
      for(i=1;i<7;i++)
      {
          tab[i][0]=' ';
      }

      do
      {
          do
          {
              p=0;
              system("cls");
              menu();
              tab [poly][0] = ' ';
              a = getch();
              if(a == 'w' || a==72)
                {

                    poly = poly--;
                    if (poly < 0)
                    {
                        poly = 7;
                    }
                }
                else if (a == 's' || a==80)
                {

                    poly = poly++;
                    if (poly > 7)
                    {
                        poly = 0;
                    }
                }
                else if((int)a==13)
                {
                    p=1;
                }

            system("cls");
            tab [poly][0] = '*';
            menu();
          }
          while (p==0);

        if(tab[poly][1] == 'k')
        {
            break;
        }

        float wynik,l,l1;

        printf("\nPodaj liczbe pierwsza: ");
        scanf("%f",&l);
        znak=tab[poly][1];

        switch(znak)
        {
            case '+':
            l1=druga_liczba();
            printf("\n%f + %f = %f",l,l1,suma(l,l1));
            break;

            case '-':
            l1=druga_liczba();
            printf("\n%f - %f = %f",l,l1,roznica(l,l1));
            break;

            case '*':
            l1=druga_liczba();
            printf("\n%f * %f = %f",l,l1,iloczyn(l,l1));
            break;

            case '/':
            l1=druga_liczba();
            if(l1!=0)
            {
                printf("\n%f / %f = %f",l,l1,iloraz(l,l1));
            }
            else
            {
                printf("\nblad");
            }
            break;

            case '^':
            l1=druga_liczba();
            printf("\n%f ^ %f = %f",l,l1,potenga(l,l1));
            break;

            case 's':
                if(pierwiastek(l)!=-1)
                {
                    printf("\nsqrt(%f) = %f",l,pierwiastek(l));
                }
                else
                {
                     printf("\nblad");
                }
            break;

            case 'p':
                l1=druga_liczba();
                printf("\n%f %% z %f = %f",l,l1,procentowanie(l,l1));
            break;

            default:
                printf("\nbrak takiego dzialania");

        }

        printf("\nChcesz liczyc dalej ? (T/N)");
        fflush(stdin);
        scanf("%c",&pom);
        fflush(stdin);

      }
      while (toupper(pom)=='T');
    printf("\nKONIEC ");

    return 0;
}
