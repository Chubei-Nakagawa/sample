#include <iostream>
#include <list>
#include <string>

using std::endl;

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

void type_info(std::ostream& ostr)
{
    ostr << "typeid" << endl;
    ostr << "bool: " << typeid(bool).name() << endl;
    ostr << "int8_t: " << typeid(int8_t).name() << endl;
    ostr << "int16_t: " << typeid(int16_t).name() << endl;
    ostr << "uint8_t: " << typeid(uint8_t).name() << endl;
    ostr << "uint16_t: " << typeid(uint16_t).name() << endl;
    ostr << "uint32_t: " << typeid(uint32_t).name() << endl;
    ostr << "char: " << typeid(char).name() << endl;
    ostr << "short: " << typeid(short).name() << endl;
    ostr << "int: " << typeid(int).name() << endl;
    ostr << "long: " << typeid(long).name() << endl;
    ostr << "float: " << typeid(float).name() << endl;
    ostr << "double: " << typeid(double).name() << endl;
    ostr << "string: " << typeid(std::string).name() << endl;
    ostr << "list<int>: " << typeid(std::list<int>).name() << endl;
    ostr << "list<string>: " << typeid(std::list<std::string>).name() << endl;
} 


int main(int argc, char** argv)
{
    cpp_info();
    unix_info();
#if defined(_WIN32) || defined(__CYGWIN__)
    windows_info(std::cout);
#endif
    type_info(std::cout);
    return 0;
}
