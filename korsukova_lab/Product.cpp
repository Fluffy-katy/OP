#include "Product.h"
#include "Utils.h"

using namespace std;

BOOST_CLASS_VERSION(Product, 1)
BOOST_CLASS_EXPORT(Product)

unsigned int Product::MaxId = 1;
static int MAX_PRICE = 10000000;


Product::Product() {
	name = L"";
	manufacturer = L"";
	price = 0;
	id = MaxId++;
	wcout << L"Создал продукт :)" << endl;
}

void Product::writeInfo() {
	wcout << L"Введите название продукта: " << endl;
	name = input_string();

	wcout << L"Введите производителя продукта: " << endl;
	manufacturer = input_string();

	wcout << L"Введите цену продукта: " << endl;
	price = GetCorrectNumber(0, MAX_PRICE);
}

void Product::printInfo() {
	wcout << L"\nТовар ID " << id << endl;
	wcout << L"Название: " << name << 
		L"\nПроизводитель: " << manufacturer <<
		L"\nЦена: " << price << endl;
}

template<class Archive>
void Product::save(Archive& ar, const unsigned int version) const {
	ar << name;
	ar << manufacturer;
	ar << price;
	ar << id;
}

template<class Archive>
void Product::load(Archive& ar, const unsigned int version) {
	ar >> name;
	ar >> manufacturer;
	ar >> price;
	ar >> id;
}

Product::~Product() {
	wcout << L"Удалил продукт :)" << endl;
}