#include <iostream>
#include "Astroid.h"

using std::string;

namespace Batrudinov {
	Astroid::Astroid(double radius) {
		this->setRadius(radius);
	}

	Astroid::Astroid() {
		this->radius = 0;
		this->length = 0;
		this->square = 0;
	}
	double Astroid::getRadius() {
		return radius;
	}
	double Astroid::getLength() {
		return length;
	}
	double Astroid::getSquare() {
		return square;
	}
	void Astroid::setRadius(double radius) {
		if (radius < 0)
			radius = 0;
		this->radius = radius;
		this->length = 6 * radius;
		this->square = 3 * pow(radius, 2.0) * PI / 8;
	}

	double Astroid::getLength(double t) {
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

	double Astroid::getCurvativeRadius(double t) { return 3 * this->radius * sin(2 * t * PI / 180) / 2; }
	void Astroid::getCoords(double* x, double* y, double t){
		t = t * PI / 180;
		*x = this->radius * pow(cos(t), 3.0);
		*y = this->radius * pow(sin(t), 3.0);
	}
	bool Astroid::getCoords(double x, double* y) {
		if (abs(x) > this->radius)
			return false;
		*y = pow(pow(this->radius, 2.0 / 3.0) - pow(x, 2.0 / 3.0), 3.0/2.0);
		return true;
	}
}