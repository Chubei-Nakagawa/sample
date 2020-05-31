#include <unistd.h>
#include <iostream>

#if defined(__MINGW64__) || defined(__MINGW32_)
#include <windows.h>
void unix_info(std::ostream& ostr)
{
    ostr << "no unix libraries" << std::endl;
}

#else
#include <sys/utsname.h>

void network_info(std::ostream& ostr);

void unix_info(std::ostream& ostr)
{
    {
        struct utsname buff;
        if (uname(&buff) < 0) {
            ostr << "uname error" << std::endl;
        } else {
            ostr << "sysname:" << buff.sysname << std::endl;
            ostr << "release:" << buff.release << std::endl;
            ostr << "version:" << buff.version << std::endl;
        }
    }
    network_info(ostr);
}

#endif

