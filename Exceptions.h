#pragma once
#include<iostream>
using namespace std;
class WrongSize :public exception {

	const char* what() const throw() {
		return "wrong size \n";
	}


};
class WrongInput :public exception {

	const char* what() const throw() {
		return "wrong input \n";
	}


};
class WrongType :public exception {

	const char* what() const throw() {
		return "wrong type \n";
	}


};

