#pragma once

template<typename T>
class CNode
{
public:
	CNode(const T& _data)
		: m_Data(_data)
	{
	}
	CNode(const CNode<T>& _other)
		: m_Data(_other.m_Data)
	{
	}
	~CNode() = default;

public:
	friend std::ostream& operator << (std::ostream& out, CNode<T> _rhs)
	{
		out << _rhs.m_Data;

		return out;
	}

	operator T&()
	{
		return m_Data;
	}

private:
	T m_Data;
};

template<typename T>
class CSingleLinkedNode final : public CNode<T>
{
public:
	CSingleLinkedNode(const T& _data)
		: CNode<T>(_data)
	{
	}
	CSingleLinkedNode(const CSingleLinkedNode<T>& _other)
		: CNode<T>(_other)
		, m_linkedNode(_other.m_linkedNode)
	{
	}
	~CSingleLinkedNode() = default;

public:
	inline std::shared_ptr<CSingleLinkedNode<T>> GetLinkNode()
	{
		return (m_linkedNode);
	}

	inline void SetLinkNode(std::shared_ptr<CSingleLinkedNode<T>> _linkNode)
	{
		m_linkedNode = (_linkNode);
	}

private:
	std::shared_ptr<CSingleLinkedNode<T>> m_linkedNode = nullptr;
};

template<typename T>
class CDoubleLinkedNode final : public CNode<T>
{
public:
	CDoubleLinkedNode(const T& _data)
		: CNode<T>(_data)
	{
	}
	CDoubleLinkedNode(const CDoubleLinkedNode<T>& _other)
		: CNode<T>(_other)
		, m_PrelinkedNode(_other.m_PrelinkedNode)
		, m_PostlinkedNode(_other.m_PostlinkedNode)
	{
	}
	~CDoubleLinkedNode() = default;

public:
	inline std::shared_ptr<CDoubleLinkedNode<T>> GetPreNode()
	{
		return (m_PrelinkedNode);
	}

	inline void SetPreNode(std::shared_ptr<CDoubleLinkedNode<T>> _linkNode)
	{
		m_PrelinkedNode = (_linkNode);
	}

	inline std::shared_ptr<CDoubleLinkedNode<T>> GetPostNode()
	{
		return (m_PostlinkedNode);
	}

	inline void SetPostNode(std::shared_ptr<CDoubleLinkedNode<T>> _linkNode)
	{
		m_PostlinkedNode = (_linkNode);
	}

private:
	std::shared_ptr<CDoubleLinkedNode<T>> m_PostlinkedNode = nullptr;
	std::shared_ptr<CDoubleLinkedNode<T>> m_PrelinkedNode = nullptr;
};


template<typename T>
class CTreeNode final : public CNode<T>
{
public:
	CTreeNode(const T& _data, const unsigned int& _iSize)
		: CNode<T>(_data)
		, m_iSize(_iSize)
		, m_ParentNode(nullptr)
	{
		std::unique_ptr<std::shared_ptr<CTreeNode<T>>[]> Array(new T[_iSize]);

		m_ChildNodes = std::move(Array);
	}
	CTreeNode(const CTreeNode<T>& _other)
		: CNode<T>(_other)
		, m_iSize(_other.m_iSize)
		, m_ParentNode(_other.m_ParentNode)
	{
		std::unique_ptr<std::shared_ptr<CTreeNode<T>>[]> Array(new T[_iSize]);

		for (int i = 0; i < m_iSize; ++i)
		{
			Array[i] = _other.m_ChildNodes[i];
		}

		m_ChildNodes = std::move(Array);
	}
	~CTreeNode() = default;

public:
	inline std::shared_ptr<CTreeNode<T>> GetParentNode()
	{
		return (m_ParentNode.lock());
	}

	inline void SetParentNode(std::shared_ptr<CTreeNode<T>> _ParentNode)
	{
		m_ParentNode = (_ParentNode);
	}

	inline std::shared_ptr<CTreeNode<T>> GetChildNode(const unsigned int& _iIndex)
	{
		if (_iIndex >= m_iSize)
		{
			return nullptr;
		}

		return (m_ChildNodes[_iIndex]);
	}

	inline void SetChildNode(const unsigned int& _iIndex, std::shared_ptr<CTreeNode<T>> _linkNode)
	{
		if (_iIndex >= m_iSize)
		{
			return;
		}

		m_ChildNodes[_iIndex] = (_linkNode);
	}

private:
	unsigned int m_iSize = 0;
	std::weak_ptr<CTreeNode<T>> m_ParentNode = nullptr;
	std::unique_ptr<std::shared_ptr<CTreeNode<T>>[]> m_ChildNodes;
};