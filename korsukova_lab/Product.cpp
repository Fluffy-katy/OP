#include "Product.h"
#include "Utils.h"

using namespace std;

unsigned int Product::MaxId = 0;
static int MAX_PRICE = 10000000;


Product::Product() {
	name = L"";
	manufacturer = L"";
	price = 0;
	id = MaxId++;
	wcout << L"Создал продукт :)" << endl;
}

wistream& operator >> (wistream& in, Product& product) {
	wcout << L"Введите название продукта: " << endl;
	product.name = input_string();

	wcout << L"Введите производителя продукта: " << endl;
	product.manufacturer = input_string();

	wcout << L"Введите цену продукта: " << endl;
	product.price = GetCorrectNumber(0, MAX_PRICE);

	return in;
}

wostream& operator << (wostream& out, Product& product) {
	out << L"\nТовар ID " << product.id << endl;
	out << L"Название: " << product.name << 
		L"\nПроизводитель: " << product.manufacturer <<
		L"\nЦена: " << product.price << endl;
	return out;
}

wifstream& operator >> (wifstream& fin, Product& product) {
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

wofstream& operator << (wofstream& fout, Product& product) {
	if (fout.is_open()) {
		fout << product.name << endl;
		fout << product.manufacturer << endl;
		fout << product.price << endl;
		fout << product.id << endl;
	}
	return fout;
}

Product::~Product() {
	wcout << L"Удалил продукт :)" << endl;
}