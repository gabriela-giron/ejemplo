#pragma once
#include<iostream>
using namespace std;
class personacli {
protected: string nombres, apellidos, NIT, genero, correo_electronico, fecha_ingreso;
		 int telefono;

		 // constructor
protected:
	personacli() {
	}
	personacli(string nom, string ape, string N, string gn, int tel, string ctc, string ing) {
		nombres = nom;
		apellidos = ape;
		NIT = N;
		genero = gn;
		telefono = tel;
		correo_electronico = ctc;
		fecha_ingreso = ing;


	}




};