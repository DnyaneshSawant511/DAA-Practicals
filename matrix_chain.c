#include <stdio.h>
#include <stdlib.h>
int inf = 1e8;

int min(int x, int y){
    if(x<y)return x;
    return y;
}

int main(){

    int n;
    scanf("%d", &n);

    int A[n];
    for(int i = 0; i < n; i++)scanf("%d", &A[i]);

    int dp[n][n];
    for(int i = 0; i < n; i++){
        dp[i][i] = 0;
    }
    for(int len = 2; len < n; len++){
        for(int i = 1; i <= (n-len); i++){
            int j = i+len-1;
            dp[i][j] = inf;
            for(int k = i; k < j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+(A[i-1]*A[k]*A[j]));
            }
        }
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

    return 0;

}