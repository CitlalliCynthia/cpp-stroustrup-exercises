#include <iostream>

using namespace std;

/*
Rectangle Area (HackerRank)
*/

class Rectangle {
public:
    void display() {
        std::cout << width << " " << height << "\n";
    }
protected:
    int width;
    int height;
};

class RectangleArea : public Rectangle {
public:
    void read_input() {
        std::cin >> width >> height;
    }
    void display() {
        std::cout << width * height << "\n";
    }
};


int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;

    /*
     * Read the width and height
     */
    r_area.read_input();

    /*
     * Print the width and height
     */
    r_area.Rectangle::display();

    /*
     * Print the area
     */
    r_area.display();

    return 0;
}