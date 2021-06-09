#pragma once
#include "Ventas2.h"
#include <mysql.h>
#include <iostream>
#include "conexiondb.h"
#include <string>
#include "Productos.h"
#include "proveedores.h"
#include"clientes.h"
#include "Ventas.h"

using namespace std;
class Ventas2 : Ventas {
	// atributos

	   // metodo constructor
public:
	Ventas2() {
	}

	Ventas2(string fechafact, int idcliente, int idempleado, string fechaingreso) : Ventas(fechafact, idcliente, idempleado, fechaingreso) {
	}
	// metodos de modificar datos
	// set ( modificar)


	void setFecha_factura(string fechafact) { fecha_factura = fechafact; }
	void setId_cliente(int idcliente) { id_cliente = idcliente; }
	void setId_empleado(int idempleado) { id_empleado = idempleado; }
	void setFecha_ingreso(string fechaingreso) { fecha_ingreso = fechaingreso; }

	// get(mostrar)

	string setFecha_factura() { return fecha_factura; }
	int setId_cliente() { return id_cliente; }
	int setId_empleado() { return id_empleado; }
	string setFecha_ingreso() { return fecha_ingreso; }


	void crear2() {
		int q_estado;
		int estado;
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		conexiondb cn = conexiondb();
		//string c = to_string(id);
		cn.abrir_conexion();
		int pizarron, chicharron;
		if (cn.getconectar()) {
			string consulta = "select max(no_factura) FROM ventas";
			const char* j = consulta.c_str();
			q_estado = mysql_query(cn.getconectar(), j);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());
				while (fila = mysql_fetch_row(resultado)) {
					pizarron = atoi(fila[0]);
					chicharron = pizarron + 1;
				}
				string serie = "A";

				if (cn.getconectar()) {
					string jj = to_string(chicharron);
					string idc = to_string(id_cliente);
					string dp = to_string(id_empleado);
					string insert = "insert into ventas(no_factura, serie, fecha_factura, id_Clientes,id_Empleado, fecha_ingreso) VALUES (" + jj + ", '" + serie + "'," + fecha_factura + " , " + idc + "," + dp + ", " + fecha_ingreso + ")";
					// executar el query
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

		cn.cerrar_conexion();
	}
	void leer_ventas() {

		int q_estado;
		conexiondb cn = conexiondb();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_conexion();
		if (cn.getconectar()) {

			string consulta = "select  x.id_Ventas_detalle, x.cantidad,x.precio_unitario,m.no_factura,d.producto,d.descripcion, k.id_Ventas, k.fecha_factura,k.fecha_ingreso, b.Marca from Ventas_detalle as x inner join ventas as m on x.id_Ventas=m.id_Ventas inner join productos as d on x.id_Productos=d.id_Productos inner join ventas as k on x.id_Ventas=k.id_Ventas  inner join marcass as b on  d.id_Productos=b.id_Marcass ;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getconectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());
				cout << "----------------------------VENTAS DETALLE------------------------\n" << endl;
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
	void eliminar() {

		int q_estado;
		conexiondb cn = conexiondb();
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string a;
			cout << " ingrese id a eliminar :";
			cin >> a;
			string sel = " DELETE FROM Ventas_detalle   WHERE id_Ventas_detalle= '" + a + "'";
			string sel2 = " DELETE FROM Ventas   WHERE id_Ventas= '" + a + "'";
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
	void modificar_ventas(int idcliente) {
		int q_estado;
		int q_estado2, q_estado3;
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		int id_Ventas_detalle;
		int id_producto;
		int cantidad;
		float precio_venta = 0;
		conexiondb cn = conexiondb();
		int n;
		string r = to_string(idcliente);
		cn.abrir_conexion();

		clientes f;
		f.leer();
		cout << "ingrese el id del cliente: ";
		cin >> n;
		Ventas2 w;
		w.leer_ventas();
		cout << "ingrese el id de venta detalle: ";
		cin >> id_Ventas_detalle;
		Productos p;
		p.leer();
		cout << "ingrese el id del producto: ";
		cin >> id_producto;
		cout << "ingrese la cantidad: ";
		cin >> cantidad;
		string s = to_string(n);
		string ivd = to_string(id_Ventas_detalle);
		string ip = to_string(id_producto);
		string c = to_string(cantidad);


		if (cn.getconectar()) {
			string update1 = " UPDATE VENTAS SET ID_CLIENTES = " + s + "  WHERE NO_FACTURA = " + r + "";
			const char* u = update1.c_str();
			q_estado = mysql_query(cn.getconectar(), u);
			if (!q_estado) {
				cout << "Modificacion exitosa..." << endl;
				leer_ventas();

			}
			else {
				cout << "xxxx error al modificar xxxx" << endl;
			}

		}
		if (cn.getconectar()) {

			string consulta3 = "select precio_venta from productos where id_Productos=" + ip + "";
			const char* cf = consulta3.c_str();
			q_estado3 = mysql_query(cn.getconectar(), cf);
			if (!q_estado3) {
				resultado = mysql_store_result(cn.getconectar());
				while (fila = mysql_fetch_row(resultado)) {
					//	zeta = atof(fila[0]);
					precio_venta = atof(fila[0]);
				}


				if (cn.getconectar()) {
					string l = to_string(precio_venta);
					string update2 = "UPDATE VENTAS_DETALLE SET ID_PRODUCTOS = " + ip + ", CANTIDAD = " + c + ", precio_unitario = " + l + " WHERE Id_Ventas_Detalle = " + ivd + "";
					const char* u2 = update2.c_str();
					q_estado2 = mysql_query(cn.getconectar(), u2);
					if (!q_estado2) {
						cout << "Modificacion exitosa..." << endl;
						leer_ventas();

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
};