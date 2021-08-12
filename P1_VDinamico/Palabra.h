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
#include "VDinamico.h"


class Palabra {
public:
    //////////////////////CONSTRUCTORES////////////////////////////
    Palabra();
    Palabra(std::string unaPalabra);
    Palabra(const Palabra& orig);
    virtual ~Palabra();
    
    Palabra reves();
    bool anagrama(Palabra pal);
    bool palindromo(Palabra pal);
    VDinamico<Palabra> getCombinaciones();
    void setPalabra(std::string unaPalabra);
    std::string getPalabra();
    
    bool operator<(const Palabra& pal)const;
    bool operator>(const Palabra& pal)const;
    bool operator==(const Palabra& pal)const;
private:
    std::string _palabra;

};

#endif /* PALABRA_H */

