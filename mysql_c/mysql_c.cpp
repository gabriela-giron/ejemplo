#include"empleados.h"
#include"puestos.h"
#include"clientes.h"
#include "Productos.h"
#include "marcas.h"
#include "proveedores.h"
#include "Compras.h"
#include "Ventas2.h"
#include "Ventas_si.h"
#include"SerialPort.h"
#include <wingdi.h>
#include <string>
#include<stdio.h>
#include <iostream>
#include <stdlib.h>
#include <tchar.h>
#include <fstream>
#include<Windows.h>

using namespace std;

void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;

	SetConsoleCursorPosition(hcon, dwPos);
}

void pintar() {
	for (int i = 2; i < 163; i++) { //lineas horizontales
		gotoxy(i, 1);
		printf("%c", 205);
		gotoxy(i, 41);
		printf("%c", 205);
	}
	for (int i = 2; i < 41; i++) {//lineas verticales
		gotoxy(2, i);
		printf("%c", 186);
		gotoxy(163, i);
		printf("%c", 186);
	}
	gotoxy(2, 1); //esquinas
	printf("%c", 201);
	gotoxy(2, 41);
	printf("%c", 200);
	gotoxy(163, 1);
	printf("%c", 187);
	gotoxy(163, 41);
	printf("%c", 188);
}



char output[MAX_DATA_LENGTH];
char incomingData[MAX_DATA_LENGTH];
char opci;
char commport[] = "\\\\.\\COM9";
char* port = commport;

	void arduino() {
		pintar();
		SerialPort arduino(port);
		if (arduino.isConnected()) {
			gotoxy(50, 16);
			cout << "CONEXION EXITOSA !" << endl << endl;
		}
		else {
			gotoxy(50, 16);
			cout << "CONEXION EXITOSA !" << endl << endl;
			gotoxy(50, 19);
			cout << "BANDA TRANSPORTADORA EN FUNCION" << endl << endl;
			gotoxy(50, 21);
			system("pause");
			system("cls");
			pintar();

		}
		while (arduino.isConnected()) {
			do {
				//cout << "Enter your command: " << endl;
				string data = "d";
				//cin >> data;

				char* charArray = new char[data.size() + 1];
				copy(data.begin(), data.end(), charArray);
				charArray[data.size()] = '\n';

				arduino.writeSerialPort(charArray, MAX_DATA_LENGTH);
				arduino.readSerialPort(output, MAX_DATA_LENGTH);

				//cout << ">> " << output << endl;

				delete[] charArray;

			} while (opci != 'x');

		}
	}


void menu_principal();
void menu_empleados();
void menu_puestos();
void menu_clientes();
void menu_marcas();
void menu_productos();
void menu_compras();
void menu_proveedores();
void menu_compras_detalle();
void menu_ventas();
void arduino();
void pintar();
void Crear_factura();


int main() {
	system("color 03");
	system("cls");
	pintar();
	menu_principal();
	return 0;
	

}



int no_factura = 0;
int variable = 0;
int id_Ventas = 9;
int id_Producto = 0;

char cadena[] = "ABCDE";


void menu_principal() {

	system("cls");
	pintar();
	int opc;
	do {
		gotoxy(50, 16);
		cout << "\t\t -------------- Menu Principal ----------------" << endl;
		gotoxy(71, 18);
		cout << "\t 1. Tabla de Empleados" << endl;
		gotoxy(71, 19);
		cout << "\t 2. Tabla de Puestos" << endl;
		gotoxy(71, 20);
		cout << "\t 3. Tabla de Clientes" << endl;
		gotoxy(71, 21);
		cout << "\t 4. Tabla de Marcas" << endl;
		gotoxy(71, 22);
		cout << "\t 5. Tabla de Productos" << endl;
		gotoxy(71, 23);
		cout << "\t 6. Tabla de Proveedores" << endl;
		gotoxy(71, 24);
		cout << "\t 7. Tabla de Ventas" << endl;
		gotoxy(71, 25);
		cout << "\t 8. Tabla de Compras" << endl;
		gotoxy(71, 26);
		cout << "\t 9. Banda transportadora" << endl;
		gotoxy(71, 27);
		cout << "\t 10. Facturacion" << endl;
		gotoxy(71, 28);
		cout << "\t 0. Salir" << endl;

		gotoxy(71, 31);
		cout << "\t Seleccione su opcion: " << endl;
		gotoxy(100, 31);
		cin >> opc;

		system("cls");
		switch (opc) {
		case 1:
			system("cls");
			menu_empleados();
			system("pause>nul");
			break;

		case 2:
			system("cls");
			menu_puestos();
			system("pause>nul");
			break;

		case 3:
			system("cls");
			menu_clientes();
			system("pause>nul");
			break;

		case 4:
			system("cls");
			menu_marcas();
			system("pause>nul");
			break;

		case 5:
			system("cls");
			menu_productos();
			system("pause>nul");
			break;

		case 6:
			system("cls");
			menu_proveedores();
			system("pause>nul");
			break;

		case 7:
			system("cls");
			menu_ventas();
			system("pause>nul");
			break;

		case 8:
			system("cls");
			menu_compras_detalle();
			system("pause>nul");
			break;

		case 9:
			system("cls");
			arduino();
			system("pause>nul");
			break;

		case 10:
			system("cls");
			Crear_factura();
			system("pause>nul");
			break;

		case 0:
			opc = false;
			break;

		}
	} while (opc);
}

//empleados
void menu_empleados() {
	system("cls");
	pintar();
	int opcion;
	gotoxy(65, 16);
	cout << "-------------- Menu Empleados: ----------------" << endl;
	gotoxy(78, 18);
	cout << " 1. Crear....." << endl;
	gotoxy(78, 19);
	cout << " 2. Leer....." << endl;
	gotoxy(78, 20);
	cout << " 3. Modificar..." << endl;
	gotoxy(78, 21);
	cout << " 4. Eliminar..." << endl;
	gotoxy(78, 22);
	cout << " 0. Menu Principal..." << endl;
	gotoxy(73, 25);
	cout << " Seleccione su opcion: " << endl;
	gotoxy(96, 25);
	cin >> opcion;
	system("cls");
	switch (opcion) {

	case 1: {
		cout << " para insertar......." << endl;
		string nombres, apellidos, direccion, DPI, genero, fecha_nacimiento, id_Puestos, fecha_inicio_labores, fecha_ingreso;
		int telefono;
		cin.ignore();
		cout << " ingrese nombres: ";
		getline(cin, nombres);
		cout << " ingrese apellidos: ";
		getline(cin, apellidos);
		cout << " ingrese direccion: ";
		getline(cin, direccion);
		cout << " ingrese telefono :";
		cin >> telefono;
		cin.ignore();
		cout << " ingrese DPI : ";
		getline(cin, DPI);
		cout << " ingrese genero [0=M/1=F]: ";
		getline(cin, genero);
		cout << " ingrese la fecha de nacimiento [AAAA-MM-DD]: ";
		getline(cin, fecha_nacimiento);
		puestos p = puestos();
		p.leer();
		cout << " ingrese el id de puestos: ";
		getline(cin, id_Puestos);
		cout << " ingrese la fecha de inicio de labores [AAAA-MM-DD]: " << endl;
		getline(cin, fecha_inicio_labores);


		empleados e = empleados(nombres, apellidos, direccion, telefono, DPI, genero, fecha_nacimiento, id_Puestos, fecha_inicio_labores, fecha_ingreso);

		e.crear();
		gotoxy(68, 39);
		system("pause");
		system("cls");
		pintar();
		break;
	}
	case 2: {
		empleados e = empleados();

		e.leer();
		gotoxy(65, 37);
		system("pause");
		system("cls");
		pintar();
		break;

	}
	case 3: {
		cout << " para modificar......." << endl;
		string nombres, apellidos, direccion, DPI, genero, fecha_nacimiento, id_Puestos, fecha_inicio_labores, fecha_ingreso;
		int telefono;
		cin.ignore();
		cout << " ingrese nombres modificados: ";
		getline(cin, nombres);
		cout << " ingrese apellidos modificados: ";
		getline(cin, apellidos);
		cout << " ingrese direccion modificada: ";
		getline(cin, direccion);
		cout << " ingrese telefono modificado:";
		cin >> telefono;
		cin.ignore();
		cout << " ingrese DPI modificado: ";
		getline(cin, DPI);
		cout << " ingrese genero modificado [0=M/1=F]: ";
		getline(cin, genero);
		cout << " ingrese fecha de nacimiento modificada[AAAA-MM-DD]: ";
		getline(cin, fecha_nacimiento);
		puestos p = puestos();
		p.leer();
		cout << " ingrese  id del puesto modificado: ";
		getline(cin, id_Puestos);
		cout << " ingrese fecha de inicio de labores modificada [AAAA-MM-DD]: " << endl;
		getline(cin, fecha_inicio_labores);
		cout << " ingrese fecha y hora de ingreso modificada [AAAA-MM-DD  HH:MM:SS]: " << endl;
		getline(cin, fecha_ingreso);



		empleados e = empleados(nombres, apellidos, direccion, telefono, DPI, genero, fecha_nacimiento, id_Puestos, fecha_inicio_labores, fecha_ingreso);
		e.leer();
		e.modificar();
		system("cls");
		system("pause");
		e.leer();
		system("pause");
		system("cls");
		pintar();
		break;
	}
	case 4: {
		empleados e = empleados();
		e.leer();
		e.eliminar();
		system("pause");
		system("cls");
		pintar();
		break;
	}
	case 0: {
		menu_principal();
		system("pause>nul");
		pintar();
		break;
	}
	}
}

//puesto
void menu_puestos() {
	int opcion;
	pintar();
	gotoxy(65, 16);
	cout << "-------------- Menu Puestos: ----------------" << endl;
	gotoxy(78, 18);
	cout << " 1. crear....." << endl;
	gotoxy(78, 19);
	cout << " 2. leer....." << endl;
	gotoxy(78, 20);
	cout << " 3. modificar..." << endl;
	gotoxy(78, 21);
	cout << " 4. eliminar..." << endl;
	gotoxy(78, 22);
	cout << " 0. Menu Principal" << endl;
	gotoxy(73, 25);
	cout << " Seleccione su opcion: ";
	gotoxy(96, 25);
	cin >> opcion;
	system("cls");
	switch (opcion) {
	case 1: {

		cout << " para ingresar......." << endl;

		string Puesto;
		cin.ignore();
		cout << " ingrese puesto: ";
		getline(cin, Puesto);
		puestos p = puestos(Puesto);

		p.crear();
		system("pause");
		system("cls");
		pintar();
		break;

	}

	case 2: {
		string Puesto;
		puestos p = puestos(Puesto);

		p.leer();
		gotoxy(65, 37);
		system("pause");
		system("cls");
		pintar();
		break;

	}

	case 3: {
		cout << " para modificar......." << endl;
		string Puesto;
		cin.ignore();
		cout << " ingrese puesto modificado: ";
		getline(cin, Puesto);
		puestos p = puestos(Puesto);

		p.leer();
		p.modificar();
		system("cls");
		system("pause");
		p.leer();
		system("pause");
		system("cls");
		pintar();
		break;
	}

	case 4: {
		string Puesto;
		puestos p = puestos(Puesto);
		p.leer();
		p.eliminar();
		system("pause");
		system("cls");
		pintar();
		break;
	}
	case 0: {
		menu_principal();
		system("pause>nul");
		pintar();
		break;

	}

	}
}

//clientes
void menu_clientes() {
	int opcion;
	pintar();
	gotoxy(65, 16);
	cout << "-------------- Menu Clientes: ----------------" << endl;
	gotoxy(78, 18);
	cout << " 1. crear....." << endl;
	gotoxy(78, 19);
	cout << " 2. leer....." << endl;
	gotoxy(78, 20);
	cout << " 3. modificar..." << endl;
	gotoxy(78, 21);
	cout << " 4. eliminar..." << endl;
	gotoxy(78, 22);
	cout << " 0. Menu Principal" << endl;
	gotoxy(73, 25);
	cout << " Seleccione su opcion: ";

	gotoxy(96, 25);
	cin >> opcion;
	system("cls");
	switch (opcion) {
	case 1: {

		string nombres, apellidos, NIT, genero, correo_electronico, fecha_ingreso;
		int telefono = 0;
		cout << " ingrese nombres: " << endl;
		cin >> nombres;
		cout << " ingrese apellidos: " << endl;
		cin >> apellidos;
		cout << " ingrese direccion: " << endl;
		cin >> NIT;
		cout << " ingrese genero [0=M/1=F] : " << endl;
		cin >> genero;
		cout << " ingrese telefono :" << endl;
		cin >> telefono;
		cout << " ingrese correo electronico: " << endl;
		cin >> correo_electronico;


		clientes c = clientes(nombres, apellidos, NIT, genero, telefono, correo_electronico, fecha_ingreso);

		c.crear();
		system("pause");
		system("cls"); 
		pintar();
		break;
	}
	case 2: {
		string nombres, apellidos, nit, genero, telefono, correo_electronico, fecha_ingreso;
		clientes c = clientes();
		c.leer();
		system("pause");
		system("cls");
		pintar();
		break;
	}
	case 3: {
		string nombres, apellidos, NIT, genero, correo_electronico, fecha_ingreso;
		int telefono = 0;
		cout << " ingrese nombres modificados: " << endl;
		cin >> nombres;
		cout << " ingrese apellidos modificados: " << endl;
		cin >> apellidos;
		cout << " ingrese direccion modificada: " << endl;
		cin >> NIT;
		cout << " ingrese genero modificado [0=M/1=F]: " << endl;
		cin >> genero;
		cout << " ingrese telefono modificado:" << endl;
		cin >> telefono;
		cout << " ingrese correo electronico modificado: " << endl;
		cin >> correo_electronico;
		cout << " ingrese la fecha ingreso modificada: " << endl;
		cin >> fecha_ingreso;


		clientes c = clientes(nombres, apellidos, NIT, genero, telefono, correo_electronico, fecha_ingreso);
		c.leer();
		c.modificar();
		system("cls");
		system("pause");
		c.leer();
		system("cls");
		pintar();
		break;
	}
	case 4: {
		clientes c = clientes();

		c.leer();
		c.eliminar();
		system("pause");
		system("cls");
		pintar();
		break;
	}



	}
}

//marcas
void menu_marcas() {
	int opcion;
	pintar();
	gotoxy(65, 16);
	cout << "-------------- Menu Marcas: ----------------" << endl;
	gotoxy(78, 18);
	cout << " 1. crear....." << endl;
	gotoxy(78, 19);
	cout << " 2. leer....." << endl;
	gotoxy(78, 20);
	cout << " 3. modificar..." << endl;
	gotoxy(78, 21);
	cout << " 4. eliminar..." << endl;
	gotoxy(78, 22);
	cout << " 0. Menu Principal" << endl;
	gotoxy(73, 25);
	cout << " Seleccione su opcion: ";

	gotoxy(96, 25);
	cin >> opcion;
	system("cls");
	switch (opcion) {
	case 1: {

		cout << " para ingresar......." << endl;

		string Marca;
		cin.ignore();
		cout << " ingrese Marca: ";
		getline(cin, Marca);
		marcas m = marcas(Marca);

		m.crear();
		system("pause");
		system("cls");
		pintar();
		break;

	}

	case 2: {

		string Marca;
		marcas m = marcas(Marca);

		m.leer();
		system("pause");
		system("cls");
		pintar();
		break;

	}

	case 3: {
		cout << " para modificar......." << endl;
		string Marca;
		cin.ignore();

		cout << " ingrese marca: ";
		getline(cin, Marca);
		marcas m = marcas(Marca);

		m.leer();
		m.modificar();
		system("cls");
		system("pause");
		m.leer();
		system("pause");
		system("cls");
		pintar();
		break;
	}

	case 4: {
		string Marca;
		marcas m = marcas(Marca);
		m.leer();
		m.eliminar();
		system("pause");
		system("cls");
		pintar();
		break;
	}
	case 0: {
		menu_principal();
		system("pause>nul");
		pintar();
		break;

	}

	}

}

//productos
void menu_productos() {
	system("cls");
	pintar();
	int opcion;
	gotoxy(65, 16);
	cout << "-------------- Menu Productos: ----------------" << endl;
	gotoxy(78, 18);
	cout << " 1. Crear....." << endl;
	gotoxy(78, 19);
	cout << " 2. Leer....." << endl;
	gotoxy(78, 20);
	cout << " 3. Modificar..." << endl;
	gotoxy(78, 21);
	cout << " 4. Eliminar..." << endl;
	gotoxy(78, 22);
	cout << " 0. Menu Principal..." << endl;
	gotoxy(73, 25);
	cout << " Seleccione su opcion: " << endl;
	gotoxy(96, 25);
	cin >> opcion;
	switch (opcion) {

	case 1: {
		system("cls");

		cout << " para insertar......." << endl;
		string product, id_Marca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso;
		cin.ignore();
		cout << " ingrese producto: ";
		getline(cin, product);
		marcas m = marcas();
		m.leer();
		cout << " ingrese id marca: ";
		getline(cin, id_Marca);
		cout << " ingrese descripcion: ";
		getline(cin, descripcion);
		cout << " ingrese imagen: ";
		getline(cin, imagen);
		cout << " ingrese el precio_costo: ";
		getline(cin, precio_costo);
		cout << " ingrese el precio_venta: ";
		getline(cin, precio_venta);
		cout << " ingrese la existencia:";
		getline(cin, existencia);



		Productos pr = Productos(product, id_Marca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso);
		pr.crear();
		system("pause");
		system("cls");
		pintar();
		break;
	}
	case 2: {
		system("cls");
		Productos pr = Productos();

		pr.leer();
		system("pause");
		system("cls");
		pintar();
		break;

	}
	case 3: {
		system("cls");
		cout << " para modificar......." << endl;
		string product, id_Marca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso;
		cin.ignore();
		cout << " ingrese producto modificado: ";
		getline(cin, product);
		marcas m = marcas();
		m.leer();
		cout << " ingrese id marca modificado: ";
		getline(cin, id_Marca);
		cout << " ingrese descripcion modificada: ";
		getline(cin, descripcion);
		cout << " ingrese imagen modificada: ";
		getline(cin, imagen);
		cout << " ingrese el precio_costo modificado: ";
		getline(cin, precio_costo);
		cout << " ingrese el precio_venta modificado: ";
		getline(cin, precio_venta);
		cout << " ingrese la existencia modificada: ";
		getline(cin, existencia);
		cout << " ingrese fecha y hora de ingreso modificada [AAAA-MM-DD  HH:MM:SS]: " << endl;
		getline(cin, fecha_ingreso);



		Productos pr = Productos(product, id_Marca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso);
		pr.leer();
		pr.modificar();
		system("cls");
		system("pause");
		pr.leer();
		system("pause");
		system("cls");
		pintar();
		break;
	}
	case 4: {
		system("cls");
		Productos pr = Productos();
		pr.leer();
		pr.eliminar();
		system("pause");
		system("cls");
		pintar();
		break;
	}
	case 0: {
		menu_principal();
		system("pause>nul");
		pintar();
		break;
	}
	}
}

//proveedores
void menu_proveedores() {
	int opcion;
	pintar();
	gotoxy(65, 16);
	cout << "-------------- Menu Productos: ----------------" << endl;
	gotoxy(78, 18);
	cout << " 1. crear....." << endl;
	gotoxy(78, 19);
	cout << " 2. leer....." << endl;
	gotoxy(78, 20);
	cout << " 3. modificar..." << endl;
	gotoxy(78, 21);
	cout << " 4. eliminar..." << endl;
	gotoxy(78, 22);
	cout << " 0. Menu Principal" << endl;
	gotoxy(73, 25);
	cout << " Seleccione su opcion: ";

	gotoxy(96, 25);
	cin >> opcion;
	system("cls");
	switch (opcion) {

	case 1: {
		cout << " para ingresar......." << endl;

		string proveedor, nit, direccion, telefono;
		cin.ignore();
		cout << " ingrese proveedor: " << endl;
		getline(cin, proveedor);
		cout << " ingrese NIT: " << endl;
		getline(cin, nit);
		cout << " ingrese direccion: " << endl;
		getline(cin, direccion);
		cout << " ingrese telefono:" << endl;
		getline(cin, telefono);


		proveedores pr = proveedores (proveedor, nit, direccion, telefono);

		pr.crear();
		system("pause");
		system("cls");
		pintar();
		break;


	}
	case 2: {
		proveedores pr = proveedores();
		pr.leer();
		system("pause");
		system("cls");
		pintar();
		break;
	}
	case 3: {
		cout << " para modificar......." << endl;

		string proveedor, nit, direccion, telefono;
		cin.ignore();
		cout << " ingrese proveedor: " << endl;
		getline(cin, proveedor);
		cout << " ingrese NIT: " << endl;
		getline(cin, nit);
		cout << " ingrese direccion: " << endl;
		getline(cin, direccion);
		cout << " ingrese telefono:" << endl;
		getline(cin, telefono);


		proveedores pr = proveedores(proveedor, nit, direccion, telefono);

		pr.modificar();
		system("pause");
		system("cls");
		pintar();
		break;


	}
	case 4: {
		proveedores pr = proveedores();
		pr.eliminar();
		system("pause");
		system("cls");
		pintar();
		break;


	}
	case 0: {
		menu_principal();
		system("pause>nul");
		pintar();
		break;

	}
	}
}

	void menu_compras_detalle() {
		system("cls");
		pintar();
		int opcion;
		gotoxy(65, 16);
		cout << "-------------- Menu compras detalle: ----------------" << endl;
		gotoxy(78, 18);
		cout << " 1. Crear....." << endl;
		gotoxy(78, 19);
		cout << " 2. Leer....." << endl;
		gotoxy(78, 20);
		cout << " 3. Modificar..." << endl;
		gotoxy(78, 21);
		cout << " 4. Eliminar..." << endl;
		gotoxy(78, 22);
		cout << " 0. Menu Principal..." << endl;
		gotoxy(73, 25);
		cout << " Seleccione su opcion: " << endl;
		gotoxy(96, 25);
		cin >> opcion;
		system("cls");
		switch (opcion) {

		case 1: {
			Compras a;
			a.leer_compras();
			menu_compras();
			system("pause");
			system("cls");
			pintar();
			break;
		}
		case 2: {
			Compras a;
			a.leer_compras();
			system("pause");
			system("cls");
			pintar();
			break;

		}
		case 3: {
			void compras1(); {
				int i;
				Compras a;
				a.leer_compras();
				cout << "ingrese el No. de orden de compra a modificar: ";
				cin >> i;
				Compras l;
				l.modificar_compras(i);
			}

			system("pause");
			system("cls");
			pintar();
			break;
		}
		case 4: {
			Compras a;
			a.leer_compras();
			a.eliminar();
			system("pause");
			system("cls");
			pintar();
			break;
		}
		case 0: {
			menu_principal();
			system("pause>nul");
			pintar();
			break;
		}
		}
	}

	void menu_ventas() {
		system("cls");
		pintar();
		int opcion;
		gotoxy(65, 16);
		cout << "-------------- Menu ventas: ----------------" << endl;
		gotoxy(78, 18);
		cout << " 1. Crear....." << endl;
		gotoxy(78, 19);
		cout << " 2. Leer....." << endl;
		gotoxy(78, 20);
		cout << " 3. Modificar..." << endl;
		gotoxy(78, 21);
		cout << " 4. Eliminar..." << endl;
		gotoxy(78, 22);
		cout << " 0. Menu Principal..." << endl;
		gotoxy(73, 25);
		cout << " Seleccione su opcion: " << endl;
		gotoxy(96, 25);
		cin >> opcion;
		system("cls");
		switch (opcion) {

		case 1: {
			Ventas2 a;
			a.leer_ventas();
			void ventas3(); {
				int p;
				string fechafact = "now()", fecha_ingreso = "now()", cantidad;
				int id_cliente, id_empleado;
				int idproducto;
				char rr;

				clientes x;
				x.leer();

				cout << ("\t\t\tIngrese Id Cliente: ");
				cin >> id_cliente;
				cout << endl;

				empleados v;
				v.leer();

				cout << ("\t\t\tIngrese Id Empleado: ");
				cin >> id_empleado;
				cout << endl;
				Ventas2 txt = Ventas2(fechafact, id_cliente, id_empleado, fecha_ingreso);
				txt.crear2();
				system("pause>nul");

				do {
					Productos q;
					q.leer();

					cout << ("\t\t\tIngrese Id Producto: ");
					cin >> idproducto;
					cout << endl;

					cout << ("\t\t\tIngrese cantidad: ");
					cin >> cantidad;
					cout << endl;

					Ventas_si constillita = Ventas_si(idproducto, cantidad);
					constillita.crear2(idproducto);

					cout << endl << endl;
					cout << ("Desea insertar otro registro s-n :");
					cin >> rr;

				} while ((rr == 's') || (rr == 'S'));

			}
			system("pause");
			system("cls");
			pintar();
			break;
		}
		case 2: {
			Ventas2 a;
			a.leer_ventas();
			system("pause");
			system("cls");
			pintar();
			break;

		}
		case 3: {
			void ventas1(); {
				int r;
				Ventas2 j;
				j.leer_ventas();
				cout << "ingrese el No. de Factura a modificar: ";
				cin >> r;
				Ventas2 a;
				a.modificar_ventas(r);
			}

			system("pause");
			system("cls");
			pintar();
			break;
		}
		case 4: {
			Ventas2 a;
			a.leer_ventas();
			a.eliminar();
			system("pause");
			system("cls");
			pintar();
			break;
		}
		case 0: {
			menu_principal();
			system("pause>nul");
			pintar();
			break;
		}
		}
	}

	void menu_compras() {
		int id_proveedor, idcompra, cero, idproducto, Cantidad;
		string  fecha1 = "now()", fechaIngreso = "now()";

		char op;

		proveedores a;
		a.leer();

		cout << ("Ingrese Id proveedor: ") << endl;
		cin >> id_proveedor;

		Compras cc = Compras(id_proveedor, fecha1, fechaIngreso);
		cc.crear(id_proveedor);

		//Comienza el detalle
		do
		{
			Productos b;
			b.leer();

			cout << endl << endl;
			cout << ("Ingrese Id Producto: ") << endl;

			cin >> idproducto;


			cout << ("Ingrese Cantidad: ") << endl;
			cin >> Cantidad;

			Compras2 f = Compras2(idproducto, Cantidad);
			f.Maestro_compras();

			cout << ("Te gustaria agregar un nuevo registro s-n") << endl << endl;
			cin >> op;

		} while ((op == 's') || (op == 'S'));

		pintar();
	}

	void Crear_factura() {
		system("cls");
		pintar();
		int q_estado;
		int q_estado2;
		int q_estado3;
		int q_estado4;
		int q_estado5;

		conexiondb cn = conexiondb();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		int  xa = 8, xb = 8, xc = 8, xd = 8, xe = 8, xf = 8, xg = 8, xh = 8, xi = 8, xj = 8, xl = 8;
		int za = 8, zb = 8, zc = 4, zd = 8, ze = 8, zf = 8, zg = 8, zh = 8, zi = 8, zj = 8, zk = 8, zl = 8;
		int lleva, lleva2;
		float lleva3;

		if (cn.getconectar()) {
			string consulta = "select max(id_Ventas) from ventas";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getconectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());
				while (fila = mysql_fetch_row(resultado)) {
					lleva = atoi(fila[0]);
				}

				if (cn.getconectar()) {
					int valor = lleva;
					string encontrar = to_string(valor);
					string consulta4 = "select   x.id_Ventas, x.no_factura,x.serie, m.nombres,m.apellidos, m.NIT, m.telefono,m.correo_electronico, d.nombres,d.apellidos, fecha_factura from ventas as x inner join clientes as m on x.id_Clientes=m.id_Clientes inner join empleados as d on x.id_Empleado=d.id_Empleados where id_Ventas=" + encontrar + "";

					const char* jk = consulta4.c_str();
					q_estado2 = mysql_query(cn.getconectar(), jk);
					if (!q_estado2) {
						resultado = mysql_store_result(cn.getconectar());
						while (fila = mysql_fetch_row(resultado)) {

							gotoxy(45, 10); cout << "No pedido: " << fila[0];
							gotoxy(45, 8); cout << "Serie: " << fila[2];
							gotoxy(55, 8); cout << "No factura: " << fila[1];
							gotoxy(45, 13); cout << "Cliente:    ";
							gotoxy(45, 15); cout << fila[3] << " " << fila[4];

							gotoxy(45, 16); cout << "NIT: " << fila[5];
							gotoxy(45, 17); cout << "No. Telefono: " << fila[6];
							gotoxy(45, 18); cout << "Correo: " << fila[7];

							gotoxy(114, 9); cout << " Atendido por :";
							gotoxy(130, 9); cout << fila[8] << " " << fila[9];

							gotoxy(115, 8); cout << "Fecha: " << fila[10] << endl;


							lleva2 = atoi(fila[1]);



						}
						int ma = 25, mb = 25, mc = 25, md = 25, me = 25, mf = 25, mg = 25, mh = 25, mi = 25, mj = 25, mk = 25, ml = 25, mm = 25;
						if (cn.getconectar()) {
							string encontrado = to_string(lleva2);

							string consulta5 = "select   x.id_Venta_detalle,d.producto,d.descripcion, x.precio_unitario,x.cantidad, m.id_Ventas from ventas_detalle as x inner join ventas as m on x.id_Ventas=m.id_Ventas inner join productos as d on x.id_Productos=d.id_Productos where no_factura=" + encontrado + "";
							const char* cc = consulta5.c_str();
							q_estado3 = mysql_query(cn.getconectar(), cc);
							if (!q_estado3) {
								resultado = mysql_store_result(cn.getconectar());
								while (fila = mysql_fetch_row(resultado)) {
									gotoxy(43, 23); cout << ("|  No.   |"); gotoxy(54, 23); cout << ("     Producto    |"); gotoxy(73, 23); cout << ("       Descripcion        |");
									gotoxy(100, 23); cout << ("  precio |"); gotoxy(110, 23); cout << ("Cantidad|"); gotoxy(120, 23);
									gotoxy(46, ma++); cout << fila[0]; gotoxy(53, mb++); cout << fila[1]; gotoxy(72, mc++); cout << fila[2];

								}
								if (cn.getconectar()) {
									string consultar = "select (cantidad * precio_unitario) from ventas_detalle where id_Venta=" + encontrar + "";
									const char* dc = consultar.c_str();
									q_estado5 = mysql_query(cn.getconectar(), dc);
									if (!q_estado5) {
										resultado = mysql_store_result(cn.getconectar());
										while (fila = mysql_fetch_row(resultado)) {

											gotoxy(121, mm++); cout << "Q." << fila[0];
										}

										if (cn.getconectar()) {
											string consulta6 = "select sum(cantidad * precio_unitario) from ventas_detalle where id_Venta=" + encontrar + "";
											const char* bb = consulta6.c_str();
											q_estado4 = mysql_query(cn.getconectar(), bb);
											if (!q_estado4) {
												resultado = mysql_store_result(cn.getconectar());
												while (fila = mysql_fetch_row(resultado)) {
													//	
													cout << ("\n\t\t\t\t\t   |-------------------------------------------------------------------------------------------");
													cout << ("\n\t\t\t\t\t   |-------------------------------------------------------------------------------------------");

												}
												cout << ("\n\t\t\t\t\t   |                                                                                          |");


											}
											else {
												cout << "\n\n\t--------- Error ---------";
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
			}
		}
		else {
			cout << "\n\n\t--------- Error en la Conexion ---------";
		}
		cn.cerrar_conexion();
		gotoxy(50,37);
		system("pause");
		system("cls");
		pintar();
	}



