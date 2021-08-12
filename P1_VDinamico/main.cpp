/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: lidia
 *
 * Created on 23 de septiembre de 2019, 17:56
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <sstream>
#include "Palabra.h"
#include "VDinamico.h"
#include "ParPalabras.h"

using namespace std;

VDinamico<Palabra> vec;
VDinamico<ParPalabras> parVec;

 void comprobar() {//funcion de prueba
	vector<string> dicc;

	ifstream is("dicc-espanol.txt");
	string palabra;

	while (is) {
		is >> palabra;
		dicc.push_back(palabra);
	}
	cout << dicc.size() << " palabras cargadas" << endl;
	is.close();
	is.open("quijote.txt");

	clock_t t_ini = clock();

	int validadas = 0, total = 0, p;
	while (is) {
		is >> palabra;
		++total;

		if (binary_search(dicc.begin(), dicc.end(), palabra)) {
			++validadas;
		}
	}
	cout <<"Total palabras: " << total << " validadas: " << validadas << endl;
	cout << "Tiempo implementación 1: " << ((clock() - t_ini) / CLOCKS_PER_SEC) << " segs." << endl;
}

 void leeDiccionario(std::string archivo){
     setlocale(LC_ALL,"es_ES.UTF8");

     ifstream fe;
     string linea;
     int total=0;
     std::string palabra;
     
     fe.open(archivo);
     if(fe.good()){
         while(fe){//se va leyendo linea a linea 
             getline(fe,linea);
             stringstream ss;
             
             ++total;
             ss<<linea;
             getline(ss,palabra);
             Palabra pal(palabra);//creamos una palabra con el contenido de la string leida para insertarla en el vector
             vec.insertar(pal);
         }
             cout<<"Palabras leidas: "<<total<<endl;
             cout<<"Tamaño del vector: "<<vec.tam()<<endl;
             fe.close();//cerramosflujo
     
        

    }else{
         cerr<<"No se pueade abrir archivo"<<endl;
    }
 }
 

int main(int argc, char** argv) {
    //------------------------------------------------------------------------//
    cout<<"///////Programa de prueba///////"<<endl;
    clock_t inicio=clock();
    comprobar();
    cout<<"Tiempo: "<<((clock()-inicio)/CLOCKS_PER_SEC)<<" segs"<<endl<<endl;
    
    //------------------------------------------------------------------------//
    cout<<"//////Lectura e Inserción Diccionario///////"<<endl;
    inicio=clock();
    leeDiccionario("dicc-espanol.txt");//metodo con el que se lee y llena el vector
    cout<<"Tiempo: "<<((clock()-inicio)/CLOCKS_PER_SEC)<<" segs"<<endl<<endl;
    
    //------------------------------------------------------------------------//
    cout<<"//////Ordenando alfabéticamente//////"<<endl;
    inicio=clock();
    vec.ordenar();
    cout<<"Tiempo: "<<((clock()-inicio)/CLOCKS_PER_SEC)<<" segs"<<endl<<endl;
    
    //------------------------------------------------------------------------//
    cout<<"//////Ordenando al reves//////"<<endl;
    inicio=clock();
    vec.ordenarRev();
    cout<<"Tiempo: "<<((clock()-inicio)/CLOCKS_PER_SEC)<<" segs"<<endl<<endl;
    for(int i=0;i<vec.tam();i++){//mostramos el vector
        cout<<vec[i].getPalabra()<<endl;
    }
    
    //------------------------------------------------------------------------//
    cout<<"//////Buscando palíndromos///////"<<endl;
    inicio=clock();
    //Busqueda condicionada a 5000 10000 ya que tardama demasiado(10 palíndromos)
    //Doble bucle en caso de encontrar un palindromo se inserta en el vector
    for(int i=70000;i<75000;i++){
        for(int j=i+1;j<80000;j++){
            if(vec[i].palindromo(vec[j])){
                ParPalabras par(vec[i].getPalabra(),vec[j].getPalabra());
                parVec.insertar(par);
                cout<<vec[i].getPalabra()<<" -palíndromo con- "<<vec[j].getPalabra()<<endl;
            }
        }
    }
    cout<<"Hay "<<parVec.tam()<<" palíndromos"<<endl;
    for(int i=0;i<parVec.tam();i++){//mostramos el vector palíndromos
        cout<<"Contenido vector palíndromos:"<<endl;
        cout<<parVec[i].getPal1()<<" - "<<parVec[i].getPal2()<<endl;
    }
    cout<<"Tiempo: "<<((clock()-inicio)/CLOCKS_PER_SEC)<<" segs"<<endl<<endl;
    
    //------------------------------------------------------------------------//
    cout<<"///////////Buscando Anagramas/////////////////"<<endl;
    int contador=0;
    for(int i=0;i<vec.tam();i++){//doble bucle en que vamos comparando cada elemento mediante anagrama()
        for(int j=i+1;j<vec.tam();j++){
            if(contador==5){
                break;
            }
            if(vec[i].anagrama(vec[j])){
            cout<<vec[i].getPalabra()<<" -anagrama con- "<<vec[j].getPalabra()<<endl;
            contador++;
            }
        }
    }
    return 0;
    
}

