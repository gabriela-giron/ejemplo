#pragma once
#include "Ventas.h"
#include <iostream>
#include <mysql.h>
using namespace std;

class Ventas {
protected: string fecha_factura, fecha_ingreso;
		 int  id_cliente = 0, id_empleado = 0;


		 // constructor
protected:
	Ventas() {
	}
	Ventas(string fechafact, int idcliente, int idempleado, string fechaingreso) {
		fecha_factura = fechafact;
		id_cliente = idcliente;
		id_empleado = idempleado;
		fecha_ingreso = fechaingreso;
	}
};


