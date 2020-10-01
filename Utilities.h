// Name: Shervin Tafreshipour
// Seneca Student ID: 155199169
// Seneca email: stafreshipour@myseneca.ca
// Date of completion: Nov 25, 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef UTILITIES_H
#define UTILITIES_H

class Utilities {

	size_t m_widthField = 1;
	static char m_delimiter;

 public:

	 void setFieldWidth(size_t width);
	 size_t getFieldWidth() const;
	 const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	 static void setDelimiter(const char delimiter);
	 const char getDelimiter() const;
};

#endif

