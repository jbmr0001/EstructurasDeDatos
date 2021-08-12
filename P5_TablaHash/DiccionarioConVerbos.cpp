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
#include "Documento.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <map>
#include <bits/stl_list.h>
///////////////////////CONSTRUCTORES/////////////////
DiccionarioConVerbos::DiccionarioConVerbos():
    _nombreDicc("dicc-espanol-sin.txt"),
    _nombreDiccVerbos("verbos_conjugados_sin_tildes_desordenados.txt"),
    _terminos(860029)//primo superior a (numeroElementos*1.6)
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
            
            unsigned long clave=djb2((unsigned char*)(pal.getPalabra()).c_str());
            _terminos.insertar(clave,pal.getPalabra(),pal);
            //si empieza por w la metemos en el vector borrar
            if(pal.getPalabra()[0]=='w'){
                _borrar.push_back(pal);
            }
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
    
             unsigned long clave=djb2((unsigned char*)(pal.getPalabra()).c_str());
            _terminos.insertar(clave,pal.getPalabra(),pal);
            //si empieza por w la metemos en el vector borrar
            if(pal.getPalabra()[0]=='w'){
                _borrar.push_back(pal);
            }
        }
        fe.close();
    }else{
        std::string("Error al abrir el fichero");
    }
}
//Función para mostrar el tamaño del hash
void DiccionarioConVerbos::tama(){
   std::cout<<"Tamaño del hash: "<<_terminos.getTamTabla()<<std::endl;
}
//Función para mostrar las maximas colisiones
void DiccionarioConVerbos::maxColisiones(){
    std::cout<<"Colisiones máximas: "<<_terminos.getMaxColisiones()<<std::endl;
}
//Función para mostrar el factor carga
void DiccionarioConVerbos::factorCarga(){
    std::cout<<"Factor Carga: "<<_terminos.getFactorCarga()<<std::endl;
}
//Función para mostrar el promedio de colisiones
void DiccionarioConVerbos::promedioColisiones(){
    std::cout<<"Promedio de colisiones: "<<_terminos.getPromedioColisiones()<<std::endl;
}
//Fución para mostrar el número de elementos del hash
void DiccionarioConVerbos::nElem(){
    std::cout<<"Numero de elementos: "<<_terminos.getNumElem()<<std::endl;
}
//Función para insertar en el hash
void DiccionarioConVerbos::insertar(Palabra pal){
     unsigned long clave=djb2((unsigned char*)(pal.getPalabra()).c_str());
     int aux=_terminos.getNColisiones();
     _terminos.insertar(clave,pal.getPalabra(),pal);
     aux=_terminos.getNColisiones()-aux;
     std::cout<<pal.getPalabra()<<" Insertada con: "<<aux<<" colisiones"<<std::endl;
}
//Función para buscar una palabra en el hash
bool DiccionarioConVerbos::buscarTermino(std::string termino,Palabra* pal){
    unsigned long clave=djb2((unsigned char*)(termino).c_str());
    Palabra* palAux=pal;
    return _terminos.buscar(clave,termino,palAux);
}
//Función que llama a borrar del hash para cada palabra metidas en el vector de borrado
void DiccionarioConVerbos::borrarPalabras(){
    for(int i=0;i<_borrar.size();i++){
        unsigned long clave=djb2((unsigned char*)(_borrar[i].getPalabra()).c_str());
        _terminos.borrar(clave,_borrar[i].getPalabra());
    }
}