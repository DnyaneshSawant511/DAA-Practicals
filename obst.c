#include <stdio.h>
#include <stdlib.h>

int min(int x, int y){
    if(x<y)return x;
    return y;
}

int main(){

    int n;
    scanf("%d", &n);

    int key[n], freq[n];
    for(int i = 0; i < n; i++)scanf("%d", &key[i]);
    for(int i = 0; i < n; i++)scanf("%d", &freq[i]);

    int dp[n][n];
    for(int i = 0; i < n; i++){
        dp[i][i] = freq[i];
    }

    for(int len = 2; len <= n; len++){
        for(int i = 0; i <= (n-len); i++){
            int j = i+len-1;
            if(len==2){
                int f1 = freq[i];
                int f2 = freq[j];
                dp[i][j] = min(f1+2*f2, f2+2*f1);
            } else {
                int s = 0;
                for(int k = i; k <= j; k++){
                    s += freq[k];
                }
                dp[i][j] = 10000;
                for(int k = i; k <= j; k++){
                    int left = dp[i][k-1];
                    if(k==i)left=0;
                    int right = dp[k+1][j];
                    if(k==j)right=0;
                    if(left+right+s < dp[i][j]){
                        dp[i][j] = left+right+s;
                    }
                }
            }
        }
    }
    printf("%d", dp[0][n-1]);

    return 0;

}