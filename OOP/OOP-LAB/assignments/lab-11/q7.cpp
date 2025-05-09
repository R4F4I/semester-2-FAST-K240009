#include <iostream>
#include <exception>
#include <string>
using namespace std;

///////////////////////////////////////////////////////////////
// Task 7: SmartArray template class with bounds checking
class OutOfBoundsException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid index access attempt";
    }
};

template <typename T>
class SmartArray {
    T* data;
    int size;
public:
    SmartArray(int s) : size(s) {
        data = new T[size];
    }

    ~SmartArray() {
        delete[] data;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size)
            throw OutOfBoundsException();
        return data[index];
    }

    void inputElements() {
        cout << "Enter " << size << " elements: ";
        for (int i = 0; i < size; ++i)
            cin >> data[i];
    }

    int getSize() const {
        return size;
    }
};

int main() {
    int size = 5;
    SmartArray<int> intArray(size);
    intArray.inputElements();

    try {
        cout << "Accessing index 2: " << intArray[2] << endl;
        cout << "Accessing index 5: ";
        cout << intArray[5] << endl; // Should throw exception
    } catch (const OutOfBoundsException& e) {
        cout << "OutOfBoundsException caught: " << e.what() << endl;
    }

    SmartArray<string> strArray(3);
    cout << "Enter 3 strings: ";
    for (int i = 0; i < 3; ++i) cin >> strArray[i];

    try {
        cout << "Accessing string index 1: " << strArray[1] << endl;
        cout << "Accessing string index 3: ";
        cout << strArray[3] << endl; // Should throw exception
    } catch (const OutOfBoundsException& e) {
        cout << "OutOfBoundsException caught: " << e.what() << endl;
    }

    return 0;
}