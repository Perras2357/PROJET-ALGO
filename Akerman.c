#include <stdio.h>

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

int main() {
   
    printf(" la valeur est  : %d", Ackermann(2,1,3)) ;

    return 0;
}