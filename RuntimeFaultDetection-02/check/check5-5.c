
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


int *fnc1(int *ptr1){

	int *a = ptr1;
	return a;
}

int *fnc2(int *ptr2, int *ptr3){

	return ptr2;
}

void fnc3(int *ptr2, int *ptr3){

	int a = 0;
	free(ptr2);
	free(ptr3);

}


int main(){

	int *ptr1 = (int *)malloc(sizeof(int));
	int *ptr2 = (int *)malloc(sizeof(int));
	int *ptr3 = (int *)malloc(sizeof(int));

	int *returnPtr;

	returnPtr = fnc1(ptr1);
	free(returnPtr);
	
	returnPtr = fnc2(ptr2, ptr3);
	
	fnc3(returnPtr, ptr3);

	return 0;

}
