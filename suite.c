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


void affiche1 () 
{
    float y = Efloat () - 1 ;
    for( int i = 1 ; i < 30 ; i++)
    {
        printf(" la valeur du terme %d est %f \n",i,y);
       y = (i)*y - 1;  
    }
}

void affiche2 () 
{
    double y = Edouble () - 1 ;
    for( int i = 0 ; i < 30 ; i++) { 
    
        printf(" la valeur du terme %d est %f \n",i,y);
       y = (i+1)*y - 1;  
    }
}

void affiche3 () 
{
   long double y = Elongdouble () - 1 ;
    for( int i = 1 ; i < 30 ; i++)
    {
        printf(" la valeur du terme %d est %Lf \n",i,y);
       y = (i)*y - 1;  
    }
}



int main() {
   
   affiche1 ();
    affiche2 ();
     affiche3 () ;


    return 0;
}