#include <iostream>
#include <type_traits>

int main()
{
  int i, &j = i;
  [=]
  {
    cout << std::is_same<decltype    ((j)),     int         >::value
         << std::is_same<decltype   (((j))),    int      &  >::value
         << std::is_same<decltype  ((((j)))),   int const&  >::value
         << std::is_same<decltype (((((j))))),  int      && >::value
         << std::is_same<decltype((((((j)))))), int const&& >::value;
  }();
}