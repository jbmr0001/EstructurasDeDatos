/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Palabra.cpp
 * Author: Juan Bautista
 * 
 * Created on 11 de octubre de 2020, 19:00
 */

#include "Palabra.h"
#include <string>
#include <stdlib.h> 
#include <iostream>
#include <algorithm>
#include "VDinamico.h"
////////////////////////////////CONSTRUCORES///////////////////////////
Palabra::Palabra():
    _palabra("")
{
}
Palabra::Palabra(std::string unaPalabra):
    _palabra(unaPalabra)
{
}

Palabra::Palabra(const Palabra& orig):
    _palabra(orig._palabra)
{
}

Palabra::~Palabra() {
}
///////////////GETTERS Y SETTERS//////////////
std::string Palabra::getPalabra(){
    return this->_palabra;
}

void Palabra::setPalabra(std::string unaPalabra){
    this->_palabra=unaPalabra;
}
///////////////OPERADORES//////////////////
bool Palabra::operator <(const Palabra& pal) const{
    return(_palabra<pal._palabra);
}
bool Palabra::operator >(const Palabra& pal) const{
    return(_palabra>pal._palabra);
}
bool Palabra::operator ==(const Palabra& pal) const{
    return(_palabra==pal._palabra);
}
///////////////FUNCIONES////////////////////
Palabra Palabra::reves(){//devuelve una palabra al reves de la que recibe
    std::string pal;
    Palabra palabra;
    int i=_palabra.length()-1;
    while(i>=0){
        pal+=_palabra[i];
        i--;   
    }
    palabra.setPalabra(pal);
    return palabra; 
}

bool Palabra::palindromo(Palabra pal){//función de comprobación de palíndromo
    if(_palabra==pal.reves()._palabra){
        return true;
    }
    return false;
}
VDinamico<Palabra> Palabra::getCombinaciones(){//metodo mas eficiente
    VDinamico<Palabra> vPalabra;
    for(int i=0;i<_palabra.length();i++){//pasamos cada letra de la palabra al vector
        std::string aux;
        aux.push_back(_palabra[i]);//conversion de char a string
        Palabra letra(aux);//creamos la palabra y la insertamos en el vectordinamico de palabras
        vPalabra.insertar(letra);
    }
    vPalabra.ordenar();//ordenamos el vector, necesario para los anagramas
    return vPalabra;
}
bool Palabra::anagrama(Palabra pal){//comparamos dos vectores de letras ordenados alfabéticamente
    VDinamico<Palabra> aux1=this->getCombinaciones();//se obtienen los vectores de palabras ordenados
    VDinamico<Palabra> aux2=pal.getCombinaciones();
    bool anagrama=true;
    if(aux1.tam()==aux2.tam()){//se comparan las dos palabras comparando cada posicion del vector ordenado
        for(int i=0;i<this->getCombinaciones().tam();i++){
            if(aux1[i]._palabra!=aux2[i]._palabra){
                anagrama=false;//si todas las palabras de cada posición son iguales-> anagrama
            }
        }
    }else{
        anagrama=false;
    }
    return anagrama;
}



