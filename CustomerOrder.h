
// Name: Shervin Tafreshipour
// Seneca Student ID: 155199169
// Seneca email: stafreshipour@myseneca.ca
// Date of completion: Nov 25, 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Item.h"

struct ItemInfo
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_fillState = false;

	ItemInfo(std::string src) : m_itemName(src) {};
};

class CustomerOrder {

	std::string m_name;
	std::string m_product;
	unsigned int m_cntItem;
	ItemInfo** m_lstItem;
	static size_t m_widthField;

public:

	CustomerOrder();
	CustomerOrder(std::string& token);
	CustomerOrder(const CustomerOrder& customerOrder);
	CustomerOrder(CustomerOrder&& customerOrder) noexcept;
	CustomerOrder& operator=(const CustomerOrder&) = delete;
	CustomerOrder& operator=(CustomerOrder&& customerOrder);
	bool getItemFillState(std::string fillState) const;
	bool getOrderFillState() const;
	void fillItem(Item& item, std::ostream& os);
	void display(std::ostream& os) const;
	~CustomerOrder();

};


#endif 
