
/* Not free Error Case */

int gv = 1;
int a = 0;

void *malloc(int a);
void free(int *ptr);

void *malloc(int size){

	int siz = size;
	a++;
	return (void *)&gv;
}

void free(int *ptr){

	a--;
}


int *fnc1(int *ptr){

	int *a = ptr;
	return a;
}


int main(){

	int *ptr = (int *)malloc(sizeof(int));
	int *returnPtr;

	returnPtr = fnc1(ptr);

	free(returnPtr);
	return 0;

}
