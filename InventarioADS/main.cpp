#include <iostream>
#include <stdlib.h>
#include <string>
#include <exception>
#include <fstream>
#include "Proveedor.h"
#include "Lote.h"
#include "Producto.h"
#include "Almacen.h"

using namespace std;

int main(){
    int i;
    Almacen almacen;
    //Lee todos los datos
    almacen=almacen.leerAlmacen();
    //Impresiones de prueba
    int z=almacen.productos.size();
        for(i=0; i<z; i++){
            cout<<"--------"<<almacen.productos[i].getNumLotes()<<"--------"<<endl;
            for(int j=0; j<almacen.productos[i].getNumLotes();j++){
                cout<<"id: "<<almacen.productos[i].lote[j].getIdProduc()<<endl;
                cout<<"cantidad: "<<almacen.productos[i].lote[j].getCantidad()<<endl;
                cout<<"precio: "<<almacen.productos[i].lote[j].getPrecioTotal()<<endl;
                cout<<"estado: "<<almacen.productos[i].lote[j].getEstado()<<endl;
                cout<<"ADIA "<<almacen.productos[i].lote[j].getFechaAdq().tm_mday<<endl;
                cout<<"AMES: "<<almacen.productos[i].lote[j].getFechaAdq().tm_mon<<endl;
                cout<<"AANIO: "<<almacen.productos[i].lote[j].getFechaAdq().tm_year<<endl;
                cout<<"cDIA "<<almacen.productos[i].lote[j].getFechaCad().tm_mday<<endl;
                cout<<"cMES: "<<almacen.productos[i].lote[j].getFechaCad().tm_mon<<endl;
                cout<<"cANIO: "<<almacen.productos[i].lote[j].getFechaCad().tm_year<<endl;
            }

        }
    //Inicia el código para gestion del almacen
    cout<<"\tAlmacen de tienda\n";
    do{
        cout<<"\nElige una opcion\n";
        cout<<"1. Productos\n";
        cout<<"2. Proveedor\n";
        cout<<"3. Salir\n";
        cin>>i;
        switch(i){
            case 1:{
            if(almacen.productos.size()==0){
                cout<<"\nNo hay ningun producto"<<endl;
            }else{
                almacen.imprimirProducto();
                if(almacen.productos[0].getNumLotes()>0){
                }
            }
            cout<<"\n1. Agregar un producto"<<endl;
            cout<<"2. Eliminar un prducto"<<endl;
            cout<<"3. Modificar un producto"<<endl;
            cout<<"4. Agregar lote"<<endl;
            cout<<"5. Regresar"<<endl;
            cout<<"Opcion: ";
            cin>>i;
                switch(i){
                    case 1:{
                        int _idP=almacen.getNumProductos();
                        string nombre, categoria;
                        float precio;
                        cout<<"\nNombre: ";
                        cin>>nombre;
                        cout<<"Categoria: ";
                        cin>>categoria;
                        cout<<"Precio de venta: ";
                        cin>>precio;
                        Producto AgProducto(_idP,nombre,categoria,precio);
                        almacen.agregarProducto(AgProducto);
                        cout<<"Hecho, has agregado un producto."<<endl;
                    break;}
                    case 2:{
                        cout<<"\nEn construccion"<<endl;
                    break;}
                    case 4:{
                        int cant,PId,PvId;
                        float precio;
                        tm ad,cad;
                        if(almacen.prov.size()==0){
                            cout<<"No hay ningun proveedor"<<endl;
                        }else{
                            almacen.imprimirProveedor();
                        }
                        cout<<"ID del producto: ";
                        cin>>PId;
                        cout<<"ID del proveedor: ";
                        cin>>PvId;
                        cout<<"Cantidad: ";
                        cin>>cant;
                        cout<<"Precio: ";
                        cin>>precio;
                        cout<<"Fecha de adquisicion: "<<endl;
                        cout<<"Dia: ";
                        cin>>ad.tm_mday;
                        cout<<"Mes: ";
                        cin>>ad.tm_mon;
                        cout<<"Ano: ";
                        cin>>ad.tm_year;
                        cout<<"Fecha de caducidad: "<<endl;
                        cout<<"Dia: ";
                        cin>>cad.tm_mday;
                        cout<<"Mes: ";
                        cin>>cad.tm_mon;
                        cout<<"Ano: ";
                        cin>>cad.tm_year;
                        Lote AgLote(PId,cant,precio,ad,cad,almacen.prov[PvId]);
                        almacen.productos[PId].agregarLote(AgLote);
                        cout<<"Hecho, has agregado un producto."<<endl;

                    break;}
                    case 5:{
                    break;}
                }
            break;}
            case 2:{
                if(almacen.prov.size()==0){
                    cout<<"No hay ningun proveedor"<<endl;
                }else{
                    almacen.imprimirProveedor();
                }
                cout<<"\n1. Agregar un proveedor"<<endl;
                cout<<"2. Eliminar un proveedor"<<endl;
                cout<<"3. Regresar"<<endl;
                cout<<"Opcion: ";
                cin>>i;
                switch(i){
                    case 1:{
                        int _idPr=almacen.getNumProveedores();
                        string nombre;
                        cout<<"\nNombre: ";
                        cin>>nombre;
                        Proveedor AgProveedor(_idPr,nombre);
                        almacen.agregarProveedor(AgProveedor);
                        cout<<"Hecho, has agregado un proveedor."<<endl;
                    break;}
                    case 3:{
                    break;}
                }
            break;}
            case 3:{
            break;}
        }
    cout<<"\nDesea continuar? Ingrese 0: ";
    cin>>i;
    system("cls");
    }while(i==0);
    //Guarda todos los datos
    almacen.guardarDatos(almacen);
}
