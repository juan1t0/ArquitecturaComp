#include <iostream>
#include "Instruccion.h"
#include "Funtion.h"
#include <string.h>
#include <stdlib.h>
#include <bitset>
#include <math.h>
using namespace std;

vector<int> registros_t;
int pc=0;

int bitset_to_int(bitset<32> a){
    int result=0;
    for(int i=0;i<32;i++)
        result+=pow(a[i],i);
}

class funcion{
public:
    string name;
    int cp;
    funcion(string nombre){
        name=nombre;
        cp=pc;
    }
};

vector<funcion> funciones;

int extraer_pc(string nombre){
    for(int i=0;i<funciones.size();i++){
        if(funciones[i].name==nombre)
            return funciones[i].cp;
    }
}

void ejecutar(Instruccion instr){
    if(instr.name=="add"){
        int a,b,c;
        a=atoi(instr.arguments[0].substr(2,instr.arguments[0].length()-2).c_str());
        b=atoi(instr.arguments[1].substr(2,instr.arguments[1].length()-2).c_str());
        c=atoi(instr.arguments[2].substr(2,instr.arguments[2].length()-2).c_str());
        registros_t[a]=registros_t[b]+registros_t[c];
    }
    else if(instr.name=="addu"){
    }
    else if(instr.name=="sub"){
        int a,b,c;
        a=atoi(instr.arguments[0].substr(2,instr.arguments[0].length()-2).c_str());
        b=atoi(instr.arguments[1].substr(2,instr.arguments[1].length()-2).c_str());
        c=atoi(instr.arguments[2].substr(2,instr.arguments[2].length()-2).c_str());
        registros_t[a]=registros_t[b]-registros_t[c];
    }
    else if(instr.name=="mult"){

    }
    else if(instr.name=="div"){
    }
    else if(instr.name=="mfhi"){
    }
    else if(instr.name=="mflo"){
    }
    else if(instr.name=="and"){
        int a,b,c;
        a=atoi(instr.arguments[0].substr(2,instr.arguments[0].length()-2).c_str());
        b=atoi(instr.arguments[1].substr(2,instr.arguments[1].length()-2).c_str());
        c=atoi(instr.arguments[2].substr(2,instr.arguments[2].length()-2).c_str());
        registros_t[a]=registros_t[b]&registros_t[c];
    }
    else if(instr.name=="or"){
        int a,b,c;
        a=atoi(instr.arguments[0].substr(2,instr.arguments[0].length()-2).c_str());
        b=atoi(instr.arguments[1].substr(2,instr.arguments[1].length()-2).c_str());
        c=atoi(instr.arguments[2].substr(2,instr.arguments[2].length()-2).c_str());
        registros_t[a]=registros_t[b]|registros_t[c];
    }
    else if(instr.name=="xor"){
        int a,b,c;
        a=atoi(instr.arguments[0].substr(2,instr.arguments[0].length()-2).c_str());
        b=atoi(instr.arguments[1].substr(2,instr.arguments[1].length()-2).c_str());
        c=atoi(instr.arguments[2].substr(2,instr.arguments[2].length()-2).c_str());
        registros_t[a]=registros_t[b]^registros_t[c];
    }
    else if(instr.name=="nor"){
        int a,b,c;
        a=atoi(instr.arguments[0].substr(2,instr.arguments[0].length()-2).c_str());
        b=atoi(instr.arguments[1].substr(2,instr.arguments[1].length()-2).c_str());
        c=atoi(instr.arguments[2].substr(2,instr.arguments[2].length()-2).c_str());
        registros_t[a]=~(registros_t[b]|registros_t[c]);
    }
    else if(instr.name=="slt"){
        int a,b,c;
        a=atoi(instr.arguments[0].substr(2,instr.arguments[0].length()-2).c_str());
        b=atoi(instr.arguments[1].substr(2,instr.arguments[1].length()-2).c_str());
        c=atoi(instr.arguments[2].substr(2,instr.arguments[2].length()-2).c_str());
        registros_t[a]=registros_t[b]<registros_t[c];

    }
    else if(instr.name=="sll"){

    }
    else if(instr.name=="srl"){

    }
    else if(instr.name=="sra"){

    }
    else if(instr.name=="jr"){

    }
    else if(instr.name=="addi"){
        int a,b,c;
        a=atoi(instr.arguments[0].substr(2,instr.arguments[0].length()-2).c_str());
        b=atoi(instr.arguments[1].substr(2,instr.arguments[1].length()-2).c_str());
        c=atoi(instr.arguments[2].c_str());
        registros_t[a]=registros_t[b]+c;
    }
    else if(instr.name=="addiu"){

    }
    else if(instr.name=="la"){

    }
    else if(instr.name=="lw"){
        int a,b;
        a=atoi(instr.arguments[0].substr(2,instr.arguments[0].length()-2).c_str());
        while(a>registros_t.size()-1)
            registros_t.push_back(0);
        b=atoi(instr.arguments[1].c_str());
        registros_t[a]=b;
    }
    else if(instr.name=="lh"){

    }
    else if(instr.name=="lb"){

    }
    else if(instr.name=="sw"){
        int a,b;
        a=atoi(instr.arguments[0].substr(2,instr.arguments[0].length()-2).c_str());
        while(a>registros_t.size())
            registros_t.push_back(0);
        b=atoi(instr.arguments[1].c_str());
        registros_t[b]=a;
    }
    else if(instr.name=="sh"){

    }
    else if(instr.name=="sb"){

    }
    else if(instr.name=="lui"){
        int a,b;
        a=atoi(instr.arguments[0].substr(2,instr.arguments[0].length()-2).c_str());
        b=atoi(instr.arguments[1].c_str());
        bitset<32> result;
        bitset<32> prev=b;
        for(int i=0;i<16;i++)
            result[i]=prev[i+16];
        registros_t[a]=bitset_to_int(result);
    }
    else if(instr.name=="andi"){
        int a,b,c;
        a=atoi(instr.arguments[0].substr(2,instr.arguments[0].length()-2).c_str());
        b=atoi(instr.arguments[1].substr(2,instr.arguments[1].length()-2).c_str());
        c=atoi(instr.arguments[2].c_str());
        registros_t[a]=registros_t[b]&c;
    }
    else if(instr.name=="ori"){
        int a,b,c;
        a=atoi(instr.arguments[0].substr(2,instr.arguments[0].length()-2).c_str());
        b=atoi(instr.arguments[1].substr(2,instr.arguments[1].length()-2).c_str());
        c=atoi(instr.arguments[2].c_str());
        registros_t[a]=registros_t[b]|c;
    }
    else if(instr.name=="xori"){
        int a,b,c;
        a=atoi(instr.arguments[0].substr(2,instr.arguments[0].length()-2).c_str());
        b=atoi(instr.arguments[1].substr(2,instr.arguments[1].length()-2).c_str());
        c=atoi(instr.arguments[2].c_str());
        registros_t[a]=registros_t[b]^c;
    }
    else if(instr.name=="slti"){
        int a,b,c;
        a=atoi(instr.arguments[0].substr(2,instr.arguments[0].length()-2).c_str());
        b=atoi(instr.arguments[1].substr(2,instr.arguments[1].length()-2).c_str());
        c=atoi(instr.arguments[2].c_str());
        registros_t[a]=registros_t[b]<registros_t[c];
    }
    else if(instr.name=="beq"){
        int a,b;
        a=atoi(instr.arguments[0].substr(2,instr.arguments[0].length()-2).c_str());
        b=atoi(instr.arguments[1].substr(2,instr.arguments[1].length()-2).c_str());
        if(registros_t[a]==registros_t[b])
            pc=extraer_pc(instr.arguments[2]);
    }
    else if(instr.name=="bne"){
        int a,b;
        a=atoi(instr.arguments[0].substr(2,instr.arguments[0].length()-2).c_str());
        b=atoi(instr.arguments[1].substr(2,instr.arguments[1].length()-2).c_str());
        if(registros_t[a]!=registros_t[b])
            pc=extraer_pc(instr.arguments[2]);
    }
    else if(instr.name=="bltz"){
        int a;
        a=atoi(instr.arguments[0].substr(2,instr.arguments[0].length()-2).c_str());
        if(registros_t[a]<0)
            pc=extraer_pc(instr.arguments[1]);
    }
    else if(instr.name=="j"){
        pc=extraer_pc(instr.arguments[0]);
    }
    else if(instr.name=="jr"){
        pc=atoi(instr.arguments[0].c_str());
    }
}

int main(){
    registros_t.push_back(0);
    cout<<"  --------------------------------------  "<<endl;
    cout<<"||                                      ||"<<endl;
    cout<<"||           Instruciones MIPS          ||"<<endl;
    cout<<"||                                      ||"<<endl;
    cout<<"  --------------------------------------  "<<endl;
    cout<<endl;
    string temp="a";
    string mips;
    vector<Instruccion> instrucciones;
    while(true){
    cout<<"ingrese una instruccion:"<<endl;
    mips="";
    while(true){
        cin>>temp;
        if(temp=="-1")
            break;
        mips+=temp;
        mips+=' ';
    }
    if(mips=="")
        break;
    else if(mips[mips.length()-2]==':'){
        funcion func(mips);
        funciones.push_back(func);
    }
    else{
        Instruccion instr(mips);
        instrucciones.push_back(instr);
        cout<<"instruccion de tipo: "<<instr.Type<<endl;
        cout<<"en bits: ";
        instr.mostrarBinario();
    }
    cout<<endl;
    }
    for(;pc<instrucciones.size();pc++){
        ejecutar(instrucciones[pc]);
    }
    for(int i=0;i<registros_t.size();i++)
        cout<<"Valor registro $t"<<i<<": "<<registros_t[i]<<endl;
    return 0;
}
