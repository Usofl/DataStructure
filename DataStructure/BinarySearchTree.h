#pragma once
#include "Node.h"

template<typename T>
class CBinarySearchTree
{
public:
	CBinarySearchTree()
		: m_frontNode(nullptr)
		, m_backNode(nullptr)
	{

	}
	~CBinarySearchTree() = default;

public:
	inline void push(const T& _Data)
	{
		std::shared_ptr<CTreeNode<T>>& pNode(std::make_shared<CTreeNode<T>>(_Data));

		if (m_RootNode)
		{
			std::shared_ptr<CTreeNode<T>>& pCurNode(m_RootNode);
			
			while (pCurNode)
			{
				if (_Data <= *pCurNode)
				{
					if (pCurNode->GetChildNode(0))
					{
						pCurNode = pCurNode->GetChildNode(0);
					}
					else
					{
						pCurNode->SetChildNode(0, pNode);
						pNode->SetParentNode(pCurNode);

						break;
					}
				}
				else
				{
					if (pCurNode->GetChildNode(1))
					{
						pCurNode = pCurNode->GetChildNode(1);
					}
					else
					{
						pCurNode->SetChildNode(1, pNode);
						pNode->SetParentNode(pCurNode);

						break;
					}
				}
			}
			
		}
		else
		{
			m_RootNode = pNode;
		}
	}

	std::shared_ptr<CTreeNode<T>> find(const T& _Data)
	{
		std::shared_ptr<CTreeNode<T>>& pCurNode(m_RootNode);

		while (pCurNode)
		{
			if (*pCurNode == _Data)
			{
				return pCurNode;
			}

			if (_Data < *pCurNode)
			{
				if (pCurNode->GetChildNode(0))
				{
					pCurNode = pCurNode->GetChildNode(0);
				}
				else
				{
					break;
				}
			}
			else
			{
				if (pCurNode->GetChildNode(1))
				{
					pCurNode = pCurNode->GetChildNode(1);
				}
				else
				{
					break;
				}
			}
		}

		return nullptr;
	}

	inline T root(void)
	{
		return *m_RootNode;
	}

	void erase(const T& _Data)
	{
		std::shared_ptr<CTreeNode<T>>& pCurNode(find(_Data));

		if (!pCurNode)
		{
			return;
		}

		std::shared_ptr<CTreeNode<T>>& RightNode(pCurNode->GetChildNode(1));

		if (RightNode)
		{
			while (RightNode->GetChildNode(0))
			{
				RightNode = RightNode->GetChildNode(0);
			}
			
			if (RightNode->GetChildNode(1))
			{
				std::shared_ptr<CTreeNode<T>>& Root(RightNode->GetRootNode());

				Root->GetChildNode(0, RightNode->GetChildNode(1));

				RightNode->GetChildNode(1)->SetRootNode(Root);
			}
			
			if (pCurNode->GetRootNode())
			{
				if (pCurNode == pCurNode->GetRootNode()->GetChildNode(0))
				{
					pCurNode->GetRootNode()->SetChildNode(0, RightNode);
				}
				else
				{
					pCurNode->GetRootNode()->SetChildNode(1, RightNode);
				}
			}
			else
			{
				m_RootNode = RightNode;
			}
			
			RightNode->SetRootNode(pCurNode->GetRootNode());

			RightNode->SetChildNode(0, pCurNode->GetChildNode(0));
			RightNode->SetChildNode(1, pCurNode->GetChildNode(1));
		}
		else
		{
			std::shared_ptr<CTreeNode<T>>& LeftNode(pCurNode->GetChildNode(0));

			if (pCurNode->GetRootNode())
			{
				pCurNode->GetRootNode()->SetChildNode(0, LeftNode);
			}
			else
			{
				m_RootNode = LeftNode;
			}

			LeftNode->SetRootNode(pCurNode->GetRootNode());

			LeftNode->SetChildNode(0, pCurNode->GetChildNode(0));
		}
	}

	friend std::ostream& operator << (std::ostream& out, CBinarySearchTree<T> _rhs)
	{
		std::shared_ptr<CTreeNode<T>> _CurNode = _rhs.m_frontNode;

		while (_CurNode)
		{
			out << *_CurNode << '\n';
			_CurNode = _CurNode->GetPreNode();
		}

		return out;
	}

private:
	std::shared_ptr<CTreeNode<T>> m_RootNode = nullptr;
};