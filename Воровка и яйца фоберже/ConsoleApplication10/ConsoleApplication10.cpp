#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;
int broski2(int n, int e) {
    if ((n + n * n) / 2 >= e - 1) {
        return n;
    }
    return broski2(n + 1, e);
}
int broski1(int b, int e) {
    while (b < e) {
        b++;
    }
    return b - 1;
}
int main() {
    int e, b = 1, n = 1;
    cout << "Skolko v dome etajeu?" << endl;
    cin >> e; // вводишь количество этажей в доме
    if (broski1(b, e) <= broski2(n, e)) {
        cout << broski1(b, e);
    }
    else cout << "Minimalnoe kolichestvo broskov: " << broski2(n, e);
    return 0;
}