#include <iostream>
#include <map>

int main()
{
  std::map<bool,int> mb = {{1,2},{3,4},{5,0}};
  std::cout << mb.size();
  std::map<int,int> mi = {{1,2},{3,4},{5,0}};
  std::cout << mi.size();
}