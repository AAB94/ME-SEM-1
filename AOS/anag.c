#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char str1[10000];
char str2[10000];
char alp[26];


int main(){
	scanf("%s",str1);
	scanf("%s",str2);
	int ans = 0,i;
	int c1[26]={0},c2[26]={0};	
	int len1,len2;
	len1 = strlen(str1);
	len2 = strlen(str2);
	for(i = 0;i < len1;i++){
		++c1[str1[i] - 'a'];
	}
	for(i = 0;i < len2;i++){
		++c2[str2[i] - 'a'];
	}
	for(i = 0;i < 26;i++){
		ans += abs(c1[i] - c2[i]);	
	}
	printf("%d",ans);	
	return 0;
}
