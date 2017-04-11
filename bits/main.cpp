#include <iostream>

using namespace std;

int complAdos(int x){
    x = ~x;
    return x+=1;
}
int sumar(int a,int b){
    int c = a&b,s=a^b;
    while(c!=0){
        int cs=c<< 1;
        c=s&cs;
        s ^= cs;
    }
    return s;
}
int multi(int a, int b){
    int result=0;
    if(a<0){
        int temp;
        temp=a;
        a=b;
        b=temp;
    }
    while(a>0){
        if (a&1)
            result+=b;
        a>>=1;
        b<<=1;
    }
    return result;
}
int multipl(int x,int y){
    int a=0,n = sizeof(x)*8,q1=0,mx=complAdos(x);

    while (n!=0){
        int q0 = y&1;
        cout<<q0<<" "<<q1<<'\t';
        if (q0==1)
            if(q1==0){
                a=sumar(a,mx);cout<<"-> ";}
        if(q0==0)
            if(q1==1){
                a=sumar(a,x);cout<<"-- ";}
        q1 = y&1;
        a>>1;
        y=y>>1;
        n-=1;
        cout<<a<<endl;
    }
    return a;
}
int divicion(int m,int q){
    int a=0;
    int n = sizeof(m)*8;

    while(n!=0){
        a=a<<1;
        q=q<<1;
        a=a-m;
        if(a<0){
            if((q&1)==1)
                q =q-1;
            a=a+m;}
        else
            if((q&1)==0)
                q=q+1;

        n-=1;
    }
    return q;
}
int main()
{
    /// 1 -> 0001   2-> 0010    3-> 0011    4->0100 5->0101
    cout<<multipl(3,5)<<endl;
    cout<<divicion(8,2)<<endl;
    cout<<multi(6,2)<<endl;

    return 0;
}

