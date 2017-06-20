#ifndef REGISTRO_H
#define REGISTRO_H
///includes
#include <iostream>
#include <string>

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
};

#endif // REGISTRO_H
