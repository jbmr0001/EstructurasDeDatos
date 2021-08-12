/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Diccionario.cpp
 * Author: Juan Bautista
 * 
 * Created on 20 de octubre de 2020, 17:23
 */

#include "Diccionario.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include "Palabra.h"

///////////////////////CONSTRUCTORES///////////////////
Diccionario::Diccionario():
    _nombreFich("")
{
}

Diccionario::Diccionario(const Diccionario& orig): 
    _nombreFich(orig._nombreFich)
{
}

Diccionario::~Diccionario() {
}
/////////////////////////FUNCIONES/////////////////////7
//Función para mostrar todo el VDinamico
void Diccionario::mostrarDiccionario(){
    for(int i=0;i<_terminos.tam();i++){
        std::cout<<_terminos[i].getPalabra()<<std::endl;
    }
    
}
//Función que llama a las busqueda binaria del VDinamico
bool Diccionario::buscarDicotomica(Palabra unaPalabra){
    if(_terminos.busquedaBin(unaPalabra)<79423){//79423 maximo de palabras que alcanza el diccionario
        return true;
    }
    return false;
}
////////////////////GETTERS Y SETTERS//////////////////
void Diccionario::setNombreFich(std::string unNombreFich){
    this->_nombreFich=unNombreFich;
}
std::string Diccionario::getNombreFich(){
    return this->_nombreFich;
}
