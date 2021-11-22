#include "../headers/rsa.h"
#include "../headers/math.h"

using NTL::ZZ;

rn::rn(int bits) 
{
    //ZZ p = NTL::RandomPrime_ZZ(bits), q = NTL::RandomPrime_ZZ(bits);
    ZZ p(3), q(11);
    N = p * q;
    e = NTL::RandomBnd(N);
    ZZ fiN = (p - 1) * (q - 1); 
    while (mcdZZ(e, fiN) != 1) {
        e = NTL::RandomBnd(N);
    }
    d = moduloZZ(inverse(e, fiN), fiN);
}

ZZ
rn::cypher(ZZ m) {
    return NTL::PowerMod(m, e, N);
}

ZZ
rn::decypher(ZZ c) {
    return NTL::PowerMod(c, d, N);
}
