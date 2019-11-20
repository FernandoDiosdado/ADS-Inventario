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
    Almacen almc;
    //Recupera datos de objeto de clase Almacen
    ifstream in("E:\\ADS\\Proyecto\\InventarioADS\\almacen.txt");
        in>>almc;
    in.close();
    //Recupera datos de objetos de clase Productos
    in.open("E:\\ADS\\Proyecto\\InventarioADS\\productos.txt");
        int x=almc.numProd;
        int r=almc.numProd;
        Producto prod[x];
        for(i=0; i<x; i++){
            in>>prod[i];
            almacen.agregarProducto(prod[i]);
        }
    in.close();
    //Recupera datos de objetos de clase Proveedor
    in.open("E:\\ADS\\Proyecto\\InventarioADS\\proveedores.txt");
        x=almc.numProv;
        Proveedor prove[x];
        for(i=0; i<x; i++){
            in>>prove[i];
            almacen.agregarProveedor(prove[i]);
        }
    in.close();
    //Recupera datos de objetos de clase Lotes
    in.open("E:\\ADS\\Proyecto\\InventarioADS\\lotes.txt");
        int y, tot=0;
        x=almacen.numProd;
        for(i=0; i<x; i++){
            y=almacen.productos[i].getNumLotes();
            almacen.productos[i].setNumLotes(0);
            tot+=y;
        }

        Lote lotin[tot];
        for(i=0; i<tot; i++){
            in>>lotin[i];
            almacen.productos[lotin[i].getIdProduc()].agregarLote(lotin[i]);
        }
    in.close();
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
    //Elimina datos de los archivos que fueron leidos para que no se sobreescriba
    system("del E:\\ADS\\Proyecto\\InventarioADS\\productos.txt");
    system("del E:\\ADS\\Proyecto\\InventarioADS\\almacen.txt");
    system("del E:\\ADS\\Proyecto\\InventarioADS\\proveedores.txt");
    system("del E:\\ADS\\Proyecto\\InventarioADS\\lotes.txt");
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
    //Guarda los datos del objetos del tipo Producto
    ofstream out("E:\\ADS\\Proyecto\\InventarioADS\\productos.txt");
    for(i=0; i<=almacen.numProd-1; i++){
        out<<almacen.productos[i];
    }
    out.close();
    //Guarda los datos del objeto de tipo Almacen
    out.open("E:\\ADS\\Proyecto\\InventarioADS\\almacen.txt");
    out<<almacen;
    out.close();
    //Guarda los datos del objeto de tipo Proveedor
    out.open("E:\\ADS\\Proyecto\\InventarioADS\\proveedores.txt");
    for(i=0;i<=almacen.prov.size()-1;i++){
        out<<almacen.prov[i];
    }
    out.close();
    //Guarda los datos del objetos del tipo Lotes
    out.open("E:\\ADS\\Proyecto\\InventarioADS\\lotes.txt");
    for(i=0; i<=almacen.numProd-1; i++){
        for(int j=0; j<=almacen.productos[i].lote.size()-1; j++){
            out<<almacen.productos[i].lote[j];
        }
    }
    out.close();
}
