#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define A_A (18-i%19+a%19)%19
#define B_B (21-i%22+b%22)%22
#define C_C (22-i%23+c%23)%23

int main()
{
    srand(time(NULL));
    int A[19],B[22],C[23];
    int a=0,b=0,c=0;
    int aa=10,bb=11,cc=12;
    int i;
    printf("A list : ");
    for(i=0; i<19; i++) {
        A[i]=rand()%2;
        printf("%d ", A[i]);
    }
    printf("\nB list : ");
    for(i=0; i<22; i++) {
        B[i]=rand()%2;
        printf("%d ", B[i]);
    }
    printf("\nC list : ");
    for(i=0; i<23; i++) {
        C[i]=rand()%2;
        printf("%d ", C[i]);
    }
    printf("\n\nOutput : ");
    for(i=0; i<64; i++) {
        if(A[18-aa]==B[21-bb] && A[18-aa]==C[22-cc]) {
            aa++;
            bb++;
            cc++;
            aa%=19;
            bb%=22;
            cc%=23;
            printf("%d ", A[A_A]^B[B_B]^C[C_C]);
            A[A_A]=((A[A_A]^A[(A_A+19-1)%19])^A[(A_A+19-2)%19])^A[(A_A+19-5)%19];
            B[B_B]=B[B_B]^B[(B_B+22-1)%22];
            C[C_C]=((C[C_C]^C[(C_C+23-1)%23])^C[(C_C+23-2)%23])^C[(C_C+23-15)%23];
        }
        else if(A[18-aa]==B[21-bb]) {
            aa++;
            bb++;
            aa%=19;
            bb%=22;
            printf("%d ",A[A_A]^B[B_B]);
            c++;
            A[A_A]=((A[A_A]^A[(A_A+19-1)%19])^A[(A_A+19-2)%19])^A[(A_A+19-5)%19];
            B[B_B]=B[B_B]^B[(B_B+22-1)%22];
        }
        else if(A[18-aa]==C[22-cc]) {
            aa++;
            cc++;
            aa%=19;
            cc%=23;
            printf("%d ",A[A_A]^C[C_C]);
            b++;
            A[A_A]=((A[A_A]^A[(A_A+19-1)%19])^A[(A_A+19-2)%19])^A[(A_A+19-5)%19];
            C[C_C]=((C[C_C]^C[(C_C+23-1)%23])^C[(C_C+23-2)%23])^C[(C_C+23-15)%23];
        }
        else {
            bb++;
            cc++;
            bb%=22;
            cc%=23;
            printf("%d ",B[B_B]^C[C_C]);
            a++;
            B[B_B]=B[B_B]^B[(B_B+22-1)%22];
            C[C_C]=((C[C_C]^C[(C_C+23-1)%23])^C[(C_C+23-2)%23])^C[(C_C+23-15)%23];
        }
    }
    return 0;
}
