#include <iostream>
using namespace std;
class point {
public:
    point() {
        x =0;
        y = 0;
    }
    
    point(float a, float b){
        x = a;
        y = b;
    }
    
    void setx(float a) {
        x = a;
    }
    
    void sety(float b) {
        y = b;
    }
    
    float getx() const {
        return x;
    }
    
    float gety() const {
        return y;
    }
    
    void display() const { cout<< "(" << x << ","<<y << ")"; }
    float distance(const point &p) const {
        float dx = x - p.x;
        float dy = y - p.y;
        return sqrt(dx * dx + dy * dy);
    }
    
private:
    float x;
    float y;
};
