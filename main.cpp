#include <iostream>
#include <armadillo>
#include <cstdlib>
#include <cstdio>
#include <iomanip>


using namespace std;
using namespace arma;

int main()
{
    clock_t start, finish;
    double x, time, y;
    int l,i,j,k;
    int number;
    number=0;
    for(l=0;l<5;l++){
    number+=100;
    double **A;
    A= new double*[number];
    for(i=0;i<number;i++){
        A[i]= new double[number];
        }
    double **B;
    B= new double*[number];
    for(i=0;i<number;i++){
        B[i]= new double[number];
        }
    double **C;
    C= new double*[number];
    for(i=0;i<number;i++){
        C[i]= new double[number];
        }
    for (i=0;i<number;i++){
        for(j=0;j<number; j++){
            x=rand();
            y=rand();
            C[i][j]= x;
            B[i][j]=y;

        }
    }
    start=clock();
    for (i=0;i<number;i++){
        for(j=0;j<number; j++){
            for(k=0; k < number; k++){
                A[i][j]+=B[i][k]*C[k][j];
            }
        }
    }
    finish=clock();
    time=(double)(finish-start)/CLOCKS_PER_SEC;
    cout << "Time: " << setprecision(8) << time << endl;

    /*for (i=0;i<number;i++){
        for(j=0;j<number; j++){
            cout << setw(4)<< setprecision(5) << A[i][j]<< setw(4);
        }
        cout << endl;
    }*/
}
    return 0;
}

