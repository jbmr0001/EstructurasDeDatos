/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Diccionario.h
 * Author: Juan Bautista
 *
 * Created on 20 de octubre de 2020, 17:23
 */

#ifndef DICCIONARIO_H
#define DICCIONARIO_H
#include <string>
#include "VDinamico.h"
#include "Palabra.h"

class Diccionario {
public:
    Diccionario();
    Diccionario(const Diccionario& orig);
    virtual ~Diccionario();
    /////////////////////////FUNCIONES//////////////////////////
    bool buscarDicotomica(Palabra unaPalabra);
    void mostrarDiccionario();
    /////////////////////GETTERS Y SETTERS/////////////////////
    void setNombreFich(std::string unNombreFich);
    std::string getNombreFich();
    
    
    
    VDinamico<Palabra> _terminos;
private:
    std::string _nombreFich;

};

#endif /* DICCIONARIO_H */

