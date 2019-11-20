#include<string>
#include<vector>
#include <iostream>
#include "Producto.h"
#include "Almacen.h"

using namespace std;
//Constructor
Producto::Producto(int _id, string _nombre, string _categoria, float _precioVenta){
    id=_id;
    nombre=_nombre;
    categoria=_categoria;
    precioVenta=_precioVenta;
    numLotes=0;
}
//setters
void Producto::setNombre(string _nombre){
    nombre=_nombre;
}
void Producto::setCategoria(string _categoria){
    categoria=_categoria;
}
void Producto::setPrecioVenta(float _precio){
    precioVenta=_precio;
}
void Producto::setID(int _id){
    id=_id;
}
void Producto::setNumLotes(int num){
    numLotes=num;
}
//getters
string Producto::getNombre(){
    return nombre;
}
string Producto::getCategoria(){
    return categoria;
}
float Producto::getPrecioVenta(){
    return precioVenta;
}
int Producto::getId(){
    return id;
}
int Producto::getNumLotes(){
    return numLotes;
}
//metodos
void Producto::agregarLote(Lote lotin){
    lote.push_back(lotin);
    numLotes++;
}

