#include<stdio.h>
#include<stdlib.h>
int max(int a,int b){
	if(a>b) return a;
	return b;
}


int main(){
	int pid;
	int p[3][20];

	int i,e,m1,m2,m3,m4,s1,s2,d1,d2,j;
	printf("No of events ");
	scanf("%d",&e);
	printf("Enter Source Process  ");
	scanf("%d",&pid);
	s1 = pid;
	printf("Enter p%d Msg event ",pid);
	scanf("%d",&m1);
	printf("Enter Process to send Msg to ");
	scanf("%d",&pid);
	d1 = pid;
	printf("Enter p%d recv event ",pid);
     scanf("%d",&m2);
	printf("Enter Source Process  ");
	scanf("%d",&pid);
	s2 = pid;	
	printf("Enter p%d Msg event ",pid);
	scanf("%d",&m3);
	printf("Enter Process to send Msg to ");
	scanf("%d",&pid);
	d2 = pid;
	printf("Enter p%d recv event ",pid);
     scanf("%d",&m4);
	
	for(i=0;i<e;++i){
		p[0][i] = i;
		p[1][i] = i;
		p[2][i] = i;
	}
	for(i=m2;i<e;++i){
		if(i==m2){
			p[d1][i] = max(p[d1][i],m1+1);
		}
		else
			p[d1][i] = p[d1][i-1] + 1;
	}
	for(i = m4;i<e;++i){
		if(i == m4){
			p[d2][i] = max(p[d2][i],m3+1);
		}
		else
			p[d2][i] = p[d2][i-1] + 1;	
	}
	for(i=0;i<3;++i){
		for(j=0;j<e;++j){
			printf("%d ",p[i][j]);		
		}
		printf("\n");
	}
	
}
