#include <stdio.h>
#include <stdlib.h>
int n, A[100];

void merge(int l, int m, int r){
    int B[m-l+1];
    int C[r-m];
    int p = 0;
    for(int i = l; i <= m; i++){
        B[p] = A[i];
        p++;
    }
    p = 0;
    for(int i = m+1; i <= r; i++){
        C[p] = A[i];
        p++;
    }
    int c = l, p1 = 0, p2 = 0;
    while(p1 < (m-l+1) && p2 < (r-m)){
        if(B[p1] < C[p2]){
            A[c] = B[p1];
            p1++;
        } else {
            A[c] = C[p2];
            p2++;
        }
        c++;
    }
    while(p1 < (m-l+1)){
        A[c] = B[p1];
        p1++;
        c++;
    }
    while(p2 < (r-m)){
        A[c] = C[p2];
        p2++;
        c++;
    }
}

void mergesort(int l, int r){
    if(l<r){
        int m = (l+r)/2;
        mergesort(l, m);
        mergesort(m+1, r);
        merge(l, m, r);
    }
}

int main(){

    scanf("%d", &n);
    for(int i = 0; i < n; i++)scanf("%d", &A[i]);
    mergesort(0, n-1);
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }

    return 0;

}