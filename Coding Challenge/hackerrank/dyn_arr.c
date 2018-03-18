#include <stdio.h>
#include <stdlib.h>


int main() {
    int n,q,i,j,x,y,num;
    char c;
    scanf("%d %d",&n,&q);
    getchar();
    int **arr = (int **)malloc(n*sizeof(int *));
    for(i=0;i<n;++i){
        num = 0;
        while((c=getchar())!=' '){
            num =  num*10 + (c-'0');                       
        }
        arr[i] = (int *)malloc(num*sizeof(int));
        num  = 0;
        for(j = 0;(c=getchar())!= '\n';){
            if(c != ' '){
               num =  num*10 + (c-'0');                       
            }
            else{
               arr[i][j] = num;
               num = 0;
               ++j;
            }
        }
        arr[i][j] = num;
        num = 0;
    }
    for(i = 0; i < q; ++i){
        scanf("%d %d", &x,&y);
        printf("%d\n",arr[x][y]);
    }
    
    return 0;
}

