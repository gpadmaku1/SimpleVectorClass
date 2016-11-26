#pragma once

class SimpleVector
{

private:

	int* _array;
	int _numElements = 0;
	int _capacity;
	void extend();

public:

	SimpleVector();
	SimpleVector(int size);
	~SimpleVector();
	int size();
	void clear();
	int empty();
	void pop_back();
	int& operator[](int i);
	const int& operator[](int i) const;
	void set(int x, int i);
	void push_back(int x);
	void reverse();
	int insert(int x, int i);
	void print();

};

