
// Name: Shervin Tafreshipour
// Seneca Student ID: 155199169
// Seneca email: stafreshipour@myseneca.ca
// Date of completion: Nov 25, 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <string>
#include <algorithm>
#include "Task.h"


Task::Task(const std::string& record) : Item(record) {
	m_pNextTask = nullptr;
}

void Task::runProcess(std::ostream& os) {
	
	if (!m_orders.empty()) {
		if (!m_orders.back().getItemFillState(this->getName())) {
			m_orders.back().fillItem(*this, os);
		}
	}
}

bool Task::moveTask() {

	bool state = false;
	if (!m_orders.empty()) {
		if (m_orders.back().getItemFillState(this->getName())) {
			m_pNextTask->operator+=(std::move(m_orders.back()));
			m_orders.pop_back();
			state = true;
		}      
	}

	return state;
}

void Task::setNextTask(Task& task) {
	m_pNextTask = &task;
}

bool Task::getCompleted(CustomerOrder& order) {
	bool state = true;
	if (!m_orders.empty() && m_orders.back().getOrderFillState()) {
			order = std::move(m_orders.back());
			m_orders.pop_back();
	}else {
		state = false;
	}
	return state;
}

void Task::validate(std::ostream& os) {
	os << this->getName() << " --> ";
	if (m_pNextTask == nullptr) {
		os << "END OF LINE";
	}
	else {
		os << m_pNextTask->getName();
	}
	os << std::endl;
}

Task& Task::operator+=(CustomerOrder&& order) {
	m_orders.push_front(std::move(order));
	return *this;
}

