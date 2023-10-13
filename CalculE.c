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

float fact = 1;
int k = 20;
const long double E = 2.719288;


float Efloat () 
{ 
    
    float e = 1.0f; 

    
        for(int i=1; i<=k; i++)
        {
            fact = fact*i;
            e += 1.0/fact;
        }
    
    return e ; 
}

/*************************************************/

//double Edouble () {retour 0 ; }
  
/*************************************************/

//long double Elongdouble () { return 0 ; }



int main(int argc, char** argv)
{
    printf(" -> %f",Efloat());
    // printf("go");
    return 0 ;
}
