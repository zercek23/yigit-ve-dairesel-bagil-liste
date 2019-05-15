/**        
* @file  Stack.cpp
* @description Stack class'ının içinde tanımlanmış fonksiyonların gövdeleri. 
* @course  1.Öğretim A Grubu  
* @assignment  2.Ödev   
* @date  27.11.2018 
* @author  Burak Bayram E-posta: burakbyrm99@gmail.com  */ 
#include <iostream>
#include "Stack.h"
using namespace std;

Node::Node(const int& itm, Node *nx)
{
	item = itm;
	next = nx;
}

Stack::Stack()
{
	topOfStack = 0;
}

bool Stack::isEmpty()const {
	return topOfStack == NULL;
}
void Stack::push(const int& item) {
	topOfStack = new Node(item, topOfStack);
}
void Stack::pop() {
	Node *tmp = topOfStack;
	topOfStack = topOfStack->next;
	delete tmp;
}
const int& Stack::top()const {
	//if(isEmpty()) throw HATA
	return topOfStack->item;
}
void Stack::makeEmpty() {
	while (!isEmpty())
		pop();
}

Stack::~Stack()
{
	makeEmpty();
	delete topOfStack;
}
