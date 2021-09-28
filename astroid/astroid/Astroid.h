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
		double  getRadius() const;
		double  getLength() const;
		double  getSquare() const;
		void setRadius(double radius);
		double  getLength(double t) const;
		double  getCurvativeRadius(const double t) const;
		Point  getCoords(double t) const;
		Point  getCoordY(const double x) const;
	};



}