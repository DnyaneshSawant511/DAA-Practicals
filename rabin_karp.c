#include <stdio.h>
#include <stdlib.h>
int mod = 1e9+7;

int f(char c){
    return (int)c - (int)'a' + 1;
}

int power(int p){
    int ans = 1;
    for(int i = 1; i <= p; i++){
        ans = (ans%mod * 10%mod)%mod;
    }
    return ans;
}

int main(){

    char S[100], P[100];
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%s", &S);
    scanf("%s", &P);

    int pattern_hash = 0;
    int str_hash = 0;
    for(int i = 0; i < m; i++){
        pattern_hash = ((10*pattern_hash)%mod + f(P[i])%mod)%mod;
        str_hash = ((10*str_hash)%mod + f(S[i])%mod)%mod;
    }

    for(int i = 0; i <= (n-m); i++){
        if(str_hash == pattern_hash){
            printf("Occurrence Found at Position %d.\n", i);
        }
        if(i==n-m)break;

        str_hash = (str_hash - (f(S[i])*power(m-1)))%mod;
        if(str_hash<0)str_hash += mod;

        str_hash *= 10;
        str_hash %= mod;

        str_hash += f(S[i+m]);
        str_hash %= mod;

    }

    return 0;

}