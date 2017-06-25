#include "Funtion.h"
Registro re(0);
vector<Registro> registros = re();

string intToString(int a){
    stringstream ss;
    ss<<a;
    return ss.str();
}
int stringToInt(string b){
    istringstream buffer(b);
    int val;
    buffer>>val;
    return val;
}
Instruccion textCache(char *linea){


}
