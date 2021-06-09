#include <iostream>
//#include "compra.h"

using namespace std;

class compra1 {
protected: string fecha_orden, fecha_ingreso;
		 int id_proveedor = 0;


		 // constructor
protected:
	compra1() {
	}
	compra1(int idpr, string ford, string fin) {
		id_proveedor = idpr;
		fecha_orden = ford;
		fecha_ingreso = fin;

	}
};

class compra_detalle {
protected:
	int id_producto = 0;

	int cantidad = 0;

	// constructor
protected:
	compra_detalle() {
	}
	compra_detalle(int pro, int can) {
		id_producto = pro;
		cantidad = can;
	}
};