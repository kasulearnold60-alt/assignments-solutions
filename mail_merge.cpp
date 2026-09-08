// Generate a Makerere University acceptance letter from user details.

#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

std::string ordinal_suffix(int day)
{
	if (day % 100 >= 11 && day % 100 <= 13)
	{
		return "th";
	}

	switch (day % 10)
	{
	case 1:
		return "st";
	case 2:
		return "nd";
	case 3:
		return "rd";
	default:
		return "th";
	}
}

int main()
{
	std::string first_name;
	std::string last_name;
	std::string study_program;
	std::string academic_year;

	std::cout << "Enter first name: ";
	std::getline(std::cin, first_name);
	std::cout << "Enter last name: ";
	std::getline(std::cin, last_name);
	std::cout << "Enter study program: ";
	std::getline(std::cin, study_program);
	std::cout << "Enter academic year: ";
	std::getline(std::cin, academic_year);

	const std::time_t current_time = std::time(nullptr);
	const std::tm* current_date = std::localtime(&current_time);
	const int day = current_date->tm_mday;

	std::cout << "\nDate: " << day << ordinal_suffix(day) << ' '
			  << std::put_time(current_date, "%B %Y") << "\n\n";
	std::cout << "To: " << first_name << ' ' << last_name << ",\n\n";
	std::cout << "Dear " << first_name << ",\n\n";
	std::cout << "CONGRATULATIONS! I am pleased to inform you that the Makerere University\n"
			  << "Admissions Board has approved your application for admission to the\n"
			  << academic_year << " academic year.\n\n";
	std::cout << "You have been offered a place for the following course:\n"
			  << "PROGRAM: " << study_program << "\n\n";
	std::cout << "As a student of Makerere University, you will be part of a historic\n"
			  << "institution dedicated to academic excellence and innovation. Please ensure\n"
			  << "that you report to the Academic Registrar's office with your original\n"
			  << "academic documents for verification during the orientation week.\n\n";
	std::cout << "We look forward to welcoming you to Makerere University.\n\n"
			  << "Yours sincerely,\n\n\n"
			  << "John Doe\n"
			  << "Registrar\n";

	return 0;
}