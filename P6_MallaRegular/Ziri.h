/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ziri.h
 * Author: Juan Bautista
 *
 * Created on 6 de enero de 2021, 21:28
 */

#ifndef ZIRI_H
#define ZIRI_H
#include "Usuario.h"
#include <list>
#include <map>
#include "MallaRegular.h"
#include "GestorTextos.h"
class Ziri {
public:
    //////////////////////CONSTRUCTORES////////////////////
    Ziri();
    Ziri(const Ziri& orig);
    virtual ~Ziri();
    /////////////////////FUNCIONES/////////////////////
    Usuario nuevoUsuarioConectado(std::string nif,std::string pass);
    void desconectarUsuario(std::string nif);
    void recibeMensajeUsuario(std::string frase,Usuario* u);
    std::vector<Usuario> analizarTermino(std::string palabra);
    std::vector<Usuario> buscarTerminoRango(std::string palabra,float rxmin,float rymin,float rxmax,float rymax);
    void leerUsuarios();
    void numeroUsuarios();
    void conectarUsuarios(int numUsuariosNoCargados);
    void escribirMensajes();
    bool buscarUsuarioMap(std::string nif);
    bool checkLogin(std::string nif,std::string pass);
    void mostrarOcurrencias(std::string palabra);
    
private:
    void chequearTexto(std::string frase,Usuario* u);
    
    std::list<Usuario> _conectados;
    std::map<std::string,Usuario> _usuariosNIF;
    GestorTextos _gestor;
    MallaRegular<Usuario> _usuarioUTM=MallaRegular<Usuario>(34.0,-10.0,45.0,4.0,60,60);
    
};

#endif /* ZIRI_H */

