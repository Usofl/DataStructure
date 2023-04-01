// DataStructure.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Stack.h"
#include "Queue.h"
#include "LinkedList.h"

int main()
{
	CStack<int> Stack;

	Stack.push(1);
	Stack.push(3);
	Stack.push(5);
	Stack.pop();
	Stack.push(2);
	Stack.push(7);

	std::cout << Stack << std::endl;

	CQueue<int> Queue;

	Queue.push(1);
	Queue.push(6);
	Queue.push(5);
	Queue.pop();
	Queue.push(2);
	Queue.push(8);

	std::cout << Queue << std::endl;

	CLinkedList<int> LinkedList;

    return 0;
}

