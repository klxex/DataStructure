
//#include "LinkedList.h"
#include "BinarySearchTree.h"
int main(void) {

	/********************************************* 
	LinkedList<int> a;
	a.add_First(3);
	a.add_First(4);
	a.add_First(5);
	a.delete_first();
	a.print_all();
	return 0;
	*********************************************/



	//이진탐색트리 순회 및 삭제
	H::BinarySearchTree* bst=new H::BinarySearchTree();
	bst->insertNode(5);
	bst->insertNode(3);
	bst->insertNode(1);
	bst->insertNode(2);
	bst->insertNode(4);
	bst->insertNode(10);
	bst->insertNode(8);
	bst->insertNode(9);
	bst->deleteNode(6);
	bst->traverse2();
	
	
	
	
	

}