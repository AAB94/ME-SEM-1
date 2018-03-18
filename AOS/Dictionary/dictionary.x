struct strlist{
	char str[100];
};

struct dict{
	char word[40];
	int wlen;
	struct strlist meaning[20];
	int count;
};

struct data{
	struct dict d[100];
	int count;	
};

program DICT_PROG{
	version DICT_VERS{
		int  INSERT_DICT_PROG(dict) = 1;
		data DISPLAY_DICT_PROG() = 2;
		int DUPLICATE_DICT_PROG(dict) = 3;
		dict GET_MEANING_DICT_PROG(dict) = 4;
		dict DELETE_WORD_DICT_PROG(dict) = 5;
		int ADD_MEAN_DICT_PROG(dict) = 6;
	} = 1;
} = 0x13451111;
