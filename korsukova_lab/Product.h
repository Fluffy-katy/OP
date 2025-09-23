#pragma once
#include <iostream>
#include <string>
#include <fstream>

class Product
{
private:
	std::wstring name;
	std::wstring manufacturer;
	float price;
	unsigned int id;
	static unsigned int MaxId;

public:
	Product();
	~Product();

	friend std::wistream& operator >> (std::wistream&, Product&);

	friend std::wostream& operator << (std::wostream&, Product&);

	friend std::wifstream& operator >> (std::wifstream&, Product&);

	friend std::wofstream& operator << (std::wofstream&, Product&);
};