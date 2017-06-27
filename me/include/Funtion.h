#ifndef FUNTION_H
#define FUNTION_H
///includes
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include "Registro.h"
#include "Instruccion.h"

using namespace std;
///funtions
string intToString(int a);
int stringToInt(string b);
void separar(vector<string> &argumentos, string resto);
void printI(char);
void sleep(int);

#endif // FUNTION_H
