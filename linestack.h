#ifndef _LINESTACK_H_
#define _LINESTACK_H_

#include <assert.h>

template <class T>
class LineStack
{
public:
	LineStack();
	~LineStack();
	bool isEmpty() const;
	void push(T& value);
	void pop();
	T& getTop() const;
	unsigned int size() const;
	unsigned int capacity() const;

private:
	T* array;
	unsigned int m_size;
	unsigned int m_capacity;
};

template<class T>
LineStack<T>::LineStack()
{
	m_size = 0;
	array = new T[10];//default
	m_capacity = 10;
}

template<class T>
LineStack<T>::~LineStack()
{
	delete [] array;
}

template<class T>
bool LineStack<T>::isEmpty() const
{
	return m_size == 0;
}

template <class T>
void LineStack<T>::push(T& value)
{
	if (m_size < m_capacity)
	{
		array[m_size++] = value;
	}
	else
	{
		m_capacity = 2 * m_capacity;
		T* oldArrayPtr = array;
		array = new T[m_capacity];//redirect

		for (auto i = 0; i < (int)m_capacity; ++i)
		{
			array[i] = oldArrayPtr[i];
		}
		array[m_size++] = value;

		delete [] oldArrayPtr;
	}
}

template<class T>
void LineStack<T>::pop()
{
	assert (NULL != m_size);
	--m_size;
}

template<class T>
T& LineStack<T>::getTop() const
{
	assert (NULL != m_size);
	return array[m_size];
}

template<class T>
unsigned int LineStack<T>::size() const
{
	return m_size;
}

template<class T>
unsigned int LineStack<T>::capacity() const
{
	return m_capacity;
}

#endif