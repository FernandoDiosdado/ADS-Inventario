#include "Almacen.h"
#include <iostream>
#include <stdlib.h>
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
    if(productos.size()==0){
        cout<<"\nNo hay productos registrados"<<endl;
    }else{
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
}
void Almacen::imprimirProveedor(){
    if(prov.size()==0){
        cout<<"\nNo hay proveedores registrados";
    }else{
        cout<<"\n||ID\t||Nombre\t\t||"<<endl;
        cout<<"-----------------------------------------"<<endl;
        for(int i=0; i<=prov.size()-1; i++){
            cout<<"||"<<prov[i].getId()<<"\t||";
            cout<<prov[i].getNombre()<<"\t\t||"<<endl;
        }
    }
}
Almacen Almacen::leerAlmacen(){
    Almacen almc;
    int i;
    //Recupera datos de objeto de clase Almacen
    ifstream in("almacen.txt");
        in>>almc;
    in.close();
    //Recupera datos de objetos de clase Productos
    in.open("productos.txt");
        int x=almc.numProd;
        Producto prod[x];
        almc.numProd=0;
        for(i=0; i<x; i++){
            in>>prod[i];
            almc.agregarProducto(prod[i]);
        }
    in.close();
    //Recupera datos de objetos de clase Proveedor
    in.open("proveedores.txt");
        x=almc.numProv;
        Proveedor prove[x];
        almc.numProv=0;
        for(i=0; i<x; i++){
            in>>prove[i];
            almc.agregarProveedor(prove[i]);
        }
    in.close();
    //Recupera datos de objetos de clase Lotes
    in.open("lotes.txt");
        for(i=0;i<almc.numProd;i++){
                //cout<<"4."<<i<<endl;
                int y=almc.productos[i].getNumLotes();
                almc.productos[i].setNumLotes(0);
            for(int j=0;j<y;j++){
                Lote lotin;
                in>>lotin;
                almc.productos[i].agregarLote(lotin);
            }
        }
    in.close();
    //Elimina datos de los archivos que fueron leidos para que no se sobreescriba
    system("del productos.txt");
    system("del almacen.txt");
    system("del proveedores.txt");
    system("del lotes.txt");
    return almc;
}
void Almacen::guardarDatos(Almacen almacen){
    int i;
    //Guarda los datos del objetos del tipo Producto
    ofstream out("productos.txt");
    for(i=0; i<almacen.numProd; i++){
        out<<almacen.productos[i];
    }
    out.close();
    //Guarda los datos del objeto de tipo Almacen
    out.open("almacen.txt");
    out<<almacen;
    out.close();
    //Guarda los datos del objeto de tipo Proveedor
    out.open("proveedores.txt");
    for(i=0;i<almacen.prov.size();i++){
        out<<almacen.prov[i];
    }
    out.close();
    //Guarda los datos del objetos del tipo Lotes
    out.open("lotes.txt");
    for(i=0; i<almacen.numProd; i++){
        for(int j=0; j<almacen.productos[i].lote.size(); j++){
            out<<almacen.productos[i].lote[j];
        }
        cout<<"--"<<i<<"--"<<endl;
    }
    out.close();
}
void Almacen::eliminarProducto(int _id){
    bool x=false;
    int i=0;
    do{
        if(productos[i].getId()==_id){
            x=true;
        }else{i++;}
    }while(x==false);
    if(productos[i].getNumLotes()>0){
        cout<<"No se puede eliminar el producto, tiene lotes registrados"<<endl;
    }else{
        productos.erase(productos.begin()+i);
        numProd-=1;
        cout<<"Producto eliminado"<<endl;
    }
    system("pause");
}
void Almacen::eliminarProveedor(int _id){
    bool x=false;
    int i=0;
    do{
        if(prov[i].getId()==_id){
            x=true;
        }else{i++;}
    }while(x==false);
    int h=0;
    for(int k=0;k<numProd;k++){
        for(int j=0;j<productos[k].getNumLotes();j++){
            if(productos[k].lote[j].getProveedor().getId()==_id){
                h++;
            }
        }
    }
    if(h>0){
        cout<<"No puedes eliminar el proveedor, está asociado a un lote"<<endl;
    }else{
        prov.erase(prov.begin()+i);
        numProv-=1;
        cout<<"Proveedor eliminado"<<endl;
    }
    system("pause");
}



