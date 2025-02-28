#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

typedef struct _point {
    double xPosition;
    double yPosition;
} point;

class Circle {
private:
    point position;
    double radius;
public:
    Circle(double x, double y, double ra){
        position.xPosition = x;
        position.yPosition = y;
        radius = ra;
    }

    Circle(point input, double ra){
        position = input;
        radius = ra;
    }

    double area(){
        return M_PI * radius * radius;
    }

    double distanceFromCenter(point pt){
        double dx, dy;
        dx = pt.xPosition - position.xPosition;
        dy = pt.yPosition - position.yPosition;
        double result = sqrt(pow(dx,2) + pow(dy,2));
        return result;
    }

    int contains(point pt){
        double dx, dy;
        dx = pt.xPosition - position.xPosition;
        dy = pt.yPosition - position.yPosition;
        double distance = sqrt(pow(dx,2) + pow(dy,2));
        if(distance <= radius){
            return 1;
        }else{
            return 0;
        }
    }
};

int main(){
    double x, y, rad, xc, yc;
    cout << "Center of Circle: ";
    cin >> x >> y;
    cout << "Radius of Circle: ";
    cin >> rad;
    cout << "Point to Check: ";
    cin >> xc >> yc;
    
    point input;
    input.xPosition = x;
    input.yPosition = y;

    Circle n(input,rad);
    point pointc;
    pointc.xPosition = xc;
    pointc.yPosition = yc;

    cout << "Area of Circle is " << n.area() << endl
        << "Distance from Center to Point (" << xc << ", " << yc << ") is " << n.distanceFromCenter(pointc) << endl;
    cout << (n.contains(pointc) == 1 ? "This circle contains this point." : "This point is not in this circle.");

}
