#include <NTL/ZZ.h>
#include <iostream>
#include "../headers/math.h"

int
main()
{
    ZZ e1 = NTL::conv<ZZ>("7");
    ZZ e2 = NTL::conv<ZZ>("11");
    ZZ n = NTL::conv<ZZ>("35794234179725868774991807832568455403003778024228226193532908190484670252364677411513516111204504060317568667");
    ZZ c1 = NTL::conv<ZZ>("35794234179725868774991807832568455403003778024228226193532908190484670252364677411513516052471686245831933544");
    ZZ c2 = NTL::conv<ZZ>("35794234179725868774991807832568455403003778024228226193532908190484670252364665786748759822531352444533388184");
    // Comprobamos que los exponentes sean coprimos
    std::cout << mcdZZ(e1, e2) << std::endl;
    // Comprobamos que los mensajes cifrados sean coprimos con n
    std::cout << mcdZZ(c1, n) << std::endl;
    std::cout << mcdZZ(c2, n) << std::endl;

    // Hallamos los inversos
    std::vector<ZZ> ext = extMcdZZ(e1, e2);
    ZZ c1inverse = inverse(c1, n);
    std::cout << "ext 1: " << ext.at(1) << "\text 2: " << ext.at(2) << std::endl;
    // Usando la formula demostrada en clase, hallamos "m"
    ZZ m = moduloZZ(NTL::PowerMod(c1inverse, (-1) * ext.at(1), n) * NTL::PowerMod(c2, ext.at(2), n), n);
    std::cout << "m: " << m << std::endl;

    // Volvemos a cifrar para asi poder comprobar nuestro resultado
    std::cout << "mc1c1: " << moduloZZ(NTL::PowerMod(m, e1, n), n) << std::endl;
    std::cout << "mc2c2: " << moduloZZ(NTL::PowerMod(m, e2, n), n) << std::endl;
}
