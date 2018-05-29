#pragma once
#include<iostream>
#include<string>
/*该book类包含ISBN号、书名、作者、版权日期、是否借出、图书类型等信息。
可实现借还书、书的检查，两本书的对比等功能。*/
using namespace std;
class Book {
public:
	enum Genre{fiction = 1,nonfiction,periodical,biography,children,profession};
	Book(string ISBN, string name, string author,string date, Genre book_type);//给定书的参数
	string get_ISBN()const{ return ISBN; }
	string get_name() { return name; }
	string get_author() { return author; }
	class invalid{};
	class borrowed{};
	class returned{};
	void Borrowed();
	bool change(string Isbn);

private: //书的信息和所处状态
	string ISBN;
	string name;
	string author;
	string date;
	Genre book_type;
	bool lend;
};
bool operator == ( Book& book1,  Book& book2);//重载运算符==，判断两本书ISBN号是否相同
bool operator != ( Book& book1,  Book& book2);//重载运算符！=，判断两本书ISBN号是否不等
ostream& operator<<(ostream& os,  Book& book);//定义运算符<<，给定书的信息分行输出书名，作者，ISBN号