// Power loss is the product of resistance and the square of the current.
// Resistance is resistivity * (length / cross-sectional area).

#include <iostream>

int main()
{
	double length = 0.0;
	double area = 0.0;
	double resistivity = 0.0;
	double current = 0.0;

	std::cout << "Enter length, cross-sectional area, resistivity, and current: ";
	std::cin >> length >> area >> resistivity >> current;

	if (area == 0.0)
	{
		std::cout << "Cross-sectional area must not be zero.\n";
		return 1;
	}

	const double resistance = resistivity * (length / area);
	const double power_loss = resistance * current * current;

	std::cout << "Power loss: " << power_loss << '\n';
	return 0;
}