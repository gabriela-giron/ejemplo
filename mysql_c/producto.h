#pragma once
#include<iostream>
using namespace std;
class producto
{
protected: string product, id_Marca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso;
		 // constructor
protected:
	producto() {
	}
	producto(string produ, string id_marc, string desc, string img, string precio_cost, string precio_vent, string exist, string fecha_ingre) {
		product = produ;
		id_Marca = id_marc;
		descripcion = desc;
		imagen = img;
		precio_costo = precio_cost;
		precio_venta = precio_vent;
		existencia = exist;
		fecha_ingreso = fecha_ingre;


	}
};