#include <iostream>
#include "Astroid.h"

using std::string;

namespace Batrudinov {
	Astroid::Astroid(double radius) {
		this->setRadius(radius);
	}

	Astroid::~Astroid() { std::cout << "Deleting ASTROID" << std::endl; }

	/*Astroid::Astroid() {
		this->radius = 0;
		this->length = 0;
		this->square = 0;
	}*/
	double  Astroid::getRadius() const {
		return radius;
	}
	double  Astroid::getLength() const {
		return 6 * radius;;
	}
	double  Astroid::getSquare() const {
		return 3 * pow(radius, 2.0) * PI / 8;
	}
	void Astroid::setRadius(double radius) {
		if (radius < 0)
			radius = 0;
		this->radius = radius;
	}

	double  Astroid::getLength(double t) const {
		if (t < 0 || t > 360)
			return -1;
		double l = 0;
		while (t > 90) {
			t -= 90;
			l += this->radius;
		}
		l += this->radius * pow(sin(t * PI / 180), 2.0);
		l = l * 3 / 2;
		return l;
	}

	double  Astroid::getCurvativeRadius(const double t) const { return 3 * this->radius * sin(2 * t * PI / 180) / 2; }
	Point  Astroid::getCoords(double t) const {
		t = t * PI / 180;
		Point point;
		point.x = this->radius * pow(cos(t), 3.0);
		point.y = this->radius * pow(sin(t), 3.0);
		return point;
	}

	Point  Astroid::getCoordY(const double x) const {
		if (abs(x) > this->radius)
			throw std::runtime_error("X > R!");
		Point point;
		point.x = x;
		point.y = pow(pow(this->radius, 2.0 / 3.0) - pow(x, 2.0 / 3.0), 3.0 / 2.0);
		return point;
	}
}