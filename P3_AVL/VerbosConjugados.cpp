/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VerbosConjugados.cpp
 * Author: Juan Bautista
 * 
 * Created on 6 de noviembre de 2020, 16:38
 */

#include "VerbosConjugados.h"
#include <fstream>
#include <sstream>
/////////////////////////CONSTRUCTORES///////////////////////
VerbosConjugados::VerbosConjugados():
    _nombreFich("verbos_conjugados_sin_tildes_desordenados.txt")
{
    leerVerbos();
}
VerbosConjugados::VerbosConjugados(const VerbosConjugados& orig):
    _nombreFich(orig._nombreFich)
{
}
VerbosConjugados::~VerbosConjugados() {
}
//////////////////////////OPERADORES///////////////////////
VerbosConjugados& VerbosConjugados::operator =(const VerbosConjugados& ver){
    _nombreFich=ver._nombreFich;
    return *this;
}

///////////////////////GETTERS Y SETTERS/////////////////////////////
std::string VerbosConjugados::getNombreFich(){
    return this->_nombreFich;
}
AVL<Palabra> VerbosConjugados::getVConjugados(){
    return _vconjugados;
}
void VerbosConjugados::setNombreFich(std::string unNombreFich){
    this->_nombreFich=unNombreFich;
}
void VerbosConjugados::setVConjugados(AVL<Palabra> unVConjugados){
    this->_vconjugados=unVConjugados;
}
//////////////////////////FUNCIONES//////////////////////////
void VerbosConjugados::leerVerbos(){
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
            _vconjugados.insertar(pal);
        }
        
        fe.close();
    }
}
bool VerbosConjugados::buscar(Palabra pal){
    Palabra result;//palabra con el resultado encontrado
    bool encontrado=false;
    if(_vconjugados.buscaIt(pal,result)){
        encontrado=true;
    }
    return encontrado;
}
void VerbosConjugados::mostrarAltura(){
    std::cout<<"Altura AVL: "<<_vconjugados.altura()<<" Numero elementos: "<<_vconjugados.numElementos()<<std::endl;
}