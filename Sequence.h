#pragma once
using namespace std;
#include"Exceptions.h"
#include<string>
class Sequence
{
protected:
	char * seq;
	int len;
public:
	// constructors and destructor
	Sequence() { len = 0; seq = " "; };
	Sequence(int length);
	Sequence(Sequence& rhs);
	virtual ~Sequence();
	// pure virtual function that should be overridden because every
	// type of sequence has its own details to be printed
	virtual void Print() = 0;
	char* getSeq()const
	{
		return seq;

	}
	void addToSeq(char x) {
		len++;
		char* seq2 = new char[len];
		for (int i = 0; i < len - 1; i++) {
		seq2[i] = seq[i];	
		}
		seq2[len - 1] = x;
		this->seq = seq2;
	}
	int getSize()const {
		return len;
	}

		
		// friend function that will find the LCS (longest common
		// subsequence) between 2 sequences of any type, according to
		// polymorphism
		friend char* Align(Sequence * s1, Sequence * s2);
};

