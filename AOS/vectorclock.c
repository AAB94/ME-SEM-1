#define R 0
#define W 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>

int fd[2];
int te; //total events
int flag;
pthread_mutex_t lock;
pthread_t t[3];

typedef struct process{
    int t[3];
}process;

process p[3][40];

typedef struct event{
	int s;  //sender process 
	int mr; //Receiver Process Message  Time
	int ms; //sender Process Message Time
	int d;  //destination/Receiver Process
	int c;  //no of bytes to read from pipe
}event;

event e[2];

void set(){
	int i;
	for(i=0;i<40;i++){
		p[0][i].t[0] = i;
		p[1][i].t[1] = i;
		p[2][i].t[2] = i;	
	}
}

int max(int a,int b){
	if(a>b)
		return a;
	return b;
}

int sendmsg(int x){
	char buf[5];
	sprintf(buf,"%d",x);
	int l = strlen(buf);
	return write(fd[W],buf,l);
}

int recvmsg(int count){
	char buf[5];	
	read(fd[R],buf,count);
	return atoi(buf);
}

void *print(void *arg){
	int i,j,k;	
	while(flag != 2);
	for(i=0;i<3;++i){
		for(j=0;j<te;++j){
                    for(k=0;k<3;++k){
			printf("%d ",p[i][j].t[]);
                    }
		}
		printf("\n");
	}
}

void *fun1(void* y){
	pthread_mutex_lock(&lock);
	int i,j,k;
	event *x = (event *)y;
	int d = x->d;
	x->ms = recvmsg(x->c);
	int ms = x->ms;
	int mr = x->mr;
	for(i=0;i<te;++i){
            if(p[d][i].t[d] == mr){
                for(j=0;j<3;++j){
                    p[d][i].t[j] = max(p[x.s][x.ms].t[j],p[d][i].t[j]);
                }
                for(j=i+1;j<te;++j){
                    for(k=0;k<3;++k){
                        p[d][j].t[k] =  p[d][j-1].t[k]; 
                    }
                }
                break;
            }
	}
	flag++;
	pthread_mutex_unlock(&lock); 
}

int main(){
	pipe(fd);
	int x,y;
	set();	
	printf("Enter numbr of Events ");
	scanf("%d",&te);
	
	//First Event
	
	printf("Enter SRC proc and Event No:  ");
	scanf("%d %d",&x,&y);
	e[0].s = x;
	e[0].c = sendmsg(y);
	printf("Enter DESTN proc and Event No:  ");
	scanf("%d %d",&x,&y);
	e[0].d = x;
	e[0].mr = y;

	//Second Event

	printf("Enter SRC proc and Event No:  ");
	scanf("%d %d",&x,&y);
	e[1].s = x;
	e[1].c = sendmsg(y);
	printf("Enter DESTN proc and Event No:  ");
	scanf("%d %d",&x,&y);
	e[1].d = x;
	e[1].mr = y;
	pthread_create(&t[0],NULL,fun1,&e[0]);
	pthread_create(&t[1],NULL,fun1,&e[1]);
	pthread_create(&t[2],NULL,print,NULL);
	for(x = 0;x<3;++x)
		pthread_join(t[x],NULL);
	return 0;
}
