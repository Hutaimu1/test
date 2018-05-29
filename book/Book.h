#pragma once
#include<iostream>
#include<string>
/*��book�����ISBN�š����������ߡ���Ȩ���ڡ��Ƿ�����ͼ�����͵���Ϣ��
��ʵ�ֽ軹�顢��ļ�飬������ĶԱȵȹ��ܡ�*/
using namespace std;
class Book {
public:
	enum Genre{fiction = 1,nonfiction,periodical,biography,children,profession};
	Book(string ISBN, string name, string author,string date, Genre book_type);//������Ĳ���
	string get_ISBN()const{ return ISBN; }
	string get_name() { return name; }
	string get_author() { return author; }
	class invalid{};
	class borrowed{};
	class returned{};
	void Borrowed();
	bool change(string Isbn);

private: //�����Ϣ������״̬
	string ISBN;
	string name;
	string author;
	string date;
	Genre book_type;
	bool lend;
};
bool operator == ( Book& book1,  Book& book2);//���������==���ж�������ISBN���Ƿ���ͬ
bool operator != ( Book& book1,  Book& book2);//�����������=���ж�������ISBN���Ƿ񲻵�
ostream& operator<<(ostream& os,  Book& book);//���������<<�����������Ϣ����������������ߣ�ISBN��