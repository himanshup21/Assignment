#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void my_init(){
        srand(time(NULL));     //for different seed at every call
}
void getArray(int n, float arr[n][n]){
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            arr[i][j] = (float)rand()/rand();   //for random reals
}

void printArray(int n, float arr[n][n]){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++)
            printf("%f  ",arr[i][j]);

        printf("\n");
    }
    printf("\n");
}

void matMul(int n, float arrA[n][n], float arrB[n][n], float arrC[n][n]){
    for(int j=0; j<n; j++)
        for (int k=0; k<n; k++){
            float r = arrB[k][j];
            for(int i = 0; i<n; i++)
                arrC[i][j] += arrA[i][k]*r;
        }
}

int main()
{
    int n = 512;    //Matrices size
    float A[n][n], B[n][n], C[n][n];

    //Initializing all entries of C as 0
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            C[i][j] = 0;

    my_init();
    getArray(n, A);

    getArray(n, B);
    matMul(n,A,B,C);
    

    //printArray(n,A);
    //printArray(n,B);
    //printArray(n,C);
}