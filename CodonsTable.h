#pragma once

#include<string>
using namespace std;
struct Codon
{
	char value[4];    	    // 4th location for null character
	char AminoAcid;  	    // corresponding AminoAcid according to Table
};
class CodonsTable
{
private:
	Codon codons[64];
public:
	// constructors and destructor
	CodonsTable();
	~CodonsTable();
	// function to load all codons from the given text file
	void LoadCodonsFromFile(string codonsFileName);
	Codon getAminoAcid(string value)const;
	void setCodon(char * value, char AminoAcid, int index);
};

