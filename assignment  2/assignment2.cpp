#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "point.hpp"
using namespace std;


point Center(const point C[], int n) {
    float xsum = 0, ysum = 0;
    for (int i = 0; i < n; i++) {
        xsum += C[i].getx();
        ysum += C[i].gety();
    }
    float xcenter = xsum / n;
    float ycenter = ysum / n;
    return point(xcenter, ycenter);
}

int ClosestCluster(const point A[], const point B[], int nA, int nB, const point &p) {
    point centerA = Center(A, nA);
    point centerB = Center(B, nB);
    float distA = centerA.distance(p);
    float distB = centerB.distance(p);
    if (distA < distB) return 1;
    else return 2;
}

int main(){
    
    srand(time(NULL));
    point A[200], B[200], p[20];
  
    for (int n=0; n<200; n++) {
        float x = rand() % 21 + 70;
        float y = rand() % 21 + 70;
        A[n] = point(x, y);
    }
    
    for (int n=0; n<200; n++) {
        float x = rand() % 21 + 20;
        float y = rand() % 21 + 20;
        B[n] = point(x, y);
    }
   
    for (int m=0; m<20; m++) {
        float x = rand() % 96 + 5;
        float y = rand() % 96 + 5;
        p[m] = point(x, y);
    }
    
    for (int m=0; m<20; m++)
    {
        int cluster = ClosestCluster(A, B, 200, 200, p[m]);
        p[m].display();
        if (cluster == 1){
            cout <<"  belongs to cluster A";
        }
        
        else{
            cout<<"  belongs to cluster B";
        }
        cout<<endl;
    }
    return 0;
}
