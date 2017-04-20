#include <iostream>
#include <bitset>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;


int mod(int a, int b){
	int q,r;
	q=a/b;
	r = a - (q*b);
	if (r<0){
		r=r+b;
	}
	return r;
}
void recorreaizquierda(bitset<8> a,int inicio, int finale){
    bool r = mod(a[inicio] + a[inicio + 2],2);
    int cant = finale - inicio;
    for(int i=0;i<cant;i++){
        a[inicio +i]=a[inicio + 1 + i];
    }
    a[finale]=r;
    cout<<a<<"iz"<<endl;
}

void recorreaderecha(bitset<8> a,int inicio, int finale){
    bool r = mod(a[inicio] + a[inicio + 2],2);
    int cant = finale - inicio;
    for(int i=0;i<cant;i++){
        a[finale -i]=a[finale - 1 - i];
    }
    a[inicio]=r;
    cout<<a<<endl;
}

int random(int seed,int tamanio,int partes,int vueltas){
    bitset<8> rand(seed);
    for(int i=0;i<4;i++){
        int a=rand[i] + rand[i+1];
        rand[i+4]=mod(a,2);
    }
    cout<<rand<<endl;
    int p = 8/partes;
    for(int i=0;i<vueltas;i++){
        for(int j=0;j<partes;j++){
            int a=mod(j,2);
            bool r = mod((rand[j*p] + rand[j*p + 2]),2);
            int cant = (j+1)*p - (j*p);
            if(a == 0){
                ///recorreaizquierda(&rand,j*p,(j+1)*p);
                for(int i=0;i<cant;i++){
                    rand[(j*p) +i]=rand[(j*p) + 1 + i];
                }
                rand[(j+1)*p]=r;
                }
            else
                ///recorreaderecha(&rand,j*p,(j+1)*p);
                for(int i=0;i<cant;i++){
                    rand[((j+1)*p) -i]=rand[((j+1)*p) - 1 - i];
                }
                rand[j*p]=r;
        }
    }
    cout<<rand<<endl;
    return rand.to_ulong();
}

int main()
{
    srand(time(NULL));
    int seed = rand()%20;
    cout << random(seed,8,2,9) << endl;
    return 0;
}
