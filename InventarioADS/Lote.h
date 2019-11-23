#ifndef LOTE_H
#define LOTE_H
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include "Proveedor.h"

using namespace std;

class Lote{
    private:
        int id_producto;
        int cantidad;
        int piezasVendidas;
        float precioTotal;
        bool estado;
        tm fechaAdq;
        tm fechaCad;
        Proveedor prove;
    public:
        Lote();
        Lote(int,int,float,tm,tm,Proveedor);
        //setters
        void setCantidad(int);
        void setPiezasVendidas(int);
        void setPrecioTotal(float);
        void setEstado(bool);
        //getters
        int getCantidad();
        int getPiezasVendidas();
        float getPrecioTotal();
        bool getEstado();
        tm getFechaAdq();
        tm getFechaCad();
        Proveedor getProveedor();
        int getIdProduc();
        //metodos
        void cambiarEstado(bool);

        bool operator==(const Lote & obj)
        {
            return (id_producto == obj.id_producto) && (cantidad == obj.cantidad) && (piezasVendidas == obj.piezasVendidas) &&
            (precioTotal == obj.precioTotal) && (estado == obj.estado)
            && (fechaAdq.tm_mday == obj.fechaAdq.tm_mday) && (fechaAdq.tm_mon == obj.fechaAdq.tm_mon) && (fechaAdq.tm_year == obj.fechaAdq.tm_year)
            && (fechaCad.tm_mday == obj.fechaCad.tm_mday) && (fechaCad.tm_mon == obj.fechaCad.tm_mon) && (fechaCad.tm_year == obj.fechaCad.tm_year);
            //&& (prove == obj.prove) ;
        }

        friend std::ostream & operator << (std::ostream &out, const Lote & obj)
        {
            out<<obj.id_producto<<"\n"<<obj.cantidad<<"\n"<<obj.piezasVendidas<<"\n"<<obj.precioTotal<<"\n"<<obj.estado<<"\n"
            <<obj.fechaAdq.tm_mday<<"\n"<<obj.fechaAdq.tm_mon<<"\n"<<obj.fechaAdq.tm_year<<"\n"
            <<obj.fechaCad.tm_mday<<"\n"<<obj.fechaCad.tm_mon<<"\n"<<obj.fechaCad.tm_year<<std::endl;
            return out;
        }
        friend std::istream & operator >> (std::istream &in,  Lote &obj)
        {
            in >> obj.id_producto;
            in >> obj.cantidad;
            in >> obj.piezasVendidas;
            in >> obj.precioTotal;
            in >> obj.estado;
            in >> obj.fechaAdq.tm_mday;
            in >> obj.fechaAdq.tm_mon;
            in >> obj.fechaAdq.tm_year;
            in >> obj.fechaCad.tm_mday;
            in >> obj.fechaCad.tm_mon;
            in >> obj.fechaCad.tm_year;
            return in;
        }
};

#endif /* LOTE_H */
