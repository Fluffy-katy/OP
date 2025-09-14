#pragma once
#include <iostream>
#include <string>
#include <fstream>

class Product
{
private:
	std::string name;
	std::string manufacturer;
	float price;
	unsigned int id;
	static unsigned int MaxId;

public:
	Product();
	~Product();

	friend std::istream& operator >> (std::istream&, Product&);

	friend std::ostream& operator << (std::ostream&, Product&);

	friend std::ifstream& operator >> (std::ifstream&, Product&);

	friend std::ofstream& operator << (std::ofstream&, Product&);
};


