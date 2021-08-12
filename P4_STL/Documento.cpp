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
    _dicc()
{
}
Documento::Documento(std::string unNombreFich):
    _nombreFich(unNombreFich),
    _dicc()
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
    _dicc->tama();
    while(fe>>palabra){//leemos cada palabra en formato de string
        Palabra pal(palabra);
        //pal.limpiar();
        pal.convertirMinuscula();
        pal.setDoc(this);
         if(_dicc->buscarTermino(pal.getPalabra()).getPalabra()!=""){
             _dicc->incrementarOcurrencia(pal.getPalabra());
         }else{
             _dicc->insertarInexistente(pal);
             _dicc->incrementarOcurrencia(pal.getPalabra());
         }  
    }
    std::cout<<"Ocurrencias mancha: "<<_dicc->buscarTermino("mancha").getNumOcurrencias()<<std::endl;
    std::cout<<"Ocurrencias estaban: "<<_dicc->buscarTermino("estaban").getNumOcurrencias()<<std::endl;
    _dicc->tama();
    std::cout<<std::endl;
    std::cout<<"-----------------FAMILIA FLOR---------------"<<std::endl<<std::endl;
    _dicc->buscarFamilias("flor");
    std::cout<<std::endl;
    std::cout<<"--------------------FAMILIA SAL--------------------"<<std::endl<<std::endl;
    _dicc->buscarFamilias("sal");
    std::cout<<std::endl;
    std::cout<<"-------------------FAMILIA MAR--------------------------"<<std::endl<<std::endl;
    _dicc->buscarFamilias("mar");
    
    _dicc->mostrarInexistentes();
   
}
