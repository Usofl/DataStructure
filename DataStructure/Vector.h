#pragma once
#include "Node.h"

template<typename T>
class CVector
{
public:
	CVector()
		: m_iSize(0)
		, m_iCapacity(5)
	{
		std::unique_ptr<T[]> Array(new T[m_iCapacity]);

		m_Array = std::move(Array);
	}
	~CVector() = default;

public:
	inline void push(const unsigned int& _index, const T& _Data)
	{
		if (m_iSize == m_iCapacity)
		{
			reserve(m_iCapacity + m_iCapacity / 2);
		}

		pushRightArray(_index);

		m_Array[_index] = (_Data);

		++m_iSize;
	}

	inline void push_back(const T& _Data)
	{
		if (m_iSize == m_iCapacity)
		{
			reserve(m_iCapacity + m_iCapacity / 2);
		}

		m_Array[m_iSize++] = (_Data);
	}

	inline void push_front(const T& _Data)
	{
		if (m_iSize == m_iCapacity)
		{
			reserve(m_iCapacity + m_iCapacity / 2);
		}

		pushRightArray(0);

		m_Array[0] = (_Data);
		
		++m_iSize;
	}

	inline void erase(const unsigned int& _index)
	{
		for (unsigned int i = _index; i < m_iSize - 1; ++i)
		{
			Array[i] = m_Array[i + 1];
		}

		--m_iSize;
	}

	inline void pop_front()
	{
		erase(0);
	}

	inline void pop_back()
	{
		--m_iSize;
	}

	int find(const T& _Data)
	{
		for (unsigned int i = 0; i < m_iSize; ++i)
		{
			if (_Data == m_Array[i])
			{
				return i;
			}
		}

		return -1;
	}

	inline T front(void)
	{
		return m_Array[0];
	}

	inline T back(void)
	{
		return m_Array[m_iSize - 1];
	}

	friend std::ostream& operator << (std::ostream& out, CVector<T>& _rhs)
	{
		for (unsigned int i = 0; i < _rhs.m_iSize; ++i)
		{
			out << (_rhs.m_Array[i]) << '\n';
		}

		return out;
	}

	inline T operator [] (const unsigned int& _iIndex)
	{
		return m_Array[_iIndex];
	}

	void reserve(const unsigned int& _iCapacity)
	{
		m_iCapacity = _iCapacity;
		std::unique_ptr<T[]> Array(new T[m_iCapacity]);

		for (unsigned int i = 0; i < m_iSize; ++i)
		{
			Array[i] = m_Array[i];
		}

		m_Array = std::move(Array);
	}

private:
	void pushRightArray(const unsigned int& _iStartIndex)
	{
		if (1 >= m_iSize)
		{
			return;
		}

		m_Array[m_iSize] = m_Array[m_iSize - 1];

		for (unsigned int i = m_iSize - 1; i > _iStartIndex; --i)
		{
			m_Array[i] = m_Array[i - 1];
		}

		m_Array[_iStartIndex] = T();
	}

private:
	unsigned int m_iSize = 0;
	unsigned int m_iCapacity = 5;
	std::unique_ptr<T[]> m_Array;
};