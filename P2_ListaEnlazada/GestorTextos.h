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
#include "Diccionario.h"
#include "Documento.h"

class GestorTextos {
public:
    //////////////////CONSTRUCTORES/////////////////
    GestorTextos();
    GestorTextos(const GestorTextos& orig);
    virtual ~GestorTextos();
    //////////////////GETTERS Y SETTERS/////////////
    Diccionario getDiccionario()const;
    Documento getDocumento()const;
    /////////////////FUNCIONES////////////////
    void chequearTexto();
    void leerDiccionario();
    void borrarNombresPropios();
private:
    Diccionario _diccionario;
    Documento _texto;
      

};

#endif /* GESTORTEXTOS_H */

