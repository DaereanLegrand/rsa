#include "../headers/math.h"

ZZ
moduloZZ(ZZ a, ZZ b) 
{
    ZZ res = a - ((a / b) * b);
    return res + (res < 0) * b;
}

ZZ
mcdZZ(ZZ x, ZZ y)
{
    ZZ q, r;
	q = x / y;
	r = moduloZZ(x,y);

	while (r!=0)
	{
		x = y;
		y = r;
		q = x/y;
		r = moduloZZ(x,y);
		x = q*y + r;
	}
	return y;
}

std::vector<ZZ> 
extMcdZZ(ZZ a, ZZ b)
{
    std::vector<ZZ> temp;
    ZZ q = a / b;
    ZZ res = a - (q * b);
    ZZ s1(1), s2(0), s = s1 - (q * s2);
    ZZ t1(0), t2(1), t = t1 - (q * t2);

    while (res > 0)
    {
        a = b;
        b = res;
        q = a / b;
        res = a - (q * b);

        s1 = s2;
        s2 = s;
        s = s1 - (q * s2);

        t1 = t2;
        t2 = t;
        t = t1 - (q * t2);

    }

    temp.push_back(b);
    temp.push_back(s2);
    temp.push_back(t2);

    return temp;
}

ZZ
inverse (ZZ a, ZZ b)
{
    if (mcdZZ(a, b) == 1) {
        return extMcdZZ(a, b).at(1);
    }
    else 
        return ZZ();
}
