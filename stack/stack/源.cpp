#include<iostream>
using namespace std;

//1.����
typedef struct Node* Link;
struct Node {
	int num;
	Link next;
};

//2.������ջͷ���
Link CreateStack()
{
	Link s;
	s = new Node;
	s->next = NULL;
	return s;
}

//3.�ж϶�ջ�Ƿ�Ϊ��
int IsEmpty(Link s)
{
	return(s->next == NULL);
}

//4.��ջ
void Push(int num, Link s)
{
	Link L;
	L = new Node;
	L->num = num;
	L->next = s->next;
	s->next = L;
}

//5.��ջ�������س�ջ����
int Pop(Link s)
{
	Link firstcell;
	int topnum;

	if (IsEmpty(s)) {
		cout << "��ջ��" << endl;
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

	//������ջͷ���
	top = CreateStack();

	//������1,2,3,4,5ѹ��ջ��
	for (i = 1; i < 6; i++) {
		Push(i, top);
		Link top2 = top->next;
		cout << top2->num << endl;
	}

	//����ջ���������ݵ���ջ
	for (i = 1; i < 3; i++) {
		cout << Pop(top) << endl;
	}

}