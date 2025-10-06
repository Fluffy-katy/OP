#pragma once
#include "Product.h"
#include "Electronics.h"

#include <C:\local\boost_1_89_0\boost\serialization\vector.hpp>

class Manager
{
private:
	std::vector<std::shared_ptr<Product>> products;
public:
	Manager();
	~Manager();

	void createProduct();
	void createElectronics();
	void showProducts();
	void clearProducts();
	void saveProducts();
	void loadProducts();
};