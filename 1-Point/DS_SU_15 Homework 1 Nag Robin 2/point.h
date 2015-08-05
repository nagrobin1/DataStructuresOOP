/* This class will declare instances of the point class.
It will then use the constructor, the member functions to set, get, and calculate
the distance between 2 points*/

//Value Semantics for the point class: Assignment and copy constructor  may be used with point objects

//Macro-Guards
#ifndef POINT_H
#define POINT_H

class point
{
    public:
        /* Constructor */
        point();
        //  Postcondition: Sets x = 0 and y = 0

        /* Modification Member Functions */
        void set_point(double,double);
        //  Precondition: Parameters must be of data type double
        //  Postcondition: Private variables x and y will be set to the values of arguments

        /* Constant In-line Function */
        double get_x()const {return x;}
        //  Postcondition: returns x value
        double get_y()const {return y;}
        //  Postcondition: returns y value

        /* Member Function */
        double get_distance(point);
        //  Precondition: Parameter must be of instance of class point
        //  Postcondition: Returns the distance between two points

        //Destructor
        virtual ~point();

    private:
        //Encapsulation of Coordinates
        double x;
        double y;
};
#endif // POINT_H
