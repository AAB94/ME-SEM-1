#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "dictionary.h"



data *out;


int main(int argc,char **argv){
	setbuf(stdout,NULL);
	CLIENT *cl;
	
	
	if(argc != 2){
		printf("client <localhost>");
		exit(1);
	}
	cl = clnt_create(argv[1],DICT_PROG,DICT_VERS,"tcp");
	int ch,i,j;
	int  exit=1;
	int *ptr;
	printf("----------------------------------------------\n");
	printf("       ||       DICTIONARY      ||\n");	
	printf("----------------------------------------------\n");
	while(exit){
		printf("-----------------------------------------------------------------------------------------------------\n");	
		printf("\tEnter 1.Insert New Word  2.Display All  3.Get Meaning   4.Delete Word  5.Add Meaning  6.Exit\n");
		printf("-----------------------------------------------------------------------------------------------------\n");
		scanf("%d",&ch);
		getchar();
		switch(ch){


/*
	Inserts Words into the dictionary.

*/

			case 1:{			 
				dict d;
				d.count = 0;				
				printf("-----------------------------------------------\n");	
				printf("       |        Enter Word!       | \n");
				printf("-----------------------------------------------\n");
				scanf("%[^\n]s",d.word);
				d.wlen = strlen(d.word);				
				ptr = duplicate_dict_prog_1(&d, cl);

				if( *ptr == -1 ){
					printf("\n  *** Word Already Present in Dictionary! *** \n");
					break;				
				}
				int stop = 1;
				int x;
				int z = d.count;
				while(stop){
					printf("-----------------------------------------------\n");	
					printf("   |    Enter 1.Add Meaning 2.Stop    |   \n");
					printf("-----------------------------------------------\n");
					scanf("%d",&x);
					getchar();
					switch(x){
						case 1:{
							char buf[50];
							
							scanf("%[^\n]s",buf);
							strcpy(d.meaning[z].str,buf);
							++z;							
							d.count = z;
							break;
						}
						case 2:
							stop = 0;
							break;										
					}
				}
				ptr = insert_dict_prog_1(&d, cl);
				if(*ptr)
					printf("Done!\n");				
				break; 
			}


/*
	Displays the Dictionary in sorted order.
*/
			case 2:
				out = display_dict_prog_1(NULL,cl);
				printf("-------------------------------------------------");				
				printf("\n\n\tDictionary\n\n");
				printf("-------------------------------------------------\n");
				for(i=0;i<out->count;i++){
					printf("%20s => \n",out->d[i].word);	
					for(j=0;j<out->d[i].count;++j){
						printf("%30s %s\n"," ",out->d[i].meaning[j].str);
					}
				}
				break;
/*		
	All meaning of a specific word are being retrieved
*/
			case 3:{
				char str[40];
				printf("-------------------------------------------------");
				printf("\nEnter Word to Retrieve Meaning\n");
				printf("-------------------------------------------------\n");
				scanf("%[^\n]s",str);
				dict t1,*t2;
				strcpy(t1.word,str);
				t1.wlen = strlen(str); 
				t2 = get_meaning_dict_prog_1(&t1, cl);
				if( t2->wlen == -1){
					printf("\n  *** Word Not Found! *** \n");
					break;				
				}
				else{
					printf("\n  *** Meaning ***\n");
					printf("%20s => \n",t2->word);
					for(i = 0;i < t2->count; ++i){
						printf("%30s %s\n"," ",t2->meaning[i].str);
					}
				}
				break;
			}			
			
/*
	Enter the Word to be deleted.
*/

			case 4:{
				char str[40];
				printf("-------------------------------------------------");
				printf("\nEnter Word to be Deleted\n");
				printf("-------------------------------------------------\n");
				scanf("%[^\n]s",str);
				dict t1,*t2;
				strcpy(t1.word,str);
				t1.wlen = strlen(str); 
				t2 = delete_word_dict_prog_1(&t1, cl);
				if( t2->wlen == -1){
					printf("\n  *** Word Not Found! *** \n");
					break;				
				}
				else{
					printf("\n  *** Meaning ***\n");
					printf("%20s => \n",t2->word);
					for(i = 0;i < t2->count; ++i){
						printf("%30s %s\n"," ",t2->meaning[i].str);
					}
					printf("\n  *** Deleted Successfully ***\n");
				}
				break;
			}
					

/*
	Add more meanings to a word
*/
			case 5:{
				char str[40];
				printf("-------------------------------------------------");
				printf("\nEnter Word to Add Meaning\n");
				printf("-------------------------------------------------\n");
				scanf("%[^\n]s",str);
				dict t1,*t2;
				strcpy(t1.word,str);
				t1.wlen = strlen(str); 
				t2 = get_meaning_dict_prog_1(&t1, cl);
				if( t2->wlen == -1){
					printf("\n  *** Word Not Found! *** \n");
					break;				
				}
				else{
					printf("\n  *** Meaning ***\n");
					printf("%20s => \n",t2->word);
					for(i = 0;i < t2->count; ++i){
						printf("%30s %s\n"," ",t2->meaning[i].str);
					}
				}
				int stop = 1,x;
				int z = t2->count;
				while(stop){
					printf("-----------------------------------------------\n");	
					printf("   |    Enter 1.Add Meaning 2.Stop    |   \n");
					printf("-----------------------------------------------\n");
					scanf("%d",&x);
					getchar();
					switch(x){
						case 1:{
							char buf[50];
							scanf("%[^\n]s",buf);
							strcpy(t2->meaning[z].str,buf);
							++z;							
							t2->count = z;
							break;
						}
						case 2:
							stop = 0;
							break;										
					}
				}
				ptr = add_mean_dict_prog_1(t2, cl);
				if(ptr != NULL)
					printf("Done!\n");	
				else
					printf("Fail!\n");	
				break;
			}

	/*
		Quit program
	*/			
			case 6:
				exit = 0;
				break;									
		}
	}
}
