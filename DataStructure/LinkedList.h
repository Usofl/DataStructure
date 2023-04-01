#pragma once
#include "Node.h"

template<typename T>
class CLinkedList
{
public:
	CLinkedList()
		: m_frontNode(nullptr)
		, m_backNode(nullptr)
	{

	}
	~CLinkedList() = default;

public:
	inline void push_back(const T& _Data)
	{
		std::shared_ptr<CDoubleLinkedNode<T>>& pNode(std::make_shared<CDoubleLinkedNode<T>>(_Data));

		if (m_backNode)
		{
			m_backNode->SetPreNode(pNode);
			pNode->SetPostNode(pNode);
			m_backNode = pNode;
		}
		else
		{
			m_frontNode = pNode;
			m_backNode = m_frontNode;
		}
	}

	inline void push_front(const T& _Data)
	{
		std::shared_ptr<CDoubleLinkedNode<T>>& pNode(std::make_shared<CDoubleLinkedNode<T>>(_Data));
		
		if (m_frontNode)
		{
			pNode->SetPreNode(m_frontNode);
			m_frontNode = pNode;
		}
		else
		{
			m_frontNode = pNode;
			m_backNode = m_frontNode;
		}
	}

	inline void pop_front()
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

	inline void pop_back()
	{
		if (m_backNode)
		{
			if (m_frontNode == m_backNode)
			{
				m_frontNode = nullptr;
				m_backNode = nullptr;
				return;
			}

			m_backNode = m_backNode->GetLinkNode();
		}
	}

	inline T front(void)
	{
		return *m_frontNode;
	}

	friend std::ostream& operator << (std::ostream& out, CQueue<T> _rhs)
	{
		std::shared_ptr<CDoubleLinkedNode<T>> _CurNode = _rhs.m_frontNode;

		while (_CurNode)
		{
			out << *_CurNode << '\n';
			_CurNode = _CurNode->GetLinkNode();
		}

		return out;
	}

private:
	std::shared_ptr<CDoubleLinkedNode<T>> m_frontNode = nullptr;
	std::shared_ptr<CDoubleLinkedNode<T>> m_backNode = nullptr;
};