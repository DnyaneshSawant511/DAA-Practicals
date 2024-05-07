#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){

    int n, m;
    scanf("%d%d", &n, &m);
    char str[100], pat[100];
    scanf("%s", &str);
    scanf("%s", &pat);

    int prefix[100];
    for(int i = 0; i <= m+5; i++)prefix[i] = 0;

    for(int i = 1; i < m; i++){
        int j = prefix[i-1];
        while(j>0 && pat[i] != pat[j]){
            j = prefix[j-1];
        }
        if(pat[i] == pat[j]){
            j++;
        }
        prefix[i] = j;
    }

    int i = 0, j = 0;
    while(i < n){
        if(str[i] == pat[j]){
            i++;
            j++;
        } else {
            if(j != 0){
                j = prefix[j-1];
            } else {
                i++;
            }
        }        
        if(j==m){
            printf("Found at %d.\n", i-m);
        }
    }

    return 0;

}