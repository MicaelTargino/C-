#include <iostream>
#include <vector>

using namespace std;

class point2d {
    private:
        int x;
        int y;
    public:
        point2d(int xx, int yy) {
            x = xx;
            y = yy;
        };

        // default constructor method for cases where no args are passed
        point2d() {
            x=0;
            y=0;
        }; 

        ~point2d() {
            cout << "Destroying Ponto2d(" << x << ", " << y << ")...";
            cout << endl;
        };

        int get_x() {
            return x;
        }

        int get_y() {
            return y;
        }
        
        std::vector<int> get_coordinates() {
            std::vector<int> coords({x,y});
            return coords;
        }

        void set_x(int xx) {
            x=xx;
        }

        void set_y(int yy) {
            y=yy;
        }

        void print_info() {
            cout << "ponto2d(";
            cout << x << ", " ;
            cout << y << ")";
            cout << endl;
        };

};


int main() {
    point2d p1(10,20);
    point2d p2;
    point2d* pp2;

    pp2 = &p2;

    pp2->set_x(100);
    pp2->set_y(200);

    p1.print_info();
    p2.print_info();

    return 0;
};