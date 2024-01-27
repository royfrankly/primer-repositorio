#include <iostream>
using namespace std;
#include <string>
#include "mostrar.h"
#include "fmultiplicar.h"
int main(){
    cout<<"hola mundo, tiene una nueva modificacion"<<endl;
    mostrar m1("esta es la descripcion del primer m1");
    m1.ver();
    multiplicar(m1, 10);
    return 0;
}
