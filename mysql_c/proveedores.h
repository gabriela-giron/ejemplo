#pragma once
#include "personapro.h"
#include<mysql.h>
#include <iostream>
#include"conexiondb.h"
#include<string>
class proveedores : personapro {
	// atributos

	   // metodo constructor
public:
	proveedores() {
	}

	proveedores(string pee, string N, string dire, string tel) : personapro(pee, N, dire, tel) {

	}
	// metodos de modificar datos
	// set ( modificar)

	void setproveedor(string pee) { proveedor = pee; }
	void setnit(string N) { nit = N; }
	void setdireccion(string dire) { direccion = dire; }
	void settelefono(string tel) { telefono = tel; }
	// get(mostrar)
	string getproveedor() { return proveedor; }
	string setnit() { return nit; }
	string setdireccion() { return direccion; }
	string settelefono() { return telefono; }


	void crear() {
		int q_estado;
		conexiondb cn = conexiondb();
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string insert = "insert into proveedores(proveedor, nit, direccion,telefono) VALUES ('" + proveedor + "',  '" + nit + "','" + direccion + "', '" + telefono + "')";
			// executar el query
			const char* h = insert.c_str();
			q_estado = mysql_query(cn.getconectar(), h);
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
		conexiondb cn = conexiondb();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getconectar()) {


			string consulta = "select * from  proveedores ";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getconectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());
				cout << "----------------------------Proveedores------------------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "  |  " << fila[1] << "  |  " << fila[2] << "  |  " << fila[3] << "  |  " << fila[4] << endl;
				}

			}
			else {

				cout << "xxxxx error de  consulta xxxx" << endl;
			}



		}
		else {

			cout << " xxxxx error en la concexion xxxxx";
		}

		cn.cerrar_conexion();


	}
	void modificar() {

		int q_estado;
		conexiondb cn = conexiondb();
		cn.abrir_conexion();

		if (cn.getconectar()) {
			string id_Proveedores;
			cout << " ingrese id a modificar :";
			cin >> id_Proveedores;
			string update = " update proveedores   set proveedor='" + proveedor + "', nit='" + nit + "', direccion='" + direccion + "', telefono='" + telefono + "'WHERE id_Proveedores= '" + id_Proveedores + "'";
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

			cout << " xxxxx error en la concexion xxxxx";
		}

		cn.cerrar_conexion();
	}
	void eliminar() {

		int q_estado;
		conexiondb cn = conexiondb();
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string id_Proveedores;
			cout << " ingrese id a eliminar :";
			cin >> id_Proveedores;
			string sel = " DELETE FROM proveedores   WHERE id_Proveedore= '" + id_Proveedores + "'";
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

			cout << " xxxxx error en la concexion xxxxx";
		}

		cn.cerrar_conexion();



	}


};
