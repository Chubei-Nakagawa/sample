#include <iostream>


void net_info(std::ofstream& ostr)
{

    addrinfo hints = {0};
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = 0;
    hints.ai_flags = AI_PASSIVE;    /* For wildcard IP address */
    hints.ai_protocol = 0;          /* Any protocol */
    hints.ai_canonname = NULL;
    hints.ai_addr = NULL;
    hints.ai_next = NULL;

    addrinfo *result;
    if (getaddrinfo(nullptr, argv[1], &hints, &result) == 0){
        for (addrinfo* rp = result; rp; rp = rp->ai_next) {
            ostr << "family: " << rp->ai_family
                 << " socktype: " << rp->ai_socktype
                 << std::endl;
        }
        freeaddrinfo(result);
    } else {
        ostr << "getaddrinfo failed";
    }
}
