#ifndef PROVEEDOR_H
#define PROVEEDOR_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

class Proveedor{
    private:
        int id;
        string nombre;
    public:
        //constructor
        Proveedor(){}
        Proveedor(int,string);
        //setters
        void setNombre(string);
        //getters
        int getId();
        string getNombre();

        bool operator==(const Proveedor & obj)
        {
            return (id == obj.id) && (nombre == obj.nombre);
        }

        friend std::ostream & operator << (std::ostream &out, const Proveedor & obj)
        {
            out<<obj.id<<"\n"<<obj.nombre<<std::endl;
            return out;
        }
        friend std::istream & operator >> (std::istream &in,  Proveedor &obj)
        {
            in >> obj.id;
            in >> obj.nombre;
            return in;
        }
};
#endif /* PROVEEDOR_H */
