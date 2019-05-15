/**        
* @file  Stack.h
* @description Stack'in class'ı ve tanımlanmış elemanları.  
* @course  1.Öğretim A Grubu  
* @assignment  2.Ödev   
* @date  27.11.2018 
* @author  Burak Bayram E-posta: burakbyrm99@gmail.com  */ 
struct Node {
	int item;
	Node *next;
	Node(const int& itm, Node *nx);
};

class Stack
{
private:
	Node *topOfStack;
public:
	Stack();
	bool isEmpty()const;
	void push(const int& item);
	void pop();
	const int& top()const;
	void makeEmpty();
	~Stack();
};