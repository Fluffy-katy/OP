#include "Manager.h"
#include "Utils.h"
#include <filesystem>

using namespace std;


void Manager::createProduct() { //переделать
	Product* p = new Product;
	wcin >> *p;
	products.push_back(p);
}

void Manager::showProducts() {
	if (products.empty()) {
		wcout << L"Товаров для просмотра нет!" << endl;
		return;
	}
	wcout << L"Список имеющихся товаров:" << endl;
	for (auto product : products) {
		wcout << *product << endl;
	}
	wcout << endl;
}


void Manager::clearProducts() {
	if (products.empty()) {
		wcout << L"Товаров для очистки нет!" << endl;
		return;
	}

	for (auto product : products) {
		delete product;
	}
	products.clear();

	if (products.empty()) {
		wcout << L"Товары очищены успешно!" << endl;
		return;
	}
}

void Manager::saveProducts() {
	if (!products.empty()) {
		wcout << L"Введите имя файла сохранения:" << endl;
		wstring name = input_string();
		name = L"Saves\\" + name + L".txt";
		wofstream file;
		file.open(name, ios::out);
		file << products.size() << endl;
		for (auto& product : products) {
			file << *product;
		}
		file.close();
		wcout << L"Успешно сохранено!" << endl; system("pause");
	}
	else { wcout << L"Сохранение не должно быть пустым! Запишите несколько товаров." << endl;}
}

void Manager::loadProducts() {
	wifstream file;
	std::wstring path = L"Saves\\";
	vector<filesystem::directory_entry> names;
	int count = 0;
	for (auto& name : filesystem::directory_iterator(path)) {
		count++;
		names.push_back(name);
		wcout << count << ". " << name.path().filename() << endl;
	}
	wcout << L"Выберите номер файла сохранения" << endl;
	int save = GetCorrectNumber(1, count);

	products.clear();
	
	int count_products;
	file.open(names[save - 1]);
	file >> count_products;

	while (count_products--)
	{
		Product* p = new Product;
		file >> *p;
		products.push_back(p);
	}
	file.close();
	wcout << L"Файл загружен!\n" << endl;
}

Manager::Manager() {
	wcout << L"Создал Менеджера :)" << endl;
}

Manager::~Manager() {
	//for (auto product : products) {
	//	delete product;
	//}
	clearProducts();
	wcout << L"Удалил Менеджера :)" << endl;
}
