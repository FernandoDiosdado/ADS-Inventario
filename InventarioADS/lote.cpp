#include<string>
#include <iostream>
#include "Lote.h"
using namespace std;
//constructor
Lote::Lote(int id_p,int _cantidad, float _precioTotal, tm fAdq, tm fCad, Proveedor prov){
    id_producto=id_p;
    prove=prov;
    cantidad=_cantidad;
    piezasVendidas=0;
    precioTotal=_precioTotal;
    fechaAdq=fAdq;
    fechaCad=fCad;
    estado=false;
}
//setters
void Lote::setCantidad(int _cantidad){
    cantidad=_cantidad;
}
void Lote::setPiezasVendidas(int aumento){
    piezasVendidas+=aumento;
}
void Lote::setPrecioTotal(float _precio){
    precioTotal=_precio;
}
void Lote::setEstado(bool _estado){
    estado=_estado;
}
//getters
int Lote::getCantidad(){
    return cantidad;
}
int Lote::getPiezasVendidas(){
    return piezasVendidas;
}
float Lote::getPrecioTotal(){
    return precioTotal;
}
bool Lote::getEstado(){
    return estado;
}
tm Lote::getFechaAdq(){
    return fechaAdq;
}
tm Lote::getFechaCad(){
    return fechaCad;
}
Proveedor Lote::getProveedor(){
    return prove;
}
int Lote::getIdProduc(){
    return id_producto;
}
//metodos
void Lote::cambiarEstado(bool etd){
    estado=etd;
}

