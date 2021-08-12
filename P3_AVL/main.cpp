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
#include "AVL.h"
#include "GestorTextos.h"
#include "Documento.h"
#include "VDinamico.h"
#include "VerbosConjugados.h"
#include <sstream>
#include <fstream>
#include "VDinamico.h"
#include "ListaEnlazada.h"
#include <chrono>

using namespace std;

/*
 * 
 */
VDinamico<Palabra> vd;
ListaEnlazada<Palabra> le;
AVL<Palabra> avl;
    
void pruebaTiempos(){//funcion para llenar las estructuras de datos de verbos y usarlas en la prueba de tiempos
     std::ifstream fe;
    string linea;
    int total=0;
    std::string palabra;
    
    fe.open("verbos_conjugados_sin_tildes_desordenados.txt");//abrimos fichero
    if(fe.good()){
        while(!fe.eof()){//bucle hasta llegue a la ultima linea
            getline(fe,linea);//leemos la línea
            std::stringstream ss;
            
            ++total;
            ss<<linea;
            getline(ss,palabra);//extraemos la palabra en forma de string de la línea leida
            Palabra pal(palabra);//creamos una Palabra con el string leido 
            vd.insertar(pal);
            le.insertaFinal(pal);
            avl.insertar(pal);
        }
        
        fe.close();
    }
}
int main(int argc, char** argv) {
    GestorTextos gt;
    gt.addDocumento("quijote2.txt");
    gt.getDocumentos()[0].chequearTexto();
    cout<<"Inexistentes Práctica 2=10387 y tras borrado 9205"<<endl;
    
    //////////PRUEBA TIEMPOS///////////
    /**
    //Datos tomados en Informe Tiempos.png
    pruebaTiempos();
    Palabra buscar1("desfecho");//palabra al pricipio
    Palabra buscar2("acarrazas");//palabra entre medias
    Palabra buscar3("guarreamos");//palabra al final 
   
    auto start=std::chrono::system_clock::now();
   
    //avl.buscaIt(buscar3,buscar1);
    //vd.busquedaBin(buscar3);
    avl.buscaR(buscar3,buscar1);
  
    auto end=std::chrono::system_clock::now();
    std::chrono::duration<float,std::milli> duration=end-start;

    std::cout<<duration.count()<<""<<std::endl;
     * */
    return 0;
}

