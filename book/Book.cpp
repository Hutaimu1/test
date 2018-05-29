#include"Book.h"
#include<iostream>
#include<string>

Book::Book(string ISBN1, string name1, string author1, string date1, Genre book_type1) {
	if (!change(ISBN1))//确定ISBN号是否正确
		throw invalid{};
	ISBN = ISBN1;
	name = name1;
	author = author1;
	date = date1;
	book_type = book_type1;
	lend = false;
}

void Book::Borrowed()//  借书和还书的状态
{
	if (lend == true)
		throw borrowed{};
	else
	{
		throw returned{};
		lend = false;
	}
}

bool Book::change(string Isbn) {//检测ISBN号是否正确
	int lenth = Isbn.size();
	for (int i = 0; i < lenth - 1; ++i) {
		int x = Isbn[i];
		if (Isbn[i] == '-') {//当ISBN号中出现‘-’时跳过
			continue;
		}
		if ((x >= 48 && x <= 57))//检测书否为数字
			return true;
	}
	int x = Isbn[lenth - 1];
	if (!((x >= 48 && x <= 57) || (x >= 65 && x <= 90) || (x <= 122 && x >= 97)))//检测最后一位是否为数字或字母
		return false;
}


bool operator == (const Book& book1, const Book& book2)//关于几个重载运算符的函数
{
	return(book1.get_ISBN() == book2.get_ISBN()) ? true : false;
}

bool operator != (Book& book1, Book& book2) {
	return(book1.get_ISBN() == book2.get_ISBN()) ? false : true;
}

ostream& operator<<(ostream& os, Book& book) {
	return os << "Bookname:" << book.get_name() << endl<< "Author:" << book.get_author() << endl
		<< "ISBN:" << book.get_ISBN() << endl;
}