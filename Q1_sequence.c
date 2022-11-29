#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

int fermat_prime(int x,int y){

    int modulus = 1;
    for (int i=1; i<=x-1; i++)
        modulus = (modulus * y%x)%x;
    
    return modulus;
}


int main(){

    char st;
    int cnt = 499;
    int m;
    long prod;
    double t_start, t_end;
    t_start = omp_get_wtime();
    for (int n=2; n<=500; n++){
        st = 'T';
        for (int m = 2; m<n; m++){
            if ( fermat_prime(n,m) != 1){
                cnt --;
                st = 'F';
                break;
            }
        }
        if (st == 'T')
            printf("%d\t",n);
    }
    t_end = omp_get_wtime();

    printf("\ncnt: %d\n",cnt);
    printf("Time required to find primes = %f seconds\n", t_end - t_start);
    return 0;
}