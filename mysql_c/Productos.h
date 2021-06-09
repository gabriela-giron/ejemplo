#pragma once
#include "producto.h"
#include<mysql.h>
#include <iostream>
#include"conexiondb.h"
#include<string>

class Productos : producto
{
public:
	Productos() {
	}

	Productos(string produ, string id_marc, string desc, string img, string precio_cost, string precio_vent, string exist, string fecha_ingre) : producto(produ, id_marc, desc, img, precio_cost, precio_vent, exist, fecha_ingre) {

	}
	void setproduct(string produ) { product = produ; }
	void setid_Marca(string id_marc) { id_Marca = id_marc; }
	void setdescripcion(string desc) { descripcion = desc; }
	void setimagen(string img) { imagen = img; }
	void setprecio_costo(string precio_cost) { precio_costo = precio_cost; }
	void setprecio_venta(string precio_vent) { precio_venta = precio_vent; }
	void setfecha_factura(string exist) { existencia = exist; }
	void setfecha_ingreso(string fecha_ingre) { fecha_ingreso = fecha_ingre; }
	// get(mostrar)
	string getproduct() { return product; }
	string getid_Marca() { return id_Marca; }
	string getdescripcion() { return descripcion; }
	string getimagen() { return imagen; }
	string getprecio_costo() { return precio_costo; }
	string getprecio_venta() { return precio_venta; }
	string getexistencia() { return existencia; }
	string getfecha_ingreso() { return fecha_ingreso; }

	void crear() {
		int q_estado;
		conexiondb cn = conexiondb();

		cn.abrir_conexion();
		if (cn.getconectar()) {
			string insert = "insert into productos(producto, id_Marca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso) VALUES ('" + product + "',  '" + id_Marca + "','" + descripcion + "','" + imagen + "', '" + precio_costo + "' , '" + precio_venta + "', '" + existencia + "', now() )";
			// executar el query
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getconectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}


		cn.cerrar_conexion();
	}

	void leer() {

		int q_estado;
		conexiondb  cn = conexiondb();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getconectar()) {

			string consulta = "SELECT p.id_Productos, p.producto, m.id_Marcass, p.descripcion, p.imagen, p.precio_costo, p.precio_venta, p.existencia, p.fecha_ingreso from productos as p inner join marcass as m on p.id_Marca = m.id_Marcass;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getconectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());
				cout << "----------------------------PRODUCTOS------------------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "  ,  " << fila[1] << "  ,  " << fila[2] << "  ,  " << fila[3] << "  ,  " << fila[4] << "  ,  " << fila[5] << "  ,  " << fila[6] << "  ,  " << fila[7] << "  ,  " << fila[8] << endl;
				}

			}
			else {

				cout << "xxxxx error de  consulta xxxx" << endl;
			}



		}
		else {

			cout << " xxxxx error en la conexion xxxxx";
		}

		cn.cerrar_conexion();


	}

	void modificar() {

		int q_estado;
		conexiondb  cn = conexiondb();
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string id_Productos;
			cout << " ingrese id del producto a modificar :";
			cin >> id_Productos;

			string update = " update productos set producto='" + product + "', id_Marca='" + id_Marca + "', descripcion='" + descripcion + "', imagen='" + imagen + "', precio_costo='" + precio_costo + "', precio_venta='" + precio_venta + "',  existencia= '" + existencia + "', fecha_ingreso= '" + fecha_ingreso + "'";
			const char* o = update.c_str();
			q_estado = mysql_query(cn.getconectar(), o);
			if (!q_estado) {
				cout << " modificacion Exitosa..." << endl;

			}
			else {

				cout << "xxxxx error de  modificacion xxxx" << endl;
			}

		}
		else {

			cout << " xxxxx error en la conexion xxxxx";
		}

		cn.cerrar_conexion();
	}


	void eliminar() {

		int q_estado;
		conexiondb  cn = conexiondb();
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string id_Productos;
			cout << " ingrese id a eliminar :";
			cin >> id_Productos;
			string sel = " DELETE FROM productos WHERE id_Productos= '" + id_Productos + "'";
			const char* u = sel.c_str();
			q_estado = mysql_query(cn.getconectar(), u);
			if (!q_estado) {
				cout << " eliminacion exitosa ..." << endl;

			}
			else {

				cout << "xxxxx error al eliminar xxxx" << endl;
			}





		}
		else {

			cout << " xxxxx error en la conexion xxxxx";
		}

		cn.cerrar_conexion();



	}
};



