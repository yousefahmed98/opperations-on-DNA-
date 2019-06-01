#include "RNA.h"
#include<iostream>

using namespace std;
WrongSize wrongSizeRNA;
WrongInput wrongInputRNA;
WrongType wrongTypeRNA;

RNA::RNA() {
	len = 0;
	seq = "";
}
RNA::RNA(char * seq,RNA_Type t,int size ):Sequence(size){
	if (size % 3 != 0)throw  wrongSizeRNA;
	for (int i = 0; i < size; i++) {
		if (seq[i] != 'A'&&seq[i] != 'G'&&seq[i] != 'C'&&seq[i] != 'U') throw wrongInputRNA;
	}
	this->seq = seq;
	if (t < 0 || t > 4) throw wrongTypeRNA;
	this->type = t;
	
	this->seq = seq;
	this->type = t;

}
RNA::RNA(RNA& rhs) {

}
void RNA::setRNA(char * seq, RNA_Type t, int size) {
	this->seq = seq;
	this->type = t;
	this->len = size;

}

// function to be overridden to print all the RNA information
void RNA::Print() {
	cout << "type "<<type<<endl;
	cout <<"seq " <<seq<<endl;
}
// function to convert the RNA sequence into protein sequence
// using the codonsTable object
Protein& RNA::ConvertToProtein(const CodonsTable & table) {
//
	Protein *p=new Protein;
	char x[3];
	for (int i = 0; i < strlen(seq); i+=3) {
		x[0] = seq[i];
		x[1] = seq[i + 1];
		x[2] = seq[i + 2];
		p->addToSeq(table.getAminoAcid(x).AminoAcid);
	}
	p->addToSeq('\0');
	return *p;
}
// function to convert the RNA sequence back to DNA
DNA RNA::ConvertToDNA() {
	DNA Dna;
	for (int i = 0; i < strlen(seq); i++) {

		if (seq[i] == 'U') { Dna.addToSeq('T'); }
	}
	return Dna;
//
}
//**************RNA operators***********************
ostream& operator<< (ostream& out, const RNA& d)
{
	out << " RNA type: ";
	if (d.type == 0) {
		out<<"mRNA";
	}

	else if (d.type == 1) {
		out << " pre_mRNA";
	}
	else if (d.type == 2) {
		out << " mRNA_exon";
	}
	else if (d.type == 3) {
		out << " mRNA_intron";
	}
	out << endl << "strand is ";
	for (int i = 0; i < d.len; i++)
	{
		out << d.seq[i];
	}
	
	out << endl;
	return out;
}

istream& operator >> (istream &in, RNA &d) {
	cout << "enter the type : ";
	int type;
	RNA_Type t;
	cout << "choose type 0-mRNA, 1-pre_mRNA, 2-mRNA_exon, 3-mRNA_intron : ";
	cin >> type;
	if (type < 0 || type > 4)
	{
		throw wrongTypeRNA;
	}
	if (type == 0) {
		t = mRNA;
	}

	else if (type == 1) {
		t = pre_mRNA;
	}
	else if (type == 2) {
		t = mRNA_exon;
	}
	else if (type == 3) {
		t = mRNA_intron;
	}
	cout << "enter the seq : ";
	string seq;
	cin >> seq;
	if (seq.length() % 3 != 0)throw  wrongSizeRNA;
	for (int i = 0; i < seq.length(); i++) {
		if (seq[i] != 'A'&&seq[i] != 'G'&&seq[i] != 'C'&&seq[i] != 'U') throw wrongInputRNA;
	}
	char *seq2 = new char[seq.length()];
	for (int i = 0; i < seq.length(); i++) {
		seq2[i] = seq[i];
	}
	seq2[seq.length()] = '\0';
	d.setRNA(seq2, t, seq.length());
	return in;
}

bool RNA::operator ==(const RNA &two) const {
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

bool RNA::  operator!= (RNA two) {
	return (*this == two);

}
RNA& RNA::operator +(const RNA &two) {
	int newSize = len + two.len;
	char* temp = new char[newSize];
	for (int i = 0; i<len; i++) {
		temp[i] = seq[i];
	}
	for (int i = 0; i<two.len; i++) {
		temp[len+i] = two.seq[i];
	}

	//creates new  object
	RNA *newRNA=new RNA(temp, this->type, newSize);

	return *newRNA;

}

RNA::~RNA()
{
}
