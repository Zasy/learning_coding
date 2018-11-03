#include <vector>
#include <iostream>
using namespace std;
template <class T>
class Rect {
public:
    Rect(T init_x, T init_y, T w, T h){
        x = init_x;
        y = init_y;
        width = w;
        height = h;
    }

    T intersection(Rect r){
        vector<T> d_x;
        vector<T> d_y;

        T dx, dy;

        if((x >= r.x && x <= r.x + r.width) || (r.x >= x && r.x <= x + width)){
            d_x.push_back(x);
            d_x.push_back(x + width);
            d_x.push_back(r.x);
            d_x.push_back(r.x + r.width);
            sort(d_x.begin(), d_x.end());
            dx = d_x[2] - d_x[1];
        }else{
            dx = 0;
        }

        if((y >= r.y && y <= r.y + r.height) || (r.y >= y && r.y <= y + height)){
            d_y.push_back(y);
            d_y.push_back(y + height);
            d_y.push_back(r.y);
            d_y.push_back(r.y + r.height);
            sort(d_y.begin(), d_y.end());
            dy = d_y[2] - d_y[1];
        }else{
            dy = 0;
        }
        return dx *dy;

    }

private:
    T x;
    T y;
    T width;
    T height;
};




int main(){
    Rect<double> a(0, 0, 10, 10);
    Rect<double> b(0, 0, 5, 5);

    cout << a.intersection(b) << endl;

    Rect<double> c(11, 11, 5, 5);

    cout << a.intersection(c) << endl;

    return 0;
}


