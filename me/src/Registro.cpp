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
            name = "$vi";
        }
    else if(n>3 && n<8){
            tipo="savers";
            name = "$ai";
        }
    else if(n>7 && n<16){
            tipo="temporales";
            name="$ti";
        }
    else if(n>15 && n<24){
            tipo="operands";
            name="$si";
            }
    else if(n==24 || n==25){
            tipo="temporales";
            name="$ti";
            }
    else if(n==26 || n==27){
            tipo="reservado OS";
            name="$ki";
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

Registro::~Registro()
{
    //dtor
}
