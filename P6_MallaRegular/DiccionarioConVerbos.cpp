/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DiccionarioConVerbos.cpp
 * Author: Juan Bautista
 * 
 * Created on 21 de noviembre de 2020, 19:14
 */

#include "DiccionarioConVerbos.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <map>
#include <bits/stl_list.h>
///////////////////////CONSTRUCTORES/////////////////
DiccionarioConVerbos::DiccionarioConVerbos():
    _nombreDicc("dicc-espanol-sin.txt"),
    _nombreDiccVerbos("verbos_conjugados_sin_tildes_desordenados.txt")
{
    leerDiccionario();
    leerVerbos();
}

DiccionarioConVerbos::DiccionarioConVerbos(const DiccionarioConVerbos& orig):
    _nombreDicc(orig._nombreDicc),
    _nombreDiccVerbos(orig._nombreDiccVerbos)
{
    leerDiccionario();
    leerVerbos();
}

DiccionarioConVerbos::~DiccionarioConVerbos() {
}
///////////////////////////GETTERS Y SETTERS////////////////////////
std::string DiccionarioConVerbos::getNombreDicc(){
    return this->_nombreDicc;
}
std::string DiccionarioConVerbos::getNombreDiccVerbos(){
    return this->_nombreDiccVerbos;
}
void DiccionarioConVerbos::setNombreDicc(std::string unaNombreDicc){
    this->_nombreDicc=unaNombreDicc;
}
void DiccionarioConVerbos::setNombreDiccVerbos(std::string unaNombreDiccVerbos){
    this->_nombreDiccVerbos=unaNombreDiccVerbos;
}
//////////////////////////////FUNCIONES/////////////////////
//Función que mediante un buffer de lectura de ficheros carga cada palabra
void DiccionarioConVerbos::leerDiccionario(){
    std::ifstream fe;
    std::string linea;
    int total=0;
    std::string palabra;
    
    fe.open(getNombreDicc());//abrimos fichero
    if(fe.good()){
        while(!fe.eof()){//bucle hasta llegue a la ultima linea
            getline(fe,linea);//leemos la línea
            std::stringstream ss;
            
            ++total;
            ss<<linea;
            getline(ss,palabra);//extraemos la palabra en forma de string de la línea leida
            Palabra pal(palabra);//creamos una Palabra con el string leido 
            pal.setDic(this);
            
            _terminos[palabra]=pal;    
        }
        fe.close();
    }else{
        std::string("Error al abrir el fichero");
    }
}
//Función que mediante un buffer de lectura de ficheros carga cada verbo
void DiccionarioConVerbos::leerVerbos(){
    std::ifstream fe;
    std::string linea;
    int total=0;
    std::string palabra;
    
    fe.open(getNombreDiccVerbos());//abrimos fichero
    if(fe.good()){
        while(!fe.eof()){//bucle hasta llegue a la ultima linea
            getline(fe,linea);//leemos la línea
            std::stringstream ss;
            
            ++total;
            ss<<linea;
            getline(ss,palabra);//extraemos la palabra en forma de string de la línea leida
            Palabra pal(palabra);//creamos una Palabra con el string leido
            pal.setDic(this);
    
            _terminos[palabra]=pal; 
        }
        fe.close();
        std::cout<<_terminos.size()<<" términos almacenados"<<std::endl;
    }else{
        std::string("Error al abrir el fichero");
    }
}
//Función para buscar una palabra en el hash
Palabra* DiccionarioConVerbos::buscarTermino(std::string termino,Usuario* usuario){
   
    if(_terminos[termino].getPalabra()!=""){
        
        _terminos[termino].incrementarOcurrencia();
    }
    return &_terminos[termino];
}
void DiccionarioConVerbos::insertarInexistente(std::string termino, Usuario* usuario){
    Palabra pal(termino);
    pal.setDichaPor(usuario);
    _terminos[termino]=pal;
    _terminos[termino].incrementarOcurrencia();
}
int DiccionarioConVerbos::getNumOcurrencias(std::string palabra){
    return _terminos[palabra].getNumOcurrencias();
}
void DiccionarioConVerbos::mostrarInexistentes(){
    std::map<std::string,Palabra>::iterator it;
    for(it=_terminos.begin();it!=_terminos.end();it++){
        if((it->second).getDichaPor()!=NULL){
            std::cout<<it->first;
        }
    }
}

