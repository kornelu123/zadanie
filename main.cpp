/*
 * Autor : Kornel Uriasz
 * Grupa : PT/P 13:15
 * Temat : ????????????
 * Data  : 21.10.2022r
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int a , b ,c ,delta ,  dzien , miesiac , rok ;
float roz1,roz2,promien;
bool isValid= true;

void kwadratowa() {
    printf("Podaj trzy liczby\n");
    scanf("%i %i %i", &a ,&b,&c);
    if(a != 0){
        delta = pow(b,2) - 4*a*c;
        printf("Delta to : %i\n",delta);
        if(delta < 0) {
            printf("Brak rozwiązan równania");
        }
        if(delta == 0){
            roz1 = float(-b)/(float(a)*2);
            printf("Rozwiązanie równania to :%f",roz1);
        }
        if(delta > 0){
            roz1 = (float(-b) - sqrt(float(delta)))/(2*a);
            roz2= (float(-b) + sqrt(float(delta)))/(2*a);
            printf("Rozwiązania równania to : %f i %f",roz1,roz2);
        }
    }else{
        printf("To nie jest równanie kwadratowe");
    }
}

void data(){
    printf("Podaj trzy liczby całkowite : dzień , miesiąc , rok: \n");
    scanf("%i %i %i",&dzien, &miesiac , &rok);
    if((miesiac==2)){
        if((rok%4!=0)&&(dzien > 29)) {
            isValid = false;
        }else if(dzien > 28){
            isValid = false;
        }
    }else if((miesiac%2==0 ) && (dzien > 30) ){
        isValid = false;
    }else if((miesiac%2==1 ) && (dzien > 31) ){
        isValid = false;
    }

    if(isValid){
        if(dzien<10){
            printf("0%i-",dzien);
        }else{
            printf("%i-",dzien);
        }
        if(miesiac<10){
            printf("0%i-",miesiac);
        }else{
            printf("%i-",miesiac);
        }
        printf("%i\n",rok);
    }
}

void trojkat(){
    isValid = true;
    printf("Podaj 3 boki trójkąta : \n");
    scanf("%i %i %i",&a,&b,&c);
    if (a > b){
        int t=a;
        a=b;
        b=t;
    }
    if (b > c){
        int t=b;
        b=c;
        c=t;
    }
    if (a > b){
        int t=a;
        a=b;
        b=t;
    }
    if((a+b)<c){
        isValid = false;
    }
    if(!isValid){
        printf("Trójkąt taki jest niemożliwy\n");
    }
    if(isValid){
        printf("Z takich boków można stworzyć trójkąt ");
        if(a==b&&a==c){
            printf("równoboczny");
        }else if(a==b||b==c||a==c){
            printf("równoramienny");
        }else if((pow(a,2)+pow(b,2))==pow(c,2)){
            printf("prostokątny");
        }else if((pow(a,2)+pow(b,2))>pow(c,2)){
            printf("ostrokątny");
        }else if((pow(a,2)+pow(b,2))<pow(c,2)){
            printf("rozwartokątny");
        }
        printf("\n");
    }
}

void kola(){
    printf("Podaj wartosc minimalna i maksymalna promienia koła oraz liczbe wierszy w tabeli\n");
    scanf("%f %f %i",&roz2,&roz1,&c);
    float krok = float((roz1-roz2)/(c-1));
    printf("==========================================\n");
    printf("| Lp | promien | obwod kola | pole kola  |\n");
    printf("==========================================\n");
    for(int i=1;i<=c;i++){
     promien = roz2 + (i-1)*(krok);
     float pole = M_PI*pow(promien,2);
     float obwod = M_PI*2*promien;
      if(obwod<10&&pole<10){
         printf("| %i | %f |   %f |   %f |\n",i ,promien,obwod,pole);
      }else{
         printf("| %i | %f |  %f |  %f |\n",i ,promien,obwod,pole);
        }
    }
    printf("==========================================\n");
}

int main() {
    printf("Autor : Kornel Uriasz (PT/P 13:15) \n\n");
    kwadratowa();
    data();
    trojkat();
    return 0;
}
