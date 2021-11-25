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

## Explicación del Algoritmo Implementado

Primero se creo la clase *rn* que esta en headers/rsa.h, posee como atributos las variables de enteros grandes, e, d y N, además tiene dos metodos *cypher(ZZ)* y *decypher(ZZ)* y por último posee un constructor que toma el número de bits con el que se crearan las claves.

> Del constructor:

Generamos dos primos aleatorios para p y q, los multiplicamos y obtenemos el valor de N, obetenemos phi de N, con la formula (p - 1) * (q - 1). Luego generamos en e aleatorio que su gcd con phi de N sea 1. Calculamos la inversa de e y phi de N, y lo guardamos en d.

Y listo tendriamos lo necesario para cifrar y decifrar, llamando los metodos de cypher y decypher.

## Nota

Si bien el trabajo esta terminado, el algoritmo de generación de claves esta modificado para p = 3 y q = 11. Se debe de descomentar una linea en el rsa.cpp para generar primos en base a un número de bits y comentar la que asigna p = 3 y q = 11.
