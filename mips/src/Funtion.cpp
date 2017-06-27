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
void printI(char o){
    if(o == 'R'){
        cout<<"Primero reconocemos la instruccion, y la dividimos segun su tipo:"<<endl;
        cout<<"                       Instruccion de tipo R"<<endl;
        cout<<" --------------------------------------------------------------------- "<<endl;
        cout<<"|   Opcode   | registre | registre | registre |  amount  |opcode exten|"<<endl;
        cout<<" --------------------------------------------------------------------- "<<endl;

    }
    else if(o == 'I'){
        cout<<"Primero reconocemos la instruccion, y la dividimos segun su tipo:"<<endl;
        cout<<"                       Instruccion de tipo I"<<endl;
        cout<<" --------------------------------------------------------------------- "<<endl;
        cout<<"|   Opcode   | registre | registre |inmediate operand or address ofset|"<<endl;
        cout<<" --------------------------------------------------------------------- "<<endl;
    }
    else if(o == 'J'){
        cout<<"Primero reconocemos la instruccion, y la dividimos segun su tipo:"<<endl;
        cout<<"                       Instruccion de tipo J"<<endl;
        cout<<" --------------------------------------------------------------------- "<<endl;
        cout<<"|   Opcode   |                  Memory Word Address                   |"<<endl;
        cout<<" --------------------------------------------------------------------- "<<endl;
    }
}
void sleep(int){
    int i=0;
    while(i<500000)
        i++;
}
