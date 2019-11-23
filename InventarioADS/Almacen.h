#ifndef ALMACEN_H
#define ALMACEN_H
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include "Producto.h"
#include "Proveedor.h"
using namespace std;

class Almacen{
    public:
        Almacen();
        int numProd;
        int numProv;
        vector <Producto> productos;
        vector <Proveedor> prov;
        //setters

        //getters
        int getNumProductos();
        int getNumProveedores();
        //metodos
        void agregarProducto(Producto);
        void agregarProveedor(Proveedor);
        void imprimirProducto();
        void imprimirProveedor();
        Almacen leerAlmacen();
        void guardarDatos(Almacen);
        void eliminarProducto(Producto);
        void eliminarProducto(Producto);
        bool operator==(const Almacen & obj)
        {
            return (numProd == obj.numProd) && (numProv == obj.numProv);
        }

        friend std::ostream & operator << (std::ostream &out, const Almacen & obj)
        {
            out<<obj.numProd<<"\n"<<obj.numProv<<std::endl;
            return out;
        }
        friend std::istream & operator >> (std::istream &in,  Almacen &obj)
        {
            in >> obj.numProd;
            in >> obj.numProv;
            return in;
        }
};
#endif /* ALMACEN_H */
