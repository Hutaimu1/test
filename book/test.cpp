#include"Book.h"
#include<iostream>
using namespace std;

int main(){
	try {
		Book book{ "111-222-333-1","Programming Principles and Practice Using C++","Bjarne","2017-3-19",Book::Genre(6) };
		cout << book << endl;
	}
	catch (Book::invalid) {
		cerr << "Please check that you input the right ISBN number,"
			<< "so that you can lend the book you want." << endl;
	}
	catch (Book::borrowed) {
		cout << "Sorry,the book you want to lend has been lended." << endl;
	}

}