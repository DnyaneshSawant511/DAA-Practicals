#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int n, m;
int g[100][100];

bool done(int child[]){
    int cnt[n+1];
    for(int i = 1; i <= n; i++)cnt[i] = 0;
    for(int i = 1; i <= n; i++){
        if(child[i]==-1)return false;
        cnt[child[i]]++;
        if(cnt[child[i]]>1)return false;
    }
    return true;
}

void func(int i, int child[]){
    //printf("%d\n", i);
    for(int j = 1; j <= n; j++){
        if(g[i][j] == 0 || i==j)continue;
        if(child[j]==-1){
            child[i] = j;
            func(j, child);
            child[i] = -1;
        }
        if(j==1){
            child[i] = 1;
            if(done(child)){
                printf("Solution Found.\n");
                for(int i = 1; i <= n; i++){
                    printf("%d : %d\n", i, child[i]);
                }
            }
            child[i] = -1;
        }
    }
}

int main(){

    scanf("%d%d", &n, &m);
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            g[i][j] = 0;
        }
    }

    for(int e = 1; e <= m; e++){
        int u, v;
        scanf("%d%d", &u, &v);
        g[u][v] = 1;
        g[v][u] = 1;
    }
    int child[n+1];
    for(int i = 1; i <= n; i++)child[i] = -1;
    func(1, child);

    return 0;

}