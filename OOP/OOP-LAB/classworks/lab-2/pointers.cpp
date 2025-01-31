#include <iostream>
using namespace std;

int main(){

    
    int a[] = {10,2,4,1,3,7,5,4,3};
    int *ptr = a;

    for (size_t i = 0; i < 9; i++)
    {
        cout << *(ptr+i)<<" ";
    }
    
    return 0;
}