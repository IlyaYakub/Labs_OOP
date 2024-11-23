#pragma once

#include <exception>
#include <string>


class DivisionOnZeroException : std::exception
{
public:
	DivisionOnZeroException(std::string str)
		:error(str)
	{}

	const char* what() const noexcept override { return error.c_str(); }

private:
	std::string error;
};

class OutOfRangeException : std::exception
{
public:
	OutOfRangeException(std::string str)
		:error(str)
	{}

	const char* what() const noexcept override { return error.c_str(); }

private:
	std::string error;
};

class GreaterZeroException : std::exception
{
public:
	GreaterZeroException(std::string str)
		:error(str)
	{}

	const char* what() const noexcept override { return error.c_str(); }
private:
	std::string error;
};