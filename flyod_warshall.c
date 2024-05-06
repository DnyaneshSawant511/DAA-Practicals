#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int n, m;
//n = nodes
//m = edges
int inf = 10000;
int g[100][100];
bool vis[100];
int dist[100][100];

int min(int x, int y){
    if(x<y)return x;
    return y;
}

int main(){

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        vis[i] = false;
        for(int j = 1; j <= n; j++){
            g[i][j] = inf;
            dist[i][j] = inf;
        }
        dist[i][i] = 0;
    }

    //input for edges
    for(int i = 1; i <= m; i++){
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        g[u][v] = c;
        dist[u][v] = c;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }

    return 0;

}