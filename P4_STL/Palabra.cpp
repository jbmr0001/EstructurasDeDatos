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
#include <bits/stdc++.h>
#include <locale>
#include <bits/stl_vector.h>
////////////////////////////////CONSTRUCORES///////////////////////////
Palabra::Palabra():
    _palabra(""),
    _ocurrencias(0),
    _dic(0),
    _doc(0)
{
}
Palabra::Palabra(std::string unaPalabra):
    _palabra(unaPalabra),
    _ocurrencias(0),
    _dic(0),
    _doc(0)
    
{
}

Palabra::Palabra(const Palabra& orig):
    _palabra(orig._palabra),
    _ocurrencias(orig._ocurrencias),
    _dic(orig._dic),
    _doc(orig._doc)
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
int Palabra::getNumOcurrencias(){
    return this->_ocurrencias;
}
Documento* Palabra::getDoc(){
    return this->_doc;
}
DiccionarioConVerbos* Palabra::getDic(){
    return this->_dic;
}
void Palabra::setDic(DiccionarioConVerbos* unDic){
    this->_dic=unDic;
}
void Palabra::setDoc(Documento* unDoc){
    this->_doc=unDoc;
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
std::vector<Palabra> Palabra::getCombinaciones(){//metodo mas eficiente
    std::vector<Palabra> vPalabra;
    for(int i=0;i<_palabra.length();i++){//pasamos cada letra de la palabra al vector
        std::string aux;
        aux.push_back(_palabra[i]);//conversion de char a string
        Palabra letra(aux);//creamos la palabra y la insertamos en el vectordinamico de palabras
        vPalabra.push_back(letra);
    }
    //ordenamos el vector, necesario para los anagramas
    std::sort(vPalabra.begin(), vPalabra.end());
    return vPalabra;
}
//Función que devuelve si dos palabras son anagramas
bool Palabra::anagrama(Palabra pal){//comparamos dos vectores de letras ordenados alfabéticamente
    std::vector<Palabra> aux1=this->getCombinaciones();//se obtienen los vectores de palabras ordenados
    std::vector<Palabra> aux2=pal.getCombinaciones();
    bool anagrama=true;
    if(aux1.size()==aux2.size()){//se comparan las dos palabras comparando cada posicion del vector ordenado
        for(int i=0;i<this->getCombinaciones().size();i++){
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
    std::vector<char> ca;//vector dinamico donde se almacenará la nueva palabra troceada
    char a='ñ';//para evitar que catalogue la ñ como no alfabética
    char car[_palabra.length()];//array de char de la longuitud de palabra
    strcpy(car,_palabra.c_str());//las ñ se insertan como n
    
    for(int i=0;i<_palabra.length();i++){//recorremos toda la palabra y solo almecenamos las letras alfabéticas y las ñ
        if(isalpha(car[i])){
            ca.push_back(car[i]);
        }
        if(car[i]==a){//ñ 
            ////if(!isalpha(car[i+1])){
             ca.push_back(car[i]);
            ////}
        }
    }
 
    std::string s="";
    for(int i=0;i<ca.size();i++){//conversií de vector dinámico a string
        s=s+ca[i];
    }
    this->_palabra=s;
          
}
//Función que convierte en minúscula la palabra
void Palabra::convertirMinuscula(){
    char car[_palabra.length()];//array de char de la misma longitud que la palabra
    strcpy(car,_palabra.c_str());//conversión de palabra a array de char
    for(int i=0;i<_palabra.length();i++){
    car[i]=tolower(car[i]);//convertimos a minúscula
    }
    
    std::string s="";//string auxiliar onde se irá guardando la palabra
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
void Palabra::incrementarOcurrencia(){
    this->_ocurrencias++;
}
//Función que devuelve true si contiene la raiz dada
bool Palabra::contieneRaiz(std::string raiz){
    std::string s1=_palabra;
    bool r=false;
    for(int i=0;i<_palabra.length();i++){//recorremos la palabra
        if(_palabra[i]==raiz[0]){//en caso encontrar la primera letra de la raiz
            std::string s2=s1.substr(i, raiz.length()); //extraemos un substring 
            if(s2==raiz){
               r=true;//si raiz=substring
            }
        }
    }
    return r;
}
