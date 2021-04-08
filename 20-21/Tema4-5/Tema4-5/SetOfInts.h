#include <iostream>

#pragma once
#ifndef SetOfInts_H_
#define SetOfInts_H_

class SetOfInts {
	// Conjuntos de enteros representados como vectores ordenados sin repeticiones
private:
	static const int MAXSIZE = 1000;

	int elems[MAXSIZE];
	int size;

	bool isFull() const;
	void binSearch(int x, bool& found, int& pos) const;
	int binSearchAux(int x, int a, int b) const;
	void shiftRightFrom(int i);
	void shiftLeftFrom(int i);

public:
	SetOfInts();
	bool isEmpty() const;
	void add(int x); //throws Error
	bool contains(int x) const;
	void remove(int x);
	void join(const SetOfInts& set);
	void intersect(const SetOfInts& set);
	int GetMin();
	int GetMax();
	int Size();
	void RemoveMin();
	void RemoveMax();
	friend std::istream& operator>>(std::istream& sIn, SetOfInts& set);
	friend std::ostream& operator<<(std::ostream& sOut, SetOfInts& set);
};

#endif /* SetOfInts_H_ */

