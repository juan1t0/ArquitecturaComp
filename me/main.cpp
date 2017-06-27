#include <iostream>
#include "Instruccion.h"
#include "Funtion.h"
#include <string.h>
#include <stdlib.h>
#include <bitset>
#include <math.h>

using namespace std;

vector<int> l(int a){
    vector<int> reg;
    for(int nox=0;nox<9;nox++)
        reg.push_back(0);
    return reg;
}
vector<int> registros_t=l(10);

int pc=0;

int bitset_to_int(bitset<32> a){
    int result=0;
    for(int i=0;i<32;i++)
        result+=pow(a[i],i);
    return result;
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
char xt;
void ejecutar(Instruccion instr){
    if(instr.name=="add"){
        int a,b,c;
        a=atoi(instr.arguments[0].substr(2,instr.arguments[0].length()-2).c_str());
        b=atoi(instr.arguments[1].substr(2,instr.arguments[1].length()-2).c_str());
        c=atoi(instr.arguments[2].substr(2,instr.arguments[2].length()-2).c_str());
        registros_t[a]=registros_t[b]+registros_t[c];
///-------------------------------------------------------------------------------------
        printI(instr.Type);
        cout<<endl;
        cout<<"---- Registros ----"<<endl;
        cout<<"Se usara "<<endl;
        cout<<"registro "+instr.arguments[1]+" y "+instr.arguments[2]<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- ALU ----"<<"  ... ... ... identificando operacion"<<endl;
        sleep(2);
        cout<<"Se sumaran los valores en "<<endl;
        cout<<"registro "+instr.arguments[1]+" y "+instr.arguments[2]<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Memoria ----"<<endl;
        cout<<"  -Esta instruccion no almacena en memoria-"<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Registro de escritura ----"<<endl;
        cout<<"El resultado se chancara en el registro "+instr.arguments[0]<<endl;
    }
    else if(instr.name=="sub"){
        int a,b,c;
        a=atoi(instr.arguments[0].substr(2,instr.arguments[0].length()-2).c_str());
        b=atoi(instr.arguments[1].substr(2,instr.arguments[1].length()-2).c_str());
        c=atoi(instr.arguments[2].substr(2,instr.arguments[2].length()-2).c_str());
        registros_t[a]=registros_t[b]-registros_t[c];
///-------------------------------------------------------------------------------------
        printI(instr.Type);
        cout<<endl;
        cout<<"---- Registros ----"<<endl;
        cout<<"Se usara "<<endl;
        cout<<"registro "+instr.arguments[1]+" y "+instr.arguments[2]<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- ALU ----"<<"  ... ... ... identificando operacion"<<endl;
        sleep(2);
        cout<<"Se restaran los valores en "<<endl;
        cout<<"registro "+instr.arguments[1]+" y "+instr.arguments[2]<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Memoria ----"<<endl;
        cout<<"  -Esta instruccion no almacena en memoria-"<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Registro de escritura ----"<<endl;
        cout<<"El resultado se chancara en el registro "+instr.arguments[0]<<endl;
    }
    else if(instr.name=="and"){
        int a,b,c;
        a=atoi(instr.arguments[0].substr(2,instr.arguments[0].length()-2).c_str());
        b=atoi(instr.arguments[1].substr(2,instr.arguments[1].length()-2).c_str());
        c=atoi(instr.arguments[2].substr(2,instr.arguments[2].length()-2).c_str());
        registros_t[a]=registros_t[b]&registros_t[c];
///-------------------------------------------------------------------------------------
        printI(instr.Type);
        cout<<endl;
        cout<<"---- Registros ----"<<endl;
        cout<<"Se usara "<<endl;
        cout<<"registro "+instr.arguments[1]+" y "+instr.arguments[2]<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- ALU ----"<<"  ... ... ... identificando operacion"<<endl;
        sleep(2);
        cout<<"Se usara la operacion 'and' con los valores en "<<endl;
        cout<<"registro "+instr.arguments[1]+" y "+instr.arguments[2]<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Memoria ----"<<endl;
        cout<<"  -Esta instruccion no almacena en memoria-"<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Registro de escritura ----"<<endl;
        cout<<"El resultado se chancara en el registro "+instr.arguments[0]<<endl;
    }
    else if(instr.name=="or"){
        int a,b,c;
        a=atoi(instr.arguments[0].substr(2,instr.arguments[0].length()-2).c_str());
        b=atoi(instr.arguments[1].substr(2,instr.arguments[1].length()-2).c_str());
        c=atoi(instr.arguments[2].substr(2,instr.arguments[2].length()-2).c_str());
        registros_t[a]=registros_t[b]|registros_t[c];
///-------------------------------------------------------------------------------------
        printI(instr.Type);
        cout<<endl;
        cout<<"---- Registros ----"<<endl;
        cout<<"Se usara "<<endl;
        cout<<"registro "+instr.arguments[1]+" y "+instr.arguments[2]<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- ALU ----"<<"  ... ... ... identificando operacion"<<endl;
        sleep(2);
        cout<<"Se usara la operacion 'or' con los valores en "<<endl;
        cout<<"registro "+instr.arguments[1]+" y "+instr.arguments[2]<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Memoria ----"<<endl;
        cout<<"  -Esta instruccion no almacena en memoria-"<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Registro de escritura ----"<<endl;
        cout<<"El resultado se chancara en el registro "+instr.arguments[0]<<endl;
    }
    else if(instr.name=="xor"){
        int a,b,c;
        a=atoi(instr.arguments[0].substr(2,instr.arguments[0].length()-2).c_str());
        b=atoi(instr.arguments[1].substr(2,instr.arguments[1].length()-2).c_str());
        c=atoi(instr.arguments[2].substr(2,instr.arguments[2].length()-2).c_str());
        registros_t[a]=registros_t[b]^registros_t[c];
///-------------------------------------------------------------------------------------
        printI(instr.Type);
        cout<<endl;
        cout<<"---- Registros ----"<<endl;
        cout<<"Se usara "<<endl;
        cout<<"registro "+instr.arguments[1]+" y "+instr.arguments[2]<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- ALU ----"<<"  ... ... ... identificando operacion"<<endl;
        sleep(2);
        cout<<"Se usara la operacion 'xor' con los valores en "<<endl;
        cout<<"registro "+instr.arguments[1]+" y "+instr.arguments[2]<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Memoria ----"<<endl;
        cout<<"  -Esta instruccion no almacena en memoria-"<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Registro de escritura ----"<<endl;
        cout<<"El resultado se chancara en el registro "+instr.arguments[0]<<endl;
    }
    else if(instr.name=="nor"){
        int a,b,c;
        a=atoi(instr.arguments[0].substr(2,instr.arguments[0].length()-2).c_str());
        b=atoi(instr.arguments[1].substr(2,instr.arguments[1].length()-2).c_str());
        c=atoi(instr.arguments[2].substr(2,instr.arguments[2].length()-2).c_str());
        registros_t[a]=~(registros_t[b]|registros_t[c]);
///-------------------------------------------------------------------------------------
        printI(instr.Type);
        cout<<endl;
        cout<<"---- Registros ----"<<endl;
        cout<<"Se usara "<<endl;
        cout<<"registro "+instr.arguments[1]+" y "+instr.arguments[2]<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- ALU ----"<<"  ... ... ... identificando operacion"<<endl;
        sleep(2);
        cout<<"Se negaran los valores en "<<endl;
        cout<<"registro "+instr.arguments[1]+" y "+instr.arguments[2]<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Memoria ----"<<endl;
        cout<<"  -Esta instruccion no almacena en memoria-"<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Registro de escritura ----"<<endl;
        cout<<"El resultado se chancara en el registro "+instr.arguments[0]<<endl;
    }
    else if(instr.name=="slt"){
        int a,b,c;
        a=atoi(instr.arguments[0].substr(2,instr.arguments[0].length()-2).c_str());
        b=atoi(instr.arguments[1].substr(2,instr.arguments[1].length()-2).c_str());
        c=atoi(instr.arguments[2].substr(2,instr.arguments[2].length()-2).c_str());
        registros_t[a]=registros_t[b]<registros_t[c];
///-------------------------------------------------------------------------------------
        printI(instr.Type);
        cout<<endl;
        cout<<"---- Registros ----"<<endl;
        cout<<"Se usara "<<endl;
        cout<<"registro "+instr.arguments[1]+" y "+instr.arguments[2]<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- ALU ----"<<"  ... ... ... identificando operacion"<<endl;
        sleep(2);
        cout<<"Se compararan los valores en "<<endl;
        cout<<"registro "+instr.arguments[1]+" y "+instr.arguments[2]<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Memoria ----"<<endl;
        cout<<"  -Esta instruccion no almacena en memoria-"<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Registro de escritura ----"<<endl;
        cout<<"El menor se chancara en el registro "+instr.arguments[0]<<endl;
    }
    else if(instr.name=="addi"){
        int a,b,c;
        a=atoi(instr.arguments[0].substr(2,instr.arguments[0].length()-2).c_str());
        b=atoi(instr.arguments[1].substr(2,instr.arguments[1].length()-2).c_str());
        c=atoi(instr.arguments[2].c_str());
        registros_t[a]=registros_t[b]+c;
///-------------------------------------------------------------------------------------
        printI(instr.Type);
        cout<<endl;
        cout<<"---- Registros ----"<<endl;
        cout<<"Se usara "<<endl;
        cout<<"registro "+instr.arguments[1]<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- ALU ----"<<"  ... ... ... identificando operacion"<<endl;
        sleep(2);
        cout<<"Se sumara el valor en "<<endl;
        cout<<"registro "+instr.arguments[1]+" y la constante"+instr.arguments[2]<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Memoria ----"<<endl;
        cout<<"  -Esta instruccion no almacena en memoria-"<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Registro de escritura ----"<<endl;
        cout<<"El resultado se chancara en el registro "+instr.arguments[0]<<endl;
    }
    else if(instr.name=="lw"){
        int a,b;
        a=atoi(instr.arguments[0].substr(2,instr.arguments[0].length()-2).c_str());
        b=atoi(instr.arguments[1].c_str());
        registros_t[a]=b;
///-------------------------------------------------------------------------------------
        printI(instr.Type);
        cout<<endl;
        cout<<"---- Registros ----"<<endl;
        cout<<"Se usara "<<endl;
        cout<<"registro "+instr.arguments[0]<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- ALU ----"<<"  ... ... ... identificando operacion"<<endl;
        sleep(2);
        cout<<"Se cargara el/los valore(s) de "<<endl;
        cout<<" -"+instr.arguments[1]+"-"<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Memoria ----"<<endl;
        cout<<"  -Ocasionalmente esta instruccion hara lecturas a la memoria-"<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Registro de escritura ----"<<endl;
        cout<<"El valor se chancara en el registro "+instr.arguments[0]<<endl;
    }
    else if(instr.name=="sw"){
        int a,b;
        a=atoi(instr.arguments[0].substr(2,instr.arguments[0].length()-2).c_str());
        b=atoi(instr.arguments[1].c_str());
        registros_t[b]=a;
///-------------------------------------------------------------------------------------
        printI(instr.Type);
        cout<<endl;
        cout<<"---- Registros ----"<<endl;
        cout<<"Se usara "<<endl;
        cout<<"registro "+instr.arguments[0]<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- ALU ----"<<"  ... ... ... identificando operacion"<<endl;
        sleep(2);
        cout<<"Se guardara el/los valore(s) de "<<endl;
        cout<<instr.arguments[0]+" en -"+instr.arguments[1]+"-"<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Memoria ----"<<endl;
        cout<<"  -Esta instruccion solo guarda en memoria-"<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Registro de escritura ----"<<endl;
        cout<<"No sobre escribe ningun registro"<<endl;
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
///-------------------------------------------------------------------------------------
        printI(instr.Type);
        cout<<endl;
        cout<<"---- Registros ----"<<endl;
        cout<<"Se usara "<<endl;
        cout<<"registro "+instr.arguments[0]<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- ALU ----"<<"  ... ... ... identificando operacion"<<endl;
        sleep(2);
        cout<<"Se carga uper-inmediato los valores en "<<endl;
        cout<<" -"+instr.arguments[1]+" en el registro "+instr.arguments[0]<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Memoria ----"<<endl;
        cout<<"  -Esta instruccion no almacena en memoria-"<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Registro de escritura ----"<<endl;
        cout<<"El valor se chancara en el registro "+instr.arguments[0]<<endl;
    }
    else if(instr.name=="andi"){
        int a,b,c;
        a=atoi(instr.arguments[0].substr(2,instr.arguments[0].length()-2).c_str());
        b=atoi(instr.arguments[1].substr(2,instr.arguments[1].length()-2).c_str());
        c=atoi(instr.arguments[2].c_str());
        registros_t[a]=registros_t[b]&c;
///-------------------------------------------------------------------------------------
        printI(instr.Type);
        cout<<endl;
        cout<<"---- Registros ----"<<endl;
        cout<<"Se usara "<<endl;
        cout<<"registro "+instr.arguments[1]<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- ALU ----"<<"  ... ... ... identificando operacion"<<endl;
        sleep(2);
        cout<<"Se usara la operacion 'and' con los valores en "<<endl;
        cout<<"registro "+instr.arguments[1]+" y la constante "+instr.arguments[2]<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Memoria ----"<<endl;
        cout<<"  -Esta instruccion no almacena en memoria-"<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Registro de escritura ----"<<endl;
        cout<<"El resultado se chancara en el registro "+instr.arguments[0]<<endl;
    }
    else if(instr.name=="ori"){
        int a,b,c;
        a=atoi(instr.arguments[0].substr(2,instr.arguments[0].length()-2).c_str());
        b=atoi(instr.arguments[1].substr(2,instr.arguments[1].length()-2).c_str());
        c=atoi(instr.arguments[2].c_str());
        registros_t[a]=registros_t[b]|c;
///-------------------------------------------------------------------------------------
        printI(instr.Type);
        cout<<endl;
        cout<<"---- Registros ----"<<endl;
        cout<<"Se usara "<<endl;
        cout<<"registro "+instr.arguments[1]<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- ALU ----"<<"  ... ... ... identificando operacion"<<endl;
        sleep(2);
        cout<<"Se usara la operacion 'or' con los valores en "<<endl;
        cout<<"registro "+instr.arguments[1]+" y la constante "+instr.arguments[2]<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Memoria ----"<<endl;
        cout<<"  -Esta instruccion no almacena en memoria-"<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Registro de escritura ----"<<endl;
        cout<<"El resultado se chancara en el registro "+instr.arguments[0]<<endl;
    }
    else if(instr.name=="xori"){
        int a,b,c;
        a=atoi(instr.arguments[0].substr(2,instr.arguments[0].length()-2).c_str());
        b=atoi(instr.arguments[1].substr(2,instr.arguments[1].length()-2).c_str());
        c=atoi(instr.arguments[2].c_str());
        registros_t[a]=registros_t[b]^c;
///-------------------------------------------------------------------------------------
        printI(instr.Type);
        cout<<endl;
        cout<<"---- Registros ----"<<endl;
        cout<<"Se usara "<<endl;
        cout<<"registro "+instr.arguments[1]<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- ALU ----"<<"  ... ... ... identificando operacion"<<endl;
        sleep(2);
        cout<<"Se usara la operacion 'xor' con los valores en "<<endl;
        cout<<"registro "+instr.arguments[1]+" y la constante "+instr.arguments[2]<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Memoria ----"<<endl;
        cout<<"  -Esta instruccion no almacena en memoria-"<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Registro de escritura ----"<<endl;
        cout<<"El resultado se chancara en el registro "+instr.arguments[0]<<endl;
    }
    else if(instr.name=="slti"){
        int a,b,c;
        a=atoi(instr.arguments[0].substr(2,instr.arguments[0].length()-2).c_str());
        b=atoi(instr.arguments[1].substr(2,instr.arguments[1].length()-2).c_str());
        c=atoi(instr.arguments[2].c_str());
        registros_t[a]=registros_t[b]<registros_t[c];
///-------------------------------------------------------------------------------------
        printI(instr.Type);
        cout<<endl;
        cout<<"---- Registros ----"<<endl;
        cout<<"Se usara "<<endl;
        cout<<"registro "+instr.arguments[1]<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- ALU ----"<<"  ... ... ... identificando operacion"<<endl;
        sleep(2);
        cout<<"Se compararan los valores en "<<endl;
        cout<<"registro "+instr.arguments[1]+" y la constante "+instr.arguments[2]<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Memoria ----"<<endl;
        cout<<"  -Esta instruccion no almacena en memoria-"<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Registro de escritura ----"<<endl;
        cout<<"El menor se chancara en el registro "+instr.arguments[0]<<endl;

    }
    else if(instr.name=="beq"){
        int a,b;
        a=atoi(instr.arguments[0].substr(2,instr.arguments[0].length()-2).c_str());
        b=atoi(instr.arguments[1].substr(2,instr.arguments[1].length()-2).c_str());
        if(registros_t[a]==registros_t[b])
            pc=extraer_pc(instr.arguments[2]);
///-------------------------------------------------------------------------------------
        printI(instr.Type);
        cout<<endl;
        cout<<"---- Registros ----"<<endl;
        cout<<"Se usara "<<endl;
        cout<<"registro "+instr.arguments[0]+" y "+instr.arguments[1]<<endl;
        cout<<"Si sus valores son iguales hara un salto"<<endl;
        cout<<"----- ------ ------- -----"<<endl;
        cout<<"si la comparacion se cumple hace un salto al tercer parametro,"<<endl;
        cout<<"----- ------ ------- -----"<<endl;

        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- ALU ----"<<"  ... ... ... identificando operacion"<<endl;
        sleep(2);
        cout<<"No es necesario entrar al ALU"<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Memoria ----"<<endl;
        cout<<"  -Esta instruccion no almacena en memoria-"<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Registro de escritura ----"<<endl;
        cout<<"No se sobreescribe nada"<<endl;
    }
    else if(instr.name=="bne"){
        int a,b;
        a=atoi(instr.arguments[0].substr(2,instr.arguments[0].length()-2).c_str());
        b=atoi(instr.arguments[1].substr(2,instr.arguments[1].length()-2).c_str());
        if(registros_t[a]!=registros_t[b])
            pc=extraer_pc(instr.arguments[2]);
///-------------------------------------------------------------------------------------
        printI(instr.Type);
        cout<<endl;
        cout<<"---- Registros ----"<<endl;
        cout<<"Se usara "<<endl;
        cout<<"registro "+instr.arguments[0]+" y "+instr.arguments[1]<<endl;
        cout<<"Si sus valores son diferentes hara un salto"<<endl;
        cout<<"----- ------ ------- -----"<<endl;
        cout<<"si la comparacion se cumple hace un salto al tercer parametro,"<<endl;
        cout<<"----- ------ ------- -----"<<endl;

        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- ALU ----"<<"  ... ... ... identificando operacion"<<endl;
        sleep(2);
        cout<<"No es necesario entrar al ALU"<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Memoria ----"<<endl;
        cout<<"  -Esta instruccion no almacena en memoria-"<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Registro de escritura ----"<<endl;
        cout<<"No se sobreescribe nada"<<endl;
    }
    else if(instr.name=="bltz"){
        int a;
        a=atoi(instr.arguments[0].substr(2,instr.arguments[0].length()-2).c_str());
        if(registros_t[a]<0)
            pc=extraer_pc(instr.arguments[1]);
///-------------------------------------------------------------------------------------
        printI(instr.Type);
        cout<<endl;
        cout<<"---- Registros ----"<<endl;
        cout<<"Se usara "<<endl;
        cout<<"registro "+instr.arguments[0]+" y la etiqueta "+instr.arguments[1]<<endl;
        cout<<"Si su valor es menor a 0 hara un salto"<<endl;
        cout<<"----- ------ ------- -----"<<endl;
        cout<<"si la comparacion se cumple hace un salto al segundo parametro,"<<endl;
        cout<<"----- ------ ------- -----"<<endl;

        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- ALU ----"<<"  ... ... ... identificando operacion"<<endl;
        sleep(2);
        cout<<"No es necesario entrar al ALU"<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Memoria ----"<<endl;
        cout<<"  -Esta instruccion no almacena en memoria-"<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Registro de escritura ----"<<endl;
        cout<<"No se sobreescribe nada"<<endl;
    }
    else if(instr.name=="j"){
        pc=extraer_pc(instr.arguments[0]);
///-------------------------------------------------------------------------------------
        printI(instr.Type);
        cout<<endl;
        cout<<"hace un salto hacia la etiqueta de su segundo parametro"<<endl;
        cout<<"---- Registros ----"<<endl;
        cout<<"No usa registros"<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- ALU ----"<<"  ... ... ... identificando operacion"<<endl;
        cout<<"No entra a ALU"<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Memoria ----"<<endl;
        cout<<"  -Esta instruccion no almacena en memoria-"<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Registro de escritura ----"<<endl;
        cout<<"No hay nada que sobreescribir"<<endl;    }
    else if(instr.name=="jr"){
        pc=atoi(instr.arguments[0].c_str());
///-------------------------------------------------------------------------------------
        printI(instr.Type);
        cout<<endl;
        cout<<"---- Registros ----"<<endl;
        cout<<"Se usara "<<endl;
        cout<<"registro "+instr.arguments[1]<<endl;
        cout<<"----- ------ ------- -----"<<endl;
        cout<<"hara un salto a reguistro"<<endl;
        cout<<"----- ------ ------- -----"<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- ALU ----"<<"  ... ... ... identificando operacion"<<endl;
        cout<<"No entrara"<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Memoria ----"<<endl;
        cout<<"  -Esta instruccion no almacena en memoria-"<<endl;
        cout<<"press plus"<<endl;cin>>xt;
        cout<<endl;
        cout<<"---- Registro de escritura ----"<<endl;
        cout<<"No tiene resultados"+instr.arguments[0]<<endl;
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
    cout<<"Para terminar cada linea de instruccion, coloque '-1'"<<endl;
    cout<<"Para terminar el programa coloque solo '-1'"<<endl;
    cout<<"Recuerde colocar siempre los parametros completos"<<endl;
    cout<<endl;
    string temp="a";
    string mips;
    vector<Instruccion> instrucciones;
    cout<<"ingrese sus instrucciones:"<<endl;
    while(true){
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
        }
        cout<<endl;
    }
    cout<<endl;
    char next;
    cout<<"-- EJECUCION --"<<endl;
    for(;pc<instrucciones.size();pc++){
        cout<<"->  "<<(instrucciones[pc]).name<<endl;
        ejecutar(instrucciones[pc]);
        cout<<"presione S para continuar con la siguiente instruccion  "<<endl;cin>>next;
    }
    cout<<endl;
    for(int i=0;i<registros_t.size();i++)
        cout<<"Valor registro $t"<<i<<":     "<<registros_t[i]<<endl;
    return 0;
}
