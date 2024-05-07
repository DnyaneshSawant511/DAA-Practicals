#include <stdio.h>
#include <stdlib.h>

int max(int x, int y){
    if(x>y)return x;
    return y;
}

int main(){

    int n, m;
    scanf("%d%d", &n, &m);

    char s[100], t[100];
    scanf("%s", &s);
    scanf("%s", &t);

    int dp[n][m];
    if(s[0]==t[0]){
        dp[0][0] = 1;
    } else {
        dp[0][0] = 0;
    }
    for(int i = 1; i < n; i++){
        if(s[i]==t[0]){
            dp[i][0] = 1;
        } else {
            dp[i][0] = dp[i-1][0];
        }
    }
    for(int j = 1; j < m; j++){
        if(s[0]==t[j]){
            dp[0][j] = 1;
        } else {
            dp[0][j] = dp[0][j-1];
        }
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(s[i]==t[j]){
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

    return 0;

}