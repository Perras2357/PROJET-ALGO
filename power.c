#include <stdio.h>


int power1 ( int x , int n ) 
{
    if ( n == 0 )
    {
        return 1 ;
    }
    else 
    {
        return x*power1(x,n-1) ;
    }      
}

int pow3( int x,int n, int *r)
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

int power3 (int x,int n) 
{
    int r = 1;
    pow3 ( x,n,&r);
    return r;
}


int power5 ( int x , int n) 
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

int power7 ( int x , int n) 
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



int pow9( int x, int n ,int *r)
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

int power9 ( int x , int n)
{
    int r = 1 ;
    pow9(x,n,&r);
    return r ;
}




int main() {
   
 
    printf(" la puissance est : %d",power9 (2,5)) ;


    return 0;
}