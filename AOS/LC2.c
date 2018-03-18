#define R 0
#define W 1
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
int flag = 0;
int p[3][20];
int count;
int fd[2];
char buf[20];
int d1,d2; //Message Dest. 	
int s1=0,s2=0; //Message send Event 
int m2=0,m4=0; //Message recv event
const int e = 8;
pthread_mutex_t lock;


int max(int a,int b){
	if(a>b)
		return a;
	return b;
}

void sendevent(int m){
	char temp[10];
	sprintf(temp,"%d",m); 
	count = write(fd[W],temp,100);
}

int getevent(){
	read(fd[R],buf,count);
	return atoi(buf);
}

void *up1(void *arg1){
	int i;
	pthread_mutex_lock(&lock);
	for(i=m2;i<e;++i){
		if(i==m2){
			p[d1][i] = max(p[d1][i],s1+1);
		}
		else
			p[d1][i] = p[d1][i-1] + 1;
	}
	++flag;

	pthread_mutex_unlock(&lock);
}
	

void *up2(void *arg1){
	int i;
	pthread_mutex_lock(&lock);
	for(i=m4;i<e;++i){
		if(i==m4){
			p[d2][i] = max(p[d2][i],s2+1);
		}
		else
			p[d2][i] = p[d2][i-1] + 1;
	}
	++flag;

	pthread_mutex_unlock(&lock);
}	

void printarr(){
	int i,j;

	while(flag!=2);
	for(i=0;i<3;++i){
		for(j=0;j<e;++j){
			printf("%d ",p[i][j]);
		}
		
		printf("\n");
	}
}


int main(){
	int i; 
	for(i=0;i<20;i++){
		p[0][i] = i;
		p[1][i] = i;
		p[2][i] = i;		
	}
	pipe(fd);
	pthread_t t[2];
	int m,s;

	printf("enter SRC PNO ");
	scanf("%d",&s);
	
	printf("enter p%d event ",s);
	scanf("%d",&m);
	s1 = m;
	
	printf("enter PNO that RECV ");
	scanf("%d",&d1);
	
	printf("enter p%d RECV event ",d1);
	scanf("%d",&m);
	sendevent(m);
	m2 = getevent();
	
	printf("enter SRC PNO ");
	scanf("%d",&s);
	
	printf("enter p%d event ",s);
	scanf("%d",&m);
	s2 = m;


	printf("enter PNO that RECV ");
	scanf("%d",&d2);
	printf("enter p%d RECV event",d2);
	scanf("%d",&m);
	
	sendevent(m);
	m4 = getevent();
	pthread_create(&t[0],NULL,up1,NULL);
	pthread_create(&t[1],NULL,up2,NULL);
	pthread_join(t[0],NULL);
	pthread_join(t[1],NULL);
	sleep(2);
        printarr();
	

	return 0;
}
