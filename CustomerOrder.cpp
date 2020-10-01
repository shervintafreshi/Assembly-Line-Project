
// Name: Shervin Tafreshipour
// Seneca Student ID: 155199169
// Seneca email: stafreshipour@myseneca.ca
// Date of completion: Nov 25, 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <iomanip>
#include <string>
#include "CustomerOrder.h"
#include "Utilities.h"

size_t CustomerOrder::m_widthField = 0;

CustomerOrder::CustomerOrder() {

	m_name = "";
	m_product = "";
	m_cntItem = 0;
	m_lstItem = nullptr;
}

CustomerOrder::CustomerOrder(std::string& token) {
	
	Utilities utility;
	std::string itemToken, tempToken = token;
	bool state = true;
	size_t pos = 0;
	m_cntItem = 0;

	m_name = utility.extractToken(tempToken, pos, state);

	pos = tempToken.find(utility.getDelimiter()) + 1;
	tempToken = tempToken.substr(pos, tempToken.length());
	m_product = utility.extractToken(token, pos, state);
	
	while (state){
		pos = tempToken.find(utility.getDelimiter()) + 1;
		tempToken = tempToken.substr(pos, tempToken.length());
		pos = 0;

		itemToken = utility.extractToken(tempToken, pos, state); 
		if (m_cntItem == 0) {
			m_lstItem = new ItemInfo*[m_cntItem + 1];
			m_lstItem[m_cntItem] = new ItemInfo(itemToken);
			m_cntItem++;

		}else{
			ItemInfo** tempList;
			tempList = new ItemInfo*[m_cntItem + 1];
			
			for (auto i = 0u; i < m_cntItem; i++) {
				tempList[i] = m_lstItem[i];
			}

			delete[] m_lstItem;
			tempList[m_cntItem] = new ItemInfo(itemToken);
			m_lstItem = new ItemInfo*[m_cntItem + 1];
			m_cntItem++;

			for (auto i = 0u; i < m_cntItem; i++) {
				m_lstItem[i] = tempList[i];
			}
	
		}
	}

	if (m_widthField < utility.getFieldWidth()) {
		m_widthField = utility.getFieldWidth();
	}
}

CustomerOrder::CustomerOrder(const CustomerOrder& customerOrder) {
	throw "";
}

CustomerOrder::CustomerOrder(CustomerOrder&& customer)  noexcept{
	m_lstItem = nullptr;
	*this = std::move(customer);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& customer) {

	if (this != &customer) {

		m_name = customer.m_name;
		m_product = customer.m_product;
		m_cntItem = customer.m_cntItem;

		delete[] m_lstItem;
		m_lstItem = customer.m_lstItem;
		customer.m_lstItem = nullptr;
		customer.m_cntItem = 0;
	}

	return *this;
}


bool CustomerOrder::getItemFillState(std::string itemName) const {
    
	bool state = true;
	for (auto i = 0u; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == itemName) {
			state = m_lstItem[i]->m_fillState;
		}
	}
	return state;
}

bool CustomerOrder::getOrderFillState() const {

	bool state = true;
	for (auto i = 0u; i < m_cntItem; i++) {
		
		if (m_lstItem[i]->m_fillState == false) {
			state = false;
			break;
		}
	}
	return state;
}

void CustomerOrder::fillItem(Item& item, std::ostream& os) {
 
	for (auto i = 0u; i < m_cntItem; i++) {
		
		if (m_lstItem[i]->m_itemName == item.getName()) {
			if (item.getQuantity() != 0) {
				item.updateQuantity();
				m_lstItem[i]->m_itemName = item.getName();
				m_lstItem[i]->m_serialNumber = item.getSerialNumber();
				m_lstItem[i]->m_fillState = true;

				os << "Filled " << m_name << ", " << m_product << "[" 
					<< m_lstItem[i]->m_itemName << "]" << std::endl;
				 
			}
			else {
				os << "Unable to fill " << m_name << ", " << m_product << "[" 
				   << m_lstItem[i]->m_itemName << "]" << std::endl;
			}
		}
	}
}

void CustomerOrder::display(std::ostream& os) const {
 
	os << m_name << " - " << m_product << std::endl;
	 
	for (auto i = 0u; i < m_cntItem; i++) {
		os << "[" << std::setw(6) << std::setfill('0') << std::right << m_lstItem[i]->m_serialNumber 
		   << std::left << std::setfill(' ') << "] " << std::setw(m_widthField) 
			<< m_lstItem[i]->m_itemName << " - ";
			
		if (m_lstItem[i]->m_fillState) {
		   os << "FILLED" << std::endl;
		}
		else
		{
			os << "MISSING" << std::endl;
		}
	}
}

CustomerOrder::~CustomerOrder() {
	if (m_lstItem != nullptr) {
		for (auto i = 0u; i < m_cntItem; i++) {
			delete m_lstItem[i];
		}
		delete[] m_lstItem;
	}
}





