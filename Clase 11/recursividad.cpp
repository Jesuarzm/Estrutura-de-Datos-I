#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int fact(int n){

    if (n == 0)
    {
        return 1;
    }else{
        return n*fact(n-1);
    }
}

int elevacion(int num, int exp){


    if (exp == 0)
    {
        return 1;
    }else{
        return num*elevacion(num, exp-1);
    }
    
}

int main(){
    /*int num = 5;
    int indice = 0;
    int mult=1;
    for (indice; indice <= num; indice++){
        
        mult=mult*indice;
    }

    cout << "Nmero "<< mult;
    
    system("");*/
    cout << "Exp: " << fact(5) << "" << endl;

    cout << "Exp: " << elevacion(2,3) << "" << endl;

}