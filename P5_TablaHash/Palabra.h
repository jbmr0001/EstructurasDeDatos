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

class DiccionarioConVerbos;
class Documento;


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
    void setDoc(Documento* unDoc);
    Documento* getDoc();
    void setDic(DiccionarioConVerbos* unDic);
    DiccionarioConVerbos* getDic();
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
    Documento *_doc;

};

#endif /* PALABRA_H */

