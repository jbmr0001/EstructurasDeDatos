/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GestorTextos.h
 * Author: Juan Bautista
 *
 * Created on 20 de octubre de 2020, 17:57
 */

#ifndef GESTORTEXTOS_H
#define GESTORTEXTOS_H
#include <vector>
#include "Palabra.h"
#include "DiccionarioConVerbos.h"
#include <iostream>
#include "Usuario.h"

class GestorTextos {
public:
    //////////////////CONSTRUCTORES/////////////////
    GestorTextos();
    GestorTextos(const GestorTextos& orig);
    virtual ~GestorTextos();
    /////////////////FUNCIONES////////////////
    Palabra* buscarTermino(std::string termino,Usuario* usuario);
    std::list<Palabra> buscarFamilias(std::string raiz);
    void insertarInexistente(std::string termino,Usuario* usuario);
    int getOcurrencias(std::string palabra);
  
private:
    DiccionarioConVerbos _diccionario;
};

#endif /* GESTORTEXTOS_H */

