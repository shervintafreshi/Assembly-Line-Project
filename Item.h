
// Name: Shervin Tafreshipour
// Seneca Student ID: 155199169
// Seneca email: stafreshipour@myseneca.ca
// Date of completion: Nov 25, 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef ITEM_H
#define ITEM_H

class Item {

	std::string m_name;
	std::string m_description;
	size_t m_serialNumber;
	size_t m_quantity;
	static size_t m_widthField;

 public:

	 Item();
	 Item(const std::string& record);
	 const std::string& getName() const;
	 const unsigned int getSerialNumber();
	 const unsigned int getQuantity();
	 void updateQuantity();
	 void display(std::ostream& s, bool full) const;
};

#endif
