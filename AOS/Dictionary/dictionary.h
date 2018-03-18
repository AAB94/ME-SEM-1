/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _DICTIONARY_H_RPCGEN
#define _DICTIONARY_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct strlist {
	char str[100];	//length of meaning entered for a word
};
typedef struct strlist strlist;

struct dict {
	char word[40];
	int wlen;   // length of the word
	struct strlist meaning[20]; // holds meanings of the word.
	int count; //maintains the number of meaning for a word
};
typedef struct dict dict;

struct data {
	struct dict d[100]; //stores all words in dictionary
	int count;			// Number of words in dictionary
};
typedef struct data data;

#define DICT_PROG 0x13451111
#define DICT_VERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define INSERT_DICT_PROG 1
extern  int * insert_dict_prog_1(dict *, CLIENT *);
extern  int * insert_dict_prog_1_svc(dict *, struct svc_req *);
#define DISPLAY_DICT_PROG 2
extern  data * display_dict_prog_1(void *, CLIENT *);
extern  data * display_dict_prog_1_svc(void *, struct svc_req *);
#define DUPLICATE_DICT_PROG 3
extern  int * duplicate_dict_prog_1(dict *, CLIENT *);
extern  int * duplicate_dict_prog_1_svc(dict *, struct svc_req *);
#define GET_MEANING_DICT_PROG 4
extern  dict * get_meaning_dict_prog_1(dict *, CLIENT *);
extern  dict * get_meaning_dict_prog_1_svc(dict *, struct svc_req *);
#define DELETE_WORD_DICT_PROG 5
extern  dict * delete_word_dict_prog_1(dict *, CLIENT *);
extern  dict * delete_word_dict_prog_1_svc(dict *, struct svc_req *);
#define ADD_MEAN_DICT_PROG 6
extern  int * add_mean_dict_prog_1(dict *, CLIENT *);
extern  int * add_mean_dict_prog_1_svc(dict *, struct svc_req *);
extern int dict_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define INSERT_DICT_PROG 1
extern  int * insert_dict_prog_1();
extern  int * insert_dict_prog_1_svc();
#define DISPLAY_DICT_PROG 2
extern  data * display_dict_prog_1();
extern  data * display_dict_prog_1_svc();
#define DUPLICATE_DICT_PROG 3
extern  int * duplicate_dict_prog_1();
extern  int * duplicate_dict_prog_1_svc();
#define GET_MEANING_DICT_PROG 4
extern  dict * get_meaning_dict_prog_1();
extern  dict * get_meaning_dict_prog_1_svc();
#define DELETE_WORD_DICT_PROG 5
extern  dict * delete_word_dict_prog_1();
extern  dict * delete_word_dict_prog_1_svc();
#define ADD_MEAN_DICT_PROG 6
extern  int * add_mean_dict_prog_1();
extern  int * add_mean_dict_prog_1_svc();
extern int dict_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_strlist (XDR *, strlist*);
extern  bool_t xdr_dict (XDR *, dict*);
extern  bool_t xdr_data (XDR *, data*);

#else /* K&R C */
extern bool_t xdr_strlist ();
extern bool_t xdr_dict ();
extern bool_t xdr_data ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_DICTIONARY_H_RPCGEN */