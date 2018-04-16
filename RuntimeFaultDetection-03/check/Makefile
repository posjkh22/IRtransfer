
all:
	clang -S -emit-llvm -o check1.bc check1.c
	clang -S -emit-llvm -o check2.bc check2.c
	clang -S -emit-llvm -o check3.bc check3.c
	clang -S -emit-llvm -o check4-1.bc check4-1.c
	clang -S -emit-llvm -o check4-2.bc check4-2.c
	clang -S -emit-llvm -o check4-3.bc check4-3.c
	clang -S -emit-llvm -o check4-4.bc check4-4.c
	clang -S -emit-llvm -o check4-5.bc check4-5.c
	clang -S -emit-llvm -o check4-6.bc check4-6.c
	clang -S -emit-llvm -o check4-7.bc check4-7.c
	clang -S -emit-llvm -o check4-8.bc check4-8.c
	clang -S -emit-llvm -o check5-1.bc check5-1.c
	clang -S -emit-llvm -o check5-2.bc check5-2.c
	clang -S -emit-llvm -o check5-3.bc check5-3.c
	clang -S -emit-llvm -o check5-4.bc check5-4.c
	clang -S -emit-llvm -o check5-5.bc check5-5.c
	clang -S -emit-llvm -o check5-6.bc check5-6.c

##opt -O3 -o opt_check4.bc check4.bc

clean:
	rm *.bc
