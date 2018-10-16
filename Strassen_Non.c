#include <stdio.h>
#include <time.h>

void strassen(const int n, int a[][n], int b[][n], int c[][n]){
    if(n == 1) {
        c[0][0] = a[0][0] * b[0][0];
        //multiply(n, a, b, c);
        return;
    }
    const int size = n/2;
    int m1[size][size], m2[size][size],
            m3[size][size], m4[size][size],
            m5[size][size], m6[size][size],
            m7[size][size];

    int temp1[size][size];
    int temp2[size][size];
    for(int i = 0; i < size; i ++){
        for(int j = 0; j < size; j++){
            temp1[i][j] = a[i][j] + a[i+size][j+size];
            temp2[i][j] = b[i][j] + b[i+size][j+size];
        }
    }
    strassen(size, temp1, temp2, m1);

    for(int i = 0; i < size; i ++){
        for(int j = 0; j < size; j++){
            temp1[i][j] = a[i+size][j] + a[i+size][j+size];
            temp2[i][j] = b[i][j];
        }
    }
    strassen(size, temp1, temp2, m2);

    for(int i = 0; i < size; i ++){
        for(int j = 0; j < size; j++){
            temp1[i][j] = a[i][j];
            temp2[i][j] = b[i][j+size] - b[i+size][j+size];
        }
    }
    strassen(size, temp1, temp2, m3);


    for(int i = 0; i < size; i ++){
        for(int j = 0; j < size; j++){
            temp1[i][j] = a[i+size][j+size];
            temp2[i][j] = b[i+size][j] - b[i][j];
        }
    }
    strassen(size, temp1, temp2, m4);

    for(int i = 0; i < size; i ++){
        for(int j = 0; j < size; j++){
            temp1[i][j] = a[i][j] + a[i][j+size];
            temp2[i][j] = b[i+size][j+size];
        }
    }
    strassen(size, temp1, temp2, m5);

    for(int i = 0; i < size; i ++){
        for(int j = 0; j < size; j++){
            temp1[i][j] = a[i+size][j] - a[i][j];
            temp2[i][j] = b[i][j] + b[i][j+size];
        }
    }
    strassen(size, temp1, temp2, m6);

    for(int i = 0; i < size; i ++){
        for(int j = 0; j < size; j++){
            temp1[i][j] = a[i][j+size] - a[i+size][j+size];
            temp2[i][j] = b[i+size][j] + b[i+size][j+size];
        }
    }
    strassen(size, temp1, temp2, m7);

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            c[i][j] = m1[i][j] + m4[i][j] - m5[i][j] + m7[i][j];
            c[i][j + size] = m3[i][j] + m5[i][j];
            c[i + size][j] = m2[i][j] + m4[i][j];
            c[i+size][j+size] = m1[i][j] - m2[i][j] + m3[i][j] + m6[i][j];
        }
    }
}

void multiply(const int n, int a[][n], int b[][n], int c[][n]){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
}

double evaluateStrassen(const int N){

    int a[N][N];
    int b[N][N];

    int result_strassen[N][N];

    double start_strassen = 0, end_strassen = 0;
    double diff_strassen = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = i + j * N;
            b[i][j] = i == j ? 1 : 0;
        }
    }

    start_strassen = clock();
    strassen(N, a, b, result_strassen);
    end_strassen = clock();

    int result = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            result = result && a[i][j] == result_strassen[i][j];
        }
    }

    diff_strassen = (end_strassen - start_strassen);

    printf("RESULT : %s", result == 1 ? "TRUE\n" : "FALSE\n");
    printf("N : %d\n", N);// + ", Threshold : " + K);
    printf("STRASSEN : %lf", diff_strassen);
    return diff_strassen;//diff_normal > diff_strassen;
}

double evaluateNormal(const int N){
    int a[N][N];
    int b[N][N];

    int result_normal[N][N];

    double start_normal = 0, end_normal = 0;
    double diff_normal = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = i + j * N;
            b[i][j] = i == j ? 1 : 0;
        }
    }

    start_normal = clock();
    multiply(N, a, b, result_normal);
    end_normal = clock();

    diff_normal = (end_normal - start_normal);

    printf("N : %d\n", N);
    printf("NORMAL : %lf\n", diff_normal);
    return diff_normal;//diff_normal > diff_strassen;
}

int main(void) {
    double n, s;
    for(int i = 2; ; i = i * 2){
        printf("\n\n");
        n = evaluateNormal(i);
        printf("\n");
        s = evaluateStrassen(i);
        printf("\n");
        if(s < n){
            printf("Found threshold\n");
            break;
        }
    }
    return 0;
}
