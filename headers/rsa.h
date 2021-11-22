#include "NTL/ZZ.h"
#include "../headers/math.h"

using NTL::ZZ;

struct rn {
    public:
    rn(int);
    ZZ e, N, d;
    ZZ cypher(ZZ);
    ZZ decypher(ZZ);
};
