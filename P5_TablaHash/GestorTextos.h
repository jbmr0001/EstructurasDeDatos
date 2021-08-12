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
#include "Documento.h"
#include <vector>

class GestorTextos {
public:
    //////////////////CONSTRUCTORES/////////////////
    GestorTextos();
    GestorTextos(const GestorTextos& orig);
    virtual ~GestorTextos();
    /////////////////FUNCIONES////////////////
    void addDocumento(std::string nombreFich);
    Documento buscarDocumento(std::string nombreFich);
    bool buscarTermino(std::string termino,Palabra* result);
    std::list<Palabra> buscarFamilias(std::string raiz);
  
private:
    DiccionarioConVerbos _diccionario;
    std::vector<Documento> _documentos;
};

#endif /* GESTORTEXTOS_H */

