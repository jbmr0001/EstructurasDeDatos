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
#include "Documento.h"
#include "VDinamico.h"

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
////////////////////////////GETTERS Y SETTERS/////////////////////
Diccionario GestorTextos::getDiccionario() const{
    return _diccionario;
}
VDinamico<Documento> GestorTextos::getDocumentos(){
    return _documentos;
}
////////////////////////////FUNCIONES////////////////////////////
void GestorTextos::addDocumento(std::string nombreFich){
    Documento doc(nombreFich);
    _documentos.insertar(doc);
    
}
