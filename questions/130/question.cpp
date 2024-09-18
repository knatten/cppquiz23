#include <iostream>

template<typename T>
void adl(T)
{
  std::cout << "T";
}

struct S
{
};

template<typename T>
void call_adl(T t)
{
  adl(S());
  adl(t);
}

void adl(S)
{
  std::cout << "S";
}

int main ()
{
  call_adl(S());
}