/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Juan Bautista
 *
 * Created on 13 de octubre de 2020, 16:38
 */

#include <cstdlib>
#include "ListaEnlazada.h"
#include "Diccionario.h"
#include "Palabra.h"
#include "GestorTextos.h"
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    GestorTextos gt;
    gt.chequearTexto();
    gt.borrarNombresPropios();
    return 0;
}

