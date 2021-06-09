#pragma once
#include "compra.h"
#include <mysql.h>
#include <iostream>
#include "conexiondb.h"
#include <string>
//#include "Compras2.h"

using namespace std;
class Compras : compra1 {
	// atributos

	   // metodo constructor
public:
	Compras() {
	}

	Compras(int idpr, string ford, string fin) : compra1(idpr, ford, fin) {
	}
	// metodos de modificar datos
	// set ( modificar)

	void setid_proveedor(int idpr) { id_proveedor = idpr; }
	void setfecha_orden(string ford) { fecha_orden = ford; }
	void setfecha_ingreso(string fin) { fecha_ingreso = fin; }

	// get(mostrar)

	int setid_proveedores() { return id_proveedor; }
	string setfecha_orden() { return fecha_orden; }
	string setfecha_ingreso() { return fecha_ingreso; }
	
	void crear(int id) {
		int q_estado;
		int estado;
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		conexiondb cn = conexiondb();
		string c = to_string(id);
		cn.abrir_conexion();

		if (cn.getconectar()) {
			string consulta = "select * from proveedores where id_Proveedores= " + c + "";
			const char* cz = consulta.c_str();
			estado = mysql_query(cn.getconectar(), cz);
			if (!estado) {
				resultado = mysql_store_result(cn.getconectar());
				while (fila = mysql_fetch_row(resultado)) {
					fila[0], fila[1];
					cout << "\t\t\t\t\t\t\t" << fila[1];
				}
			}
			else {
				cout << "\n\n\t--------- Error en la Base de datos  ---------";
			}

			int pizarron, chicharron;
			if (cn.getconectar()) {
				string consulta = "select max(no_orden_compra) FROM compras";
				const char* j = consulta.c_str();
				q_estado = mysql_query(cn.getconectar(), j);
				if (!q_estado) {
					resultado = mysql_store_result(cn.getconectar());
					while (fila = mysql_fetch_row(resultado)) {
						pizarron = atoi(fila[0]);
						chicharron = pizarron + 1;
					}


					if (cn.getconectar()) {
						string jj = to_string(chicharron);

						string insert = "insert into compras(no_orden_compra, id_proveedor, fecha_orden, fecha_ingreso) VALUES (" + jj + ", " + c + "," + fecha_orden + " , " + fecha_ingreso + ")";
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
						cout << " xxx Error en la Conexion1 xxxx" << endl;
					}

				}
			}
			else {
				cout << " xxx Error en la Conexion2 xxxx" << endl;
			}
		}

		else {
			cout << " xxx Error en la Conexion3 xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void leer_compras() {

		int q_estado;
		conexiondb cn = conexiondb();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getconectar()) {

			string consulta = "select  x.id_Compras_detalle, x.cantidad,x.precio_costo_unitario, m.no_orden_compra ,d.producto,d.descripcion, k.id_Compras, k.fecha_orden,k.fecha_ingreso, b.Marca,f.proveedor from compras_detalle as x inner join compras as m on x.id_compra=m.id_Compras inner join productos as d on x.id_producto=d.id_Productos inner join compras as k on x.id_compra=k.id_Compras inner join marcass as b on  d.id_Productos=b.id_Marcass inner join proveedores as f on k.id_proveedor=f.id_Proveedores;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getconectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());
				cout << "----------------------------COMPRAS DETALLE------------------------\n" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "  |  " << fila[1] << "  |  " << fila[2] << "  |  " << fila[3] << "  |  " << fila[4] << "  |  " << fila[5] << "  |  " << fila[6] << "  |  " << fila[7] << "  |  " << fila[8] << "  |  " << fila[9] << "  |  " << fila[10] << endl;
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
	
	void modificar_compras(int idpr) {
		int q_estado;
		int q_estado2, q_estado3;
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		int id_Compras_detalle;
		int id_producto;
		int cantidad;
		float precio_Costo = 0;
		conexiondb cn = conexiondb();
		int n;
		string i = to_string(idpr);
		cn.abrir_conexion();
		cout << "ingrese el id del proveedor: ";
		cin >> n;
		cout << "ingrese el id de compra detalle: ";
		cin >> id_Compras_detalle;
		cout << "ingrese el id del producto: ";
		cin >> id_producto;
		cout << "ingrese la cantidad: ";
		cin >> cantidad;
		string s = to_string(n);
		string icd = to_string(id_Compras_detalle);
		string ip = to_string(id_producto);
		string c = to_string(cantidad);


		if (cn.getconectar()) {
			string update1 = " UPDATE COMPRAS SET ID_PROVEEDOR = " + s + "  WHERE NO_ORDEN_COMPRA = " + i + "";
			const char* u = update1.c_str();
			q_estado = mysql_query(cn.getconectar(), u);
			if (!q_estado) {
				cout << "Modificacion exitosa..." << endl;
				leer_compras();

			}
			else {
				cout << "xxxx error al modificar xxxx" << endl;
			}

		}
		if (cn.getconectar()) {

			string consulta3 = "select precio_costo from productos where id_Productos=" + ip + "";
			const char* cf = consulta3.c_str();
			q_estado3 = mysql_query(cn.getconectar(), cf);
			if (!q_estado3) {
				resultado = mysql_store_result(cn.getconectar());
				while (fila = mysql_fetch_row(resultado)) {
					//	zeta = atof(fila[0]);
					precio_Costo = atof(fila[0]);
				}


				if (cn.getconectar()) {
					string l = to_string(precio_Costo);
					string update2 = "UPDATE COMPRAS_DETALLE SET ID_PRODUCTO = " + ip + ", CANTIDAD = " + c + ", precio_costo_unitario = " + l + " WHERE Id_Compras_Detalle = " + icd + "";
					const char* u2 = update2.c_str();
					q_estado2 = mysql_query(cn.getconectar(), u2);
					if (!q_estado2) {
						cout << "Modificacion exitosa..." << endl;
						leer_compras();

					}
					else {
						cout << "xxxx error al modificar xxxx" << endl;
					}

				}
				else {
					cout << "xxxx error en la conexion xxxx" << endl;

				}

			}
			else {
				cout << "xxxx error en la conexion xxxx" << endl;

			}

			cn.cerrar_conexion();
		}
	}
	void eliminar() {

		int q_estado;
		conexiondb cn = conexiondb();
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string a;
			cout << " ingrese id a eliminar :";
			cin >> a;
			string sel = " DELETE FROM compras_detalle   WHERE id_Compras_detalle= '" + a + "'";
			string sel2 = " DELETE FROM compras   WHERE id_Compras= '" + a + "'";
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




class Compras2 : compra_detalle {
	// atributos

	   // metodo constructor
public:
	Compras2() {
	}

	Compras2(int pro, int can) : compra_detalle(pro, can) {

	}

	void setid_producto(int pro) { id_producto = pro; }
	void setcantidad(int can) { cantidad = can; }
	int getid_producto() { return id_producto; }
	int setcantidad() { return cantidad; }


	void Maestro_compras() {
		int q_estado;
		int q_estado2;
		int q_estado3;

		conexiondb cn = conexiondb();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		string productoid = to_string(id_producto);
		string can = to_string(cantidad);

		float precio_Costo = 0;
		int aguacate;


		if (cn.getconectar()) {
			string consulta = "select max(id_Compras) FROM compras";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getconectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());
				while (fila = mysql_fetch_row(resultado)) {
					//val = atoi(fila[0]);
					aguacate = atoi(fila[0]);
				}

				if (cn.getconectar()) {

					string consulta3 = "select precio_costo from productos where id_Productos=" + productoid + "";
					const char* cf = consulta3.c_str();
					q_estado3 = mysql_query(cn.getconectar(), cf);
					if (!q_estado3) {
						resultado = mysql_store_result(cn.getconectar());
						while (fila = mysql_fetch_row(resultado)) {
							//	zeta = atof(fila[0]);
							precio_Costo = atof(fila[0]);
						}

						if (cn.getconectar()) {
							/*
							int op = val;
							string hj = to_string(op);
							string hk = to_string(zeta);
							*/

							string ll = to_string(aguacate);
							string costo = to_string(precio_Costo);

							string  insertar = "insert into compras_detalle(id_Compra,id_producto,cantidad,precio_costo_unitario) VALUES (" + ll + "," + productoid + "," + can + "," + costo + ")";

							const char* p = insertar.c_str();

							q_estado2 = mysql_query(cn.getconectar(), p);
							if (!q_estado2) {


								if (!q_estado2) {

								}
								else {

								}

							}
							else {
								cout << "\n\n\t--------- Error en la Conexion ---------";
							}

						}
						else {
							cout << "\n\n\t--------- Error en la Base de datos  ---------";
						}
					}
				}
				else {
					cout << "\n\n\t--------- Error en la Conexion ---------";
				}
			}
		}
		else {
			cout << "\n\n\t--------- Error en la Conexion ---------";
		}

		cn.cerrar_conexion();
	}
};