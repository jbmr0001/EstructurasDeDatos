/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   THashPalabra.cpp
 * Author: Juan Bautista
 * 
 * Created on 13 de diciembre de 2020, 16:12
 */

#include "THashPalabra.h"
#include <iostream>
//////////////////////////CONSTRUCTORES/////////////////
THashPalabra::THashPalabra(unsigned long tamTabla):
    _tamaTabla(tamTabla),
    _tabla(tamTabla,Entrada()),
    _nElem(0),
    _nColisiones(0),
    _maxColisiones(0),
    _nTerRepetidos(0)
{
    _primo=calcularPrimoMenor(_tamaTabla);
}

THashPalabra::THashPalabra(const THashPalabra& orig):
    _tamaTabla(orig._tamaTabla),
    _tabla(orig._tabla),
    _nElem(orig._nElem),
    _nColisiones(orig._nColisiones),
    _maxColisiones(orig._maxColisiones),
    _nTerRepetidos(orig._nTerRepetidos),
    _primo(orig._primo)
{
}

THashPalabra::~THashPalabra() {
}
/////////////////////////OPERADORES//////////////////
THashPalabra& THashPalabra::operator =(const THashPalabra& orig){
    _tamaTabla=orig._tamaTabla;
    _tabla=orig._tabla;
    _nElem=orig._nElem;
    _nColisiones=orig._nColisiones;
    _maxColisiones=orig._maxColisiones;
    _nTerRepetidos=orig._nTerRepetidos;
    _primo=orig._primo;
    return *this;
}
/////////////////////FUNCIONES//////////////////
bool THashPalabra::insertar(unsigned long clave, const std::string& ter, Palabra& pal){
    unsigned colisiones=0;
    unsigned posicion=0;
    bool insercion=false;
    while((!insercion)&&(colisiones<30)){
        //posicion=hashCuadratica(clave,colisiones);
        posicion=hashDoble1(clave,colisiones);
        //posicion=hashDoble2(clave,colisiones);
        if(_tabla[posicion]._estado==Libre || _tabla[posicion]._estado==Disponible){//si está vacía o recien borrada(disponible)
            _nElem++;
            _tabla[posicion]._termino=ter;
            _tabla[posicion]._estado=Ocupada;
            _tabla[posicion]._clave=clave;
            _tabla[posicion]._pal=pal;
            insercion=true;
        }else{
            ++colisiones;
        }
    }
    
    if(colisiones>_maxColisiones){//actualizamos el maximo de colisiones en caso de superarlo
        _maxColisiones=colisiones;
    }
    _nColisiones=_nColisiones+colisiones;//colisiones totales
    return insercion;
}

bool THashPalabra::buscar(unsigned long clave, const std::string& ter, Palabra*& pal){
    unsigned colisiones=0;
    unsigned posicion=0;
    bool buscado=false;
    while((!buscado)&&(colisiones<30)){
        //posicion=hashCuadratica(clave,colisiones);
        posicion=hashDoble1(clave,colisiones);
        //posicion=hashDoble2(clave,colisiones);
        if(_tabla[posicion]._estado==Ocupada&&_tabla[posicion]._termino==ter){
            pal=&(_tabla[posicion]._pal);
            buscado=true;
        }else{
            if(_tabla[posicion]._estado==Libre){
                break;//salimos
            }else{
                ++colisiones;
            }
        }
    }
    return buscado;
    
}

bool THashPalabra::borrar(unsigned long clave, const std::string& ter){
    unsigned colisiones=0;
    unsigned posicion=0;
    bool borrado=false;
    while(!borrado && colisiones<30){
        //posicion=hashCuadratica(clave,colisiones);
        posicion=hashDoble1(clave,colisiones);
        //posicion=hashDoble2(clave,colisiones);
        if(_tabla[posicion]._estado==Ocupada && _tabla[posicion]._termino==ter){
            _tabla[posicion]._estado=Disponible;
            borrado=true;
            _nElem--;
        }else{
            if(_tabla[posicion]._estado==Libre){
               break; //salimos
            }else{
                ++colisiones;
            }
        }
    }
    return borrado;
}
////////////////GETTERS///////////////
unsigned int THashPalabra::getTamTabla(){
    return _tamaTabla;
}
float THashPalabra::getPromedioColisiones(){
    if(_nElem==0){
        throw std::string("Numero elemetos = 0");
    }
    return (float)_nColisiones/_nElem;
}
float THashPalabra::getFactorCarga(){
    if(_tamaTabla==0){
        throw std::string("Tamaño de tabla = 0");
    }
    return (float)_nElem/_tamaTabla;
}
unsigned int THashPalabra::getMaxColisiones(){
    return _maxColisiones;
}
unsigned int THashPalabra::getNColisiones(){
    return _nColisiones;
}
unsigned int THashPalabra::getNumElem(){
    return _nElem;
}