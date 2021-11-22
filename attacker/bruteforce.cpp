#include <iostream>
#include <NTL/ZZ.h>
#include <thread>
#include <vector>

using NTL::ZZ;

ZZ
moduloZZ(ZZ a, ZZ b) 
{
    ZZ res = a - ((a / b) * b);
    return res + (res < 0) * b;
}

ZZ
bruteforce(ZZ a, ZZ b, ZZ e, ZZ n, ZZ c)
{
   for (ZZ m = a; m < b; m++) {
        std::cout << m << std::endl;
        if (NTL::PowerMod(m, e, n) == c) {
            std::cout << m << std::endl;
            return m;
        }
   }  
   return ZZ(0);
}

int
main()
{
    int nt = std::thread::hardware_concurrency();
    std::vector<std::thread> ths(nt);
    ZZ e = NTL::conv<ZZ>("65537");
    ZZ n = NTL::conv<ZZ>("999630013489");
    ZZ c = NTL::conv<ZZ>("747120213790");
    ZZ min = n / nt;
    for (int i = 0; i < nt; i++) {
        ths[i] = std::thread(bruteforce, i * min, (i + 1) * min, e, n, c);
    } 
    
    for (int i = 0; i < nt; i++) {
        std::cout << "Joined: " << i << std::endl;
        ths[i].join();
    } 
}
