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
#include "Usuario.h"

/////////////////////CONSTRUCTORES/////////////////
GestorTextos::GestorTextos()
{
}

GestorTextos::GestorTextos(const GestorTextos& orig)
{
}

GestorTextos::~GestorTextos() {
}
////////////////////////////FUNCIONES////////////////////////////
//Función que llama a buscarTermino en el diccionario
Palabra* GestorTextos::buscarTermino(std::string termino, Usuario* usuario){  
    return _diccionario.buscarTermino(termino,usuario);

}
//Funcion que llama a insertarInexistente en el diccionario
void GestorTextos::insertarInexistente(std::string termino, Usuario* usuario){
    _diccionario.insertarInexistente(termino,usuario);
}
//Función que llama a getOcurrencias en el diccionario
int GestorTextos::getOcurrencias(std::string palabra){
    return _diccionario.getNumOcurrencias(palabra);
}
