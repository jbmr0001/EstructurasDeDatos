/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GestorTextos.cpp
 * Author: Juan Bautista
 * 
 * Created on 20 de octubre de 2020, 17:57
 */

#include "GestorTextos.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "Palabra.h"
#include "Diccionario.h"
#include "ListaEnlazada.h"
#include <bits/stdc++.h>
#include <locale>

/////////////////////CONSTRUCTORES/////////////////
GestorTextos::GestorTextos() {
}

GestorTextos::GestorTextos(const GestorTextos& orig) {
}

GestorTextos::~GestorTextos() {
}
////////////////////////////GETTERS Y SETTERS/////////////////////
Diccionario GestorTextos::getDiccionario() const{
    return _diccionario;
}
Documento GestorTextos::getDocumento() const{
    return _texto;
}

////////////////////////////FUNCIONES////////////////////////////
//Función en la que se carga el diccionario y lee el quijote para añadir las no presentes en inexistentes.
void GestorTextos::chequearTexto(){
    _diccionario.setNombreFich("dicc-espanol-sin.txt");
    _texto.setNombreFich("quijote2.txt");
    leerDiccionario();//función para cargar la palabras del diccionario
  
    std::fstream fe;
    string palabra;
    fe.open(_texto.getNombreFich());//abrimos flujo de lectura de fichero
  
    while(fe>>palabra){//leemos cada palabra en formato de string
        Palabra pal(palabra);
        pal.limpiar();//la mandamos a limpiarse de signos no alfabéticos
        if(!_diccionario.buscarDicotomica(pal)){//en caso de no encontrar la palabra en el diccionario la insertamos
            _texto.addInexistente(pal);
        }
    }
    _texto._inexistentes.borrarRepetidos();//funcion imlementada para borrar repetidos 
    _texto.MostrarInexistentes();
    std::cout<<std::endl<<"Tamaño: "<<_texto._inexistentes.tama()<<std::endl;//Mostramos el tamaño de la lista
  
}
//Función que mediante un buffer de lectura de ficheros carga cada palabra en el VDinamico de palabras
void GestorTextos::leerDiccionario(){
    std::ifstream fe;
    string linea;
    int total=0;
    std::string palabra;
    
    fe.open(_diccionario.getNombreFich());//abrimos fichero
    if(fe.good()){
        while(!fe.eof()){//bucle hasta llegue a la ultima linea
            getline(fe,linea);//leemos la línea
            std::stringstream ss;
            
            ++total;
            ss<<linea;
            getline(ss,palabra);//extraemos la palabra en forma de string de la línea leida
            Palabra pal(palabra);//creamos una Palabra con el string leido 
            _diccionario._terminos.insertar(pal);
        }
        std::cout<<"Palabras leidas diccionario: "<<total<<std::endl;
        std::cout<<"Tamaño diccionario: "<<_diccionario._terminos.tam()<<std::endl;
        fe.close();
    }
}
//Funcion que borra nombres propios y palabras que cambiando la primera letra a minuscula se encuentren en el diccionario
void GestorTextos::borrarNombresPropios(){
    ListaEnlazada<Palabra>::Iterador<Palabra> it=_texto._inexistentes.iterador();//creamos un iterador 
    while(it.haySiguiente()){//recorremos todala lista
        
        Palabra pal(it.nodo->dato.getPalabra());//creamos una palabra auxiliar con la palabra obtenida del iterador
        if(pal.primeraLetraEsMayus()){//en caso de ser un nombre propio ya que no se encentra en el diccionario y tiene la primera mayus
             pal.convertirPrimeraLetraMinuscula();//pasamos su primera letara a minuscula
             if(!_diccionario.buscarDicotomica(pal)){
                _texto._inexistentes.borrar(it);//se borra
             }
         }
        it.siguiente();
    } 
    std::cout<<"Tamaño tras borrado de nombres propios: "<<_texto._inexistentes.tama();
}

