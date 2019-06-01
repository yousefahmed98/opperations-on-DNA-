#include "Protein.h"
#include <iostream>
#include<string>
using namespace std;
WrongInput wrongInputProtein;
WrongType wrongTypeProtein;




Protein::Protein()
{
	len = 0;
	seq = "";
}
Protein::Protein::Protein(char * p,Protein_Type t,int size):Sequence(size) {
	
	this->seq = seq;
	if (t < 0 || t > 4) throw wrongTypeProtein;
	this->type = t;

	this->seq = seq;
	this->type = t;
	for (int i = 0; i < size; i++) {
		this->seq[i] = p[i];
	}
	this->type = t;
}
void Protein::Print() {
																							   
	cout << seq;
}
void Protein::setProtein(char * seq, Protein_Type t, int size) {
	this->seq = seq;
	this->type = t;
	this->len = size;
}

// return an array of DNA sequences that can possibly
// generate that protein sequence
DNA* Protein::GetDNAStrandsEncodingMe( const DNA & bigDNA) {
	 //seq && size
	CodonsTable c;
	int z = 0, x = 0, c1 = 0,ch=0;

	char* seq1 = new char[bigDNA.getSize()];
	char* seq2 = new char[bigDNA.getSize()];
	char found[4];
	found[3] = '\0';
	seq1 = bigDNA.getSeq();
	c.LoadCodonsFromFile("RNA_codon_table.txt");

	for (int i = 0; i < bigDNA.getSize(); i++)
	{
		if (seq1[i] == 'T')
		{
			seq1[i] = 'U';
		}
	}


	for (int i = 0; i < bigDNA.getSize(); i++)
	{
		found[0] = seq1[i];
		found[1] = seq1[i + 1];
		found[2] = seq1[i + 2];

		//DNA* newd = new DNA(seq2, bigDNA.getType(), bigDNA.getSize());
		if (seq[c1] == (c.getAminoAcid(found).AminoAcid))
		{
			for (int j = 0; j < 3; j++)
			{
				seq2[z] = found[j];
				z++;
				
				
				ch++;

			}
			c1++;
			i += 2;
			
			if (c1 == len) {
				c1 = 0;
				ch = 0;
			}
		}
		else
		{
			c1 = 0;
			
			z -= ch;
			
			ch = 0;
			
		}
	}
	seq2[z] = '\0';
	int y = 0;
	int b = 0;
	for (int i = 0; i < z; i++)
	{
		if (seq2[i] == 'U')
		{
			seq2[i] = 'T';
		}
	}
	while( y < z) {
		for (int i = 0; i < len*3; i++) {
			cout << seq2[y] << seq2[y + 1] << seq2[y + 2];
			i += 2;
			y += 3;
						   
		}
		b++;
		cout << endl;

	}
	DNA* d = new DNA[b];
	 y = 0;
	 int l=0;
	 char *seqdna = new char[len * 3];
	 while (y < b) {
		 for (int i = 0; i < len * 3; i++) {

			 seqdna[i] = seq2[i+l];

		 }
		 d[y].setDNA(seqdna, bigDNA.getType(), len * 3);
		 l += len * 3;
		 y++;
	 }

	 return d;
	
}	
//**************Protien operators***********************
ostream& operator<< (ostream& out, const Protein& d)
{
	out << "Protien type: ";
	if (d.type == 0) {
		out << " Hormon";
	}
	else if (d.type == 1) {
		out << " Enzyme";
	}
	else if (d.type == 2) {
		cout << "TF";
	}
	else if (d.type == 3) {
		out<<" Cellular_Function";
	}
	out << endl << "strand is ";		;
	for (int i = 0; i < d.len; i++)
	{
		out << d.seq[i];
	}
	out << endl;
	return out;
}
istream& operator >> (istream &in, Protein& d) {
	cout << "enter the type";
	int type;
	Protein_Type t;
	cout << "0- hormon " << "2-enzyme" << "3-TF " << "4-celluar_Function : ";
	cin >> type;
	if (type == 0) {
		t = Hormon;
	}
	else if (type == 1) {
		t = Enzyme;
	}
	else if (type == 2) {
		t = TF;
	}
	else if (type == 3) {
		t = Cellular_Function;
	}
	cout << "enter the seq";
	string seq;
	cin >> seq;
	char *seq2 = new char[seq.length()];
	for (int i = 0; i < seq.length(); i++) {
		seq2[i] = seq[i];
	}
	d.setProtein(seq2, t, seq.length());
	return in;
}


Protein& Protein::operator +(const Protein &two) {
	int newSize = len + two.len;
	char* temp = new char[newSize];
	for (int i = 0; i<len; i++) {
		temp[i] = seq[i];
	}
	for (int i = 0; i<two.len; i++) {
		temp[len + i] = two.seq[i];
	}

	//creates new Protein object
	Protein *newProtein=new Protein(temp, this->type, newSize);


	return *newProtein;//newProtein;

}
bool Protein::  operator!= (Protein two) {
	return (*this == two);

}
bool Protein::operator ==(const Protein &two) const {
	if (two.len != len) {
		return false;
	}
	for (int i = 0; i<len; i++) {
		if (seq[i] != two.seq[i]) {
			return false;
		}
	}
	return true;
}


Protein::~Protein()
{
}
