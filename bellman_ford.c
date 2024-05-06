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

struct e {
    int u;
    int v;
    int c;
};
struct e edges[1000];
int curr = 0;

int main(){

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        vis[i] = false;
        dist[i] = inf;
        parent[i] = -1;
        for(int j = 1; j <= n; j++){
            g[i][j] = inf;
        }
    }

    //input for edges
    for(int i = 1; i <= m; i++){
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        g[u][v] = c;
        edges[curr].u = u;
        edges[curr].v = v;
        edges[curr].c = c;
        curr++;
    }

    for(int i = 0; i < m; i++){
        printf("%d -> %d at cost %d.\n", edges[i].u, edges[i].v, edges[i].c);
    }

    dist[1] = 0;
    for(int i = 1; i < n; i++){
        for(int i = 0; i < m; i++){
            int u = edges[i].u;
            int v = edges[i].v;
            int c = edges[i].c;
            if(dist[v] > dist[u] + c){
                dist[v] = dist[u] + c;
                parent[v] = u;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        printf("%d => %d\n", i, dist[i]);
    }

    int dest = 3;
    while(dest != -1){
        printf("%d ", dest);
        dest = parent[dest];
    }

    return 0;

}