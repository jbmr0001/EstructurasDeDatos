/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ziri.cpp
 * Author: Juan Bautista
 * 
 * Created on 6 de enero de 2021, 21:28
 */

#include "Ziri.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <bits/stdc++.h>
#include "Usuario.h"
////////////////////CONSTRUCTORES//////////////////
Ziri::Ziri() {
}

Ziri::Ziri(const Ziri& orig) {
}

Ziri::~Ziri() {
}
//////////////////////FUNCIONES/////////////////
//función para cargar usuarios en el map y malla regular
void Ziri::leerUsuarios(){
   std::ifstream fe;
    std::string linea;
    int total=0;
    std::string nif;
    std::string clave;
    std::string nombre;
    std::string direccion;
    std::string latitud;
    std::string longitud;
    std::string frase;
    float aXMin=200;
    float aYMin=200;
    float aXMax=-2000;
    float aYMax=-200;
    float latitudF=0;
    float longitudF=0;
    
     fe.open("usuarios_frases_win.csv");//abrimos fichero
    if(fe.good()){
        while(!fe.eof()){//bucle hasta llegue a la ultima linea
            getline(fe,linea);//leemos la línea
            std::stringstream ss;
            
            ++total;
            ss<<linea;
            
            if(total>1){
            getline(ss,nif,';');            //El carácter ; se lee y se elimina de ss
            getline(ss,clave,';'); 
            getline(ss,nombre,';');
            getline(ss,direccion,';');
            getline(ss,latitud,';');
            latitudF=std::stof(latitud);
            getline(ss,longitud,';');
            longitudF=std::stof(longitud);
            getline(ss,frase,';');
            
            
            //std::cout<<nif+" "+clave+" "+nombre+" "+direccion+" "+latitud+" "+longitud+" "+frase<<std::endl;
            
            if(latitudF<aXMin){
                aXMin=latitudF;
            }
             if(longitudF<aYMin){
                aYMin=longitudF;
            }
            if(latitudF>aXMax){
                aXMax=latitudF;
            }
           
            if(longitudF>aYMax){
                aYMax=longitudF;
            }

            
            
            Usuario u(nif,clave,nombre,direccion,latitudF,longitudF,frase);
            u.setEnlaceZiri(this);
            _usuariosNIF[nif]=u;
           
            _usuarioUTM.insertar(u.getLatitud(),u.getLongitud(),u);
            
            }
        }
        std::cout<<"aXMin: "<<aXMin<<std::endl;
        std::cout<<"aYMin: "<<aYMin<<std::endl;
        std::cout<<"aXMax: "<<aXMax<<std::endl;
        std::cout<<"aYMax: "<<aYMax<<std::endl;
        fe.close();
        
        
        
         
    }else{
        std::string("Error al abrir el fichero");
    }
     
    std::cout<<"MaxElementoPorCelda: "<<_usuarioUTM.maxElementosPorCelda()<<std::endl;
    std::cout<<"MediaElementosPorCelda: "<<_usuarioUTM.mediaElementosPorCelda()<<std::endl;
}

//Función qie devuelve el número de usuarios del mapa
void Ziri::numeroUsuarios(){
    std::cout<<"Numero usuarios: ";
    std::cout<<_usuariosNIF.size()<<std::endl;
}
//Función que conecta todos los usuarios menos los numUsuariosNoConectar ultimos
void Ziri::conectarUsuarios(int numUsuariosNoConectar){
        std::map<std::string, Usuario>::iterator it;
        int pos=_usuariosNIF.size()-numUsuariosNoConectar;
        int cont=0;
        it=_usuariosNIF.begin();
        while(it!=_usuariosNIF.end()){
            if(cont<pos){
                _conectados.push_back(it->second);
            }
            it++;
            cont++;
        }
        std::cout<<_conectados.size()<<" Usuarios conectados"<<std::endl;
}
//Función que devuelve si existe un usuario
bool Ziri::buscarUsuarioMap(std::string nif){
    if ( _usuariosNIF.find(nif) == _usuariosNIF.end() ) {
        std::cout<<"  -Usuario no existente."<<std::endl;
        return false;
    }else{
        std::cout<<"  -Usuario existente."<<std::endl;
        return true;
    }
}
//Función que añade un usuario a la lsita de conectados si el login es true
Usuario Ziri::nuevoUsuarioConectado(std::string nif, std::string pass){
    std::cout<<"Conectando usuario "<<nif<<":"<<std::endl;
    if(buscarUsuarioMap(nif)){
        if(_usuariosNIF[nif].login(nif,pass)){
            _conectados.push_back(_usuariosNIF[nif]);
        }
    }
    return _usuariosNIF[nif];
}
//Funcíon para checkear el login cuado la llamemos desde usuario
bool Ziri::checkLogin(std::string nif, std::string pass){
    bool login=false;
        if(_usuariosNIF[nif].getClave()==pass){
            std::cout<<"  -Contraseña correcta, conectado."<<std::endl;
            login=true;
        }else{
            std::cout<<"  -Contraseña incorrecta, no conectado."<<std::endl;
        }
    return login;
}
//Función para borrar un usuario de la lista de conectados
void Ziri::desconectarUsuario(std::string nif){
   std::list<Usuario>::iterator it;
   for(it=_conectados.begin();it!=_conectados.end();it++){
       if(it->getNif()==nif){
           std::cout<<"Usuario existente"<<std::endl;
           std::cout<<"Borrando...."<<std::endl;
           _conectados.erase(it);
       }else{
           std::cout<<"Usuario inexistente"<<std::endl;
       }
   }
}
//Función con la que ziri recibe una frase y llama a chequearTexto
void Ziri::recibeMensajeUsuario(std::string frase, Usuario* u){
    chequearTexto(frase,u);
}
//Función para escribir las frases de todos los usuarios conectados
void Ziri::escribirMensajes(){
   std::list<Usuario>::iterator it;
   for(it=_conectados.begin();it!=_conectados.end();it++){//escribimos mensajes de todos los conectados
       it->escribeMensaje();
   }
}
//Función que separa cada palabra de la frase
void Ziri::chequearTexto(std::string frase, Usuario* usuario){
    std::istringstream isstream(frase);
    while(!isstream.eof()){//se saca cada palabra de la frase
        std::string palabra;
        isstream>>palabra;
        Palabra pal(palabra);
        pal.convertirMinuscula();
        if(_gestor.buscarTermino(pal.getPalabra(),usuario)->getPalabra()==""){//si no existe llamamos insertar inexistente
            _gestor.insertarInexistente(palabra,usuario);
        }
       
    } 
}
//Función que guarda en un vector los usuarios que están tanto en el vector de usuarrios en un rango y vector de usuarios que han escrito una palabra
std::vector<Usuario> Ziri::buscarTerminoRango(std::string palabra, float rxmin, float rymin, float rxmax, float rymax){
  
    std::vector<Usuario> vRango=_usuarioUTM.buscarRango(rxmin,rymin,rxmax,rymax);
    std::vector<Usuario> vPal=analizarTermino(palabra);
    std::vector<Usuario> vResult;
    std::vector<Usuario>::iterator it1;
    std::vector<Usuario>::iterator it2;
    
    for (it1=vPal.begin();it1!=vPal.end();it1++){//recorremos el vector de usuarios en rango
        for(it2=vRango.begin();it2!=vRango.end();it2++){//recorremos el vector de usuarios con palabra
            if((*it1).getNif()==(*it2).getNif()){//los que se se encuentren en ambos se añaden el vector resultante
                vResult.push_back(*it1);
            }
        }
    }
    
    return vResult;
}
//Funcion que devuelve los usuarios conectados que han dicho una palabra
std::vector<Usuario> Ziri::analizarTermino(std::string _palabra){
    std::list<Usuario>::iterator it;
    std::vector<Usuario> v;
   for(it=_conectados.begin();it!=_conectados.end();it++){//recorremos la lista de conectados
        std::istringstream isstream(it->getFrase());
        while(!isstream.eof()){//se separa cada palabra de la frase y se pasa a minuscula
        std::string palabra;
        isstream>>palabra;
        Palabra pal(palabra);
        pal.convertirMinuscula();
            if(pal.getPalabra()==_palabra){//en caso de coincidir con la palabra buscada añadimos el usuario al vector
                v.push_back(*it);
            }
        } 
   }
    return v;
}
//Función que muestra el número de ocurrecias de una palabra
void Ziri::mostrarOcurrencias(std::string palabra){
    std::cout<<"Ocurrecias de "<<palabra<<": "<<_gestor.getOcurrencias(palabra)<<std::endl;
}
