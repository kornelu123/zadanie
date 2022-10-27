/*
Autor: Kornel Uriasz
Grupa: PT/P 13:15
Temat: Drugie Laboratorium
Data : 26.10.2022r 13:45
*/


#include <stdio.h>
#include <math.h>
#include <time.h>

void zad1(){
    int wiersz , kolumna;
    printf("Program tabliczka mnozenia \n Podaj liczbe wierszy: \n");
    scanf("%i",&wiersz);
    printf("Podaj liczbe kolumn: \n");
    scanf("%i",&kolumna);
    if((wiersz<1)||(kolumna<1)){
        printf("Podaj liczbe wieksza od zera");
        zad1();
    }else{
        printf("    |");
        for(int i=1;i<=kolumna;i++){
            printf("%4d",i);
        }
        printf("\n");
        printf("=====");
        for(int i=0;i<kolumna;i++){
            printf("====");
        }
        printf("\n");
        for(int i=1;i<=wiersz;i++){
            printf("%4d|",i);
            for(int j=1;j<=kolumna;j++){
                printf("%4d",i*j);
            }
            printf("\n");
        }
    }
    printf("\n\n\n");
}

void zad2(){
    unsigned long liczba_calk;
    int suma = 0;
    printf("Podaj duza liczbe calkowita dodatnia :");
    scanf("%lu",&liczba_calk);
    while(liczba_calk>0){
        suma = suma + (liczba_calk%10);
        liczba_calk = liczba_calk/ 10;
        printf("%lu ",suma);
    }
    printf("Suma cyfr to : %d \n\n\n",suma);
}

void zad3(){
    int a , b  ,NWD,NWW;
    printf("Podaj dwie liczby calkowite , do ktorych chcesz obliczyc NWW i NWD : \n");
    scanf("%d %d",&a,&b);
    if(a<=0 || b<=0){
        printf("Liczby nie moga byc zerem ani byc ujemne \n\n");
        zad3();
    }else {
        int i;
        if (a > b) {
            int t = a;
            a = b;
            b = t;
        }
        NWW = a * b;
        for (i = a * b; i > 0; i--) {
            if (i / a != 0 && i/b != 0) {
                if (i % a == 0 && i % b == 0) {
                    if (NWW > i) {
                        NWW = i;
                    }
                }
            }
        }

        NWD = 1;
        for (i = 1; i < b; i++) {
            if (a / i != 0 && b / i != 0) {
                if (a % i == 0 && b % i == 0) {
                    if (NWD < i) {
                        NWD = i;
                    }
                }
            }
        }
        printf("Najwiekszy wspolny dzielnik to : %d \nNajmniejsza wspolna wielokrotnosc to : %d\n\n\n", NWD, NWW);
    }
}


void zad4(){
    double eps ,S1 , S2, wyr;
    S1 = 0.0;
    S2 = 0.0;
    printf("Prosze podac pozadana wartosc obliczen mniejsza od 0.1\n");
    scanf("%lf",&eps);
    if(eps>=0.1){
        printf("Podana wartosc nie jest mniejsza od 0.1 \n");
        zad4();
    }else{
        int k=1;
        do{
            wyr = 1.0/(2.0*k-1.0);
            if(k%2==0){
                S1 -= wyr;
            }else{
                S1 += wyr;
            }
            k++;
        }while(wyr > eps);
        S1 = 4.0*S1;
        k=0;
        do{
           if(k!=0){
               wyr = wyr*(1.0/k);
           }else{
               wyr = 1;
           }
           S2 = S2+ wyr;
           k++;
        }while(wyr>eps);
        printf("Suma pierwszego ciagu z dokladnoscia do %lf to : %.15lf \nSuma drugiego ciagu z dokladnoscia do %.15lf to : %lf\n\n\n",eps,S1,eps,S2);
    }
}

void zad5(){
    int min, max, quant, sum , sum_n , sum_p , quant_n , quant_p;
    float  mean_p , mean_n;
    quant_n =0;
    quant_p=0;
    sum =0;
    sum_p =0;
    sum_n=0;
    printf("Podaj liczbe minimalna ,maksymalna i ilosc losowanych liczb :\n");
    scanf("%d %d %d",&min,&max,&quant);
    srand (time(NULL));
    for(int i=0;i<quant;i++){
        int losowa = min + rand()%(max-min+1);
        if(losowa < 0){
            quant_n++;
            sum_n += losowa;
        }
        if(losowa > 0){
            quant_p++;
            sum_p += losowa;
        }
        printf("Wygenerowana liczba to : %d\n",losowa);
    }
    mean_p = (float)sum_p/quant_p;
    mean_n = (float)sum_n/quant_n;
    printf("Ilosc liczb dodatnich to : %d\n",quant_p);
    printf("Srednia liczb dodatnich to : %f\n",mean_p);
    printf("Ilosc liczb ujemnych to : %d\n",quant_n);
    printf("Srednia liczb ujemnych to : %f\n\n\n",mean_n);
}


void menu(){
    int wybor;
    printf("|===========================================|\n");
    printf("|Wybierz program ktory chcialbys uruchomic :|\n");
    printf("|===========================================|\n");
    printf("|1.Wypisanie tabliczki mnozenia             |\n");
    printf("|===========================================|\n");
    printf("|2.Suma cyfr liczby calkowitej              |\n");
    printf("|===========================================|\n");
    printf("|3.NWW i NWD                                |\n");
    printf("|===========================================|\n");
    printf("|4.Suma szeregu                             |\n");
    printf("|===========================================|\n");
    printf("|5.Wartosc srednia liczb losowych           |\n");
    printf("|===========================================|\n");
    printf("|6.Zakonczenie programu                     |\n");
    printf("|===========================================|\n\n\n");
    scanf("%d",&wybor);
    switch(wybor){
        case 1 :
            zad1();
            menu();
            break;
        case 2 :
            zad2();
            menu();
            break;
        case 3 :
            zad3();
            menu();
            break;
        case 4  :
            zad4();
            menu();
            break;
        case 5 :
            zad5();
            menu();
            break;
        case 6 :
            break;
        default:
            printf("\nNiepoprawy wybor , sprobuj ponownie\n\n");
            menu();
            break;
    }
}

int main() {
    menu();
    return 0;
}