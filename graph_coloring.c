#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int n, m;
//n = nodes
//m = edges
int g[100][100];
bool vis[100];
int C;
//number of colors

bool done(int color[]){
    for(int i = 1; i <= n; i++){
        if(color[i]==-1)return false;
        for(int j = 1; j <= n; j++){
            if(g[i][j]==1){
                if(color[i] == color[j])return false;
            }
        }
    }
    return true;
}

void func(int i, int color[]){
    if(done(color)){

        printf("Solution Found.\n");
        for(int i = 1; i <= n; i++){
            printf("%d : %d\n", i, color[i]);
        }
        return;

    } else {

        for(int j = 1; j <= n; j++){
            if(g[i][j] == 1 && color[j] == -1){

                for(int k = 1; k <= C; k++){

                    if(k != color[i]){

                        color[j] = k;
                        func(j, color);
                        color[j] = -1;

                    }

                }

            }
        }

    }
}

int main(){

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        vis[i] = false;
        for(int j = 1; j <= n; j++){
            g[i][j] = 0;
        }
    }

    //input for edges
    for(int i = 1; i <= m; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        g[u][v] = 1;
        g[v][u] = 1;
    }
    scanf("%d", &C);

    int color[n+5];
    for(int i = 1; i <= n; i++)color[i] = -1;

    for(int c = 1; c <= C; c++){
        color[1] = c;
        func(1, color);
    }

    return 0;

}