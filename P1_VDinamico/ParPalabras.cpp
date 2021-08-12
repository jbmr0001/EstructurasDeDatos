/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ParPalabras.cpp
 * Author: Juan Bautista
 * 
 * Created on 11 de octubre de 2020, 19:43
 */

#include "ParPalabras.h"
////////////////////////////CONSTRUCTORES//////////////////////////////
ParPalabras::ParPalabras():
    _pal1(""),
    _pal2("")
{
}
ParPalabras::ParPalabras(std::string unaPalabra1, std::string unaPalabra2):
    _pal1(unaPalabra1),
    _pal2(unaPalabra2)
{
}

ParPalabras::ParPalabras(const ParPalabras& orig):
    _pal1(orig._pal1),
    _pal2(orig._pal2)
{
}

ParPalabras::~ParPalabras() {
}
//////////////////////////GETTERS Y SETTERS/////////////////////////////
std::string ParPalabras::getPal1(){
    return this->_pal1;
}
std::string ParPalabras::getPal2(){
    return this->_pal2;
}
