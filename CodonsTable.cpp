#include "CodonsTable.h"
#include <fstream>
#include<iostream>
using namespace std;

CodonsTable::CodonsTable()
{
}


// function to load all codons from the given text file
void CodonsTable::LoadCodonsFromFile(string codonsFileName) {
	string line;
	ifstream myfile(codonsFileName);
	if (myfile.is_open())
	{
		int j=0;
		while (getline(myfile, line)&& j!=65)
		{
			for (int i = 0; i < 3; i++) {
				this->codons[j].value[i] = line[i];
			}
			codons[j].AminoAcid = line[4];
			j++;

		}
		myfile.close();
	}
}


Codon CodonsTable::getAminoAcid(string value)const {
	bool found=false;
	Codon c;
	int i = 0,j=0;
	while (!found) {
		if (codons[i].value[j] == value[j]) {
			j++;
			if (codons[i].value[j] == value[j]) {
				j++;
				if (codons[i].value[j] == value[j]) {
						j=0;
						found = true;
						c.AminoAcid = codons[i].AminoAcid;
				}
			}
		}
		j = 0;
		i++;
	}
	return c;
		
}


void CodonsTable::setCodon(char * value, char AminoAcid, int index) {
	codons[index].AminoAcid = AminoAcid;
	for (int i = 0; i < 4; i++) {
		codons[index].value[i] = value[i];
	}
}


CodonsTable::~CodonsTable()
{
}
