#ifndef REGISTRO_H
#define REGISTRO_H
///includes
#include <iostream>
#include <string>
#include <vector>
#include "Funtion.h"

using namespace std;
///registro
class Registro
{
public:
    string name;
    int number;
    string tipo;

    Registro(int n);
    virtual ~Registro();

    vector<Registro> operator() ();
};

#endif // REGISTRO_H
