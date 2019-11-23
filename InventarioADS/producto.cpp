#include<string>
#include<vector>
#include <iostream>
#include <stdlib.h>
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
void Producto::imprimirLotes(){
    cout<<"\nid: "<<id<<" Nombre: "<<nombre<<endl;
    if(numLotes==0){
        cout<<"Este producto no tiene nigun lote"<<endl;
    }else{
        for(int i=0;i<numLotes;i++){
            cout<<"\nLote No."<<i+1<<endl;
            cout<<"Cantidad de piezas: "<<lote[i].getCantidad()<<endl;
            cout<<"Piezas vendidas: "<<lote[i].getPiezasVendidas()<<endl;
            cout<<"Precio por pieza: "<<lote[i].getPrecioTotal()<<endl;
            cout<<"Estado del pesdido: ";
                if(lote[i].getEstado()==0){
                    cout<<"No disponible para venta"<<endl;
                }else{
                    cout<<"Disponible para venta"<<endl;
                }
            cout<<"Fecha de adquisicion: "<<lote[i].getFechaAdq().tm_mday<<"/"
                <<lote[i].getFechaAdq().tm_mon<<"/"<<lote[i].getFechaAdq().tm_year<<endl;
            cout<<"Fecha de caducidad: "<<lote[i].getFechaCad().tm_mday<<"/"
                <<lote[i].getFechaCad().tm_mon<<"/"<<lote[i].getFechaCad().tm_year<<endl;
            cout<<"Proveedor: "<<lote[i].getProveedor().getNombre()<<endl;
        }
    }
}
Lote Producto::loteReciente(){
    Lote enviado;
    int suma,suma2;
    for(int i=0;i<numLotes;i++){
        suma=lote[i].getFechaAdq().tm_year*365+lote[i].getFechaAdq().tm_mon*31+lote[i].getFechaAdq().tm_mday;
        suma2=lote[i-1].getFechaAdq().tm_year*365+lote[i-1].getFechaAdq().tm_mon*31+lote[i-1].getFechaAdq().tm_mday;
        if(suma<suma2){
            enviado=lote[i];
        }
    }
    return enviado;
}

