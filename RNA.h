#pragma once
#include"CodonsTable.h"
#include"Protein.h"
class Protein;
class DNA;
	enum RNA_Type { mRNA, pre_mRNA, mRNA_exon, mRNA_intron };
class RNA : public Sequence
{
private:

	RNA_Type type;
public:
	// constructors and destructor
	RNA();
	RNA(char * seq, RNA_Type t, int size);
	RNA(RNA& rhs);
	void setRNA(char * seq, RNA_Type t, int size);
	~RNA();
	// function to be overridden to print all the RNA information
	void Print();
	// function to convert the RNA sequence into protein sequence
	// using the codonsTable object
	Protein& ConvertToProtein(const CodonsTable & table);
	// function to convert the RNA sequence back to DNA
	DNA ConvertToDNA();
	bool operator==(const RNA& two) const;
	RNA& operator+(const RNA& two);
	friend istream& operator >> (istream& x, RNA &d);
	friend ostream& operator<< (ostream& out, const RNA& d);
	bool   operator!= (RNA two);
};

