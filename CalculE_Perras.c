
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



int main(int argc, char** argv)
{
    printf(" Efloat--> %.10f \n",Efloat());
    printf(" Edouble--> %.10lf \n",Edouble());
    printf(" Elongdouble--> %.10Lf \n",Elongdouble());
    printf("%f",fact);
    return 0 ;
}
