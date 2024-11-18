#include "String.h"
#include <iostream>

int main()
{
	std::string str1, str2;
	std::cout << "\t-->Input data<--\n\n";
	std::cout << "Write the data for str1 ---> "; std::cin >> str1; 
	std::cout << "Write the data for str2 ---> "; std::cin >> str2; 
	std::cout << "\n";

	String Str1(str1.c_str());
	String Str2(str2.c_str());

	std::cout << "\t-->Is empty<--\n\n";
	(!Str1) ? std::cout << "Str1 is empty\n" : std::cout << "Str1 is not empty\n";
	(!Str2) ? std::cout << "Str2 is empty\n" : std::cout << "Str2 is not empty\n\n";

	int begin_Str1, end_Str1, begin_Str2, end_Str2;
	std::cout << "\t-->Find substring<--\n\n";

	std::cout << "Enter begin_Str1 --> "; std::cin >> begin_Str1;
	std::cout << "Enter end_Str1   --> "; std::cin >> end_Str1;   
	std::cout << "\n";

	std::cout << "Substring(" << begin_Str1 << ", " << end_Str1 << ") for Str1--> " << Str1(begin_Str1, end_Str1) << "\n\n\n";

	std::cout << "Enter begin_Str2 --> "; std::cin >> begin_Str2;
	std::cout << "Enter end_Str2   --> "; std::cin >> end_Str2; 
	std::cout << "Substring(" << begin_Str2 << ", " << end_Str2 << ") for Str1--> " << Str2(begin_Str2, end_Str2) << "\n\n\n";

	int index_Str1, index_Str2;
	std::cout << "\t-->Find concrete symbol<--\n\n";
	
	std::cout << "Enter begin_Str2 --> "; std::cin >> index_Str1; 
	std::cout << "Enter begin_Str2 --> "; std::cin >> index_Str2; 
	std::cout << "\n";

	std::cout << "Str1[" << index_Str1 << "] --> " << Str1[index_Str1] << "(" << str1 << ")\n";
	std::cout << "Str2[" << index_Str2 << "] --> " << Str2[index_Str2] << "(" << str2 << ")\n";

	return 0;
}