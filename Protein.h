#pragma once
#include"DNA.h"
class DNA;
enum Protein_Type { Hormon, Enzyme, TF, Cellular_Function };

class Protein : public Sequence
{
private:
	Protein_Type type;
public:
	// constructors and destructor
	Protein();
	Protein(char * p,Protein_Type t,int size);
	void Print();
	~Protein();
	void setProtein(char * seq, Protein_Type t, int size);
	
		// return an array of DNA sequences that can possibly
		// generate that protein sequence
	DNA* GetDNAStrandsEncodingMe(const DNA & bigDNA);
	bool operator==(const Protein& two) const;
	Protein& operator+(const Protein& two);
	friend istream& operator >> (istream& x, Protein &d);
	friend ostream& operator<< (ostream& out, const Protein& d);
	bool   operator!= (Protein two);
};

