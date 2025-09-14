#pragma once
#include <vector>
#include "Product.h"

class Manager
{
private:
	std::vector<Product*> products;
public:
	Manager();
	~Manager();

	void createProduct();
	void showProducts();
	void clearProducts();
	void saveProducts();
	void loadProducts();
};