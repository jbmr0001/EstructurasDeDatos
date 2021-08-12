/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Juan Bautista
 *
 * Created on 4 de noviembre de 2020, 17:36
 */

#include <cstdlib>
#include <sstream>
#include <fstream>
#include <iostream>
#include <chrono>
#include "DiccionarioConVerbos.h"
#include "GestorTextos.h"
#include <map>
#include "Usuario.h"
#include "Ziri.h"

using namespace std;

int main(int argc, char** argv) {
   
    Usuario a;
    Ziri z;
    std::cout<<"//////////////////CARGA DE DATOS///////////////"<<std::endl;
    z.leerUsuarios();
    z.numeroUsuarios();
    std::cout<<"////////////////CARGA DE USUARIOS//////////////"<<std::endl;
    z.conectarUsuarios(50);
    z.nuevoUsuarioConectado("34923452L","pU7Pqq");
    std::cout<<"///////////////ESCRITURA DE MENSAJES////////////"<<std::endl;
    std::cout<<"Usuarios que han dicho la palabra casa: "<<std::endl;
    z.escribirMensajes();
    std::vector<Usuario> v1=z.analizarTermino("casa");
    std::vector<Usuario>::iterator it;
    for(it=v1.begin();it!=v1.end();it++){
       std::cout<<(*it).getNif()<<"    "<<(*it).getNombre()<<"    "<<(*it).getFrase()<<std::endl;
    }
    std::cout<<"///////////////BUSQUEDA POR RANGO////////////"<<std::endl;
    std::cout<<"-Busqueda palabra ''ganas'' en Jaén"<<std::endl;
    v1=z.buscarTerminoRango("ganas",37,3,38,4);
    for(it=v1.begin();it!=v1.end();it++){
       std::cout<<(*it).getLatitud()<<"    "<<(*it).getLongitud()<<"     "<<(*it).getNif()<<"    "<<(*it).getNombre()<<"    "<<(*it).getFrase()<<std::endl;
    }
    z.mostrarOcurrencias("ganas");
    std::cout<<"-Busqueda palabra ''extranjero'' en Jaén"<<std::endl;
    v1=z.buscarTerminoRango("extranjero",37,3,38,4);
    for(it=v1.begin();it!=v1.end();it++){
       std::cout<<(*it).getLatitud()<<"    "<<(*it).getLongitud()<<"     "<<(*it).getNif()<<"    "<<(*it).getNombre()<<"    "<<(*it).getFrase()<<std::endl;
    }
    z.mostrarOcurrencias("extranjero");
    std::cout<<"-Busqueda palabra ''es'' en Jaén"<<std::endl;
    v1=z.buscarTerminoRango("es",37,3,38,4);
    for(it=v1.begin();it!=v1.end();it++){
       std::cout<<(*it).getLatitud()<<"    "<<(*it).getLongitud()<<"     "<<(*it).getNif()<<"    "<<(*it).getNombre()<<"    "<<(*it).getFrase()<<std::endl;
    }
    z.mostrarOcurrencias("es");
    return 0;
}

