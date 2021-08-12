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
#include "THashPalabra.h"

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
    bool buscarTermino(std::string termino,Palabra* pal);
    void borrarPalabras();
    void insertar(Palabra pal);
    void leerDiccionario();
    void leerVerbos();
    void nElem();
    void tama();
    void maxColisiones();
    void factorCarga();
    void promedioColisiones();
    
    
    
private:
    std::string _nombreDicc;
    std::string _nombreDiccVerbos;
    THashPalabra _terminos;
    std::vector<Palabra> _borrar;
    
   
};

#endif /* DICCIONARIOCONVERBOS_H */

