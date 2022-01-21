// https://www.youtube.com/watch?v=WAyPIMme3Yw&list=PL2_aWCzGMAwLL-mEB4ef20f3iqWMGWa25&index=8

#include <bits/stdc++.h>
using namespace std;

struct point{
    double x;
    double y;
};

double cross_product(point A, point B){
    // return the cross product of two points
    // in cartesian plane

    return A.x*B.y - A.y*B.x;
}

double area2(point A, point B){
    // return the area of triangle with 
    // one co-ordinate at origin
    return abs(cross_product(A, B)/2.0);
}

double area1(point A, point B, point C){
    // to calculate the area of triangle represented 
    // by co-ordinates A, B and C
    
    // Method1 - shift one vertices to origin and use
    // "area2" function 

    // Method2 - use cross product similar to function "area2"
    // This method will calculate area of any triangle
    // JUST MAKE SURE THE ORDER OF VERTICES IN CROSS PRODUCT
    // THEY ALL SHOULD BE IN CLOCKWISE OR COUNTER-CLOCK WISE DIR.
    return abs(cross_product(A, B)+
               cross_product(B, C)+ 
               cross_product(C, A))/2.0;
}

double area(vector<point> &vertices){
    const int N=vertices.size();
    // To calculate the area of polygons
    // with N number of vertices
    double sum = 0.0;
    // N sided polygon will have N triangles
    // so to calculate the area of polygon we need 
    // to calculate tha area of each triangle

    for(int i=0;i<N;++i){
        sum+= cross_product(vertices[i], vertices[(i+1)%N]);
    }
    
    return abs(sum)/2.0;
}



int main(){


    return 0;
}