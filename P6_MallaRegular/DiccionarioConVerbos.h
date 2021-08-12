/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DiccionarioConVerbos.h
 * Author: Juan Bautista
 *
 * Created on 21 de noviembre de 2020, 19:14
 */

#ifndef DICCIONARIOCONVERBOS_H
#define DICCIONARIOCONVERBOS_H

#include <string>
#include <vector>
#include <map>
#include <list>
#include "Palabra.h"
#include "Usuario.h"

class DiccionarioConVerbos {
public:
    ////////////////CONSTRUCTORES/////////////////
    DiccionarioConVerbos();
    DiccionarioConVerbos(const DiccionarioConVerbos& orig);
    virtual ~DiccionarioConVerbos();
    ///////////////GETTERS Y SETTERS/////////////////
    void setNombreDicc(std::string unaNombreDicc);
    std::string getNombreDicc();
    void setNombreDiccVerbos(std::string unaNombreDiccVerbos);
    std::string getNombreDiccVerbos();
    ///////////////FUNCIONES/////////////////
    Palabra* buscarTermino(std::string termino,Usuario* usuario);
    void insertarInexistente(std::string termino,Usuario* usuario);
    void mostrarInexistentes();
    void leerDiccionario();
    void leerVerbos();
    int getNumOcurrencias(std::string palabra);
 
   
private:
    std::string _nombreDicc;
    std::string _nombreDiccVerbos;
    std::map<std::string,Palabra> _terminos;
    
};

#endif /* DICCIONARIOCONVERBOS_H */

