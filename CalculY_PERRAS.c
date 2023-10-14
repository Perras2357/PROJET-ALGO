
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



int main(int argc, char** argv)
{
    
    afficheYlongdouble(30);
    //printf(" Efloat--> %.10f \n",Efloat());
    return 0 ;
}
