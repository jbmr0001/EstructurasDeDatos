/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Usuario.h
 * Author: Juan Bautista
 *
 * Created on 7 de enero de 2021, 21:10
 */

#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>

class Ziri;

class Usuario {
public:
    /////////////////CONSTRUCTORES/////////////
    Usuario();
    Usuario(std::string unNif,std::string unaClave,std::string unNombre,std::string unaDireccion,float unaLatitud,float unaLongitud,std::string unaFrase);
    Usuario(const Usuario& orig);
    virtual ~Usuario();
    /////////////////FUNCIONES///////////////
    bool login(std::string nif,std::string pass);
    void logOff();
    void escribeMensaje();
    /////////////////GETTERS Y SETTERS/////////////////
    void setNif(std::string unNif);
    std::string getNif();
    void setClave(std::string unaClave);
    std::string getClave();
    void setNombre(std::string unNombre);
    std::string getNombre();
    void setDireccion(std::string unaDireccion);
    std::string getDireccion();
    void setLatitud(float unaLatitud);
    float getLatitud();
    void setLongitud(float unaLongitud);
    float getLongitud();
    void setFrase(std::string unaFrase);
    std::string getFrase();
    void setEnlaceZiri(Ziri* unEnlace);
    Ziri* getEnlaceZiri();
   
private:
    std::string _nif;
    std::string _clave;
    std::string _nombre;
    std::string _direccion;
    float _latitud;
    float _longitud;
    std::string _frase;
    Ziri *_enlaceZiri;
    

};

#endif /* USUARIO_H */

