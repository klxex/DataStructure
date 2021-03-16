#pragma once
#include<time.h>
#include<iostream>
#include<stack>
#ifndef HOME
#define HELLO 3
#define a(x) x*x
#define f(x) {return x*x}
#endif

#if HOME==3

#endif
using namespace std;
namespace H {

	enum A { MON, TUE, THREE };
	class BinarySearchTree {
	private:
		class Node {
			
		public:
			Node* leftnode=nullptr;
			Node* rightnode=nullptr;
			int value;
			Node(int value) {
				this->value = value;
			}

		};
	public:
		Node* root;
		void insertNode(int a);
		int deleteNode(int value);
		void traverse1();
		void traverse2();
		void traverse3();
		void posttraverse(Node* visit);
	};



}

void H::BinarySearchTree::insertNode(int value) {
	if (root == nullptr) {
		root = new Node(value);
		return;
	}
	Node* temp = root;
	Node* child;
	if (value <= temp->value) {
		child=temp->leftnode;
	}
	else {
		child=temp->rightnode;
	
	}
	
	while (child != nullptr) {
		temp = child;
		if (value <= temp->value) {
			child = temp->leftnode;
		}
		else {
			child = temp->rightnode;

		}
	}

	if (value <= temp->value) {
		temp->leftnode = new Node(value);
		
	}
	else {
		temp->rightnode = new Node(value);
		
	}

	return;
}

int H::BinarySearchTree::deleteNode(int value) {

	if (root == nullptr) {
		return -1;
	}
	
	//루트요소를 지울때
	if (root->value == value) {
		Node* temp = nullptr;
		temp = root;
		//자식이 0인경우
		if (root->leftnode == nullptr && root->rightnode == nullptr) {
			root = nullptr;
		}
		//왼쪽만 있는경우
		else if ((root->leftnode != nullptr) && (root->rightnode == nullptr)) {
			root = root->leftnode;
		}
		//오른쪽만 있는경우
		else if ((root->leftnode == nullptr) && (root->rightnode != nullptr)) {
			root = root->rightnode;
		}
		//양쪽다있는경우
		else {
			root = root->leftnode;
		}
		
		free(temp);
		
		return 0;
	}


	Node* parent = root;
	Node* child;

	//부모와 자식 설정
	if (value < root->value) {
		child = root->leftnode;
	}
	else {
		child = root->rightnode;
	}

	//value 동일한 노드 찾기
	while (child != nullptr) {
		if (child->value == value) {
			break;
		}
		else if (value < child->value) {
			parent = child;
			child = child->leftnode;
		}
		else if (value > child->value) {
			parent = child;
			child = child->rightnode;
		}
		
	}
	//자식없는경우 리턴
	if (child == nullptr) {
		return -1;
	}
	else {  
		Node* temp=nullptr;
		if (child->leftnode != nullptr && child->rightnode != nullptr) {    //양쪽다있는경우
			
			temp =child->leftnode;
			
		}
		else if (child->leftnode != nullptr && child->rightnode == nullptr) { //왼쪽노드만
			temp = child->leftnode;
		}
		else if (child->leftnode == nullptr && child->rightnode != nullptr) { //오른쪽노드만
			temp = child->rightnode;
		}
		else {																  //하나도 없는경우
			
		}

		if (temp != nullptr) {
			if (parent->leftnode == child) {
				parent->leftnode = temp;
			}
			else {
				parent->rightnode = temp;
			}
		}
		free(child);

		
	}
	return 0;
}

void H::BinarySearchTree::traverse1() {
	

	Node* temp = root;
	stack<Node*> st;
	if (root == nullptr) {
		return;
	}
	st.push(temp);
	
	while (st.empty()!=1) {
		
		temp=st.top();
		st.pop();
		cout << temp->value << endl;
		if (temp->rightnode != nullptr) {
			st.push(temp->rightnode);
		}
		if (temp->leftnode != nullptr) {
			st.push(temp->leftnode);
		}
		
		
	}

	return;
}

void H::BinarySearchTree::traverse2() {
	if (root == nullptr) {
		return;
	}
	
	posttraverse(root);
	return;
	
}

void H::BinarySearchTree::posttraverse(Node* visit) {
	if (visit == nullptr) {
		return;
	}
	
	posttraverse(visit->leftnode);
	posttraverse(visit->rightnode);
	cout << visit->value << endl;
	return;
}

void H::BinarySearchTree::traverse3() {
	Node* temp = root;
	stack<Node*> st;
	if (root == nullptr) {
		return;
	}
	st.push(temp);

	while (st.empty() != 1) {

		temp = st.top();
		st.pop();
		
		if (temp->leftnode != nullptr) {
			st.push(temp->leftnode);
		}
		cout << temp->value << endl;
		if (temp->rightnode != nullptr) {
			st.push(temp->rightnode);
		}

	}
	return;
}