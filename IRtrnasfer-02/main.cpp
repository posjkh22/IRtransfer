#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include <ostream>
#include <fstream>
#include <vector>
#include <utility>
#include <llvm/IRReader/IRReader.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/Bitcode/BitcodeWriter.h>
#include <llvm/Bitcode/BitcodeReader.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/Support/FileSystem.h>

#include "wrapper.hpp"
#include "wTask.hpp"
#include "wFunction.hpp"
#include "wBasicBlock.hpp"
#include "wInstruction.hpp"
#include "printIRcode.hpp"
#include "Path.hpp"
#include "PathImpl.hpp"
#include "checker.hpp"
#include "transferIRcode.hpp"



using namespace llvm;

bool DebugWrapperModule(wTask* wtask);

int main(int argc, char *argv[]) {

	if (argc != 2) {
   		std::cerr << "Usage: " << argv[0] << "bitcode_filename" << std::endl;
    	return 1;
	}

	StringRef filename = argv[1];
	LLVMContext context;
	SMDiagnostic error;
	std::unique_ptr<Module> m = parseIRFile(filename, error, context);
	
	//PrintAllModule(m);

	/* Wrapper */
	wrapper w;

	std::cout << "[BasicBlock Call Split]" << std::endl;
	while(w.splitBBModuleChecker(m) != 0){
		w.splitBBModule(m);
	}
	w.splitBBModule(m);
	std::cout <<  std::endl;
	
	PrintAllModule(m);

	w.wrapperModule(m, w.getwTask());
	w.BaiscBlockBranchAndFunctionCallImpl(w.getwTask());
	w.setPathsInEachFunc(w.getwTask());
	
	
	/* Wrapper Show */
	std::cout << std::endl;
	std::cout << std::endl << "[Fucntion PathList]" << std::endl;
	w.ShowPathsInEachFunc(w.getwTask());

	/* GPL */
	PathImpl pathimpl;
	std::list<Path *> *ResultPathList; 
	wFunction *main_func;
	main_func = w.getwTask()->SearchFunction(std::string("main"));
	
	/* Make GPL */
	ResultPathList = pathimpl.GenerateGPL(main_func->getPATHSLIST());

	std::cout << std::endl;
	std::cout << std::endl << "[Generated Global PathList]" << std::endl;
	PathList pathList(ResultPathList);
	pathList.ShowPathList();
	std::cout << std::endl;

	Path *path1 = pathList.getNextPath();
	Path *path2 = pathList.getNextPath();

	/*

	std::cout << std::endl << "[Determine same Path Example]" << std::endl;
	std::cout << "Path1:" << std::endl;
	path1->ShowPath();
	std::cout << "Path2:" << std::endl;
	path2->ShowPath();

	Path *result = pathimpl.createSameElementPath(path1, path2);
	std::cout << "Result Path:" << std::endl;
	result->ShowPath();
	
	*/

	/* Transfer IRcode */
	transferIRcode transIR;
	IRBuilder<> builder(context);

	/* Generate Function Basic */
	transIR.InsertFunction(m, context, builder);

	/* InsertIRcode */
	transIR.InsertIRcode(m, context, builder, "f1");
	transIR.InsertIRcode(m, context, builder, "f2");
	transIR.InsertIRcode(m, context, builder, "f3");
	transIR.InsertIRcode(m, context, builder, "f4");
	transIR.InsertIRcode(m, context, builder, "f5");


	/* Transfer IRcode */
	Module *mp = m.release();
	std::error_code EC;
	raw_fd_ostream OS("Result.bc", EC, sys::fs::F_None);


	WriteBitcodeToFile(mp, OS, true, nullptr, true, nullptr);
	OS.flush();




	//main_func->viewPathsList();
	//DebugWrapperModule(w.getwTask());

	return 0;
}






bool DebugWrapperModule(wTask* wtask){
	
	std::cout << "[Debug Test]" << std::endl;
	std::list<wFunction *>::iterator iter1;
	for(iter1 = wtask->getwFuncList()->begin(); iter1 != wtask->getwFuncList()->end(); iter1++){
		std::cout << "Function: " << (*iter1)->getFunction()->getName().str() << "(" ;

		wFunction *wfunc = (*iter1);
		std::list<wBasicBlock *>::iterator iter2;

		if(wfunc->getFuncRetTy() == wFunction::FuncRetTy::VoidTy){
			std::cout << "VoidTy)" << std::endl;
		}else{
			std::cout << "NonVoidTy)" << std::endl;
		}

		for(iter2 = wfunc->getwBBList()->begin(); iter2 != wfunc->getwBBList()->end(); iter2++){
			std::cout << " BasicBlock: " << (*iter2)->getBasicBlock() << " ";
			std::cout << " wBasicBlock: " << (*iter2) << " ";
			std::cout << "[" << *((*iter2)->getName()) << "]";
			std::cout << "Call Num: " << (*iter2)->getNumFuncCall() << std::endl;

			std::pair<wBasicBlock *, wBasicBlock *> *branchBlockPair = (*iter2)->getBranchBlock();

			if((*iter2)->getType() == wBasicBlock::ONE_BRANCH){
				wBasicBlock *target1 = branchBlockPair->first;
				std::cout << " [BranchBlock]: " << target1->getBasicBlock() << " ";
				std::cout << " [wBranchBlock]: " << target1->getBasicBlock() << std::endl;

			}else if((*iter2)->getType() == wBasicBlock::TWO_BRANCH){
				wBasicBlock *target1 = branchBlockPair->first;
				wBasicBlock *target2 = branchBlockPair->second;
				std::cout << " [BranchBlock]: " << target1->getBasicBlock() << " ";
				std::cout << " [wBranchBlock]: " << target1 << std::endl;
				std::cout << " [BranchBlock]: " << target2->getBasicBlock() << " ";
				std::cout << " [wBranchBlock]: " << target2 << std::endl;
			}else{
				std::cout << " [Return]" << std::endl;

			}

			wBasicBlock *wbb = (*iter2);
			std::list<wInstruction *>::iterator iter3;
			for(iter3 = wbb->getwInstList()->begin(); iter3 != wbb->getwInstList()->end(); iter3++){
				std::cout << "   Instruction: " << (*iter3)->getInstruction()->getOpcodeName();
					
				wInstruction *wInst = *iter3;
				int opnt_cnt = wInst->getInstruction()->getNumOperands();

				for(int i = 0; i < opnt_cnt; i++)
       	 		{
          			Value *opnd = wInst->getInstruction()->getOperand(i);
					std::string o = opnd->getName();
					if(opnd->hasName()) {
						std::cout << " [S]" << o;

					} else {
						std::cout << " [P]" << opnd;
					}
				}
				std::cout << std::endl;
				
			}
		}	
	}
	return true;
}
