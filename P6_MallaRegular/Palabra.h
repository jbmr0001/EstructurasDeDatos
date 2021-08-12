/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Palabra.h
 * Author: Juan Bautista
 *
 * Created on 11 de octubre de 2020, 19:00
 */

#ifndef PALABRA_H
#define PALABRA_H

#include <string>
#include <vector>
#include "Usuario.h"

class DiccionarioConVerbos;

class Palabra {
public:
    //////////////////////CONSTRUCTORES////////////////////////////
    Palabra();
    Palabra(std::string unaPalabra);
    Palabra(const Palabra& orig);
    ~Palabra();
    /////////////////////FUNCIONES///////////////////////////
    Palabra reves();
    bool anagrama(Palabra pal);
    bool palindromo(Palabra pal);
    std::vector<Palabra> getCombinaciones();
    void limpiar();
    void convertirMinuscula();
    bool primeraLetraEsMayus();
    void incrementarOcurrencia();
    bool contieneRaiz(std::string raiz);
    ////////////////////////GETTERS Y SETTERS//////////////////
    void setPalabra(std::string unaPalabra);
    std::string getPalabra();
    int getNumOcurrencias();
    void setDic(DiccionarioConVerbos* unDic);
    DiccionarioConVerbos* getDic();
    void setDichaPor(Usuario* unDichaPor);
    Usuario* getDichaPor();
    ////////////////////////OPERADORES/////////////////////
    bool operator<(const Palabra& pal)const;
    bool operator>(const Palabra& pal)const;
    bool operator==(const Palabra& pal)const;
    bool operator!=(const Palabra& pal)const;
    bool operator<=(const Palabra& pal)const;
    bool operator>=(const Palabra& pal)const;
     
private:
    std::string _palabra;
    int _ocurrencias;
    DiccionarioConVerbos *_dic;
    
    Usuario *_dichaPor;
};

#endif /* PALABRA_H */

