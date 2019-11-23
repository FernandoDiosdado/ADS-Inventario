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
    int i, _id;
    float _precio;
    bool x;
    string _nombre;
    Almacen almacen;
    //Lee todos los datos
    almacen=almacen.leerAlmacen();
    //Inicia el código para gestion del almacen
    cout<<"\tAlmacen de tienda"<<endl;
    do{
        cout<<"\nElige una opcion"<<endl;
        cout<<"1. Productos"<<endl;
        cout<<"2. Proveedor"<<endl;
        cout<<"3. Lotes"<<endl;
        cout<<"4. Salir"<<endl;
        cout<<"Opcion: ";
        cin>>i;
        switch(i){
            case 1:{
            almacen.imprimirProducto();
            cout<<"\n1. Agregar producto"<<endl;
            cout<<"2. Eliminar prducto"<<endl;
            cout<<"3. Modificar producto"<<endl;
            cout<<"4. Regresar"<<endl;
            cout<<"Opcion: ";
            cin>>i;
                switch(i){
                    case 1:{
                        string categoria;
                        if(almacen.getNumProductos()==0){
                            _id=0;
                        }else{
                            _id=almacen.productos[almacen.getNumProductos()-1].getId()+1;
                        }
                        cout<<"\nNombre: ";
                        cin>>_nombre;
                        cout<<"Categoria: ";
                        cin>>categoria;
                        cout<<"Precio de venta: ";
                        cin>>_precio;
                        Producto AgProducto(_id,_nombre,categoria,_precio);
                        almacen.agregarProducto(AgProducto);
                        cout<<"Hecho, has agregado un producto."<<endl;
                        i=0;
                        system("pause");
                    break;}
                    case 2:{
                        cout<<"\nEn construccion"<<endl;
                    break;}
                    case 3:{
                        cout<<"\nIntroduce el id del prodcuto a editar"<<endl;
                    break;}
                    case 4:{
                        i=0;
                    break;}
                }
            break;}
            case 2:{
                almacen.imprimirProveedor();
                cout<<"\n1. Agregar proveedor"<<endl;
                cout<<"2. Eliminar proveedor"<<endl;
                cout<<"3. Modificar proveedor"<<endl;
                cout<<"4. Regresar"<<endl;
                cout<<"Opcion: ";
                cin>>i;
                switch(i){
                    case 1:{
                        if(almacen.getNumProveedores()==0){
                            _id=0;
                        }else{
                            _id=almacen.productos[almacen.getNumProveedores()-1].getId()+1;
                        }
                        cout<<"\nNombre: ";
                        cin>>_nombre;
                        Proveedor AgProveedor(_id,_nombre);
                        almacen.agregarProveedor(AgProveedor);
                        cout<<"Hecho, has agregado un proveedor."<<endl;
                        i=0;
                        system("pause");
                    break;}
                    case 4:{
                        i=0;
                    break;}
                }
            break;}
            case 3:{
                for(i=0;i<almacen.getNumProductos();i++){
                    almacen.productos[i].imprimirLotes();
                }
                cout<<"\n1. Agregar lote"<<endl;
                cout<<"2. Activar-desactivar lote"<<endl;
                cout<<"3. Lote mas antiguo para venta"<<endl;
                cout<<"4. Regresar"<<endl;
                cout<<"Opcion: ";
                cin>>i;
                switch(i){
                    case 1:{
                        int cantidad,PvId;
                        tm ad,cad;
                        almacen.imprimirProducto();
                        almacen.imprimirProveedor();
                        cout<<"ID del producto: ";
                        cin>>_id;
                        cout<<"ID del proveedor: ";
                        cin>>PvId;
                        cout<<"Cantidad: ";
                        cin>>cantidad;
                        cout<<"Precio: ";
                        cin>>_precio;
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
                        x=false;
                        i=0;
                        do{
                           if(almacen.productos[i].getId()==_id){
                                x=true;
                           }else{i++;}
                        }while(x==false);
                        Lote AgLote(_id,cantidad,_precio,ad,cad,almacen.prov[PvId]);
                        almacen.productos[i].agregarLote(AgLote);
                        cout<<"Hecho, has agregado un lote."<<endl;
                        i=0;
                        system("pause");
                    break;}
                    case 2:{
                        int nLote;
                        string decision;
                        cout<<"Activar-Desactivar lote";
                        cout<<"\nId del producto: ";
                        cin>>_id;
                        cout<<"Numero de lote: ";
                        cin>>nLote;
                        i=0;
                        x=false;
                        do{
                           if(almacen.productos[i].getId()==_id){
                                x=true;
                           }else{i++;}
                        }while(x==false);
                        cout<<"El estado del lote es:";
                        if(almacen.productos[i].lote[nLote-1].getEstado()==0){
                            cout<<"No disponible"<<endl;
                            cout<<"Cambiar estado a disponible? si/no"<<endl;
                            cin>>decision;
                            if(decision=="si"){
                                almacen.productos[i].lote[nLote-1].cambiarEstado(true);
                            }else{
                                cout<<"No hay cambios"<<endl;
                            }
                        }else{
                            cout<<"Disponible"<<endl;
                            cout<<"Cambiar estado a no disponible? si/no"<<endl;
                            cin>>decision;
                            if(decision=="si"){
                                almacen.productos[x].lote[nLote-1].cambiarEstado(false);
                            }else{
                                cout<<"No hay cambios"<<endl;
                            }
                        }
                        i=0;
                    break;}
                    case 4:{
                        i=0;
                    break;}
                    case 3:{
                        cout<<"Ingrese el id del producto: ";
                        cin>>_id;
                        x=false;
                        i=0;
                        do{
                           if(almacen.productos[i].getId()==_id){
                                x=true;
                           }else{i++;}
                        }while(x==false);
                        cout<<almacen.productos[i].loteReciente().getPrecioTotal();
                        system("pause");
                        i=0;
                    break;}
                }

            break;}
            case 4:{
                i=4;
            break;}
        }
    system("cls");
    }while(i!=4);
    //Guarda todos los datos
    almacen.guardarDatos(almacen);
}
