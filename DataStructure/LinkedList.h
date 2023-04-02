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
	inline void push(const T& _FindData, const T& _Data)
	{
		std::shared_ptr<CDoubleLinkedNode<T>>& pNode(std::make_shared<CDoubleLinkedNode<T>>(_Data));

		std::shared_ptr<CDoubleLinkedNode<T>>& findNode(_FindData);

		if (findNode)
		{
			pNode->SetPostNode(findNode);
			pNode->SetPreNode(findNode->GetPreNode());

			findNode->SetPreNode(pNode);

			if (m_backNode == findNode)
			{
				m_backNode = findNode;
			}
		}
	}

	inline void push_back(const T& _Data)
	{
		std::shared_ptr<CDoubleLinkedNode<T>>& pNode(std::make_shared<CDoubleLinkedNode<T>>(_Data));

		if (m_backNode)
		{
			m_backNode->SetPreNode(pNode);
			pNode->SetPostNode(m_backNode);
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
			m_frontNode->SetPostNode(pNode);
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

			m_frontNode = m_frontNode->GetPreNode();

			if (m_frontNode)
			{
				m_frontNode->GetPostNode()->SetPreNode(nullptr);
				m_frontNode->SetPostNode(nullptr);
			}
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

			m_backNode = m_backNode->GetPostNode();

			if (m_backNode)
			{
				m_backNode->GetPreNode()->SetPostNode(nullptr);
				m_backNode->SetPreNode(nullptr);
			}
		}
	}

	std::shared_ptr<CDoubleLinkedNode<T>> find(const T& _Data)
	{
		std::shared_ptr<CDoubleLinkedNode<T>> _CurNode = m_frontNode;

		while (_CurNode)
		{
			if (_Data == *_CurNode)
			{
				return _CurNode;
			}
			_CurNode = _CurNode->GetPreNode();
		}

		return nullptr;
	}

	inline T front(void)
	{
		return *m_frontNode;
	}

	inline T back(void)
	{
		return *m_backNode;
	}

	friend std::ostream& operator << (std::ostream& out, CLinkedList<T> _rhs)
	{
		std::shared_ptr<CDoubleLinkedNode<T>> _CurNode = _rhs.m_frontNode;

		while (_CurNode)
		{
			out << *_CurNode << '\n';
			_CurNode = _CurNode->GetPreNode();
		}

		return out;
	}

private:
	std::shared_ptr<CDoubleLinkedNode<T>> m_frontNode = nullptr;
	std::shared_ptr<CDoubleLinkedNode<T>> m_backNode = nullptr;
};