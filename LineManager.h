
// Name: Shervin Tafreshipour
// Seneca Student ID: 155199169
// Seneca email: stafreshipour@myseneca.ca
// Date of completion: Nov 25, 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef LINEMANAGER_H
#define LINEMANAGER_H

#include "CustomerOrder.h"
#include "Task.h"
#include "Utilities.h"
#include <vector>
#include <deque>

class LineManager {

	std::vector<Task*> AssemblyLine;
	std::deque<CustomerOrder> ToBeFilled;
	std::deque<CustomerOrder> completed;
	unsigned int m_cntCustomerOrder;

  public:

	  LineManager(const std::string& , std::vector<Task*>&, std::vector<CustomerOrder>&);
	  bool run(std::ostream& os);
	  void displayCompleted(std::ostream& os) const;
	  void validateTasks() const;

};

#endif
