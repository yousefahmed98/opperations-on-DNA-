#include <iostream>
#include <string>
#include <fstream>
#include"Exceptions.h"
#include"Sequence.h"
#include"DNA.h"
#include"Protein.h"



CodonsTable c;
Protein p1;
DNA d1;
RNA r1;
using namespace std;
int main(){
	bool end = false;
	bool haveTable = false, haveRNA = false, haveDNA = false, haveProtein = false;
	while (!end) {
		try {
			cout << endl<<"**************************"<<endl<<"hello user what do u want " << endl;
			cout << "1- DNA functions " << endl << "2-RNA functions" << endl << "3- protein functions" << endl;
			cout << "4-load codons table\n" << "5-save"<<endl<<"0-end"<<endl;
			
			int ch;
			cout << "enter a num : ";
			cin >> ch;
			if (ch == 1) {
				int x;
				while (true)
				{
				cout<<endl<<endl<<"************************" << endl <<" what do want to do : \n" << "1-add DNA "<<"2 - print DNA\n" << "3 - convert to RNA\n" << "4 -compare DNA sequence"<<endl<<"5- for addtion"<<endl<<"6-d1==d2\n"<<endl << "7-load from file" << endl<<"0-BACK"<<endl;
					cin >> x;
					if (x == 1) {
						cin >> d1;																			  
						haveDNA = true;
					}
					else if (x == 2) {
						cout << d1<<endl;
					}
					else if (x == 3) {
						r1 = d1.ConvertToRNA();
						cout << "counverted now you have mRNA" << endl;
						haveRNA = true;
					}
					else if (x == 4) {
						cout << "enter sec DNA : ";
						DNA	 d2;
						cin >> d2;
						Sequence *s = new DNA;
						Sequence *s2 = new DNA;
						s = &d1;
						s2 = &d2;
						cout<<"LONG SEQ ="<<Align(s, s2)<<endl;
					}
					else if (x == 5) {
						DNA d2;
						cout << "enter sec dna" << endl;
						cin >> d2;
						cout << d1 + d2;
					}
					else if (x == 6) {
						DNA d2;
						cout << "enter sec dna" << endl;
						cin >> d2;
						if (d1 == d2) {
							cout << "equal" << endl;
						}
						else {
							cout << "not equal" << endl;
						}
					}
					else if (x == 7) {
						string filename,line;
						cin >> filename;
						ifstream myfile(filename);
						if (myfile.is_open())
						{
							int j = 0;
								myfile >> d1;
								cout << "you have DNA\n";
								haveDNA = true;
							
							myfile.close();
						}

					}
					else {
						break;
					}
				}
			}
			else if (ch == 2) {
				int x;
				while (true)
				{
					cout << endl << endl << "************************" << endl << "what do want to do : \n" <<"1- add RNA"<< "2-print RNA\n" << "3-convert to protien\n" << "4-convert to DNA"<<endl<< "5 - for addtion"<<endl<<"6-r1==r2"<<endl<<"7-load from file"<<endl<<"0-BACK" << endl;
					cin >> x;
					if (x == 1) {
						cin >> r1;
						haveRNA = true;
					}
					else if (x == 2) {
						if (haveRNA)
							cout<<r1<<endl;
						else {
							cout << "please add RNA first"<<endl;
							x = 1;
						}
					}
					else if (x == 3) {
						if (haveTable) {
							p1 = r1.ConvertToProtein(c);
							cout << "counveted now you have protien" << endl << p1<<endl;
							haveProtein = true;
						}
						else {
							cout << "you dont have a codon table"<<endl;
						}
					}
					else  if (x == 4) {
						d1 = r1.ConvertToDNA();
						haveDNA = true;
					}
					else if (x == 5) {
						RNA r2;
						cout << "enter sec rna" << endl;
						cin >> r2;
						cout << r1 + r2;
					}
					else if (x == 6) {
						RNA r2;
						cout << "enter sec rna" << endl;
						cin >> r2;
						if (r1 == r2) {
						
							cout << "equal\n";
						}
						else {
							cout<<"not equal\n";
						}
					}
					else if (x == 7) {
						string filename, line;
						cin >> filename;
						ifstream myfile(filename);
						if (myfile.is_open())
						{
							int j = 0;
							myfile >> r1;
							cout << "you have RNA\n";
							haveRNA = true;

							myfile.close();
						}
					}

					else {
						break;
					}
				}
			}
			else if (ch == 3) {
				int x;
				while (true)
				{
					cout << endl << endl << "************************" << endl << "what do want to do : \n" << "1-enter Protien \n" << "2-print protien\n" << "3-get the DNA sequences that can possibly generate that protein sequence\n" << "4 - for addtion"<<endl<<"5-p1==p2"<<endl<<"6-load from file" << endl<<"0-BACK" << endl;
					cin >> x;
					if (x == 1) {
						cin >> p1;
						haveProtein = true;
					}
					else if (x == 2) {
						if (haveProtein)
							cout<<p1<<endl;
						else cout << "you dont have protein"<<endl;
					}
					else  if (x == 3) {
						if (haveDNA&&haveProtein) {
							p1.GetDNAStrandsEncodingMe(d1);
						}
						else if(haveDNA) {
							cout<<"you must have a protien "<<endl;
						}
						else {
							cout << "dont have DNA"<<endl;
						}
					}
					else if (x == 4) {
						Protein p2;
						cout << "enter sec protien" << endl;
						cin >> p2;
						cout << p1 + p2;
					}
					else if (x == 5) {
						Protein p2;
						cout << "enter sec protien" << endl;
						cin >> p2;
						if (p1 == p2) {
							cout << "equal\n";
						}
						else {
							cout << "not equal";
						}
					}
					else if (x == 6) {
						string filename, line;
						cin >> filename;
						ifstream myfile(filename);
						if (myfile.is_open())
						{
							int j = 0;
							myfile >> p1;
							cout << "you have protien\n";
							haveProtein = true;

							myfile.close();
						}
					}
					else {
						break;
					}
				}
				
			}
			else if (ch == 4) { 
				
				string file;
				cout << "enter file name : ";
				cin >> file;
				if (file == "RNA_codon_table.txt") {
					c.LoadCodonsFromFile(file);
					cout << "now you have codon table" << endl;
					haveTable = true;
				}
				else {
					cout << "there is no file " << endl;
				}
			
			}
			else if (ch == 5) {
				string filename;
				cout << "enter file name : ";
				cin >> filename;
				ofstream myfile(filename);
				if (myfile.is_open())
				{
					myfile << "your info.\n";
					if (haveDNA) {
						myfile << "DNA info.\n";
						myfile << d1<<endl;
						
					}
					 if (haveRNA) {
						myfile << "RNA info.\n";
						myfile << r1<<endl;
					}
					 if(haveProtein){
						myfile << "protein info.\n";
						myfile << p1<<endl;
					
					 }
					 if(!haveDNA&&!haveProtein&&!haveRNA) {
						 myfile << "you have noting";
					 }
					
					myfile.close();
				}
				else cout << "Unable to open file";
			}
			if(ch==0)end = true;
			
		}
		catch (exception &x) {
			cout<<x.what()<<endl;
		}
	}
}