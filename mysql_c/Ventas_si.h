#include <mysql.h>
#include <iostream>
#include "conexiondb.h"
#include <string>
#include "Ventas_extra.h"
//#include "Ventas_si.h"

using namespace std;
class Ventas_si : Ventas_extra {

public:
	Ventas_si() {
	}

	Ventas_si(int id_prod, string cant) : Ventas_extra(id_prod, cant) {
	}

	void setIdproducto(int id_prod) { id_producto = id_prod; }
	void setcantidad(string cant) { cantidad = cant; }

	// get(mostrar)

	int setIdproducto() { return id_producto; }
	string setcantidad() { return cantidad; }


	void crear2(int id_producto) {
		int q_estado;
		int q_estado2;
		int estado;
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		conexiondb cn = conexiondb();
		//string c = to_string(id);
		cn.abrir_conexion();
		string idc = to_string(id_producto);

		float aguacate = 0;
		
		int pizarron, chicharron;
		if (cn.getconectar()) {
			string consulta = "select max(id_Ventas) FROM ventas";
			const char* j = consulta.c_str();
			q_estado = mysql_query(cn.getconectar(), j);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());
				while (fila = mysql_fetch_row(resultado)) {
					pizarron = atoi(fila[0]);
				}


				if (cn.getconectar()) {
					string ver = "select precio_venta from productos where id_Productos =" + idc + "";
					const char* dd = ver.c_str();
					q_estado2 = mysql_query(cn.getconectar(), dd);
					if (!q_estado2) {
						resultado = mysql_store_result(cn.getconectar());
						while (fila = mysql_fetch_row(resultado)) {
							aguacate = atof(fila[0]);
						}

						if (cn.getconectar()) {
							string mostaza = to_string(aguacate);
							string lomito = to_string(pizarron);

							string insert = "insert into ventas_detalle (id_Ventas, id_Productos,cantidad, precio_unitario) VALUES (" + lomito + ", " + idc + ",'" + cantidad + "' , " + mostaza + ")";
							const char* h = insert.c_str();
							q_estado = mysql_query(cn.getconectar(), h);
							if (!q_estado) {
								cout << "Ingreso Exitoso Grande..." << endl;
							}
							else {
								cout << " xxx Error al Ingresar  xxx" << endl;
							}
						}

						else {
							cout << " xxx Error en la Conexion1 xxxx" << endl;
						}

					}
				}
				else {
					cout << " xxx Error en la Conexion2 xxxx" << endl;
				}
			}
		}
		else {
			cout << " xxx Error en la Conexion2 xxxx" << endl;
		}

		cn.cerrar_conexion();
	}
};



