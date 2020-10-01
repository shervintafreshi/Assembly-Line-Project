
// Name: Shervin Tafreshipour
// Seneca Student ID: 155199169
// Seneca email: stafreshipour@myseneca.ca
// Date of completion: Nov 25, 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <string>
#include "Utilities.h"

char Utilities::m_delimiter;
void Utilities::setFieldWidth(size_t width) {
	m_widthField = width;
}

size_t Utilities::getFieldWidth() const {
	return m_widthField;
}

const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
	size_t npos = -1;
	std::string temp = str.substr(next_pos, str.length());
	
	if (temp.find(this->m_delimiter) != npos) {
		
		if (temp.at((temp.find(this->m_delimiter) + 1)) == this->m_delimiter) {
			throw "Two Delimiters";
		}else{
			more = true;
			temp = temp.substr(0, temp.find(this->m_delimiter));
			if (m_widthField < temp.length()) {
				m_widthField = temp.length();
			}
		}
	}else{
		more = false;
		temp = temp.substr(0, temp.find("\n"));
		if (m_widthField < temp.length()) {
			m_widthField = temp.length();
		}
	}
	return temp;
}

void Utilities::setDelimiter(const char delimiter) {
	m_delimiter = delimiter;
}

const char Utilities::getDelimiter() const {
	return m_delimiter;
}