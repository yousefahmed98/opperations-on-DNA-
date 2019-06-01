

#include<iostream>

#include "DNA.h"


using namespace std;
WrongSize wrongSize;
WrongInput wrongInput;
WrongType wrongType;

DNA::DNA()
{
	len = 0;
	seq = "";
}

DNA::DNA(char * seq,DNA_Type t, int size) :Sequence(size) {
	if (size % 3 != 0)throw  wrongSize;
	for (int i = 0; i < size; i++) {
		if (seq[i] != 'A'&&seq[i] != 'G'&&seq[i] != 'C'&&seq[i] != 'T') throw wrongInput;
	}
	this->seq = seq;
	if (t < 0 ||t > 4) throw wrongType;
	this->type = t;
	endIndex = size - 1;
	startIndex = 0;
	BuildComplementaryStrand();
}
DNA::DNA(DNA& rhs) {

}
RNA& DNA::ConvertToRNA() {
	char* seq2 = new char;
	RNA *rna = new RNA(seq2,mRNA,0);
	for (int i = 0; i < endIndex+1; i++) {

		if (seq[i] == 'T') { rna->addToSeq('U'); }
		if (seq[i] == 'A') { rna->addToSeq('A'); }
		if (seq[i] == 'C') { rna->addToSeq('C'); }
		if (seq[i] == 'G') { rna->addToSeq('G'); }
	}
	rna->addToSeq('\0');

	return *rna;

}

void DNA::setSeq(string x) {
	for (int i = 0; i < x.size(); i++) {
		seq[i] = x[i];
	}
}

void DNA::BuildComplementaryStrand() {
	int x = len;
	complementary_strand = new DNA;
	complementary_strand->len = len;
	complementary_strand->seq = new char[len];
	
	for (int i = 0; i < x; i++) {
		if (seq[i] == 'A') { complementary_strand->seq[i] = 'T'; }
		if (seq[i] == 'T') { complementary_strand->seq[i] = 'A'; }
		if (seq[i] == 'C') { complementary_strand->seq[i] = 'G'; }
		if (seq[i] == 'G') { complementary_strand->seq[i] = 'C'; }
	}

}
void DNA::Print() {
	cout << "strand 1 info : " << this->seq << endl;
	cout << "start index " << startIndex << endl;
	cout << "end index " << endIndex << endl;
	cout << "strand 2 info : " << this->complementary_strand->seq << endl;
	cout << "start index " << this->complementary_strand->startIndex << endl;
	cout << "end index " << this->complementary_strand->endIndex << endl;
}



DNA::~DNA()
{
	//delete complementary_strand;
}

//**************DNA operators***********************
ostream& operator<< (ostream& out, const DNA& d)
{
	out << "DNA type: ";
	if (d.type == 0) {
		out << "promoter";
	}

	else if (d.type == 1) {
		out << " motif";
	}
	else if (d.type == 2) {
		out << " tail";
	}
	else if (d.type == 3) {
		 out<<" noncoding";
	}
	out << endl << "strand is ";
	for (int i = 0; i < d.len; i++)
	{
		out << d.seq[i];
	}
	out << endl;
	out << endl << "comp strand is ";
	for (int i = 0; i < d.len; i++)
	{
		out << d.complementary_strand->seq[i];
	}
	out << endl;
	return out;
}
istream& operator >> (istream &in, DNA &d) {
	cout << "enter the type : ";
	int type;
	DNA_Type t;
	cout << "chose type 0-promoter 1-motif 2-tail 3-noncoding : ";
	in >> type;
	if (type < 0 || type > 4)
	{
		throw wrongType;
	}
	if (type == 0) {
		t = promoter;
	}
	
	else if (type == 1) {
		t = motif;
	}
	else if (type == 2) {
		t = tail;
	}
	else if (type == 3) {
		t = noncoding;
	}
	cout << "enter the seq : ";
	string seq;
	in >> seq;
	if (seq.length() % 3 != 0)throw  wrongSize;
	for (int i = 0; i < seq.length(); i++) {
		if (seq[i] != 'A'&&seq[i] != 'G'&&seq[i] != 'C'&&seq[i] != 'T') throw wrongInput;
	}
	char *seq2 = new char[seq.length()];
	for (int i = 0; i < seq.length(); i++) {
		seq2[i] = seq[i];
	}
	seq2[seq.length()] = '\0';
	d.setDNA(seq2, t, seq.length());
	d.BuildComplementaryStrand();
	return in;
}


DNA& DNA::operator +(const DNA &two) {
	if (this->type != two.getType())throw wrongType;
	int newSize = len + two.len;
	char* temp = new char[newSize];
	for (int i = 0; i<len; i++) {
		temp[i] = seq[i];
	}
	for (int i = 0; i<two.len; i++) {
		temp[len + i] = two.seq[i];
	}

	//creates new DNA object
	DNA* newDNA=new DNA(temp, this->type, newSize);

	return *newDNA;

}
bool DNA::operator ==(const DNA &two) const {
	if (two.len != len) {
		return false;
	}
	if (two.getType() != type) return false;
	for (int i = 0; i<len; i++) {
		if (seq[i] != two.seq[i]) {
			return false;
		}
	}
	return true;
}
bool DNA::operator!= (DNA two) {
	return !(*this == two);

}
void DNA::setDNA(char * seq, DNA_Type t, int size) {
	if (size % 3 != 0)throw  wrongSize;
	for (int i = 0; i < size; i++) {
		if (seq[i] != 'A'&&seq[i] != 'G'&&seq[i] != 'C'&&seq[i] != 'T') throw wrongInput;
	}
	this->seq = seq;
	if (t < 0 || t > 4) throw wrongType;
	this->type = t;
	len = size;
	endIndex = size - 1;
	startIndex = 0;
}
