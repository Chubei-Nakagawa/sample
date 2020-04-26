#include <iostream>

void unix_info();

void cpp_info()
{
  std::cout << "C++ version:" << __cplusplus << std::endl;
  if (__cplusplus >= 201103L){
    std::cout << "C++11 or later" << std::endl;
  } else {
    std::cout << "old style C++" << std::endl;
  }
}

int main(int argc, char** argv)
{
  cpp_info();
  unix_info();
  return 0;
}
