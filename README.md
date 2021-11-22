# Laboratorio 07

### Estudiante: Frank Roger Salas Ticona        CCOMP 3-1

Compilador utilizado g++ (GCC) 11.1.0.

Sistema Operativo: Archlinux 5.15.2-zen1-1-zen.

## Uso

> Compilando con g++.

        g++ main.cpp libraries/* -o output

> Si se usa Windows se debe agregar la extension \*.exe al momento de compilar.


> Ejecutando el programa.

        ./output
        # Si se usa Windows reemplazar el '/' con '\'.

> El programa mostrará los resultados correspondientes.

## Nota

Si bien el trabajo esta terminado, el algoritmo de generación de claves esta modificado para p = 3 y q = 11. Se debe de descomentar una linea en el rsa.cpp para generar primos en base a un número de bits y comentar la que asigna p = 3 y q = 11.
