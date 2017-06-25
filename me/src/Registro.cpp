#include "Registro.h"

Registro::Registro(int n)
{
    number = n;

    if(n==0){
        tipo = "zero";
        name = "$zero";
        }
    else if(n==1){
            tipo = "reservado";
            name = "$at";
        }
    else if(n==2 || n==3){
            tipo = "procesos";
            name = "$v"+intToString(n);
        }
    else if(n>3 && n<8){
            tipo="savers";
            name = "$a"+intToString(n);
        }
    else if(n>7 && n<16){
            tipo="temporales";
            name="$t"+intToString(n);
        }
    else if(n>15 && n<24){
            tipo="operands";
            name="$s"+intToString(n);
            }
    else if(n==24 || n==25){
            tipo="temporales";
            name="$t"+intToString(n);
            }
    else if(n==26 || n==27){
            tipo="reservado OS";
            name="$k"+intToString(n);
            }
    else if(n==28){
            tipo="global pointer";
            name="$gp";
        }
    else if(n==29){
            tipo="stack pointer";
            name="$sp";
            }
    else if(n==30){
            tipo="frame pointer";
            name="$fp";
        }
    else if(n==31){
            tipo="return address";
            name="$ra";
        }
}

Registro::~Registro(){}

vector<Registro> Registro::operator() (){
    vector<Registro> R;
    for(int k=0;k<32;k++){
        Registro r(k);
        R.push_back(r);
    }
    return R;
}
