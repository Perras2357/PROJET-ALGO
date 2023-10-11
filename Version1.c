

#include <stdio.h>
#include <stdlib.h>

/*************************************************** /
/* */
/* sucre syntaxique */
/* */
/*************************************************** /

#définir ET &&
#définir OU ||
#define N'EST PAS !=
#définir NON !
#définir alors

typedef enum { faux, vrai} bool ;

/*************************************************** /
/* */
/* factorielle */
/* */
/*************************************************** /

fait long (int n)
{ if (n==0) renvoie 1 ;
  sinon, retourne n * fact(n-1) ;
}

// itou avec un arg out => passage par adresse

void bisfact(int n, long * r)
{ si (n==0)
         *r=1,0 ;
  sinon { bisfact(n-1,r) ;
         *r = *r *n ;
       }
}

fait long2 (int n)
{ long r ;
  bisfact(n,&r) ;
  retourner r ;
}

/*************************************************** /
/* */
/* Calcul de e */
/* */
/*************************************************** /

  // d'après google,
  // e = 2,7182818284 5904523536 0287471352 6624977572 4709369995
  // 9574966967 6277240766 3035354759 4571382178 5251664274

     // Il est proposé de faire 3 versions pour observer des phénomènes de précision.
     // C'est le même code, seul le type change.

/*************************************************** /

float Efloat () { return 0 ; }

/*************************************************** /

double Edouble () {retour 0 ; }
  
/*************************************************** /

long double Elongdouble () { return 0 ; }

/*************************************************** /
/* */
/* Suite Y */
/* */
/*************************************************** /

void afficheYfloat (int n) {}

/*************************************************** /

void afficheYdouble (int n) {}

/*************************************************** /

void afficheYlongdouble (int n) {}


/*************************************************** /
/* */
/* Puissance */
/* */
/*************************************************** /


double puissance1 (double x, long n) { return 0 ; }

/*************************************************** /

double puissance2a (double x, long n) { return 0 ; }

/*************************************************** /

double puissance2b (double x, long n) { return 0 ; }

/*************************************************** /

double puissance3 (double x, long n) { return 0 ; }

/*************************************************** /

double puissance4 (double x, long n) { return 0 ; }

/*************************************************** /

     // Observation (1+1/10^k)^(10^k) : rame : 8 en 1/2s, 9 en qqs s, 10 en 1m

double puissance5 (double x, long n)
{
    si (n == 0)
         retourner 1 ;
    sinon si (n % 2 == 0)
              retourner (puissance5(x,n/2)*puissance5(x,n/2) ) ;
         sinon return (power5(x,n/2)*power5(x,n/2) *x) ;   
}

/*************************************************** /

double puissance6 (double x, long n) { return 0 ; }

/*************************************************** /

double puissance7 (double x, long n) { return 0 ; }

/*************************************************** /

double puissance8 (double x, long n) { return 0 ; }

/*************************************************** /

double puissance9 (double x, long n) { return 0 ; }

/*************************************************** /

     // Observation (1+1/10^k)^(10^k) : calcul immédiat

double puissance10 (double x, long n)
{
    double r = 1,0 ;
    tandis que (n N'EST PAS 0)
      { si (n % 2 == 1) alors r = r*x ; // pas d'autre
        n = n / 2 ;
        x = x * x ;
       }
    retourner r ;
}

/*************************************************** /

double puissance (double x, long n, int i)
{ commutateur (i)  
   {
   cas 1 : renvoyer power1(x,n) ; casser ;
   cas 2 : return power2a(x,n) ; casser ; // 2 pour 2a
   cas 0 : renvoie power2b(x,n) ; casser ; // 0 pour 2b
   cas 3 : return power3(x,n) ; casser ;
   cas 4 : renvoie la puissance4(x,n) ; casser ;
   cas 5 : retour power5(x,n) ; casser ;
   cas 6 : retourner la puissance6(x,n) ; casser ;
   cas 7 : retour power7(x,n) ; casser ;
   cas 8 : retourner la puissance8(x,n) ; casser ;
   cas 9 : renvoyer la puissance9(x,n) ; casser ;
  cas 10 : renvoie la puissance10(x,n) ; casser ;
     par défaut : renvoie 0 ;
   }
}

   // remarque : les break sont ici inutiles car les return font déjà des break

/*************************************************** /

    // memes versions que la 10 mais avec des long double, puis des floats
    // but du jeu : observateur des variations de précision

   // observation :
   // imprécision à partir de k~5 (float), k~12 (double), k~14 (long double)
   // rend 1 à partir de k=8 (float), k=16 (double)
   // rend 1 non observé sur les long double, maxint avant atteint

longue double puissance11 (longue double x, longue n)
{
    long double r = 1,0 ;
    tandis que (n N'EST PAS 0)
      { si (n % 2 == 1) alors r = r*x ; // pas d'autre
        n = n / 2 ;
        x = x * x ;
       }
    retourner r ;
}

/*************************************************** /

float power12 (float x, long n)
{
    flottant r = 1,0 ;
    tandis que (n N'EST PAS 0)
      { si (n % 2 == 1) alors r = r*x ; // pas d'autre
        n = n / 2 ;
        x = x * x ;
       }
    retourner r ;
}


/*************************************************** /
/* */
/* Ackermann */
/* */
/*************************************************** /


int A1(int m, int n) { return 0 ; }

int Ackermann1 (int m) { return 0 ; }

/*************************************************** /

int A2(int m, int n) { return 0 ; }

int Ackermann2 (int m) { return 0 ; }

/*************************************************** /

int Ackermann3 (int m) { return 0 ; }

/*************************************************** /

int Ackermann4 (int m) { return 0 ; }

/*************************************************** /

int Ackermann5 (int m) { return 0 ; }

/*************************************************** /
  
int Ackermann (int m, int i)
{ commutateur (i)  
   {
   cas 1 : renvoie Ackermann1 (m) ; // casser ;
   cas 2 : renvoie Ackermann2 (m) ; // casser ;
   cas 3 : renvoie Ackermann3 (m) ; // casser ;
   cas 4 : renvoie Ackermann4 (m) ; // casser ;
   cas 5 : renvoie Ackermann5 (m) ; // casser ;
   par défaut : renvoie 0 ;
   }
}


/*************************************************** /
/* */
/* principal */
/* */
/*************************************************** /


int principal (int argc, char** argv)
{

       double X ;
       long double y ;
       flotter z ;
       
       int cptx ;
  
       nx long ;
       
       int je,j ;
       
/*************************************************** ****************************/
 
    // mettre "if true" vs "if false" selon que vous voulez les tests ou non
  
/**************** petit test sur le fonctionnement du switch ***********/

si vrai) {

 interrupteur (2)  
   {
   cas 1 : printf("toc\n") ; casser ;
   cas 2 : printf("pata") ;
   cas 3 : printf("pouf\n") ; casser ;
   cas 4 : printf("youpla") ;
   par défaut : printf("boum\n") ;
   }


 interrupteur (4)  
   {
   cas 1 : printf("toc\n") ; casser ;
   cas 2 : printf("pata") ;
   cas 3 : printf("pouf\n") ; casser ;
   cas 4 : printf("youpla") ;
   par défaut : printf("boum\n") ;
   }

   printf("\n") ;

}
      
      
/************************ taille des nombres ********************** ***/
      
si vrai) {     
       
       printf("ce programme suppose que les polices longues sont de 8 octets\n") ;
       printf("S'ils n'en font que 4, il faudra utiliser long long\n") ;

       printf("short : %d octets\n", (int) sizeof(short));
       printf("int : %d octets\n", (int) sizeof(int));
       printf("long : %d octets\n", (int) sizeof(long));
       printf("long long : %d octets\n", (int) sizeof(long long));
       printf("float : %d octets\n", (int) sizeof(float));
       printf("double : %d octets\n", (int) sizeof(double));
       printf("long double : %d octets\n", (int) sizeof(long double));
       printf("\n") ;
 
       x = 1,0 ;
       cptx = 0 ;
       tandis que ( (1.0 + x) - 1.0 != 0 )
          {x = x/10 ; cptx++ ; }
       printf("1+1/10^c devient 1 à partir de c=%d pour les double\n", cptx) ;
       printf("et 1+1/10^%d vaut en fait 1+%lf\n", cptx-1, (1.0 + 10*x) - 1.0) ;
        
       printf("ce programme suppose que les doubles font au moins 8 octets\n") ;
       printf("et que ((double) 1+1/10^-15) n'est pas 1 \n") ;       
       printf("Si ce n'est pas le cas, utilisez des long double \n") ;
       
       printf("\n") ;      
}

/************************ factorielle *********************** */

si vrai) {

     printf("%ld \n",fact(5)) ;
     printf("%ld \n",fact2(5)) ;
     printf("\n") ;
}


/****************** Autour de e **************************** ***/

  // d'après google,
  // e = 2,7182818284 5904523536 0287471352 6624977572 4709369995
  // 9574966967 6277240766 3035354759 4571382178 5251664274

si vrai) {  
       

        printf(" e1 = %.20f \n", Efloat()) ;
        printf(" e3 = %.30lf \n", Edouble()) ;
        printf(" e3 = %.40Lf \n", Elongdouble()) ;
        
}

si vrai) {  
            afficheYfloat(30) ;
            afficheYdouble(30) ;
            afficheYlongdouble(30) ;
}
        
/****************** pouvoir ****************************** */

si (faux) {  

        // test simplet, vérifie le BA BA, test de 2^10 pour toutes les versions
        
        pour(i=0 ; i<=10 ; i++)
        printf("Power %d dit que power(2,10) vaut %.0lf \n", i, power(2,10,i) ) ;
        
        printf("\n") ;
      
}

        
si (faux) {  

        je=5 ; // numéro de la version que l'on teste

        // test de la résistance de puissance version i, calcul de (1+1/N)^N
        // pour des N puissances de 10 de plus en plus grosses
     
        x = 1,0 ;
        nx = 1 ;
        pour(j=0 ; j<=15 ; j++)
        {
        printf("puissance %d ((1+10^-%2d)^(10^%2d)) rendu %.12lf\n", i, j, j, puissance(1+x,nx,i)) ;
        x = x/10 ;
        nx = nx * 10 ;
        }
        printf("\n") ;
       
}
     
si (faux) {

        // tests sur la précision que l'on obtient suivant que
        // on utilise float, double, long double

        printf("VERSION 12 avec float \n") ;
        z = 1,0 ;
        nx = 1 ;
        pour(j=0 ; j<=18 ; j++)
        {
        printf("power((1+10^-%2d)^(10^%2d)) rend %.12f\n", j, j, power12(1+z,nx)) ;
        z = z/10 ;
        nx = nx * 10 ;
        }
        printf("\n") ;


        printf("VERSION 10 avec double \n") ;
        x = 1,0 ;
        nx = 1 ;
        pour(j=0 ; j<=18 ; j++)
        {
        printf("power((1+10^-%2d)^(10^%2d)) rendu %.12lf\n", j, j, power10(1+x,nx)) ;
        x = x/10 ;
        nx = nx * 10 ;
        }
        printf("\n") ;


        printf("VERSION 11 avec long double \n") ;
        y = 1,0 ;
        nx = 1 ;
        pour(j=0 ; j<=18 ; j++)
        {
        printf("power((1+10^-%2d)^(10^%2d)) rendu %.12LF\n", j, j, power11(1+y,nx)) ;
        y = y/10 ;
        nx = nx * 10 ;
        }
        printf("\n") ;



}

/****************** Ackermann ***************************** */
                
si (faux) {
 
        for(i=1 ; i<=5 ; i++) // numéro de version
        
        for(j=0 ; j<=5 ; j++) // test de A(j,0) pour j de 0 à 5
        
        printf("Ack%d(%d) = %d \n", i, j, Ackermann(j,i)) ;
}

/*************************************************** **********************/

    renvoie 0 ;
}





