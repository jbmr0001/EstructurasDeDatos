/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Juan Bautista
 *
 * Created on 4 de noviembre de 2020, 17:36
 */

#include <cstdlib>
#include <sstream>
#include <fstream>
#include <iostream>
#include <chrono>
#include "Documento.h"
#include "DiccionarioConVerbos.h"
#include "GestorTextos.h"
#include "Documento.h"
#include <map>

using namespace std;

int main(int argc, char** argv) {
 
    GestorTextos gt;
    gt.addDocumento("quijote-sin-simbolos.txt");
    gt.addDocumento("divinaComedia.txt");
    gt.buscarDocumento("quijote-sin-simbolos.txt").chequearTexto();
    return 0;
}

