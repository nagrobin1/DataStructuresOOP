/*DS_SU_15 Homework 1 Nag Robin */
#include <iostream>
#include "point.h"
using namespace std;

int main()
{   cout << "Calculate the distance between (-2,-3) and (-4,4)" << endl;
    point A, B;

    A.set_point(-2,-3);
    B.set_point(-4,4);

    cout << "The distance is: " << A.get_distance(B) << endl;

    return 0;
}
