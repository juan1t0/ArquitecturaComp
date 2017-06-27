#ifndef INSTRUCCION_H
#define INSTRUCCION_H

///Includes
#include <iostream>
#include <vector>
#include <string>
#include "Funtion.h"

using namespace std;

class Instruccion
{
    public:
        vector<string> bits;
        vector<string> arguments;
        string name;
        char Type;
        int instruc;

        Instruccion(string nombre);
        ~Instruccion();
        void fuller(void);
        void mostrarBinario(void);
};

#endif // INSTRUCCION_H
