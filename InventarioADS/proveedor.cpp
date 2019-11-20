#include <string>
#include "Proveedor.h"
using namespace std;

Proveedor::Proveedor(int _id,string _nombre){
    id=_id;
    nombre=_nombre;
}
/*Proveedor::Proveedor(){
    id=0;
}*/
//setters
void Proveedor::setNombre(string _nombre){
    nombre=_nombre;
}
//getters
string Proveedor::getNombre(){
    return nombre;
}
int Proveedor::getId(){
    return id;
}

