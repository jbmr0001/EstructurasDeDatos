/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Usuario.cpp
 * Author: Juan Bautista
 * 
 * Created on 7 de enero de 2021, 21:10
 */

#include "Usuario.h"
#include "Ziri.h"
//////////////////////////CONSTRUCTORES////////////
Usuario::Usuario():
    _nif(""),
    _clave(""),
    _nombre(""),
    _direccion(""),
    _latitud(0.0),
    _longitud(0.0),
    _frase(""),
    _enlaceZiri(NULL)
{
}

Usuario::Usuario(std::string unNif,std::string unaClave,std::string unNombre,std::string unaDireccion,float unaLatitud,float unaLongitud,std::string unaFrase):
    _nif(unNif),
    _clave(unaClave),
    _nombre(unNombre),
    _direccion(unaDireccion),
    _latitud(unaLatitud),
    _longitud(unaLongitud),
    _frase(unaFrase),
    _enlaceZiri(NULL)
{
    
}

Usuario::Usuario(const Usuario& orig) :
    _nif(orig._nif),
    _clave(orig._clave),
    _nombre(orig._nombre),
    _direccion(orig._direccion),
    _latitud(orig._latitud),
    _longitud(orig._longitud),
    _frase(orig._frase),
    _enlaceZiri(orig._enlaceZiri)
{
}

Usuario::~Usuario() {
}
///////////////////////FUNCIONES//////////////////
//Función  para confirmar un login, devuelve una llamada a la comprobación de identidad en Ziri
bool Usuario::login(std::string nif, std::string pass){
    return _enlaceZiri->checkLogin(nif,pass);
}
//Función que desconecta un usuario en Ziri
void Usuario::logOff(){
    _enlaceZiri->desconectarUsuario(this->_nif);
}
//Función que escribe en mensaje en Ziri
void Usuario::escribeMensaje(){
    _enlaceZiri->recibeMensajeUsuario(this->_frase,this);
}
/////////////////////GETTERS/////////////////////////
std::string Usuario::getNif(){
    return this->_nif;
}
std::string Usuario::getClave(){
    return this->_clave;
}
std::string Usuario::getNombre(){
    return this->_nombre;
}
std::string Usuario::getDireccion(){
    return this->_direccion;
}
std::string Usuario::getFrase(){
    return this->_frase;
}
float Usuario::getLatitud(){
    return this->_latitud;
}
float Usuario::getLongitud(){
    return this->_longitud;
}
////////////////////SETTERS/////////////////
void Usuario::setNif(std::string unNif){
    this->_nif=unNif;
}
void Usuario::setNombre(std::string unNombre){
    this->_nombre=unNombre;
}
void Usuario::setClave(std::string unaClave){
    this->_clave=unaClave;
}
void Usuario::setDireccion(std::string unaDireccion){
    this->_direccion=unaDireccion;
}
void Usuario::setLatitud(float unaLatitud){
    this->_latitud=unaLatitud;
}
void Usuario::setLongitud(float unaLongitud){
    this->_longitud=unaLongitud;
}
void Usuario::setFrase(std::string unaFrase){
    this->_frase=unaFrase;
}
void Usuario::setEnlaceZiri(Ziri* unEnlace){
    this->_enlaceZiri=unEnlace;
}
Ziri* Usuario::getEnlaceZiri(){
    return this->_enlaceZiri;
}