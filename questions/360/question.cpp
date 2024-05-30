#include <iostream>
#include <type_traits>
using namespace std;

int main() {
    cout << is_const_v<const int *>
         << is_const_v<const int [1]>
         << is_const_v<const int **>
         << is_const_v<const int (*)[1]>
         << is_const_v<const int *[1]>
         << is_const_v<const int [1][1]>;
}