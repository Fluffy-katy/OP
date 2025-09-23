#include "Manager.h"
#include "Utils.h"
#include <filesystem>

using namespace std;


void Manager::createProduct() { //переделать
	system("cls");
	Product* p = new Product;
	wcin >> *p;
	products.push_back(p);
}

void Manager::showProducts() {
	system("cls");
	if (products.empty()) {
		wcout << L"Товаров для просмотра нет!" << endl;
		system("pause");
		return;
	}
	wcout << L"Список имеющихся товаров:" << endl;
	for (auto product : products) {
		wcout << *product << endl;
	}
	wcout << endl;
	system("pause");
}


void Manager::clearProducts() {
	system("cls");
	if (products.empty()) {
		wcout << L"Товаров для очистки нет!" << endl;
		system("pause");
		return;
	}
	for (auto product : products) {
		delete product;
	}
	products.clear();

	if (products.empty()) {
		wcout << L"Товары очищены успешно!" << endl;
		system("pause");
		return;
	}
}

void Manager::saveProducts() {
	system("cls");
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
	else { wcout << L"Сохранение не должно быть пустым! Запишите несколько товаров." << endl; system("pause"); }
}

void Manager::loadProducts() {
	system("cls");
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
	system("pause");
}

Manager::Manager() {
	wcout << L"Создал Менеджера :)" << endl;
}

Manager::~Manager() {
	for (auto product : products) {
		delete product;
	}
	products.clear();
	wcout << L"Удалил Менеджера :)" << endl;
}
