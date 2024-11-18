#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class Array
{
public:
	Array();							//default constructor
	Array(size_t size);					//constructor with size parameter
	Array(const Array& Ar);				//copy constructor
	
	bool Input();						//For data input

	bool IsAlreadyExist(int value, const std::vector<int>& vec) const;		//Check if element is already in some vector
	std::vector<int> GetIntersection(const Array& Arr2) const;				//get vector which contains intersection of 2 arrays
	std::vector<int> GetAssociation(const Array& Arr2)  const;				//get vector which contains association  of 2 arrays

	~Array();

private:
	int* arr;
	size_t size;
};

void printVector(const std::vector<int>& vec, const std::string& header);