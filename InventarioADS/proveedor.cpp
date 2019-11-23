#include <string>
#include <stdlib.h>
#include "Proveedor.h"
using namespace std;

Proveedor::Proveedor(int _id,string _nombre){
    id=_id;
    nombre=_nombre;
}
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

