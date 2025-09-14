#include "Manager.h"
#include "Utils.h"
#include <filesystem>

using namespace std;


void Manager::createProduct() {
	system("cls");
	Product* p = new Product;
	cin >> *p;
	products.push_back(p);
}

void Manager::showProducts() {
	system("cls");
	if (products.empty()) {
		cout << "Товаров для просмотра нет!" << endl;
		system("pause");
		return;
	}
	cout << "Список имеющихся товаров:" << endl;
	for (auto product : products) {
		cout << *product << endl;
	}
	cout << endl;
	system("pause");
}


void Manager::clearProducts() {
	system("cls");
	if (products.empty()) {
		cout << "Товаров для очистки нет!" << endl;
		system("pause");
		return;
	}
	for (auto product : products) {
		delete product;
	}
	products.clear();

	if (products.empty()) {
		cout << "Товары очищены успешно!" << endl;
		system("pause");
		return;
	}
}

void Manager::saveProducts() {
	system("cls");
	if (!products.empty()) {
		cout << "Введите имя файла сохранения:" << endl;
		string name = input_string();
		name = "Saves\\" + name + ".txt";
		ofstream file;
		file.open(name, ios::out);
		file << products.size() << endl;
		for (auto& product : products) {
			file << *product;
		}
		file.close();
		cout << "Успешно сохранено!" << endl; system("pause");
	}
	else { cout << "Сохранение не должно быть пустым! Запишите несколько товаров." << endl; system("pause"); }
}

void Manager::loadProducts() {
	system("cls");
	ifstream file;
	std::string path = "Saves\\";
	vector<filesystem::directory_entry> names;
	int count = 0;
	for (auto& name : filesystem::directory_iterator(path)) {
		count++;
		names.push_back(name);
		cout << count << ". " << name.path().filename() << endl;
	}
	cout << "Выберите номер файла сохранения" << endl;
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
	cout << "Файл загружен!\n" << endl;
	system("pause");
}

Manager::Manager() {
	cout << "Создал Менеджера :)" << endl;
}

Manager::~Manager() {
	for (auto product : products) {
		delete product;
	}
	products.clear();
	cout << "Удалил Менеджера :)" << endl;
}
