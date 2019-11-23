#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include "Lote.h"
using namespace std;

class Producto{
    private:
        int id;
        int numLotes;
        float precioVenta;
        string nombre;
        string categoria;
    public:
        vector <Lote> lote;
        //constructor
        Producto(){}
        Producto(int, string, string, float);
        //setters
        void setNombre(string);
        void setCategoria(string);
        void setPrecioVenta(float);
        void setID(int);
        void setNumLotes(int);
        //getters
        string getNombre();
        string getCategoria();
        float getPrecioVenta();
        int getId();
        int getNumLotes();
        //metodos
        void agregarLote(Lote);
        void imprimirLotes();
        Lote loteReciente();

        bool operator==(const Producto & obj)
        {
            return (id == obj.id) && (numLotes == obj.numLotes) && (precioVenta == obj.precioVenta) && (nombre == obj.nombre) && (categoria == obj.categoria);
        }

        friend std::ostream & operator << (std::ostream &out, const Producto & obj)
        {
            out<<obj.id<<"\n"<<obj.numLotes<<"\n"<<obj.precioVenta<<"\n"<<obj.nombre<<"\n"<<obj.categoria<<std::endl;
            return out;
        }
        friend std::istream & operator >> (std::istream &in,  Producto &obj)
        {
            in >> obj.id;
            in >> obj.numLotes;
            in >> obj.precioVenta;
            in >> obj.nombre;
            in >> obj.categoria;
            return in;
        }

};

#endif /* PRODUCTO_H */



