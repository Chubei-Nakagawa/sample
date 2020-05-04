#include <iostream>

extern void windows_info(std::ostream&);
extern void unix_info();

void cpp_info()
{
  std::cout << "C++ version:" << __cplusplus << std::endl;
  if (__cplusplus >= 201402L){
      std::cout << "C++14 or later" << std::endl;
  } else if (__cplusplus >= 201103L){
    std::cout << "C++11 or later" << std::endl;
  } else {
    std::cout << "old style C++" << std::endl;
  }
}

int main(int argc, char** argv)
{
    cpp_info();
    unix_info();
#if defined(_WIN32) || defined(__CYGWIN__)
    windows_info(std::cout);
#endif
    return 0;
}
