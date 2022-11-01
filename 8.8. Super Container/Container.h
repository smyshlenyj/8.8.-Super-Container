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
	Container(int count);
	Container(const Container& source);
	const int GetLength() const;
	//template <typename X, typename Y> void show(X x, Y y)
	const T GetElementByIndex(int index) const;
	void InsertElementByIndex(int index, T newElement);
	void DeleteElementByIndex(int index);
	void SetSizeOfArray(int newSize);
	void PushBack(T newElement);
	void PushFront(T newElement);
	void PopBack();
	void PopFront();
	void CopyContainerTo(Container& destinationContainer);
	const int GetIndexByValue(T keyword);
	//void PrintContainer();
	T& operator[](int index);
	~Container();
};

template <typename T> Container<T>::Container(int count) : _count(count)
{

	if (count < 0)
	{
		throw BadLength();
	}

	array = new T[count]{};
}

template <typename T> Container<T>::Container(const Container& source) : _count(source._count), array(source.array)
{

}
template <typename T> void Container<T>::InsertElementByIndex(int index, T newElement)
{
	if (index < 0 || index > _count)
	{
		throw BadRange();
	}

	_count += 1;
	int* tempArray = new int[_count];

	for (int i = 0; i < index; ++i)
	{
		tempArray[i] = array[i];
	}

	tempArray[index] = newElement;

	for (int i = index + 1; i < _count; ++i)
	{
		tempArray[i] = array[i - 1];
	}

	delete[] array;
	array = tempArray;
}
template <typename T> void Container<T>::DeleteElementByIndex(int index)
{
	if (index < 0 || index > _count - 1)
	{
		throw BadRange();
	}

	_count -= 1;
	int* tempArray = new int[_count];
	for (int i = 0; i < index; ++i)
	{
		tempArray[i] = array[i];
	}

	for (int i = index; i < _count; ++i)
	{
		tempArray[i] = array[i + 1];
	}

	delete[] array;
	array = tempArray;
}

template <typename T> const T Container<T>::GetElementByIndex(int index) const
{
	if (index < 0 || index > _count - 1)
	{
		throw BadRange();
	}

	return array[index];
}

template <typename T> const int Container<T>::GetLength() const
{
	return _count;
}
template <typename T> void Container<T>::SetSizeOfArray(int newSize)
{
	if (newSize == _count)
	{
		return;
	}
	if (newSize < 0)
	{
		throw BadLength();
	}

	if (newSize > _count)
	{
		int* tempArray = new int[newSize];

		for (int i = 0; i < newSize; ++i)
		{
			tempArray[i] = array[i];
		}

		delete[] array;

		array = tempArray;
		_count = newSize;
	}
	else
	{
		int* tempArray = new int[newSize];

		for (int i = 0; i < newSize; ++i)
		{
			tempArray[i] = array[i];
		}

		delete[] array;

		array = tempArray;
		_count = newSize;
	}

}

template <typename T> void Container<T>::PushBack(T newElement)
{
	if (newElement < INT_MIN || newElement > INT_MAX) //hmmm....
	{
		throw BadRange(); // no matter
	}

	SetSizeOfArray(_count + 1);
	array[_count - 1] = newElement;
}

template <typename T> void Container<T>::PushFront(T newElement)
{
	_count += 1;
	int* tempArray = new int[_count];
	tempArray[0] = newElement;

	for (int i = 1; i < _count; ++i)
	{
		tempArray[i] = array[i - 1];
	}

	delete[] array;

	array = tempArray;
}

template <typename T> void Container<T>::PopBack()
{
	if (_count < 1)
	{
		throw BadLength();
	}

	_count -= 1;
	SetSizeOfArray(_count);
}

template <typename T> void Container<T>::PopFront()
{
	if (_count < 1)
	{
		throw BadLength();
	}

	_count -= 1;
	int* tempArray = new int[_count];

	for (int i = 0; i < _count; ++i)
	{
		tempArray[i] = array[i + 1];
	}

	delete[] array;

	array = tempArray;
}

template <typename T> void Container<T>::CopyContainerTo(Container& destinationContainer)
{

	if (destinationContainer._count != _count)
	{
		throw BadLength();
	}

	for (int i = 0; i < _count; ++i)
	{
		destinationContainer[i] = array[i];
	}
}

template <typename T> const int Container<T>::GetIndexByValue(T keyword)
{
	for (int i = 0; i < _count; ++i)
	{
		if (array[i] == keyword)
			return i;
	}
	return -1;
}

//template <typename T> void Container<T>::PrintContainer()
//{
//	std::cout << "Count " << _count << std::endl;
//	for (int i{ 0 }; i < _count; ++i)
//		std::cout << array[i] << '\n';
//}

template <typename T> T& Container<T>::operator[](int index)
{
	if (index < 0 || index > _count - 1)
	{
		throw BadRange();
	}

	return array[index];
}

template <typename T> Container<T>::~Container()
{
	delete[] array;
}