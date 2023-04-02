// DataStructure.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Stack.h"
#include "Queue.h"
#include "Vector.h"
#include "LinkedList.h"
#include "BinarySearchTree.h"

int main()
{
	//CStack<int> Stack;

	//Stack.push(1);
	//Stack.push(3);
	//Stack.push(5);
	//Stack.pop();
	//Stack.push(2);
	//Stack.push(7);

	//std::cout << Stack << std::endl;

	//CQueue<int> Queue;

	//Queue.push(1);
	//Queue.push(6);
	//Queue.push(5);
	//Queue.pop();
	//Queue.push(2);
	//Queue.push(8);

	//std::cout << Queue << std::endl;

	//CLinkedList<int> LinkedList;

	//LinkedList.push_back(52);
	//LinkedList.push_back(1);
	//LinkedList.push_front(3);
	//LinkedList.push_back(194);
	//LinkedList.push_front(10);

	//std::cout << LinkedList << std::endl;

	//std::cout << (*LinkedList.find(194)) << std::endl;

	CVector<int> vector;

	vector.push_back(52);
	vector.push_back(1);
	vector.push_front(3);
	vector.push_back(194);
	vector.push_front(10);

	std::cout << vector << std::endl;

	std::cout << (vector.find(194)) << std::endl;

    return 0;
}

