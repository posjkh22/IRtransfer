


int SpecificMem = 0;
int Sum = 0;

void f1(){

	int a = 1;
	if(SpecificMem == 1){
		
		if(a == 1){
			Sum += SpecificMem;
		}
		else{
			Sum -= SpecificMem;
		}
	}
}

void f2(){

	int a = 1;
	if(SpecificMem == 1){
		
		if(a == 1){
			Sum += SpecificMem;
		}
		else{
			Sum -= SpecificMem;
		}
	}
}

void f3(){

	int a = 1;
	if(SpecificMem == 1){
		
		if(a == 1){
			Sum += SpecificMem;
		}
		else{
			Sum -= SpecificMem;
		}
	}
}

void f4(){

	int a = 1;
	if(SpecificMem == 1){
		
		if(a == 1){
			Sum += SpecificMem;
		}
		else{
			Sum -= SpecificMem;
		}
	}
}

void f5(){

	int a = 1;
	if(SpecificMem == 1){
		
		if(a == 1){
			Sum += SpecificMem;
		}
		else{
			Sum -= SpecificMem;
		}
	}
}


int main(){

	SpecificMem = 1;
	Sum += SpecificMem;

	f1();
	f2();
	f3();
	f4();
	f5();

	return 0;
}
