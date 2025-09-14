#include "Product.h"
#include "Utils.h"

using namespace std;

unsigned int Product::MaxId = 0;
static int MAX_PRICE = 10000000;


Product::Product() {
	name = "";
	manufacturer = "";
	price = 0;
	id = MaxId++;
	cout << "Создал продукт :)" << endl;
}

istream& operator >> (istream& in, Product& product) {
	cout << "Введите название продукта: " << endl;
	product.name = input_string();

	cout << "Введите производителя продукта: " << endl;
	product.manufacturer = input_string();

	cout << "Введите цену продукта: " << endl;
	product.price = GetCorrectNumber(0, MAX_PRICE);

	return in;
}

ostream& operator << (ostream& out, Product& product) {
	out << "\nТовар ID " << product.id << endl;
	out << "Название: " << product.name << "\nПроизводитель: " << product.manufacturer <<
		"\nЦена: " << product.price << endl;
	return out;
}

ifstream& operator >> (ifstream& fin, Product& product) {
	if (fin.is_open()) {
		fin >> ws;
		getline(fin, product.name);
		getline(fin, product.manufacturer);
		fin >> product.price;
		fin >> product.id;
		Product::MaxId = (Product::MaxId < product.id) ? product.id : Product::MaxId;
	}
	return fin;
}

ofstream& operator << (ofstream& fout, Product& product) {
	if (fout.is_open()) {
		fout << product.name << endl;
		fout << product.manufacturer << endl;
		fout << product.price << endl;
		fout << product.id << endl;
	}
	return fout;
}

Product::~Product() {
	cout << "Удалил продукт :)" << endl;
}