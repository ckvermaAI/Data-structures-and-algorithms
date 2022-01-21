// https://www.youtube.com/watch?v=VMVuKpj_RQQ&list=PL2_aWCzGMAwLL-mEB4ef20f3iqWMGWa25&index=9

#include <bits/stdc++.h>
using namespace std;

/*

Given a point(P) and a line sgement(AB) we need to find out whether 
P lies on the left of line segment or on right side

Applications =>
1. find out whether we should turn left or right on a map to reach a destination
2. find out line segment intersection
3. finding the convex hull of a set of points

Now, if A is at origin then we can find out the cross product of 
two vector OP and OB and if cross product is positive then P is on 
left side of AB and if it is negative then P is on right side of AB

translate/shift the origin to A
*/

struct Point{
    double x, y;
};

const int LEFT = -1, RIGHT = 1, ON_THE_LINE = 0;

Point subtract(Point A, Point P){
    Point result;
    result.x = A.x - P.x;
    result.y = A.y - P.y;
    return result;
}

double cross_product(Point A, Point B){
    return A.x*B.y - B.x*A.y;
}


int get_direction(Point A, Point B, Point P){
    B = subtract(B, A);
    P = subtract(P, A);

    // calculates the B X P
    double dir = cross_product(B, P);
    if(dir>0)
        return LEFT;
    else if(dir<0)
        return RIGHT;
    else
        return ON_THE_LINE;
}





int main(){



    return 0;
}