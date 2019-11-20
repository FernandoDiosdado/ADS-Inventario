#include "Almacen.h"
#include <iostream>
#include <string>

using namespace std;
//contructor
Almacen::Almacen(){
    numProd=0;
    numProv=0;
}
//getters
int Almacen::getNumProductos(){
    return productos.size();
}
int Almacen::getNumProveedores(){
    return prov.size();
}
//metodos
void Almacen::agregarProducto(Producto produc){
    productos.push_back(produc);
    numProd++;
}
void Almacen::agregarProveedor(Proveedor p){
    prov.push_back(p);
    numProv++;
}
void Almacen::imprimirProducto(){
    cout<<"\n||ID\t||Nombre\t\t||Categoria\t\t||Precio\t||numLotes"<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;
    for(int i=0; i<=productos.size()-1; i++){
        cout<<"||"<<productos[i].getId()<<"\t||";
        cout<<productos[i].getNombre()<<"\t\t||";
        cout<<productos[i].getCategoria()<<"\t\t||";
        cout<<productos[i].getPrecioVenta()<<"\t\t||";
        cout<<productos[i].getNumLotes()<<endl;
    }
}
void Almacen::imprimirProveedor(){
    cout<<"\n||ID\t||Nombre\t\t||"<<endl;
    cout<<"-----------------------------------------"<<endl;
    for(int i=0; i<=prov.size()-1; i++){
        cout<<"||"<<prov[i].getId()<<"\t||";
        cout<<prov[i].getNombre()<<"\t\t||"<<endl;
    }
}



