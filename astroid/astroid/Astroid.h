#include <cmath>

namespace Batrudinov {
	const double PI = 3.141592653589793;

	struct Point {
		double x, y;
	};

	class Astroid {
	private:
		double radius;
	public:
		Astroid(double radius = 0);
		~Astroid();
		double const getRadius();
		double const getLength();
		double const getSquare();
		void setRadius(double radius);
		double const getLength(double t);
		double const getCurvativeRadius(const double t);
		Point const getCoords(double t);
		Point const getCoordY(const double x);
	};



}