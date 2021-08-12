/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Documento.cpp
 * Author: Juan Bautista
 * 
 * Created on 20 de octubre de 2020, 17:57
 */

#include "Documento.h"
#include <string>
#include <iostream>
//////////////////////////CONSTRUCTORES/////////////////////
Documento::Documento():
    _nombreFich("")
{
}

Documento::Documento(const Documento& orig):
    _nombreFich(orig._nombreFich)
{
}

Documento::~Documento() {
}
/////////////////////////GETTERS Y SETTERS///////////////////////////
std::string Documento::getNombreFich(){
    return this->_nombreFich;
}
void Documento::setNombreFich(std::string unNombreFich){
    this->_nombreFich=unNombreFich;
}
/////////////////////////FUNCIONES//////////////////////////////
void Documento::MostrarInexistentes(){//Se recorre con in iterador la lista y la mostramos
    ListaEnlazada<Palabra>::Iterador<Palabra> it=_inexistentes.iterador();
    int contador=0;
    while(it.haySiguiente()){
        std::cout<<contador<<": "<<it.nodo->dato.getPalabra()<<std::endl;
        it.siguiente();
        contador++;
    }       
}
//Función que llama a insertaOrdenado de la lista
void Documento::addInexistente(Palabra p){
    _inexistentes.insertaOrdenado(p);
    
}


