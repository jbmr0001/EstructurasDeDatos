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

class Documento {
public:
    //////////////////CONSTRUCTORES//////////////
    Documento();
    Documento(const Documento& orig);
    virtual ~Documento();
    /////////////////GETTERS Y SETTERS///////////
    std::string getNombreFich();
    void setNombreFich(std::string unNombreFich);
    ////////////////FUNCIONES////////////////
    void MostrarInexistentes();
    void addInexistente(Palabra p);
    
    
    
    ListaEnlazada<Palabra> _inexistentes;
private:
    std::string _nombreFich;
    

};

#endif /* DOCUMENTO_H */

