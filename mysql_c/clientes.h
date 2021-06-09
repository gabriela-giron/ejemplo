#pragma once
#include "personacli.h"
#include<mysql.h>
#include <iostream>
#include"conexiondb.h"
#include<string>
using namespace std;
class clientes : personacli {
	// atributos

	   // metodo constructor
public:
	clientes() {
	}

	clientes(string nom, string ape, string N, string gn, int tel, string ctc, string ing) : personacli(nom, ape, N, gn, tel, ctc, ing) {

	}
	// metodos de modificar datos
	// set ( modificar)

	void setnombre(string nom) { nombres = nom; }
	void setapellidos(string ape) { apellidos = ape; }
	void setNIT(string N) { NIT = N; }
	void setgenero(string gn) { genero = gn; }
	void settelefono(int tel) { telefono = tel; }
	void setcorreo_electronico(string ctc) { correo_electronico = ctc; }
	void setfecha_ingreso(string ing) { fecha_ingreso = ing; }
	// get(mostrar)
	string getnombres() { return nombres; }
	string getapellidos() { return apellidos; }
	string getNIT() { return NIT; }
	string getgenero() { return genero; }
	int gettelefono() { return telefono; }
	string getcorreo_electronico() { return correo_electronico; }
	string getfecha_ingreso() { return fecha_ingreso; }

	void crear() {
		int q_estado;
		conexiondb cn = conexiondb();
		cn.abrir_conexion();
		string T = to_string(telefono);
		if (cn.getconectar()) {
			string insert = "insert into clientes(nombres, apellidos, NIT,  genero, telefono, correo_electronico,fecha_ingreso) VALUES ('" + nombres + "',  '" + apellidos + "','" + NIT + "', '" + genero + "','" + T + "', '" + correo_electronico + "' , now() )";
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


			string consulta = "select * from  clientes ";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getconectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());
				cout << "----------------------------Clientes------------------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "  |  " << fila[1] << "  |  " << fila[2] << "  |  " << fila[3] << "  |  " << fila[4] << "  |  " << fila[5] << "  |  " << fila[6] << endl;
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
			string id_Clientes;
			cout << " ingrese id a modificar :";
			cin >> id_Clientes;
			string T = to_string(telefono);
			string update = " update clientes   set nombres='" + nombres + "', apellidos='" + apellidos + "', NIT='" + NIT + "', genero='" + genero + "', telefono='" + T + "', correo_electronico='" + correo_electronico + "', fecha_ingreso= '" + fecha_ingreso + "' WHERE id_Clientes= '" + id_Clientes + "'";
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
			string id_Clientes;
			cout << " ingrese id a eliminar :";
			cin >> id_Clientes;
			string sel = " DELETE FROM clientes   WHERE id_Clientes= '" + id_Clientes + "'";
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