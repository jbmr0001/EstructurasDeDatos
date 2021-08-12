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
#include <bits/stdc++.h>
#include <locale>
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
bool Palabra::operator!=(const Palabra& pal)const{
    return(_palabra!=pal._palabra);
}
bool Palabra::operator<=(const Palabra& pal)const{
    return(_palabra<=pal._palabra);
}
bool Palabra::operator >=(const Palabra& pal) const{
    return(_palabra>=pal._palabra);
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
//Función que develve un VDinamico ordenado con las letras de una palabra
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
//Función que devuelve si dos palabras son anagramas
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
//Funcion que quita los signos no alfabéticos de una palabra 
void Palabra::limpiar(){
    VDinamico<char> ca;//vector dinamico donde se almacenará la nueva palabra troceada
    char a='ñ';//para evitar que catalogue la ñ como no alfabética
    char car[_palabra.length()];//array de char de la longuitud de palabra
    strcpy(car,_palabra.c_str());//las ñ se insertan como n
    
    for(int i=0;i<_palabra.length();i++){//recorremos toda la palabra y solo almecenamos las letras alfabéticas y las ñ
        if(isalpha(car[i])){
            ca.insertar(car[i]);
        }
        if(car[i]==a){//ñ 
            //if(!isalpha(car[i+1])){
            ca.insertar(car[i]);
            //}
        }
    }
 
    string s="";
    for(int i=0;i<ca.tam();i++){//conversií de vector dinámico a string
        s=s+ca[i];
    }
    this->_palabra=s;
          
}
//Función que convierte en minúscula la primera letra de una palabra
void Palabra::convertirPrimeraLetraMinuscula(){
    char car[_palabra.length()];//array de char de la misma longitud que la palabra
    strcpy(car,_palabra.c_str());//conversión de palabra a array de char
    
    car[0]=tolower(car[0]);//convertimos a minúscula
    
    string s="";//string auxiliar onde se irá guardando la palabra
    for(int i=0;i<_palabra.length();i++){
        s=s+car[i];
    }
    this->_palabra=s;
}
//Funcion que devuelve si la primera letra es mayúscula
bool Palabra::primeraLetraEsMayus(){
    char car[_palabra.length()];
    strcpy(car,_palabra.c_str());
    bool m=false;
    if(isupper(car[0])){
        m=true;
        
    }
    return m;
}

