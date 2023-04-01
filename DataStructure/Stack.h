#pragma once
#include "Node.h"

template<typename T>
class CStack
{
public:
	CStack()
		: m_TopNode(nullptr)
	{
	}
	~CStack() = default;

public:
	inline void push(const T& _Data)
	{
		std::shared_ptr<CSingleLinkedNode<T>>& pNode(std::make_shared<CSingleLinkedNode<T>>(_Data));

		if (m_TopNode)
		{
			pNode->SetLinkNode(m_TopNode);
			m_TopNode = pNode;
		}
		else
		{
			m_TopNode = pNode;
		}
	}

	inline void pop()
	{
		if (m_TopNode)
		{
			m_TopNode = m_TopNode->GetLinkNode();
		}
	}

	inline T top(void)
	{
		return *m_TopNode;
	}

	friend std::ostream& operator << (std::ostream& out, CStack<T> _rhs)
	{
		std::shared_ptr<CSingleLinkedNode<T>> _CurNode(_rhs.m_TopNode);

		while (_CurNode)
		{
			out << *_CurNode << '\n';
			_CurNode = _CurNode->GetLinkNode();
		}

		return out;
	}

private:
	std::shared_ptr<CSingleLinkedNode<T>> m_TopNode = nullptr;
};

