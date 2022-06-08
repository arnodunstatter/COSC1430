#include "Triangle.cpp"

int main()
{
    double side1, side2, side3;
    for (int i = 0; i < 4; i++)
    {
        cout << "Enter the sides of triangle separated by space: ";
        cin >> side1;
        cin >> side2;
        cin >> side3;
        
        try
        {
            Triangle<double> triangle(side1, side2, side3);
            cout << "The area is: " << fixed << setprecision(2) << triangle.calcArea() << endl;
            cout << "The perimeter is: " << fixed << setprecision(2) << triangle.calcPerimeter() << endl;
        }
        catch (TriangleError error)
        {
            cout << error.message();
        }
    }
    return 0;
}
