#include <iostream>
#include <type_traits>

using namespace std;

int main()
{
  int i, &j = i;
  [=]
  {
    cout << is_same<decltype    ((j)),     int         >::value
         << is_same<decltype   (((j))),    int      &  >::value
         << is_same<decltype  ((((j)))),   int const&  >::value
         << is_same<decltype (((((j))))),  int      && >::value
         << is_same<decltype((((((j)))))), int const&& >::value;
  }();
}