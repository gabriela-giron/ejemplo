// Clase mama desde Ventas_estra
#pragma once
#include "Ventas_extra.h"
#include <iostream>
#include <mysql.h>


using namespace std;

class Ventas_extra {

protected:
	string  cantidad;
	int id_producto;
	// constructor
protected:
	Ventas_extra() {
	}
	Ventas_extra(int id_prod, string cant) {
		id_producto = id_prod;
		cantidad = cant;
	}
};