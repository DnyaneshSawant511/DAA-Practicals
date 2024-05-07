#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int n, m;
//n = nodes
//m = edges
int inf = 10000;
int g[100][100];
bool vis[100];
int dist[100];
int parent[100];

int getMin(){
    int index = -1, mn = inf;
    for(int i = 1; i <= n; i++){
        if(!vis[i] && dist[i]<mn){
            mn = dist[i];
            index = i;
        }
    }
    return index;
}

int main(){

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        vis[i] = false;
        dist[i] = inf;
        parent[i] = i;
        for(int j = 1; j <= n; j++){
            g[i][j] = inf;
        }
    }

    //input for edges
    for(int i = 1; i <= m; i++){
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        g[u][v] = c;
        g[v][u] = c;
    }

    dist[1] = 0;
    while(getMin() != -1){
        int i = getMin();
        vis[i] = true;
        for(int j = 1; j <= n; j++){
            if(g[i][j] != inf){
                if(dist[j] > g[i][j]){
                    dist[j] = g[i][j];
                    parent[j] = i;
                }
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += dist[i];
        printf("%d : %d\n", i, parent[i]);
    }
    printf("%d\n", ans);

    return 0;

}