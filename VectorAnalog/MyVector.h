#pragma once
#include "VectorLink.h"
#include <stdexcept>
#include <iostream>

template <class T>
class MyVector
{
private:
	size_t length = 0;
	VectorLink<T>* firstPtr = nullptr;

public:
	MyVector();
	MyVector(const MyVector<T>&);
	~MyVector();

	T GetElement(int index);
	void AddElement(T data);
	size_t GetLength();
};

template <class T>
T MyVector<T>::GetElement(int index)
{
	if (index >= length || index < 0)
	{
		throw std::invalid_argument("Index out of range!");
	}

	VectorLink<T>* temp = firstPtr;
	for (int i = 0; i < index; i++)
	{
		temp = temp->next;
	}
	return temp->data;
}

template<class T>
MyVector<T>::MyVector()
{
}

template<class T>
MyVector<T>::MyVector(const MyVector<T>& newVector)
{
	if (!newVector.firstPtr)
	{
		return;
	}

	firstPtr = new VectorLink<T>;
	firstPtr->data = newVector.firstPtr->data;
	VectorLink<T>* current = firstPtr;
	VectorLink<T>* originalCurrent = newVector.firstPtr->next;


	while (originalCurrent != nullptr)
	{
		current->next = new VectorLink<T>;
		current->next->data = originalCurrent->data;
		current = current->next;
		originalCurrent = originalCurrent->next;
	}

	length = newVector.length;
}

template<class T>
MyVector<T>::~MyVector()
{
	while (firstPtr->next)
	{
		VectorLink<T>* temp = firstPtr->next;
		delete firstPtr;
		firstPtr = temp;
	}
}

template <class T>
void MyVector<T>::AddElement(T data)
{
	VectorLink<T>* temp = new VectorLink<T>;
	temp->data = data;

	if (length == 0)
	{
		firstPtr = temp;
	}
	else
	{
		VectorLink<T>* firstSaved = firstPtr;
		while (firstPtr->next)
		{
			firstPtr = firstPtr->next;
		}

		firstPtr->next = temp;
		firstPtr = firstSaved;
	}
	length++;
}

template <class T>
size_t MyVector<T>::GetLength()
{
	return length;
}
