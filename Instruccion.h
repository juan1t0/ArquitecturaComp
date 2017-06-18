#ifndef INSTRUCCION_H
#define INSTRUCCION_H

///Includes
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Instruccion
{
    public:
        vector<int> bits;
        string name;
        char Type;
        int instruc;

        Instruccion(string nombre);
        ~Instruccion();
        void fuller();
        void mostrarBinario(void);
};

#endif // INSTRUCCION_H
