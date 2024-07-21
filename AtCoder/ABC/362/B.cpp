#include <iostream>

using namespace std;

void task() {
    int xA, yA, xB, yB, xC, yC;
    cin >> xA >> yA >> xB >> yB >> xC >> yC;
    
    int dAB = (xA - xB) * (xA - xB) + (yA - yB) * (yA - yB);
    int dAC = (xA - xC) * (xA - xC) + (yA - yC) * (yA - yC);
    int dBC = (xB - xC) * (xB - xC) + (yB - yC) * (yB - yC);

    if (dAB + dAC == dBC || dAC + dBC == dAB || dAB + dBC == dAC) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}

int main() {
    task();
    return 0;
}