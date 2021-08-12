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
#include <bits/stdc++.h>
#include <locale>
#include "Documento.h"

/////////////////////CONSTRUCTORES/////////////////
GestorTextos::GestorTextos():
    _documentos()
{
}

GestorTextos::GestorTextos(const GestorTextos& orig): 
    _documentos(orig._documentos)
{
}

GestorTextos::~GestorTextos() {
}
////////////////////////////FUNCIONES////////////////////////////
void GestorTextos::addDocumento(std::string nombreFich){
    Documento doc(nombreFich);
    _documentos.push_back(doc);   
}
Documento GestorTextos::buscarDocumento(std::string nombreFich){
    for(int i=0;i<_documentos.size();i++){
        if(_documentos[i].getNombreFich()==nombreFich){
            return _documentos[i];
        }        
    }   
}
bool GestorTextos::buscarTermino(std::string termino, Palabra* result){  
    return _diccionario.buscarTermino(termino,result);
}
