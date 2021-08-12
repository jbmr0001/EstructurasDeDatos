/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ParPalabras.h
 * Author: Juan Bautista
 *
 * Created on 11 de octubre de 2020, 19:43
 */

#ifndef PARPALABRAS_H
#define PARPALABRAS_H
#include <string>

class ParPalabras {
public:
    //////////////////CONSTRUCTORES//////////////////////////
    ParPalabras();
    ParPalabras(std::string unaPalabra1, std::string unaPalabra2);
    ParPalabras(const ParPalabras& orig);
    virtual ~ParPalabras();
    ////////////////GETTERS Y SETTERS////////////////////////////
    std::string getPal1();
    std::string getPal2();
private:
    std::string _pal1;
    std::string _pal2;
    
};

#endif /* PARPALABRAS_H */

