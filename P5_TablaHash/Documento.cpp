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
#include "Palabra.h"
#include <fstream>
//////////////////////////CONSTRUCTORES/////////////////////
Documento::Documento():
    _nombreFich(""),
    _dicc(NULL)
{
}
Documento::Documento(std::string unNombreFich):
    _nombreFich(unNombreFich),
    _dicc(NULL)
{
}

Documento::Documento(const Documento& orig):
    _nombreFich(orig._nombreFich),
    _dicc(orig._dicc)
{
}

Documento::~Documento() {
}
/////////////////////////GETTERS Y SETTERS///////////////////////////
std::string Documento::getNombreFich(){
    return this->_nombreFich;
}
DiccionarioConVerbos* Documento::getDiccionario(){
    return this->_dicc;
}
void Documento::setNombreFich(std::string unNombreFich){
    this->_nombreFich=unNombreFich;
}
void Documento::setDiccionario(DiccionarioConVerbos* unDiccionario){
    this->_dicc=unDiccionario;
}
/////////////////////OPERADORES///////////////////
Documento& Documento::operator =(const Documento& doc){
    _nombreFich=doc._nombreFich;
    _dicc=doc._dicc;
    return *this;
}
void Documento::chequearTexto(){
    std::fstream fe;
    std::string palabra;
    fe.open(getNombreFich());//abrimos flujo de lectura de fichero
    DiccionarioConVerbos d;
    _dicc=&d;
    //mostramos info de la tabla hash
    _dicc->nElem();
    _dicc->tama();
    _dicc->factorCarga();
    _dicc->maxColisiones();
    _dicc->promedioColisiones();
    while(fe>>palabra){//leemos cada palabra en formato de string
        Palabra pal(palabra);
        pal.limpiar();
        pal.convertirMinuscula();
        pal.setDoc(this);
        Palabra* aux;
        if(!_dicc->buscarTermino(pal.getPalabra(),aux)&&!esInexistente(pal)){//inserción evitando repetidos
            _inexistentes.push_back(pal);
        }
    }
    mostrarTamInexistentes();
    
    std::cout<<std::endl<<std::endl<<"-------Inserción wifi------"<<std::endl;
    Palabra pal;
    pal.setPalabra("wifi");
    insertarPalabraDiccionario(pal);
    _dicc->nElem();
    
    std::cout<<std::endl<<"------Borrado palabras que empiezan por 'w'------"<<std::endl;
    _dicc->nElem();
    borrarVectorPalabras();
    _dicc->nElem();;
    
    
     std::cout<<std::endl<<"------Insercion waterpolo y windsurf------"<<std::endl;
     pal.setPalabra("waterpolo");
     _dicc->insertar(pal);
     pal.setPalabra("windsurf");
     _dicc->insertar(pal);
}
//Función de inserción de inexistentes
void Documento::insertarInexistente(Palabra pal){
    _inexistentes.push_back(pal);
}
//Función para mostrar el tamaño de la lista de inexistentes
int Documento::mostrarTamInexistentes(){
    std::cout<<"Tamaño inexistentes: "<<_inexistentes.size();
}
//Función para mostrar la lista de inexistentes
void Documento::mostrarInexistentes(){
    std::list<Palabra>::iterator it;
    _inexistentes.sort();
    int contador=0;
    for(it=_inexistentes.begin();it!=_inexistentes.end();it++){
        std::cout<<contador<<": "<<it->getPalabra()<<std::endl;
        contador++;
    }
}
//Funcion que determina si una palabra está en la lista de inexistentes
bool Documento::esInexistente(Palabra p){
    std::list<Palabra>::iterator it;
    bool esInexistente=false;
    for(it=_inexistentes.begin();it!=_inexistentes.end();it++){
        if(p.getPalabra()==it->getPalabra()){
            esInexistente=true;
        }
    }
    return esInexistente;
}
//Función de inserción que llama al método insertar de diccionario
void Documento::insertarPalabraDiccionario(Palabra pal){
    _dicc->insertar(pal);
}
//Función de borrado que llama al método borrar de diccionario
void Documento::borrarVectorPalabras(){
    _dicc->borrarPalabras();
}