#pragma once
#include<iostream>
using namespace std;
class persona {
protected: string nombres, apellidos, direccion, DPI, genero, fecha_nacimiento, id_Puestos, fecha_inicio_labores, fecha_ingreso;
		 int telefono = 0;
		 // constructor
protected:
	persona() {
	}
	persona(string nom, string ape, string dire, int tel, string D, string gn, string fn, string idp, string fnc, string ing) {
		nombres = nom;
		apellidos = ape;
		direccion = dire;
		telefono = tel;
		DPI = D;
		genero = gn;
		fecha_nacimiento = fn;
		id_Puestos = idp;
		fecha_inicio_labores = fnc;
		fecha_ingreso = ing;


	}
};

