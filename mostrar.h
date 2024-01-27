#ifndef MOSTRAR_H
#define MOSTRAR_H
#include <iostream>
using namespace std;
#include <string>

class mostrar{
    private:
        string des;
    public:
    mostrar(string);
    void ver();
};
mostrar::mostrar(string _des){
    des = _des;
}
void mostrar::ver(){
    cout<<"La descripcion es: "<<des<<endl;
}

#endif