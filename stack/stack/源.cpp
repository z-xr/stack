#include<iostream>
using namespace std;

//1.定义
typedef struct Node* Link;
struct Node {
	int num;
	Link next;
};

//2.创建堆栈头结点
Link CreateStack()
{
	Link s;
	s = new Node;
	s->next = NULL;
	return s;
}

//3.判断堆栈是否为空
int IsEmpty(Link s)
{
	return(s->next == NULL);
}

//4.入栈
void Push(int num, Link s)
{
	Link L;
	L = new Node;
	L->num = num;
	L->next = s->next;
	s->next = L;
}

//5.出栈，并返回出栈数据
int Pop(Link s)
{
	Link firstcell;
	int topnum;

	if (IsEmpty(s)) {
		cout << "堆栈空" << endl;
		return NULL;
	}
	else {
		firstcell = s->next;
		s->next = firstcell->next;
		topnum = firstcell->num;
		delete firstcell;
		return topnum;
	}
}
int main()
{
	Link top;
	int i;

	//创建堆栈头结点
	top = CreateStack();

	//将数据1,2,3,4,5压入栈中
	for (i = 1; i < 6; i++) {
		Push(i, top);
		Link top2 = top->next;
		cout << top2->num << endl;
	}

	//将堆栈上两个数据弹出栈
	for (i = 1; i < 3; i++) {
		cout << Pop(top) << endl;
	}

}