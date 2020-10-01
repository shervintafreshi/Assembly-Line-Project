
// Name: Shervin Tafreshipour
// Seneca Student ID: 155199169
// Seneca email: stafreshipour@myseneca.ca
// Date of completion: Nov 25, 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <string>
#include <iomanip>
#include "Item.h"
#include "Utilities.h"

size_t Item::m_widthField = 0;


Item::Item() {

	m_name = "";
	m_description = "";
	m_serialNumber = 0;
	m_quantity = 0;
}

Item::Item(const std::string& record) {

	Utilities utility;
	bool state = true;
	size_t pos = 0;
	std::string temp;
	
		m_name = utility.extractToken(record, pos, state);
		m_widthField = utility.getFieldWidth();

		pos = record.find(utility.getDelimiter()) + 1;
		temp = record.substr(pos, record.length());
		m_serialNumber = std::stoi((utility.extractToken(record, pos, state)));

		pos = temp.find(utility.getDelimiter()) + 1;
		temp = temp.substr(pos, temp.length());
		pos = 0;
		m_quantity = std::stoi(utility.extractToken(temp, pos, state));

		temp = temp.substr(temp.find(utility.getDelimiter()) + 1, temp.length());
		m_description = utility.extractToken(temp, pos, state);
}

const std::string& Item::getName() const {
	return m_name;
}

const unsigned int Item::getSerialNumber() {
	++m_serialNumber;
	return m_serialNumber - 1;
}

const unsigned int Item::getQuantity() {
	return m_quantity;
}

void Item::updateQuantity() {
	if (m_quantity > 0) {
		--m_quantity;
	}
}

void Item::display(std::ostream& s, bool full) const {
   
	s << std::left << std::setw(m_widthField);
	if (full) {
		s << m_name << " [" << std::setw(6) << std::setfill('0') << std::right 
		<< m_serialNumber << std::setfill(' ')  << "] Quantity: "
		<< std::setw(m_widthField) << std::left << m_quantity 
		<< " Description: " << m_description << std::endl;

	}else{
		s << m_name << " [" << std::setw(6) << std::setfill('0') << std::right 
		<< m_serialNumber << std::setfill(' ') << "]" << std::endl;
	}
}

