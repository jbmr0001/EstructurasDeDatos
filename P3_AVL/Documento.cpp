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
#include "VerbosConjugados.h"
#include <fstream>
//////////////////////////CONSTRUCTORES/////////////////////
Documento::Documento():
    _nombreFich(""),
    _inexistentes(),
    _dicc("dicc-espanol-sin.txt")
{
}
Documento::Documento(std::string unNombreFich):
    _nombreFich(unNombreFich),
    _inexistentes(),
    _dicc("dicc-espanol-sin.txt")
{
}

Documento::Documento(const Documento& orig):
    _nombreFich(orig._nombreFich),
    _inexistentes(orig._inexistentes),
    _dicc(orig._dicc)
{
}

Documento::~Documento() {
}
/////////////////////////GETTERS Y SETTERS///////////////////////////
std::string Documento::getNombreFich(){
    return this->_nombreFich;
}
Diccionario Documento::getDiccionario(){
    return this->_dicc;
}
ListaEnlazada<Palabra> Documento::getInexistentes(){
    return this->_inexistentes;
}
void Documento::setNombreFich(std::string unNombreFich){
    this->_nombreFich=unNombreFich;
}
void Documento::setDiccionario(Diccionario unDiccionario){
    this->_dicc=unDiccionario;
}
/////////////////////OPERADORES///////////////////
Documento& Documento::operator =(const Documento& doc){
    _nombreFich=doc._nombreFich;
    //_inexistentes=doc._inexistentes;
    _dicc=doc._dicc;
    return *this;
}
/////////////////////////FUNCIONES//////////////////////////////
void Documento::MostrarInexistentes(){//Se recorre con in iterador la lista y la mostramos
    ListaEnlazada<Palabra>::Iterador<Palabra> it=_inexistentes.iterador();
    int contador=0;
    while(it.haySiguiente()){
        std::cout<<contador<<": "<<it.nodo->dato.getPalabra()<<std::endl;
        it.siguiente();
        contador++;
    }       
}
//Función que llama a insertaOrdenado de la lista
void Documento::addInexistente(Palabra p){
    _inexistentes.insertaOrdenado(p);
    
}
void Documento::chequearTexto(){
    _dicc.setNombreFich("dicc-espanol-sin.txt");
    _dicc.leerDiccionario();//función para cargar la palabras del diccionario
    VerbosConjugados v;//variable auxiliar para asignarle losverbos 
    std::fstream fe;
    string palabra;
    fe.open(getNombreFich());//abrimos flujo de lectura de fichero
  
    while(fe>>palabra){//leemos cada palabra en formato de string
        Palabra pal(palabra);
        pal.limpiar();//la mandamos a limpiarse de signos no alfabéticos solo en caso de leer quijote2.txt
        v=_dicc.getVerbos();
        if(!_dicc.buscarDicotomica(pal) && !v.buscar(pal)){//en caso de no encontrar la palabra en el diccionario la insertamos
            addInexistente(pal); 
        } 
    }
    _inexistentes.borrarRepetidos();//funcion imlementada para borrar repetidos 
    //MostrarInexistentes();
    std::cout<<std::endl<<"Tamaño inexistentes: "<<_inexistentes.tama()<<std::endl;//Mostramos el tamaño de la lista
    v.mostrarAltura();
    borrarNombresPropios();
}
//Funcion que borra nombres propios y palabras que cambiando la primera letra a minuscula se encuentren en el diccionario
void Documento::borrarNombresPropios(){
    ListaEnlazada<Palabra>::Iterador<Palabra> it=_inexistentes.iterador();//creamos un iterador 
    VerbosConjugados v;//variable auxiliar para asignarle losverbos 
    while(it.haySiguiente()){//recorremos todala lista
        v=_dicc.getVerbos();
        Palabra pal(it.nodo->dato.getPalabra());//creamos una palabra auxiliar con la palabra obtenida del iterador
        if(pal.primeraLetraEsMayus()){//en caso de ser un nombre propio ya que no se encentra en el diccionario y tiene la primera mayus
             pal.convertirPrimeraLetraMinuscula();//pasamos su primera letara a minuscula
             if(!_dicc.buscarDicotomica(pal) && !v.buscar(pal)){
                _inexistentes.borrar(it);//se borra
             }
         }
        it.siguiente();
    } 
    std::cout<<"Tamaño tras borrado de nombres propios: "<<_inexistentes.tama()<<std::endl;
}
