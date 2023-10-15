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

float fact = 1.0;
int k = 20;
const long double E = 2.718281;
//e = 2,7182818284 5904523536 0287471352 6624977572 4709369995

float Efloat () 
{ 
    float e = 1.0f; 
    int i = 1;
    
    while(fabs(E-e)>0.000001)
    {
        fact = fact*i;
        e += 1.0/fact;
        i++;
    }
    
    fact = 1.0;
    return e ; 
}

/*************************************************/

double Edouble () 
{
    double e = 1.0; 
    int i = 1;
    
    while(fabs(E-e)>0.000001)
    {
        fact = fact*i;
        e += 1.0/fact;
        i++;
    }

    fact = 1.0;
    return e ;  
}
  
/*************************************************/

long double Elongdouble () 
{ 
    long double e = 1.0; 
    int i = 1;
    
    while(fabs(E-e)>0.000001)
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


double power1 (double x, long n) { return 0 ; }

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

double power3 (double x, long n) { return 0 ; }

/*************************************************/
void pow4 (double x, long n , double *r) 
{ 
     
    if (n!=0)  
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

double power5 (double x, long n)
{
    if (n == 0)
         return 1 ;
    else if (n % 2 == 0)
              return (power5(x,n/2)*power5(x,n/2)   ) ;
         else return (power5(x,n/2)*power5(x,n/2) *x) ;   
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

double power7 (double x, long n) { return 0 ; }

/*************************************************/

void pow8 (double x, long n, double *r) 
{ 
    if(n!=0) 
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

double power9 (double x, long n) { return 0 ; }

/*************************************************/
double power10 (double x, long n)
{
    int r = 1.0 ;

    while (n!=0) 
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
        case 2 : return power2a(x,n) ;  // 2 pour 2a
        case 0 : return power2b(x,n) ; // 0 pour 2b
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


int main(int argc, char** argv)
{
    
    printf(" %f \n",power(-2,-2,2));
    return 0 ;
}
