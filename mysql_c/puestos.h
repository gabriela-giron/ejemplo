#pragma once
#include "puesto.h"
#include<mysql.h>
#include <iostream>
#include"conexiondb.h"
#include<string>
#include<windows.h>
#include<stdlib.h>

using namespace std;
class puestos : puesto {
	// atributos

	   // metodo constructor
public:
	puestos() {
	}

	puestos(string pu) : puesto(pu) {

	}
	// metodos de modificar datos
	// set ( modificar)

	void setPuesto(string pu) { Puesto = pu; }

	// get(mostrar)
	string getPuesto() { return Puesto; }

	void gotoxy(int x, int y) {
		HANDLE hcon;
		hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD dwPos;
		dwPos.X = x;
		dwPos.Y = y;

		SetConsoleCursorPosition(hcon, dwPos);
	}



	void crear() {
		int q_estado;
		conexiondb cn = conexiondb();

		cn.abrir_conexion();

		if (cn.getconectar()) {
			string  insert = "insert into puestos(Puesto) VALUES ('" + Puesto + "')";
			// executar el query
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getconectar(), i);
			if (!q_estado) {
				gotoxy(68, 20);
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				gotoxy(68, 20);
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			gotoxy(68, 20);
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

			string consulta = "select * from  puestos ";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getconectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());
				cout << "----------------------------Puestos------------------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "  ,  " << fila[1] << endl;
				}

			}
			else {

				cout << "xxxxx error de  consulta xxxx" << endl;
			}



		}
		else {
			gotoxy(68, 21);
			cout << " xxxxx error en la conexion xxxxx";
		}

		cn.cerrar_conexion();


	}
	void modificar() {

		int q_estado;
		conexiondb cn = conexiondb();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string id_Puestos, puesto;
			char s;
			cout << "------------------------------------------------" << endl;
			cout << "Ingrese el id del registro que desea modificar: ";
			cin >> id_Puestos;
			string consulta = "select * from puestos where id_Puestos='" + id_Puestos + "'";
			const char* i = consulta.c_str();
			q_estado = mysql_query(cn.getconectar(), i);

			if (!q_estado) {

				resultado = mysql_store_result(cn.getconectar());

				while (fila = mysql_fetch_row(resultado)) {
					cout << "Id Puesto: " << fila[0] << endl;
					cout << "PUESTO : " << fila[1] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {

						cout << "\ningrese el nuevo puesto: ";
						cin >> puesto ;

			string update = " update puestos   set Puesto='" + puesto  + "' WHERE id_Puestos= '" + id_Puestos + "'";
			const char* y = update.c_str();
			q_estado = mysql_query(cn.getconectar(), y);
					}
					else {
						cout << ("Modificacion exitosa") << endl;
					}
				}
			}

			else {
				cout << "Error al modificar\n";
			}
		}
		else {
			cout << "Error en la conexion\n";
		}
		cn.cerrar_conexion();


	}
	void eliminar() {

		int q_estado;
		conexiondb cn = conexiondb();
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string id_Puestos;
			cout << " ingrese id a eliminar :";
			cin >> id_Puestos;
			string sel = " DELETE FROM puestos   WHERE id_Puestos= '" + id_Puestos + "'";
			const char* io = sel.c_str();
			q_estado = mysql_query(cn.getconectar(), io);
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



