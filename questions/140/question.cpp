#include <iostream>

size_t get_size_1(int* arr)
{
  return sizeof arr;
}

size_t get_size_2(int arr[])
{
  return sizeof arr;
}

size_t get_size_3(int (&arr)[10])
{
  return sizeof arr;
}

int main()
{
  int array[10];
  // Assume sizeof(int*) != sizeof(int[10])
  std::cout << (sizeof(array) == get_size_1(array));
  std::cout << (sizeof(array) == get_size_2(array));
  std::cout << (sizeof(array) == get_size_3(array));
}