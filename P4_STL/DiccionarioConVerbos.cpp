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
    }
}
//Función para obtener el tamaño del map
void DiccionarioConVerbos::tama(){
    std::map<std::string, Palabra>::iterator it3=_terminos.begin();//iterador para el avl
    int contador=1;
       for(it3;it3!=_terminos.end();it3++){
           contador++;
       }
   std::cout<<"Tamaño del map: "<<contador<<std::endl;
}
//Función para insertar en el map
void DiccionarioConVerbos::insertarInexistente(Palabra pal){
   _terminos[pal.getPalabra()]=pal;
}
//Función para buscar una palabra en el map
Palabra DiccionarioConVerbos::buscarTermino(std::string termino){
    return _terminos[termino];
}
//Función para mostrar las palabras del diccionario inexistentes(tienen un documento asignado)
void DiccionarioConVerbos::mostrarInexistentes(){
     std::map<std::string, Palabra>::iterator it;
     std::cout<<"PALABRAS INEXISTENTES"<<std::endl;
     int contador=0;
     for(it=_terminos.begin();it!=_terminos.end();it++){
         if(it->second.getDoc()!=0){//buscamos las que tienen un documento asignado
         std::cout<<it->first<<"|en documento|"<<it->second.getDoc()->getNombreFich()<<"   ";
         contador++;
         }
     }
     std::cout<<"Total inexistentes: "<<contador;
}
//Función para incrementar las ocurrencias de una palabras en el texto
void DiccionarioConVerbos::incrementarOcurrencia(std::string unString){
    _terminos[unString].incrementarOcurrencia();
}
//Función que devuelve una lista depalabras familiares a una raiz
std::list<Palabra> DiccionarioConVerbos::buscarFamilias(std::string raiz){
    std::map<std::string,Palabra>::iterator it;
    std::list<Palabra> l;
    for(it=_terminos.begin();it!=_terminos.end();it++){
        if(it->second.contieneRaiz(raiz)){
            l.push_back(it->second);
            std::cout<<it->first<<" ";
        }
    }
    std::cout<<std::endl;
    return l;
}