#include <unistd.h>
#include <iostream>

#if defined(__MINGW64__) || defined(__MINGW32_)
#include <windows.h>
void unix_info()
{
    std::cout << "no unix libraries" << std::endl;
}
#else
#include <sys/utsname.h>

void unix_info()
{
  {
    struct utsname buff;
    if (uname(&buff) < 0) {
      std::cout << "uname error" << std::endl;
    } else {
      std::cout << "sysname:" << buff.sysname << std::endl;
      std::cout << "release:" << buff.release << std::endl;
      std::cout << "version:" << buff.version << std::endl;
    }
  }
}

#endif

