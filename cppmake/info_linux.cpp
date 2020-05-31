#include <iostream>
#include <cstdio>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <netdb.h>

void network_info(std::ostream& ostr)
{
    const int MAX_IFR = 10;
    ifreq ifr[MAX_IFR];

    int fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd == -1) {
        ostr << "socket() error " << strerror(errno);
    } else {
    ifconf ifc = {0};
    ifc.ifc_len =  sizeof(ifr);

    ifc.ifc_ifcu.ifcu_buf = (char *)ifr;

    ioctl(fd, SIOCGIFCONF, &ifc);

    /* kernelから帰ってきた数を計算 */
    int nifs = ifc.ifc_len / sizeof(struct ifreq);

    /* 全てのインターフェース名を表示 */
    for (int i=0; i<nifs; i++) {
        printf("%s\n", ifr[i].ifr_name);
    }

    close(fd);
    }

    addrinfo hints = {0};
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_flags = AI_PASSIVE;    /* For wildcard IP address */
    hints.ai_protocol = 0;          /* Any protocol */
    hints.ai_canonname = nullptr;
    hints.ai_addr = nullptr;
    hints.ai_next = nullptr;

    addrinfo *result;
    if (getaddrinfo("localhost", nullptr, &hints, &result) == 0){
        for (addrinfo* rp = result; rp; rp = rp->ai_next) {
            ostr << "family: " << rp->ai_family
                << " socktype: " << rp->ai_socktype
                << std::endl;
        }
        freeaddrinfo(result);
    } else {
        ostr << "getaddrinfo failed" << std::endl;
    }
}

