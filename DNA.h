#pragma once
#include"Sequence.h"
#include"RNA.h"
#include<string>
class RNA;
using namespace std;
	enum DNA_Type { promoter, motif, tail, noncoding };

class DNA : public Sequence
{
	DNA_Type type;
	DNA* complementary_strand;
	int startIndex;
	int endIndex;

public:
	// constructors and destructor
	DNA();
	DNA(char * seq, DNA_Type t,int size);
	DNA(DNA& rhs);
	void setSeq(string);
	DNA_Type getType() const{
		return type;
	}
	void setDNA(char * seq, DNA_Type t, int size);
	// function printing DNA sequence information to user
	void Print();
	// function to convert the DNA sequence to RNA sequence
	// It starts by building the complementary_strand of the current
	// DNA sequence (starting from the startIndex to the endIndex), then,
	// it builds the RNA corresponding to that complementary_strand.
	RNA& ConvertToRNA();
	// function to build the second strand/pair of DNA sequence
	// To build a complementary_strand (starting from the startIndex to
	// the endIndex), convert each A to T, each T to A, each C to G, and
	// each G to C. Then reverse the resulting sequence.
	void BuildComplementaryStrand();
	bool operator==(const DNA& two) const;
	DNA& operator+(const DNA& two);
	bool operator!= (DNA two);
	friend istream& operator >> (istream& x, DNA &d);
	friend ostream& operator<< (ostream& out, const DNA& d);
	~DNA();
};

