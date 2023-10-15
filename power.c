#include <stdio.h>


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



double pow9( double x, long  n ,double *r)
{
    if ( n==0)
    {
        //
    }
    else {
        if( n%2 !=0)
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




int main() {
   
 
    printf(" la puissance est : %.2f",power1 ( 0,0)) ;


    return 0;
}