#include<stdio.h>

#define M 3
#define N 3

int main() {
    double a[M][N] = {3, 5, 6,
                      4, 2, 1,
                      0, 7, 1};
    double v[N] = {2, 1, -2}, b[M];
    int i, j;

    for(i=0; i<M; i++) {
        b[i] = 0;
        for(j=0; j<N; j++) {
            b[i]+= a[i][j]*v[j];
        }
    }
    printf("b = %.0lf, %.0lf, %.0lf \n", b[0], b[1], b[2]);
    return 0;
}
