#include<iostream>
#include<string>
using namespace std;

class Book {
	string book;
	string author;
	int price;
public:
	Book(string _book, string _author, int _price) :
		book(_book),
		author(_author),
		price(_price) {};
	string get_book() { return book; }
	string get_author() { return author; }
	int get_price() { return price; }
	void set_book(string Book) { book = Book; }
	void set_author(string Author) { author = Author; }
	void set_price(int Price) { price = Price; }

	void print() {
		cout <<
			"�������� �����: " << book << endl <<
			"�����: " << author << endl <<
			"����: " << price << endl;
	}
};

class BookGenre :public Book {
	string genre;
public:
	BookGenre(string _book, string _author, int _price, string _genre) : 
		Book(_book, _author, _price), 
		genre(_genre) {};
	string get_genre() { return genre; }
	void set_genre(string Genre) { genre = Genre; }
	void print() {
		Book::print();
		cout << "����: " << genre << endl;
	}
};

class BookGenrePubl final : BookGenre {
	string info;
public:
	BookGenrePubl(string _book, string _author, int _price, string _genre, string _info) :
		BookGenre(_book, _author, _price, _genre),
		info(_info) {};

	string get_info() { return info; }
	void set_info(string Info) { info = Info; }
	void print() {
		BookGenre::Book::print();
		cout << "���������� �� ��������: " <<info << endl;
	}
};

int main() {
	setlocale(LC_ALL, "Rus");
	Book book("���������", "������� ����� ����", 2048);
	BookGenre bookgenre("�", "������ ��������", 4096,"����������������");
	BookGenrePubl bookgenrepubl("C++", "����� ����������",1024, "����������������", "BELL LABS");
	book.print();
	bookgenre.print();
	bookgenrepubl.print();
	//����� ��� �� ��� ���� ���������
	system("pause");
}