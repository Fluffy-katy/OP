#include "Manager.h"
#include "Utils.h"
#include <vector>
#include <fstream>
#include <filesystem>
#include <memory>

using namespace std;


void Manager::createProduct() { //переделать
	shared_ptr<Product> p(new Product);
	p->writeInfo();
	products.push_back(p);
}

void Manager::createElectronics() {
	shared_ptr<Product> p(new Electronics);
	p->writeInfo();
	products.push_back(p);
}

void Manager::showProducts() {
	if (products.empty()) {
		wcout << L"Товаров для просмотра нет!" << endl;
		return;
	}
	wcout << L"Список имеющихся товаров:" << endl;
	for (auto product : products) {
		product->printInfo();
	}
	wcout << endl;
}


void Manager::clearProducts() {
	if (products.empty()) {
		wcout << L"Товаров для очистки нет!" << endl;
		return;
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
		ofstream fout;
		fout.open(name, ios::out);
		boost::archive::text_oarchive ar(fout);
		//ar << products.size();
		//for (auto product : products){
		//	ar << product;
		//}
		ar << products;
		fout.close();
		wcout << L"Успешно сохранено!" << endl; system("pause");
	}
	else { wcout << L"Сохранение не должно быть пустым! Запишите несколько товаров." << endl;}
}

void Manager::loadProducts() {
	//wifstream file;
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

	clearProducts();
	
	ifstream fin;
	fin.open(names[save - 1]);
	boost::archive::text_iarchive ar(fin);
	/*size_t n;*/
	/*ar >> n;*/
	//for (int i = 0; i < n; ++i){
	//	shared_ptr<Zimin_Product> p;
	//	ar >> p;
	//	products.push_back(p);
	//}
	ar >> products;
	fin.close();
	wcout << L"Файл загружен!\n" << endl;
}

Manager::Manager() {
	wcout << L"Создал Менеджера :)" << endl;
}

Manager::~Manager() {
	//for (auto product : products) {
	//	delete product;
	//}
	//clearProducts();
	wcout << L"Удалил Менеджера :)" << endl;
}
