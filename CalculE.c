#include <stdio.h>

float Efloat () 
{ 
    double e =  1 ; double  n = 1 ; double  temp = 1 ; double  val = 2.7182818284 ;

    do 
    {
        temp = temp / n ;
        e += temp ;   
        n = n + 1 ;
    } while( val - e > 0) ;
    
    return e ; 
}

double Edouble () 
{ 
    double e =  1 ; double  n = 1 ; double  temp = 1 ; double  val = 2.7182818284 ;

    do 
    {
        temp = temp / n ;
        e += temp ;   
        n = n + 1 ;
    } while( val - e > 0) ;
    
    return e ; 
}


long double Elongdouble () 
{ 
    long double e =  1 ; long double  n = 1 ; long double  temp = 1 ; long double  val = 2.7182818284 ;

    do 
    {
        temp = temp / n ;
        e += temp ;   
        n = n + 1 ;
    } while( val - e > 0) ;
    
    return e ; 
}

int main() {
   
    printf("la somme est  %.15f \n",Efloat());
    printf("la somme est  %.15f \n",Edouble());
    printf("la somme est  %.15Lf \n",Elongdouble());

    return 0;
}