#include <stdio.h>
#include <stdlib.h>

int min(int x, int y){
    if(x<y)return x;
    return y;
}

int main(){

    int n, m;
    //n = number of coins
    //m = total sum
    scanf("%d%d", &n, &m);

    int A[n+1];
    for(int i = 1; i <= n; i++){
        scanf("%d", &A[i]);
    }

    int dp[n+5][m+5];
    for(int i = 0; i <= n; i++){
        dp[i][0] = 0;
    }
    dp[0][0] = 0;
    for(int i = 1; i <= m; i++){
        dp[0][i] = 1e7;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = dp[i-1][j]; //don't pick the coin
            //pick the coin
            if(A[i]<=j){
                dp[i][j] = min(dp[i][j], 1+dp[i][j-A[i]]);
            }
        }
    }
    int i = n, j = m;
    while(j > 0){
        if(dp[i-1][j] < 1+dp[i][j-A[i]]){
            i=i-1;
            continue;
        }
        printf("%d ", A[i]);
        j = j-A[i];
    }

    return 0;

}