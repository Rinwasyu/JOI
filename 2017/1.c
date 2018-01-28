#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i, j;
    int N, Q, S, T;
    int *A, *L, *R, *X;
    long long tmp;
    
    while (scanf("%d %d %d %d", &N, &Q, &S, &T) != EOF) {
        A = malloc(sizeof(int) * (N + 1));
        L = malloc(sizeof(int) * Q);
        R = malloc(sizeof(int) * Q);
        X = malloc(sizeof(int) * Q);
        
        // 地形データ
        for (i = 0; i < N + 1; i++) {
            scanf("%d", &A[i]);
        }
        
        // 変化データ
        for (i = 0; i < Q; i++) {
            scanf("%d %d %d", &L[i], &R[i], &X[i]);
        }
        
        // シミュレーション
        for (i = 0; i < Q; i++) {
            // 地殻変動
            for (j = L[i]; j <= R[i]; j++) {
                A[j] += X[i];
            }
            
            // 温度測定
            tmp = 0;
            for (j = 1; j < N + 1; j++) {
                if (A[j-1] < A[j]) {
                    tmp -= abs(A[j-1]-A[j]) * S;
                }else{
                    tmp += abs(A[j-1]-A[j]) * T;
                }
            }
            
            printf("%lld\n", tmp);
        }
        
        free(A);
        free(L);
        free(R);
        free(X);
    }
    
    return 0;
}
