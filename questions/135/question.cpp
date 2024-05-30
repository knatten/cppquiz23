#include <iostream>
#include <map>
using namespace std;

int main()
{
  map<bool,int> mb = {{1,2},{3,4},{5,0}};
  cout << mb.size(); 
  map<int,int> mi = {{1,2},{3,4},{5,0}};
  cout << mi.size();
}