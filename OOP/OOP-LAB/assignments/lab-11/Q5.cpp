#include <iostream>
#include <string>
using namespace std;

///////////////////////////////////////////////////////////////
// Task 5: Generic findMax function using templates
template <typename T>
T findMax(T arr[], int size) {
    T maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
    return maxVal;
}

int main() {
    // Array of integers
    int intArr[] = {10, 20, 5, 30, 25};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    cout << "Array: [10, 20, 5, 30, 25]" << endl;
    cout << "Maximum: " << findMax(intArr, intSize) << endl;

    // Array of strings
    string strArr[] = {"Apple", "Mango", "Banana", "Peach"};
    int strSize = sizeof(strArr) / sizeof(strArr[0]);
    cout << "Array: [\"Apple\", \"Mango\", \"Banana\", \"Peach\"]" << endl;
    cout << "Maximum: " << findMax(strArr, strSize) << endl;

    return 0;
}