
#ifndef SETOFInts2_H_
#define SETOFInts2_H_

#include "Error.h"

class SetOfInts2 {
	// Conjuntos de enteros representados como un vector no ordenado sin repeticiones
	private:
		static const int MAXSIZE = 5;

		int elems[MAXSIZE];
		int size;

		bool isFull() const;
		void linSearch(int x, int left, int right, bool& found, int& pos) const;

	public:
		SetOfInts2();
		bool isEmpty() const;
		void add(int x); // throws Error
		bool contains(int x) const;
		void remove(int x);
		void join(const SetOfInts2& set);
		void intersect(const SetOfInts2& set);
		friend istream& operator>>(istream& sIn,SetOfInts2& set);
		friend ostream& operator<<(ostream& sOut,SetOfInts2& set);
};

#endif /* SETOFInts2_H_ */
