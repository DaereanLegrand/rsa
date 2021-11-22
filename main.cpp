#include <iostream>
#include <NTL/ZZ.h>
#include "headers/rsa.h"
#include "headers/math.h"

int
main()
{
    rn rsa(4);
    std::cout << "N: " << rsa.N << std::endl << "e: " << rsa.e << std::endl << "d: " << rsa.d << std::endl << std::endl;

    for (ZZ m(0); m < rsa.N - 1; m++) {
        std::cout << "m: " << m << std::endl;
        ZZ c = rsa.cypher(m);
        ZZ nm = rsa.decypher(c);
        std::cout << "\tc: " << c << std::endl;
        std::cout << "\tnew m: " << nm << std::endl;
        if (m == c)
            std::cout << "\tOriginal message and cyphered message are the same!\n";
    }
}
