#include <iostream>
#include <string>
using namespace std;

///////////////////////////////////////////////////////////////
// Task 3: Template Pair class
template <typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;

    Pair(T1 f, T2 s) : first(f), second(s) {}

    void display() {
        cout << "Pair: (" << first << ", " << second << ")" << endl;
    }
};

int main() {
    Pair<int, string> p1(5, "Hello");
    p1.display();

    Pair<double, int> p2(3.14, 42);
    p2.display();

    return 0;
}