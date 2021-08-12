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
#include "ListaEnlazada.h"
#include <string>
#include "Diccionario.h"

class Documento {
public:
    //////////////////CONSTRUCTORES//////////////
    Documento();
    Documento(std::string unNombreFich);
    Documento(const Documento& orig);
    virtual ~Documento();
    /////////////////GETTERS Y SETTERS///////////
    std::string getNombreFich();
    Diccionario getDiccionario();
    ListaEnlazada<Palabra> getInexistentes();
    void setNombreFich(std::string unNombreFich);
    void setDiccionario(Diccionario unDiccionario);
    ////////////////FUNCIONES////////////////
    void MostrarInexistentes();
    void addInexistente(Palabra p);
    void chequearTexto();
    void borrarNombresPropios();
    //////////////OPERADORES///////////////////
    Documento& operator=(const Documento& doc);
    
private:
    std::string _nombreFich;
    Diccionario _dicc;
    ListaEnlazada<Palabra> _inexistentes;
    

};

#endif /* DOCUMENTO_H */

