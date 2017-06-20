#include "Funtion.h"
vector<Registro> registros;

//for(int k=0;k<32;k++){;
   // Registro r(k);
  //  registros.push_back(r);
//}

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
