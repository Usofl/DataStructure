#pragma once
#include "Node.h"

template<typename T>
class CQueue
{
public:
	CQueue()
		: m_frontNode(nullptr)
		, m_backNode(nullptr)
	{

	}
	~CQueue() = default;

public:
	inline void push(const T& _Data)
	{
		std::shared_ptr<CSingleLinkedNode<T>>& pNode(std::make_shared<CSingleLinkedNode<T>>(_Data));

		if (m_backNode)
		{
			m_backNode->SetLinkNode(pNode);
			m_backNode = pNode;
		}
		else
		{
			m_frontNode = pNode;
			m_backNode = m_frontNode;
		}
	}

	inline void pop()
	{
		if (m_frontNode)
		{
			if (m_frontNode == m_backNode)
			{
				m_frontNode = nullptr;
				m_backNode = nullptr;
				return;
			}

			m_frontNode = m_frontNode->GetLinkNode();
		}
	}

	inline T front(void)
	{
		return *m_frontNode;
	}

	friend std::ostream& operator << (std::ostream& out, CQueue<T> _rhs)
	{
		std::shared_ptr<CSingleLinkedNode<T>> _CurNode = _rhs.m_frontNode;

		while (_CurNode)
		{
			out << *_CurNode << '\n';
			_CurNode = _CurNode->GetLinkNode();
		}

		return out;
	}

private:
	std::shared_ptr<CSingleLinkedNode<T>> m_frontNode = nullptr;
	std::shared_ptr<CSingleLinkedNode<T>> m_backNode = nullptr;
};