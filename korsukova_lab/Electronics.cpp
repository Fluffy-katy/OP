#include "Electronics.h"
#include "Utils.h"

using namespace std;

static double MAX_WEIGHT = 100;

BOOST_CLASS_VERSION(Electronics, 2)
BOOST_CLASS_EXPORT(Electronics)

Electronics::Electronics() {
	device_type = L"";
	wcout << L"Создал Электронику :)" << endl;
}
Electronics::~Electronics() {
	wcout << L"Удалил Электронику :)" << endl;
}

void Electronics::writeInfo() {
	wcout << L"Введите категорию электроники: " << endl;
	device_type = input_string();
	Product::writeInfo();

	wcout << L"Есть ли батарея у устройства?(1 - да, 0 - нет): " << endl;
	if (GetCorrectNumber(0, 1)) { has_battery = true; }
	else { has_battery = false; }
	wcout << L"Введите вес(кг): " << endl;
	weight = GetCorrectNumber(1.0, MAX_WEIGHT);
}

void Electronics::printInfo() {
	Product::printInfo();
	wstring status = has_battery ? L" есть" : L" нет";
	wcout << L"Категория: " << device_type << endl;
	wcout << L"Наличие батареи: " << status << endl;
	wcout << L"Вес(кг): " << weight << endl;
}

template<class Archive>
void Electronics::save(Archive& ar, const unsigned int version) const {
	ar& boost::serialization::base_object<Product>(*this);
	ar << device_type;
	ar << has_battery;
	ar << weight;
}

template<class Archive>
void Electronics::load(Archive& ar, const unsigned int version) {
	ar& boost::serialization::base_object<Product>(*this);
	ar >> device_type;
	ar >> has_battery;
	ar >> weight;
}