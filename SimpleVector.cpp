#include "SimpleVector.h"
#include <iostream>
using namespace std;

SimpleVector::SimpleVector() //Default Constructor
{
	_capacity = 10;
	_array = new int[_capacity];
}

SimpleVector::SimpleVector(int size) //Constructor with size passed in
{
	_capacity = size;
	_array = new int[_capacity];
}

SimpleVector::~SimpleVector() //Destructor
{
	delete[] _array;
}

int &SimpleVector::operator[](int i)
{
	if (i < 0 || i >= _numElements)
	{
		cout << "Index out of bounds." << endl;
		return _array[0];
	}
	return _array[i];
}

const int &SimpleVector::operator[](int i) const
{
	if (i < 0 || i >= _numElements)
	{
		cout << "Index out of bounds." << endl;
		return _array[0];
	}
	return _array[i];
}

int SimpleVector::empty() //Check if vector is empty
{
	if (_numElements == 0)
		return 1;
	else
		return 0;
}

int SimpleVector::size() //Return number of elements in the vector
{
	return _numElements;
}

void SimpleVector::pop_back() //Delete last element from the vector
{
	if (_numElements != 0) {
		_array[_numElements - 1] = 0;
		_numElements = _numElements - 1;
	}
}

void SimpleVector::clear() //Clear all data from the vector
{
	_numElements = 0;
}

void SimpleVector::set(int x, int i)
//Sets position i to a particular value
{
	if (i > 0 && i < _numElements) {
		_array[i] = x;
	}
	else
	{
		cout << "Index out of bounds." << endl;
	}
}

void SimpleVector::extend()
{
	//Creates a new array in the heap with double capacity
	_capacity = _capacity * 2;
	int* _extendedArray = new int[_capacity]; 
	//copy(_array, _array + _numElements, _extendedArray);
	//Delete old array
	for (int i = 0; i < _capacity; i++)
	{
		_extendedArray[i] = _array[i];
	}
	delete[] _array; 
	//Double the capacity
	//Points to new array
	_array = _extendedArray;
}

void SimpleVector::push_back(int x)
	//Adds a new element to the vector
{
	_array[_numElements] = x;
	_numElements = _numElements + 1; 
	if (_capacity <= _numElements)
	{
		extend();
	}
}

int SimpleVector::insert(int x, int i)
//Insert an element into the vector and shift the rest of the elements
{
	if (i < 0 || i > _numElements - 1)
	{
		cout << "Array is out of bounds." << endl;
		return 1;
	}
	if (++_numElements >= _capacity)
	{
		extend();
	}
	for (int j = _numElements; j > i; --j)
	{
		_array[j] = _array[j - 1];
	}
	_array[i] = x;

	return 0;
}

void SimpleVector::reverse() 
//Reverse the vector 
{
	for (int i = 0; i < (_numElements/2); i++)
	{
		int temp;
		temp = _array[_numElements - 1 - i];
		_array[_numElements - 1 - i] = _array[i];
		_array[i] = temp;
	}
}

void SimpleVector::print() 
{
	for (int i = 0; i < _numElements; i++) 
	{
		cout << "Element at position " << i << " "<< _array[i] << endl;
	}
}
