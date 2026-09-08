// Calculate the area of a triangle from its three coordinate points.

#include <cmath>
#include <iomanip>
#include <iostream>

double distance(double x1, double y1, double x2, double y2)
{
	return std::hypot(x2 - x1, y2 - y1);
}

int main()
{
	double x1 = 0.0;
	double y1 = 0.0;
	double x2 = 0.0;
	double y2 = 0.0;
	double x3 = 0.0;
	double y3 = 0.0;

	std::cout << "Enter three points for a triangle: ";
	std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	const double side1 = distance(x1, y1, x2, y2);
	const double side2 = distance(x2, y2, x3, y3);
	const double side3 = distance(x3, y3, x1, y1);
	const double semiperimeter = (side1 + side2 + side3) / 2.0;
	const double heron_term = semiperimeter * (semiperimeter - side1)
		* (semiperimeter - side2) * (semiperimeter - side3);

	if (heron_term <= 0.0)
	{
		std::cout << "The three points must form a non-degenerate triangle.\n";
		return 1;
	}

	const double area = std::sqrt(heron_term);
	std::cout << std::fixed << std::setprecision(1)
			  << "The area of the triangle is " << area << "\n";

	return 0;
}