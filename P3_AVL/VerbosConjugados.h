/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VerbosConjugados.h
 * Author: Juan Bautista
 *
 * Created on 6 de noviembre de 2020, 16:38
 */

#ifndef VERBOSCONJUGADOS_H
#define VERBOSCONJUGADOS_H
#include <string>
#include "AVL.h"
#include "Palabra.h"

class VerbosConjugados {
public:
    ///////////////////CONSTRUCTORES/////////////////
    VerbosConjugados();
    VerbosConjugados(const VerbosConjugados& orig);
    virtual ~VerbosConjugados();
    /////////////////GETTERSY SETTERS////////////////////
    void setNombreFich(std::string unNombreFich);
    void setVConjugados(AVL<Palabra> unVConjugados);
    std::string getNombreFich();
    AVL<Palabra> getVConjugados();
    ///////////////////////FUNCIONES////////////////////////
    void leerVerbos();
    bool buscar(Palabra pal);
    void mostrarAltura();
    ////////////////////OPERADORES////////////////////////
    VerbosConjugados& operator =(const VerbosConjugados& ver);

    
  
private:
    std::string _nombreFich;
    AVL<Palabra> _vconjugados;
};

#endif /* VERBOSCONJUGADOS_H */

