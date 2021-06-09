#pragma once
#include<iostream>
using namespace std;
class personapro {
protected: string proveedor, nit, direccion, telefono;


		 // constructor
protected:
	personapro() {
	}
	personapro(string pee, string N, string dire, string tel) {
		proveedor = pee;
		nit = N;
		direccion = dire;
		telefono = tel;


	}


};
