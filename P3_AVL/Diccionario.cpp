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
    _nombreFich(""),
    _terminos()
{
}
Diccionario::Diccionario(std::string unNombreFich):
    _nombreFich(unNombreFich),
    _terminos()
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
void Diccionario::setVerbos(VerbosConjugados unosVerbosConjugados){
    this->_verbos=unosVerbosConjugados;
}
std::string Diccionario::getNombreFich()const{
    return _nombreFich;
}
VerbosConjugados Diccionario::getVerbos()const{
    return _verbos;
}

//Función que mediante un buffer de lectura de ficheros carga cada palabra en el VDinamico de palabras
void Diccionario::leerDiccionario(){
    std::ifstream fe;
    string linea;
    int total=0;
    std::string palabra;
    
    fe.open(getNombreFich());//abrimos fichero
    if(fe.good()){
        while(!fe.eof()){//bucle hasta llegue a la ultima linea
            getline(fe,linea);//leemos la línea
            std::stringstream ss;
            
            ++total;
            ss<<linea;
            getline(ss,palabra);//extraemos la palabra en forma de string de la línea leida
            Palabra pal(palabra);//creamos una Palabra con el string leido 
            _terminos.insertar(pal);
        }
        std::cout<<"Palabras leidas diccionario: "<<total<<std::endl;
        std::cout<<"Tamaño diccionario: "<<_terminos.tam()<<std::endl;
        fe.close();
    }
}