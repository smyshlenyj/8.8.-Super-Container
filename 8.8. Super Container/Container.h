#pragma once
#include <iostream>

class BadRange : public std::exception
{
public:
	virtual const char* what() const noexcept override
	{
		return "ERROR: Bad Range";
	}
};

class BadLength : public std::exception
{
public:
	virtual const char* what() const noexcept override
	{
		return "ERROR: Bad Length";
	}
};

template <typename T> class Container
//class Container
{
private:
	int _count;
	T* array;

public:
	Container() = default;
	Container(const int& count);
	Container(const Container& source);
	const int GetLength() const;
	//template <typename X, typename Y> void show(X x, Y y)
	const T GetElementByIndex(const int& index) const;
	void InsertElementByIndex(const int& index, const T& newElement);
	void DeleteElementByIndex(const int& index);
	void SetSizeOfArray(const int& newSize);
	void PushBack(const T& newElement);
	void PushFront(const T& newElement);
	void PopBack();
	void PopFront();
	void CopyContainerTo(Container& destinationContainer);
	const int GetIndexByValue(const T& keyword);
	//void PrintContainer();
	T& operator[](const int& index);
	Container<T>& operator=(const Container<T>& right);
	~Container();
};
#include "Container.inl"
