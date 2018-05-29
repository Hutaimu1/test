#include"Book.h"
#include<iostream>
#include<string>

Book::Book(string ISBN1, string name1, string author1, string date1, Genre book_type1) {
	if (!change(ISBN1))//ȷ��ISBN���Ƿ���ȷ
		throw invalid{};
	ISBN = ISBN1;
	name = name1;
	author = author1;
	date = date1;
	book_type = book_type1;
	lend = false;
}

void Book::Borrowed()//  ����ͻ����״̬
{
	if (lend == true)
		throw borrowed{};
	else
	{
		throw returned{};
		lend = false;
	}
}

bool Book::change(string Isbn) {//���ISBN���Ƿ���ȷ
	int lenth = Isbn.size();
	for (int i = 0; i < lenth - 1; ++i) {
		int x = Isbn[i];
		if (Isbn[i] == '-') {//��ISBN���г��֡�-��ʱ����
			continue;
		}
		if ((x >= 48 && x <= 57))//������Ϊ����
			return true;
	}
	int x = Isbn[lenth - 1];
	if (!((x >= 48 && x <= 57) || (x >= 65 && x <= 90) || (x <= 122 && x >= 97)))//������һλ�Ƿ�Ϊ���ֻ���ĸ
		return false;
}


bool operator == (const Book& book1, const Book& book2)//���ڼ�������������ĺ���
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