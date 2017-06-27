#include "Instruccion.h"
#include <string.h>

///globales
#define r 16
#define i 17
#define j 2


/**
instrucciones tipo alu:
instrucciones de carga:
instrucciones de almacenamiento:
instrucciones branch:
instrucciones de salto:
*/
string R[r]={"add","addu","sub","mult","div","mfhi","mflo","and","or","xor","nor","slt","sll","srl","sra","jr"};
int R_fn[r]={32,33,34,0,0,0,0,36,37,38,39,42,0,0,0,8};
string I[i]={"addi","addiu","la","lw","lh","lb","sw","sh","sb","lui","andi","ori","xori","slti","beq","bne","bltz"};
int I_op[i]={8,9,0,35,0,0,43,0,0,15,12,13,14,10,4,5,1};
string J[j]={"j","jal"};
int J_op[j]={2,0};

///Funciones Auxiliares
int find_posR(string name){
    int pos=-1;
    for(int k=0 ;k < r; ++k){
        if(R[k] == name){
            pos = k;
            return pos;
        }
    }
    return r;
}
int find_posI(string name){
    int pos=-1;
    for(int k=0 ;k < i; k++){
        if(I[k] == name){
            pos = k;
            return pos;
        }
    }
    return i;
}
int find_posJ(string name){
    int pos=-1;
    for(int k=0 ;k < j; k++){
        if(J[k] == name){
            pos = k;
            return pos;
        }
    }
    return j;
}
char typeofthis(string name){
    if( find_posJ(name) < j){
        return 'J';
    }
    else if(find_posR(name) < r){
        return 'R';
    }
    else if(find_posI(name) < i){
        return 'I';
    }
    else {
        cout<<"no se encontro la instruccion"<<endl;
        return '\0';
    }
}
void separar(vector<string> &argumentos, string resto){
    string temp;
    for(int a=0;a<resto.length();a++){
        if(resto[a]==','){
            argumentos.push_back(temp);
            temp="";
            continue;
        }
        if(resto[a]==' ')
            continue;
        temp+=resto[a];
    }
    argumentos.push_back(temp);
}

///constructores
Instruccion::Instruccion(string nome)
{
    int espacio=nome.find(' ');
    this->name = nome.substr(0,espacio);
    string resto=nome.substr(espacio+1,nome.length()-(espacio+2));
    separar(arguments,resto);
    this->Type = typeofthis(name);
    fuller();
    cout<<"-----"+nome<<endl;
}
Instruccion::~Instruccion(){}
///metodos
void Instruccion::fuller(void){
    int op=0;
    if (Type=='J'){
        this->instruc=find_posJ(name);
        string brand;
        cin>>brand;
        op=J_op[instruc];
        bits.push_back(intToString(op));
        bits.push_back(brand);
    }
    if(Type == 'I'){
        this->instruc=find_posI(name);
        string rs,rt,inmediate;
        op=I_op[instruc];///registros y valor inmediato puede ser ingresado por el usurio recien aqui
        bits.push_back(intToString(op));
        bits.push_back(rs);
        bits.push_back(rt);
        bits.push_back(inmediate);
    }
    if(Type == 'R'){
        this->instruc=find_posR(name);
        string rs,rt,rd,sh,fn=intToString(R_fn[instruc]);
        op=0;///registros
        bits.push_back(intToString(op));
        bits.push_back(rs);
        bits.push_back(rt);
        bits.push_back(rd);
        bits.push_back(sh);
        bits.push_back(fn);
    }
}
void Instruccion::mostrarBinario(void){
    int sizz= this->bits.size();
    cout<<"[ ";
    for(int k=0;k<sizz;k++){
        cout<<bits[k]<<" ,";
    }
    cout<<"]"<<endl;
}
