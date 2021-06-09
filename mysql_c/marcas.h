#pragma once
#include "marca.h"
#include<mysql.h>
#include <iostream>
#include"conexiondb.h"
#include<string>
using namespace std;
class marcas : marca {

	// atributos

	   // metodo constructor
public:
	marcas() {
	}

	marcas(string mar) : marca(mar) {

	}
	// metodos de modificar datos
	// set ( modificar)

	void setmarca(string mar) { Marca = mar; }

	// get(mostrar)
	string getmarca() { return Marca; }

	void crear() {
		int q_estado;
		conexiondb cn = conexiondb();

		cn.abrir_conexion();

		if (cn.getconectar()) {

			string  insert = "insert into marcass(Marca) VALUES ('" + Marca + "')";
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
		conexiondb cn = conexiondb();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getconectar()) {


			string consulta = "select * from  marcass ";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getconectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());
				cout << "----------------------------Marcas------------------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "  |  " << fila[1] << endl;
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
			string id_Marcass;
			cout << " ingrese id a modificar :";
			cin >> id_Marcass;
			string update = " update marcass   set Marca='" + Marca + "'WHERE id_Marcass= '" + id_Marcass + "'";
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
			string id_Marcass;
			cout << " ingrese id a eliminar :";
			cin >> id_Marcass;
			string sel = " DELETE FROM marcass   WHERE id_Marcass= '" + id_Marcass + "'";
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