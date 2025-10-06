#pragma once
#include "Product.h"

#include <boost/serialization/base_object.hpp>

class Electronics :
	public Product
{
private:
	friend class boost::serialization::access;

protected:
	std::wstring device_type;
	bool has_battery;
	double weight;

public:
	BOOST_SERIALIZATION_SPLIT_MEMBER();
	Electronics();
	~Electronics();

	void writeInfo() override;

	void printInfo() override;

	template<class Archive>
	void save(Archive& ar, const unsigned int version) const;

	template<class Archive>
	void load(Archive& ar, const unsigned int version);
};