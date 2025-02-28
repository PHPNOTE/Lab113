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
    // สร้าง Object เพื่อทดสอบด้วยตัวเอง
}
