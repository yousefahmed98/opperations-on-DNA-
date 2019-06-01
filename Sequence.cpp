#include "Sequence.h"
#include <iostream>

using namespace std;



Sequence::Sequence(int length) {
	len = length;
	seq=new char[length];


}

Sequence::Sequence(Sequence& rhs) {

}
Sequence:: ~Sequence() {

}


// pure virtual function that should be overridden because every
// type of sequence has its own details to be printed

// friend function that will find the LCS (longest common
// subsequence) between 2 sequences of any type, according to
// polymorphism
char* Align(Sequence * s1, Sequence * s2) {
	int** arr = new int*[s2->len+1];		// open row = s2->len+1 because we need  a zero row 
	for (int i = 0; i < s2->len+1; i++) {
		arr[i] = new int[s1->len + 1];		   // open col =   s2->len+1 because we need  a zero col 
		
	}
	for (int i = 0; i < s2->len + 1; i++) {
		for (int j = 0; j < s1->len + 1; j++) {
		arr[i][j] =0;
		}
		
	}
	for (int i = 1; i < s2->len+1; i++) {
		for (int j = 1; j < s1->len+1; j++) {
			if (s2->seq[i - 1] == s1->seq[j - 1]) {
				arr[i][j] = arr[i-1][j-1]+1;
				
			}
			else {
				if (arr[i - 1][j]>arr[i][j - 1]) {
					arr[i][j] = arr[i - 1][j];
				}
				else {
					arr[i][j] = arr[i][j - 1];
				}
			}
		
		
		}
	}
	int lenOfSeq = arr[s2->len][s1->len];
	int i = s2->len ;
	int j = s1->len ;
	char* longSeq = new char[lenOfSeq];
	longSeq[lenOfSeq] = '\0';
	while (lenOfSeq  >= 0&&i!=0&&j!=0) {
		
		if (arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i][j - 1]) {
			j--;
		}
		else if (arr[i][j - 1] == arr[i - 1][j] && arr[i][j] > arr[i][j - 1]) {
			longSeq[lenOfSeq-1]= s2->seq[i-1];
			j--;
			i--;
			lenOfSeq--;
		}
		else {
			if (arr[i][j - 1] > arr[i - 1][j]) {
				j--;
			}
			else {
				i--;
			}
		}
	}

	
	cout << longSeq;
	return longSeq;

}

