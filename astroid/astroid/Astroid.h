#include <cmath>
#include <string>

namespace Batrudinov {
	const double PI = 3.141592653589793;
	class Astroid {
	private:
		double radius,
			length,
			square;
	public:
		Astroid(double radius);
		Astroid();
		double getRadius();
		double getLength();
		double getSquare();
		void setRadius(double radius);
		double getLength(double t);
		double getCurvativeRadius(double t);
		void getCoords(double* x, double* y, double t);
		bool getCoords(double x, double* y);
		char* toString();
	};


}