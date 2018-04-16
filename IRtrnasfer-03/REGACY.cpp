
bool DebugBaiscBlockBranchAndFunctionCallImpl(wTask* wtask){

	std::list<wFunction *>::iterator iter1;
	for(iter1 = wtask->getwFuncList()->begin(); iter1 != wtask->getwFuncList()->end(); iter1++){
		std::cout << "Function: " << (*iter1)->getFunction()->getName().str() << std::endl;

		wFunction *CurrentFunc = (*iter1);
		std::list<wBasicBlock *>::iterator iter2;
		for(iter2 = CurrentFunc->getwBBList()->begin(); iter2 != CurrentFunc->getwBBList()->end(); iter2++){
			std::cout << " BasicBlock: " << (*iter2)->getBasicBlock() << std::endl;

			wBasicBlock *CurrentBB = (*iter2);
			std::list<wInstruction *>::iterator iter3;
			for(iter3 = CurrentBB->getwInstList()->begin(); iter3 != CurrentBB->getwInstList()->end(); iter3++){
				std::cout << "   Instruction: " << (*iter3)->getInstruction()->getOpcodeName() << std::endl;
				
				Instruction *CurrentInst = (*iter3)->getInstruction();

				if(!strcmp(CurrentInst->getOpcodeName(), "call")){
					
					Value *branch_opnd = CurrentInst->getOperand(CurrentInst->getNumOperands() -1);
					Function *branch_func = reinterpret_cast<Function *>(branch_opnd);
					wFunction *target_wfunc =  wtask->SearchFunction(branch_func);
					(*iter2)->pushFuncCallList(target_wfunc);
				}

				if(!strcmp(CurrentInst->getOpcodeName(), "br")){
					/* Unconditional branch */
					if(CurrentInst->getNumOperands() == 1){
						Value* opnd = CurrentInst->getOperand(CurrentInst->getNumOperands() -1);
						CurrentBB->setType(wBasicBlock::BRANCH1);

						BasicBlock *BranchBB = reinterpret_cast<BasicBlock *>(opnd);
						wBasicBlock* BranchwBB = CurrentFunc->SearchBasicBlock(BranchBB);
			
						std::pair<wBasicBlock* , wBasicBlock *> BranchwBBpair = std::make_pair(BranchwBB , reinterpret_cast<wBasicBlock *>(0)); 
						CurrentBB->setBranchBlock(&BranchwBBpair);
						std::cout << "br: " << BranchwBB->getBasicBlock() << std::endl;

					/* Conditional branch: LLVM IR only two direction */	
					}else if(CurrentInst->getNumOperands() == 3) {
						Value* opnd1 = CurrentInst->getOperand(CurrentInst->getNumOperands() -1);
						BasicBlock *BranchBB1 = reinterpret_cast<BasicBlock *>(opnd1);
						wBasicBlock* BranchwBB1 = CurrentFunc->SearchBasicBlock(BranchBB1);
					
						std::cout << "br: " << BranchwBB1->getBasicBlock() << " ";

						Value* opnd2 = CurrentInst->getOperand(CurrentInst->getNumOperands() -2);
						BasicBlock *BranchBB2 = reinterpret_cast<BasicBlock *>(opnd2);
						wBasicBlock* BranchwBB2 = CurrentFunc->SearchBasicBlock(BranchBB2);
						CurrentBB->setType(wBasicBlock::BRANCH2);
						
						std::cout << "br: " << BranchwBB2->getBasicBlock() << std::endl;
						std::pair<wBasicBlock* , wBasicBlock *> BranchwBBpair = std::make_pair(BranchwBB1 , BranchwBB2); 
						CurrentBB->setBranchBlock(&BranchwBBpair);
					}

				}

				if(!strcmp(CurrentInst->getOpcodeName(), "ret")){		
					//std::cout << "    [return!]" << std::endl << std::endl;
					CurrentBB->setType(wBasicBlock::RETURN);
					
					std::cout << "ret: " << std::endl;
				}
					
			}
		}


	}
	return true;
}

bool BaiscBlockBranchAndFunctionCallImpl(wTask* wtask){

	std::list<wFunction *>::iterator iter1;
	for(iter1 = wtask->getwFuncList()->begin(); iter1 != wtask->getwFuncList()->end(); iter1++){

		wFunction *CurrentFunc = (*iter1);
		std::list<wBasicBlock *>::iterator iter2;
		for(iter2 = CurrentFunc->getwBBList()->begin(); iter2 != CurrentFunc->getwBBList()->end(); iter2++){

			wBasicBlock *CurrentBB = (*iter2);
			std::list<wInstruction *>::iterator iter3;
			for(iter3 = CurrentBB->getwInstList()->begin(); iter3 != CurrentBB->getwInstList()->end(); iter3++){
				
				Instruction *CurrentInst = (*iter3)->getInstruction();

				if(!strcmp(CurrentInst->getOpcodeName(), "call")){
					
					Value *branch_opnd = CurrentInst->getOperand(CurrentInst->getNumOperands() -1);
					Function *branch_func = reinterpret_cast<Function *>(branch_opnd);
					wFunction *target_wfunc =  wtask->SearchFunction(branch_func);
					(*iter2)->pushFuncCallList(target_wfunc);
				}

				if(!strcmp(CurrentInst->getOpcodeName(), "br")){
					/* Unconditional branch */
					if(CurrentInst->getNumOperands() == 1){
						Value* opnd = CurrentInst->getOperand(CurrentInst->getNumOperands() -1);
						CurrentBB->setType(wBasicBlock::BRANCH1);

						BasicBlock *BranchBB = reinterpret_cast<BasicBlock *>(opnd);
						wBasicBlock* BranchwBB = CurrentFunc->SearchBasicBlock(BranchBB);
			
						std::pair<wBasicBlock* , wBasicBlock *> BranchwBBpair = std::make_pair(BranchwBB , reinterpret_cast<wBasicBlock *>(0)); 
						CurrentBB->setBranchBlock(&BranchwBBpair);

					/* Conditional branch: LLVM IR only two direction */	
					}else if(CurrentInst->getNumOperands() == 3) {
						Value* opnd1 = CurrentInst->getOperand(CurrentInst->getNumOperands() -1);
						BasicBlock *BranchBB1 = reinterpret_cast<BasicBlock *>(opnd1);
						wBasicBlock* BranchwBB1 = CurrentFunc->SearchBasicBlock(BranchBB1);
					

						Value* opnd2 = CurrentInst->getOperand(CurrentInst->getNumOperands() -2);
						BasicBlock *BranchBB2 = reinterpret_cast<BasicBlock *>(opnd2);
						wBasicBlock* BranchwBB2 = CurrentFunc->SearchBasicBlock(BranchBB2);
						CurrentBB->setType(wBasicBlock::BRANCH2);
						
						std::pair<wBasicBlock* , wBasicBlock *> BranchwBBpair = std::make_pair(BranchwBB1 , BranchwBB2); 
						CurrentBB->setBranchBlock(&BranchwBBpair);
					}
				}
				if(!strcmp(CurrentInst->getOpcodeName(), "ret")){		
					CurrentBB->setType(wBasicBlock::RETURN);
				}
			}
		}


	}
	return true;
}


bool wrapperModule(std::unique_ptr<Module> &m, wTask* wtask){

	/* Module Entry */
  	for (auto iter1 = m->getFunctionList().begin(); iter1 != m->getFunctionList().end(); iter1++) {

		/* Function Entry */
		Function &f = *iter1;
		wFunction *wf = new wFunction;
		wf->setwFunction(&f);
		wtask->pushFuncList(wf);

		for (auto iter2 = f.getBasicBlockList().begin(); iter2 != f.getBasicBlockList().end(); iter2++) {

			/* BasicBlock Entry */
			BasicBlock &bb = *iter2;
			wBasicBlock *wbb = new wBasicBlock;

			
			/* split BB by "call instruction" */

			#ifdef DD
		  	for (auto iter3 = bb.begin(); iter3 != bb.end(); iter3++) {

				/* Instruction Entry */
				Instruction &inst = *iter3;

				BasicBlock *newSplitedBB;
				if(!strcmp(inst.getOpcodeName(), "call")){
					newSplitedBB = bb.splitBasicBlock(&inst);
					//f.getBasicBlockList().insert((iter2), newSplitedBB);
					//f.getBasicBlockList().push_back(newSplitedBB);
					//std::cout << "long" << std::endl;
				}
				
				/*
       		 	int opnt_cnt = inst.getNumOperands();

				for(int i = 0; i < opnt_cnt; i++){
          			Value *opnd = inst.getOperand(i);
					wInst->pushOperandList(opnd);
        		}
				*/
			}
			#endif

			wbb->setwBasicBlock(&bb);
			wf->pushBBList(wbb);
	
			
			Instruction* br_inst;
		  	for (auto iter3 = bb.begin(); iter3 != bb.end(); iter3++) {

				/* Instruction Entry */
				Instruction &inst = *iter3;
				br_inst = &inst;

				wInstruction *wInst = new wInstruction;
				wInst->setwInstruction(&inst);
				wbb->pushInstList(wInst);

       		 	int opnt_cnt = inst.getNumOperands();

				for(int i = 0; i < opnt_cnt; i++){
          			Value *opnd = inst.getOperand(i);
					wInst->pushOperandList(opnd);
        		}

      		}
			/* BasicBlock EndPoint */
		
    	}
		/* Function EndPoint */	
  	}

	return true;

}

