#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
int n;

//k represents row, i represents the column in which you want to place the queen
bool safe(int k, int i, int pos[]){
    for(int j = 1; j < k; j++){
        if(pos[j]==i || abs(k-j)==abs(i-pos[j]))return false;
        //(row-row) == (col-col) then false
    }                        
    return true;
}

//k represents placing queen in the kth row
void nqueen(int k, int pos[]){
    if(k==n+1){
        printf("Solution Found :- \n");
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(pos[i]==j){
                    printf("Q ");
                } else {
                    printf("_ ");
                }
            }
            printf("\n");
        }
    } else {
        for(int i = 1; i <= n; i++){
            if(safe(k, i, pos)){
                pos[k] = i;
                nqueen(k+1, pos);
            }
        }
    }
}

int main(){
    
    scanf("%d", &n);
    int pos[n+5];
    for(int i = 1; i <= n; i++){
        pos[i] = -1;
    }
    nqueen(1, pos);
    
    return 0;
    
}