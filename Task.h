
// Name: Shervin Tafreshipour
// Seneca Student ID: 155199169
// Seneca email: stafreshipour@myseneca.ca
// Date of completion: Nov 25, 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef TASK_H
#define TASK_H

#include "CustomerOrder.h"
#include "Item.h"
#include <deque>

class Task : public Item{

	std::deque<CustomerOrder> m_orders;
	Task* m_pNextTask;

   public:

	   Task(const std::string& record);
	   Task(Task&) = delete;
	   Task(Task&&) = delete;
	   Task& operator=(const Task&) = delete;
	   Task& operator=(const Task&&) = delete;
	   void runProcess(std::ostream& os);
	   bool moveTask();
	   void setNextTask(Task& task);
	   bool getCompleted(CustomerOrder& order);
	   void validate(std::ostream& os);
	   Task& operator+=(CustomerOrder&& order);

	   // testing

	   void displayAll() const;

};

#endif
