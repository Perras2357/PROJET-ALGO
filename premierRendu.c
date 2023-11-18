
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*************************************************/
/*                                               */
/*                sucre syntaxique               */
/*                                               */
/*************************************************/

#define AND &&
#define OR ||
#define ISNOT != 
#define NOT !
#define then 

typedef enum { false, true} bool ;




/*************************************************/
/*                                               */
/*            Calcul de e                        */
/*                                               */
/*************************************************/
// d'après google,
//e = 2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274
// Il est proposé de faire 3 versions pour observer des phénomènes de précision.
// C'est le même code, seul le type change.

int k = 20;
const long double E = 2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274;
//e = 2,7182818284 5904523536 0287471352 6624977572 4709369995

/*************************************************/
float Efloat () 
{ 
    float fact = 1.0 ;
    float e = 1.0f; 
    
    for(int i = 1; (1/fact)>0; i++)
    {
        fact = fact*i;
        e += 1.0/fact;
        i++;
    }
    
    return e ; 
}

/*************************************************/

double Edouble () 
{
    double fact = 1.0; 
    double e = 1.0; 
    
    for(int i = 1; (1/fact)>0; i++)
    {
        fact = fact*i;
        e += 1.0/fact;
        i++;
    }

    return e ;  
}
  
/*************************************************/

long double Elongdouble () 
{ 
    long double e = 1.0; 
    long double fact = 1.0;
    
    for(int i = 1; (1/fact)>0; i++)
    {
        fact = fact*i;
        e += 1.0/fact;
        i++;
    }

    fact = 1.0;
    return e ; 
}

/*************************************************/
/*                                               */
/*            Suite Y                            */
/*                                               */
/*************************************************/

void afficheYfloat (int n) 
{
    float y ;
    
    n = 30 ;
    y = Efloat () -1;

    for (int i=0;i<30 ;i++ ) 
    {
        printf("%d -> %f \n",i,y);
        y = ((i+1)*y)-1;
    }
}

/*************************************************/

void afficheYdouble (int n) 
{
    double y ;
    
    n = 30 ;
    y = Edouble () -1;

    for (int i=0;i<30 ;i++ ) 
    {
        printf("%d -> %lf \n",i,y);
        y = ((i+1)*y)-1;
    }
}

/*************************************************/

void afficheYlongdouble (int n) 
{
    long double y ;
    
    n = 30 ;
    y = Elongdouble () -1;
    
    for (int i=0;i<30 ;i++ ) 
    {
        printf("%d -> %Lf \n",i,y);
        y = ((i+1)*y)-1;
    }
}

/*************************************************/
/*                                               */
/*            Puissance                          */
/*                                               */
/*************************************************/


double power1 ( double x , long n ) 
{
    if ( n == 0 )
    {
        return 1 ;
    }
    else if ( n < 0)
    {
        return (1/x)*power1(x,n+1) ;
    } 
    else
    {
        return x*power1(x,n-1) ;
    }
}

/*************************************************/

double power2a (double x, long n) 
{ 
    double r = 1.0;

    for (int i=1;i<=fabs(n) ; i++) 
    {
        r = r * x ;  
    }

    if (n<0) 
    {
        return (1.0/r);
    } 
    else
    {
        return r;
    }

}

/*************************************************/

double power2b (double x, long n) 
{ 
    double r = 1.0;

    while (n>0) 
    {
        r = r * x ;
        n-- ;
    }
    return r ; 
}

/*************************************************/

double pow3( double x,long  n, double *r)
{
    if ( n == 0)
    {
        //
    } 
    else 
    {
        *r = *r*x ;
        pow3(x,n-1,r);
    }
}

double power3 (double x,long  n) 
{
    double r = 1.0;
    pow3 ( x,n,&r);
    return r;
}

/*************************************************/
void pow4 (double x, long n , double *r) 
{ 

    if (n ISNOT 0)  
    {
        *r *= x;
        pow4(x, n-1, r) ; 
    } 
}

double power4 (double x, long n) 
{ 
    double r = 1.0;
    pow4(x, n, &r);
    return  r; 
}

/*************************************************/

double power5 ( double x , long  n) 
{
    if(n== 0){
        return 1 ;
    }
    else if( n%2 ==0){
        return power5(x, n/2) * power5(x, n/2) ;
    }
    else {
        return power5(x, n/2) * power5(x, n/2) * x;
    }
}

/*************************************************/

double power6 (double x, long n) 
{ 
    double y;
    
    if (n==0) 
    {
        return 1;
    } 
    else 
    {
        y = power6(x,n/2);

        if (n%2==0) 
        {
            return y*y;
        } 
        else 
        {
           return y*y*x ;
        }
    } 
}

/*************************************************/

double power7 ( double x , long  n) 
{
    if(n== 0){
        return 1 ;
    }
    else if( n%2 ==0){
        return power7(x*x, n/2)   ;
    }
    else {
        return power7(x*x, n/2) * x;
    }
}

/*************************************************/

void pow8 (double x, long n, double *r) 
{ 
    if(n ISNOT 0) 
    {
        if (n%2==0) 
        {
            pow8(x*x,n/2,r);
        } 
        else 
        {
            *r *= x ;
            pow8(x*x,n/2,r);
        }
    }
}

double power8 (double x, long n) 
{ 
    double r = 1.0;
    pow8(x,n,&r) ; 
    return r;
}

/*************************************************/

double pow9( double x, long  n ,double *r)
{
    if ( n==0)
    {
        //
    }
    else {
        if( n%2 ISNOT 0)
        {
            *r = *r*x ;
        }
        pow9(x*x,n/2,r);
    }
}

double power9 ( double x , long  n)
{
    double r = 1.0 ;
    pow9(x,n,&r);
    return r ;
}

/*************************************************/
double power10 (double x, long n)
{
    int r = 1.0 ;

    while (n ISNOT 0) 
    { 
        if (n%2 == 1) 
        {
            r = r*x ; 
        } 
        n = n / 2 ; 
        x = x * x ;
    }
    return r ;
}

/*************************************************/

double power (double x, long n, int i)
{ 
    switch (i)  
    {
        case 1 : return power1(x,n) ;
        case 2 : return power2a(x,n) ;  
        case 0 : return power2b(x,n) ; 
        case 3 : return power3(x,n) ;
        case 4 : return power4(x,n) ;
        case 5 : return power5(x,n) ;
        case 6 : return power6(x,n) ;
        case 7 : return power7(x,n) ;
        case 8 : return power8(x,n) ;
        case 9 : return power9(x,n) ;
        case 10 : return power10(x,n);
        default : return 0 ; 
    }
}

/*************************************************/
/*                                               */
/*             Ackermann                         */
/*                                               */
/*************************************************/

 int Ackermann1(int m , int n)
{
    if ( m==0)
    {
        return n+1 ;
    }
    else if ( n==0){
        return Ackermann1(m-1,1);
    }
    else {
        return Ackermann1(m-1,Ackermann1(m,n-1));
    }
}
/*************************************************/
int Ackermann2 (int m, int n) {
    while (m > 0) {
        if (n == 0) {
            n = 1;
        } else {
            n = Ackermann2 (m, n - 1);
        }
        m--;
    }
    if (m == 0) {
        return n + 1;
    } else {
        return Ackermann2 (m - 1, n);
    }
}
/*************************************************/
int Ackermann3(int m, int n) {
    while (m > 0) {
        if (n == 0) {
            n = 1;
        } else {
            n = Ackermann3(m, n - 1);
            m--;
        }
    }
    if (m == 0) {
        return n + 1;
    } else {
        return Ackermann3(m - 1, 1);
    }
}
/*************************************************/
int Ackermann4(int m,int n)
{
    if ( m == 0 ) 
    {
        return n+1 ;
    }
    else {
        int r = 1 ;
        for ( int i =1 ; i <= n+1 ; i++)
        {
            r = Ackermann4(m-1,r);
        }
        return r;
    }
    
}
/*************************************************/
int Ackermann5(int m, int n) {
    while (m > 0) {
        if (n == 0) {
            n = 1;
        } else {
            n = Ackermann5(m, n - 1);
        }
        m--;
    }
    return n + 1;
}
/*************************************************/

int Ackermann (int m, int n , int i) {
    
    switch (i) {
        
        case 1: Ackermann1( m ,  n) ;
                break ;
        case 2: Ackermann2( m ,  n) ;
                break ;
        case 3: Ackermann3( m , n) ;
                break ;
        case 4: Ackermann4( m ,  n) ;
                break ;
        case 5: Ackermann5( m ,  n) ;
                break ;
    default:
            return 0;

    }
}

/*************************************************/
/*                                               */
/*      Fonction Log2()                          */
/*                                               */
/*************************************************/
int ln2(int n)
{
    if (n==1) 
    {
        return 0 ;
    } 
    else 
    {
        return 1 + ln2(n/2);
    }
}
/*************************************************/

/*************************************************/
/*                                               */
/*      FonctionXn()                             */
/*                                               */
/*************************************************/

int X1(int n)
{
    int x = 2 ;
    for (int i = 1; i<=n; i++) 
    {
        x = x+ln2(x);
    }

    return x;
}
/*************************************************/
int X2(int n)
{
    int X ;
    if (n==0) 
    {
        return 2 ;
    } 
    else 
    {
        X = X2(n-1) ;
        return X + ln2(X);
    }
}
/*************************************************/
int sousX3(int n,int r)
{
    int X ;
    if (n==0) 
    {
        return r ;
    }
    else
    {    
        X = sousX3(n-1,r) ;
        return X  + ln2(X);
    }
}

int X3(int n)
{
    int r = 2;
     
    return sousX3(n,r) ;
}
/*************************************************/

void sousX4(int n,int *r)
{
    
    if(n ISNOT 0)
    {
        *r = *r + ln2(*r) ;
        sousX4(n-1,r);
    }
}

int X4(int n)
{
    int r = 2;
    sousX4(n,&r);
    return r;
}


int X (int n, int i)
{ 
    switch (i)  
    {
        case 1 : return X1(n) ;
        case 2 : return X2(n);  
        case 3 : return X3(n) ;
        case 4 : return X4(n) ;
        default : return 0 ; 
    }
}
/*************************************************/

/*************************************************/
/*                                               */
/*               main                            */
/*                                               */
/*************************************************/
 int main(int argc, char** argv)
{

       double x ;
       long double y ;
       float z ;
       
       int cptx ;
  
       long nx ;
       
       int i,j ; 
       
/******************************************************************************/
 
    // mettre "if true" vs "if false" selon que vous voulez les tests ou non
    
/************************  taille des nombres  *************************/
      
if (false) {     
       
       printf("ce programme suppose que les long font 8 octets\n") ;
       printf("S'ils n'en font que 4, il faudra utiliser long long\n") ;

       printf("short : %d octets\n", (int) sizeof(short));
       printf("int : %d octets\n", (int) sizeof(int));
       printf("long : %d octets\n", (int) sizeof(long));
       printf("long long : %d octets\n", (int) sizeof(long long));
       printf("float : %d octets\n", (int) sizeof(float));
       printf("double : %d octets\n", (int) sizeof(double));
       printf("long double : %d octets\n", (int) sizeof(long double));
       printf("\n") ;
 
       x = 1.0 ;
       cptx = 0 ;
       while ( (1.0 + x) - 1.0 ISNOT  0 )
          { x = x/10 ; cptx ++ ; }
       printf("1+1/10^c devient 1 a partir de c=%d pour les double\n", cptx) ; 
       printf("et 1+1/10^%d vaut en fait 1+%lf\n", cptx-1, (1.0 + 10*x) - 1.0) ;
        
       printf("ce programme suppose que les doubles font au moins 8 octets\n") ;
       printf("et que ((double) 1+1/10^-15) n'est pas 1 \n") ;       
       printf("Si ce n'est pas le cas, utiliser des long double \n") ;
       
       printf("\n") ;      
}


/******************    Autour de e      *******************************/

  // d'après google,
  // e = 2,7182818284 5904523536 0287471352 6624977572 4709369995 
  //       9574966967 6277240766 3035354759 4571382178 5251664274

if (true) {  
       

        printf(" e1 = %.20f \n", Efloat()) ;
        printf(" e2 = %.30lf \n", Edouble()) ; 
        printf(" e3 = %.40Lf \n", Elongdouble()) ; 
        
}

if (false) {  
            afficheYfloat(30) ;
             afficheYdouble(30) ;
             afficheYlongdouble(30) ;
}
        
/******************    power     *******************************/

if (false) {  

        //   test simplet, vérifie le B.A. BA, test de 2^10 pour toutes les versions
        
        for(i=0 ; i<=10 ; i++)
        printf("Power %d dit que power(2,10) vaut %.0lf \n", i, power(2,10,i) ) ;
        
        printf("\n") ;
      
}

        
if (false) {  

        i=5 ;  // numéro de la version que l'on teste

        // test de la résistance de power version i, calcul de (1+1/N)^N
        // pour des N puissances de 10 de plus en plus grosses
     
        x = 1.0 ;
        nx = 1 ;
        for(j=0 ; j<11 ; j++)
        {
        printf("power %d ((1+10^-%2d)^(10^%2d)) rend %.12lf\n", i, j, j, power(1+x,nx,j)) ;
        x = x/10 ;
        nx = nx * 10 ;
        }
        printf("\n") ;
       
}
     
if (false) {

        // tests sur la précision que l'on obtient suivant que
        // l'on utilise float, double, long double

        printf("VERSION 12 avec float \n") ;
        z = 1.0 ;
        nx = 1 ;
        for(j=0 ; j<=18 ; j++)
        {
        printf("power((1+10^-%2d)^(10^%2d)) rend %.12f\n", j, j, power10(1+z,nx)) ;
        z = z/10 ;
        nx = nx * 10 ;
        }
        printf("\n") ;


        printf("VERSION 10 avec double \n") ;
        x = 1.0 ;
        nx = 1 ;
        for(j=0 ; j<=18 ; j++)
        {
        printf("power((1+10^-%2d)^(10^%2d)) rend %.12lf\n", j, j, power10(1+x,nx)) ;
        x = x/10 ;
        nx = nx * 10 ;
        }
        printf("\n") ;


        printf("VERSION 11 avec long double \n") ;
        y = 1.0 ;
        nx = 1 ;
        for(j=0 ; j<=18 ; j++)
        {
        printf("power((1+10^-%2d)^(10^%2d)) rend %.12lf\n", j, j, power10(1+y,nx)) ;
        y = y/10 ;
        nx = nx * 10 ;
        }
        printf("\n") ;



}

/******************    Ackermann    *******************************/
                
if (false) { 
 
        for(i=1 ; i<=5 ; i++)  // numéro de version
        
        for(j=0 ; j<4 ; j++)  // test de A(j,0) pour j de 0 à 5
        
        printf("Ack%d(%d) = %d \n", i, j, Ackermann(j,0,i)) ;
}


/****************** Suite Grand X  *******************************/
                
if (false) { 
 
        for(i=1 ; i<=5 ; i++)  // numéro de version
            printf(" X%d  = %d\n",i,X(3,i)) ;
}

/***********************************************************************/

    return 0;
}

