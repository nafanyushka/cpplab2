#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW

#include <iostream>
#include "Astroid.h"

#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
using namespace Batrudinov;
void menu(Astroid& astroid);
template <class T>
bool getNum(T& a);

using namespace Batrudinov;

int main(int argc, char* argv[])
{

	Astroid* astroid = new Astroid();
	menu(*astroid);
	delete astroid;
	_CrtDumpMemoryLeaks();
}

void menu(Astroid& astroid) {
	while (true) {
		std::cout << "Radius = " << astroid.getRadius() << "; Length = " << astroid.getLength() << "; Square = " << astroid.getSquare() << "\n\tMENU:\n\t1. Change radius, now r = " << astroid.getRadius()
			<< ".\n\t2. Get curvative radius by t."
			<< "\n\t3. Get length by t."
			<< "\n\t4. Get coordinates y by x."
			<< "\n\t5. Get coords x and y by t."
			<< "\n\t6. Exit.\n" << std::endl;
		int choice = 0;
		bool b = false;
		Point point;
		while (true) {
			b = getNum(choice);
			if (b)
				break;
			std::cout << "TRY AGAIN!" << std::endl;
		}
		double x, r, t;
		switch (choice) {
		case 1:
			std::cout << "R = ";
			while (true) {
				b = getNum(r);
				if (b)
					break;
				std::cout << "TRY AGAIN!" << std::endl;
			}
			astroid.setRadius(r);
			std::cout << "SUCCESS!" << std::endl;
			break;
		case 2:
			std::cout << "t = ";
			while (true) {
				b = getNum(t);
				if (b)
					break;
				std::cout << "TRY AGAIN!" << std::endl;
			}
			std::cout << "r(t) = " << astroid.getCurvativeRadius(t) << std::endl;
			break;
		case 3:
			std::cout << "t = ";
			while (true) {
				b = getNum(t);
				if (b)
					break;
				std::cout << "TRY AGAIN!" << std::endl;
			}
			std::cout << "r(t) = " << astroid.getLength(t) << std::endl;
			break;
		case 4:
			std::cout << "x = ";
			while (true) {
				b = getNum(x);
				if (b)
					break;
				std::cout << "TRY AGAIN!" << std::endl;
			}
			try {
				point = astroid.getCoordY(x);
				std::cout << "y(x) = " << abs(point.y) << " or y(x) = -" << abs(point.y) << std::endl;
				break;
			}
			catch(std::exception e) {
				std::cerr << "X > R!" << std::endl;
				break;
			}
		case 5:
			std::cout << "t = ";
			while (true) {
				b = getNum(t);
				if (b)
					break;
				std::cout << "TRY AGAIN!" << std::endl;
			}
			point = astroid.getCoords(t);
			std::cout << "x(t) = " << point.x << ", y(t) = " << point.y << std::endl;
			break;
		case 6:
			return;
		default:
			break;
		}
	}
}

template <class T>
bool getNum(T& a) {
	std::cin >> a;
	if (!std::cin.good()) {
		std::cin.clear();
		while (std::cin.get() != '\n');
		return false;
	}
	return true;
}