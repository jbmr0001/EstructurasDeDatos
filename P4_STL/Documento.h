/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Documento.h
 * Author: Juan Bautista
 *
 * Created on 20 de octubre de 2020, 17:57
 */

#ifndef DOCUMENTO_H
#define DOCUMENTO_H
#include <string>
#include "Palabra.h"
#include <string>
#include <list>
#include "DiccionarioConVerbos.h"

class Documento {
public:
    //////////////////CONSTRUCTORES//////////////
    Documento();
    Documento(std::string unNombreFich);
    Documento(const Documento& orig);
    virtual ~Documento();
    /////////////////GETTERS Y SETTERS///////////
    std::string getNombreFich();
    DiccionarioConVerbos* getDiccionario();
    void setNombreFich(std::string unNombreFich);
    void setDiccionario(DiccionarioConVerbos* unDiccionario);
    ////////////////FUNCIONES////////////////
    void chequearTexto();
    //////////////OPERADORES///////////////////
    Documento& operator=(const Documento& doc);
    
private:
    std::string _nombreFich;
    DiccionarioConVerbos *_dicc;
};

#endif /* DOCUMENTO_H */

