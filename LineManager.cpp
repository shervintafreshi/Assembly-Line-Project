
// Name: Shervin Tafreshipour
// Seneca Student ID: 155199169
// Seneca email: stafreshipour@myseneca.ca
// Date of completion: Nov 25, 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include "LineManager.h"

LineManager::LineManager( const std::string& fileName, std::vector<Task*>& taskList, std::vector<CustomerOrder>& orderList) {

	Utilities utility;
	std::string tempToken, nextToken;
	std::string token;
	bool state = true;
	size_t pos;

	ToBeFilled.resize(orderList.size());
	std::move(orderList.begin(), orderList.end(), ToBeFilled.begin());
	std::move(taskList.begin(), taskList.end(), std::back_inserter(AssemblyLine));
	m_cntCustomerOrder = orderList.size();

	std::ifstream file(fileName);

	if (!file) {
		throw "Bad file name!";
	}

	while (!file.eof()) {

		std::getline(file, token);
		pos = 0;

		if (token.find(utility.getDelimiter()) != std::string::npos) {

			tempToken = utility.extractToken(token, pos, state);
			pos = token.find(utility.getDelimiter()) + 1;
			nextToken = utility.extractToken(token, pos, state);


			for (auto i = 0u; i < AssemblyLine.size(); i++) {

				if (AssemblyLine[i]->getName() == tempToken) {
					for (auto j = 0u; j < AssemblyLine.size(); j++) {

						if (AssemblyLine[j]->getName() == nextToken) {
							AssemblyLine[i]->setNextTask(*AssemblyLine[j]);
						}
					}
				}
			}

		}
	}

	file.close();
}

bool LineManager::run(std::ostream& os) {

	static size_t completeOrders = 0;
	static size_t orderQuantity = ToBeFilled.size();
	bool state = false;
    
	if (completeOrders < orderQuantity) {
        
        // move customer orders into Assembly Line

		if (ToBeFilled.size() != 0) {

			AssemblyLine.back()->operator+=(std::move(ToBeFilled.front()));
			ToBeFilled.pop_front();
			completed.resize(completed.size() + 1);
		}

		// fill pendings tasks on Assembly Line

		for (auto i = 0u; i < AssemblyLine.size(); i++) {
			AssemblyLine[i]->runProcess(os);
		}

		// place completed orders into Completed deque

		for (int j = AssemblyLine.size() - 1; j >= 0; j--) {

			if (completeOrders < completed.size()) {
				if (AssemblyLine[j]->getCompleted(completed[completeOrders])) {
					completeOrders++;
				}
			}
		}
		             
		// move tasks along Assembly Line

		for (auto i = 0u; i < AssemblyLine.size(); i++) {
			AssemblyLine[i]->moveTask();
		}

	
	}else{
		state = true;
	}

	return state;
}

void LineManager::displayCompleted(std::ostream& os) const {
	for (auto i = 0u; i < completed.size(); i++) {
		completed[i].display(os);
	}
}

void LineManager::validateTasks() const {
	for (auto i = 0u; i < AssemblyLine.size(); i++) {
		AssemblyLine[i]->validate(std::cout);
	}
}
