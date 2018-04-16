
typedef struct file {

	int a;

}FILE;

int a = 0;
FILE g_file;


FILE *fopen(char *in, char *mod){

	a++;

	return &g_file;
}

void fclose(FILE *in){

	a--;
}


void fnc1(FILE* fin){

	fclose(fin);
	fclose(fin);

}

int main(){

	FILE *fin  = fopen("file.in", "r");

	fnc1(fin);

	a = 0;

	return 0;

}
