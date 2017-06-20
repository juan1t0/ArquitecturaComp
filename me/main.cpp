#include <iostream>
#include "Instruccion.h"
using namespace std;

int main(){
    cout<<"  --------------------------------------  "<<endl;
    cout<<"||                                      ||"<<endl;
    cout<<"||           Instruciones MIPS          ||"<<endl;
    cout<<"||                                      ||"<<endl;
    cout<<"  --------------------------------------  "<<endl;
    cout<<endl;
    string mips;
while(true){
    cout<<"ingrese una instruccion:"<<endl;
    cin>>mips;
    if(mips == "-1")
        break;

    Instruccion instr(mips);
    cout<<"instruccion de tipo: "<<instr.Type<<endl;
    cout<<"en bits: ";
    instr.mostrarBinario();
    cout<<endl;
}
    return 0;
}
