#include<stdio.h>
#include<string.h>
#include "dictionary.h"

void sort();
int find(dict *in);
void delete(int index);

data out;		// Holds all the words & meanings present in dictionary that will be sent to client 
dict *d; 		// points to the array that holds the array of words and meanings that are being enetered by client	
dict td; 		// used in Meaning and Delete function
int count = 0;	// Keeps track of number of Words being entered
int res;		// sends the result of fucntion whether success or failure.


/*
	Insert word along with its meanings to dictionary.
*/

int* insert_dict_prog_1_svc(dict *in, struct svc_req *rqstp){
	if(d == NULL){
		d = (dict *)malloc(100*sizeof(dict));
	}		
	int i,j;	
	strcpy(d[count].word,in->word);
	d[count].count = in->count;	
	d[count].wlen = in->wlen;		
	for(i=0;i<d[count].count;++i){								// d.count keeps track of number of meanings of a word
		strcpy(d[count].meaning[i].str,in->meaning[i].str);		//d[count] is the array
	}
	++count;	
	res = 1;
	return &res;
}

/*
	Displays all Words Entered in Dictionary
	returns type pointer to data that holds all words in dictionary 
*/

data* display_dict_prog_1_svc(void *p, struct svc_req *rqstp){
	int i;
	out.count = count;
	sort();
	for(i=0; i < count ;++i){
		out.d[i] = d[i];			
	}
	return &out;
}

/*
	checks if entered word is already in Dictionary

*/

int* duplicate_dict_prog_1_svc(dict *in, struct svc_req *rqstp){
	int x = find(in);
	if(count > 0 &&  (x >= 0 && x < count)){
		res	= -1;
		return &res;
	}
	res = 0;
	return &res;
}

/*
	retrieve all meaning for the word
*/

dict* get_meaning_dict_prog_1_svc(dict *in, struct svc_req *rqstp){
	int index = find(in);
	if(index == -1){
		td.count = -1;
		td.wlen = -1;
		return &td;
	}
	td = d[index];
		
	return &td;		
}

/*
	Deletes the word from dictionary
*/

dict* delete_word_dict_prog_1_svc(dict *in, struct svc_req *rqstp){
	int index = find(in);
	if(index == -1){
		td.count = -1;
		td.wlen = -1;
		return &td;
	}
	td = d[index];
	delete(index);
	return &td;
}

/*
Adds meanings to a word
*/

int* add_mean_dict_prog_1_svc(dict *in, struct svc_req *rqstp){
	int index = find(in);
	int i,j;		
	i = d[index].count;
	d[index].count = in->count;
	for(;i < in->count ;++i){
		strcpy(d[index].meaning[i].str,in->meaning[i].str);
	}	
	res = 1;
	return &res;
}


/*
	Sorts the words in ascending order eg car,cat,dog etc.
	To avoid unnecessary checks the word length is also matched 
	if length matched then a character by character check is done 
	to ensure words are lexicographically ordered.

*/
void sort(){
	int i,j,z;
	int n = count;
	dict temp;
	for(i=0;i < n; i++){
		for(j=0;j<n-i-1;++j){
			if(d[j].word[0] > d[j+1].word[0]){
				temp = d[j];
				d[j] = d[j+1];
				d[j+1] = temp;								
			}
			else if(d[j].word[0] == d[j+1].word[0]){
				int l,k;
				int l1 = strlen(d[j].word);
				int l2 = strlen(d[j+1].word);
				if(l1 < l2)
					l = l1;
				else
					l = l2;
				for(k=1;k<l;++k){
					if(d[j].word[k]>d[j+1].word[k]){
						temp = d[j];
						d[j] = d[j+1];
						d[j+1] = temp;
						break;					
					}
				}						
			}
		}
	}
}


/*

	-1 when word not found.
	 if word found then current index value of word returned.
*/


int find(dict *in){
	int i;
	int j;
	int f;
	if(count > 0){	
		for(i = 0; i < count; ++i){
			f = 0;
			if((in->wlen == d[i].wlen) && (in->word[0] == d[i].word[0])){				
				for(j = 0;j < in->wlen ; ++j){
					if( in->word[j] == d[i].word[j] ){
						++f;					
					}
					else
						break;				
				}
				if( f == in->wlen ){
					return i;				
				}	
			}
		}
	}
	return -1;
}

/* 
	Delete the specicifed Word 
	and copy contents to new array!
*/
void delete(int index){
	dict *t;
	t = (dict *)malloc(100*sizeof(dict));
	int i,j = 0;
	for(i = 0;i < count;++i){
		if(index != i){
			t[j] = d[i];
			++j;
		}
	}	
	--count;
	free(d);
	d = t;
}

