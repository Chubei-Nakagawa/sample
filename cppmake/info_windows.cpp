#include <iostream>
#include <windows.h>

using std::endl;

void windows_info(std::ostream& ostr)
{
    DWORD v = GetVersion();
    int major = LOBYTE(LOWORD(v));
    int minor = HIBYTE(LOWORD(v));
    int build = v < 0x80000000 ? HIWORD(v) : 0;
    ostr << "windows version: " << major
         << "." << minor
         << " build: " << build << std::endl;
}
