#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::IO;


public ref class Receta
{
public:
	String^ nombre;
	List<String^>^ ingredientes;
	List<String^>^ pasos;
	Receta^ hermano;
	Receta^ hijo;
public:
	Receta() { nombre = ""; ingredientes = gcnew List<String^>(); pasos = gcnew List<String^>(); }
	void AgregarPaso(String^ paso) {
		pasos->Add(paso);
	}
	void AgregarIngrediente(String^ ingrediente) {
		ingredientes->Add(ingrediente);
	}
	void EliminarPaso(String^ paso) {
		pasos->Remove(paso);
	}
	void EliminarIngrediente(String^ ingrediente) {
		ingredientes->Remove(ingrediente);
	}
};





public ref class Producto
{
public:
	String^ Nombre;
	String^ Descripcion;
	int precio;
	int cantDisp;
public://punteros de hermanos e hijos
	Producto^ hermano;//derecha
	Receta^ hijoraiz;//izquierda
public:
	Producto() { Nombre = Descripcion = ""; precio = cantDisp = 0; }
	void AgregarReceta(Receta^ nuevo) {
		if (hijoraiz == nullptr)
		{
			hijoraiz = nuevo;
		}
		else {
			Receta^ aux = hijoraiz;
			while (aux->hermano != nullptr) aux = aux->hermano;
			aux->hermano = nuevo;
		}

	}
	void EliminarReceta(Receta^ eliminar) {
		if (hijoraiz == eliminar)
		{
			hijoraiz = eliminar->hermano;
		}
		else {
			Receta^ aux = hijoraiz;
			while (aux->hermano != eliminar) aux = aux->hermano;
			aux->hermano = eliminar->hermano;
		}
	}
	Receta^ BuscarReceta(String^ buscar) {
		Receta^ aux = hijoraiz;
		while (aux != nullptr && aux->nombre != buscar) aux = aux->hermano;
		if (aux == nullptr) MessageBox::Show("No se encontro la receta");
		else MessageBox::Show("Receta encontrada");
		return aux;

	}
	void mostrarRecetas(ListBox^ lb) {
		Receta^ aux = hijoraiz;
		lb->Items->Clear();
		while (aux != nullptr) {
			lb->Items->Add(aux->nombre);
			aux = aux->hermano;
		}
	}
	void AgregarPaso(Receta^ receta, String^ paso) {
		receta->pasos->Add(paso);
	}
	void AgregarIngrediente(Receta^ receta, String^ ingrediente) {
		receta->ingredientes->Add(ingrediente);
	}
};





public ref class Pasteleria
{
private:
	Producto^ productoraiz = gcnew Producto();
	Producto^ dos = gcnew Producto();
public:
	Pasteleria() {
		productoraiz = gcnew Producto();
		dos->Nombre = "Pastel";
		dos->Descripcion = "Pastel de chocolate";
		dos->precio = 100;
		dos->cantDisp = 10;
		dos->hermano = nullptr;
		dos->hijoraiz = nullptr;

	}
	void AgregarProducto(Producto^ nuevo) {
		if (productoraiz == nullptr) {
			nuevo = productoraiz;
		}
		else {
			Producto^ aux = productoraiz;
			while (aux->hermano != nullptr) {
				aux = aux->hermano;

			}
			aux->hermano = nuevo;
		}


	}
	void EliminarProducto(Producto^ eliminar) {
		if (productoraiz == eliminar)
		{
			productoraiz = eliminar->hermano;
		}
		else {
			Producto^ aux = productoraiz;
			while (aux->hermano != eliminar) aux = aux->hermano;
			aux->hermano = eliminar->hermano;
		}
	}
	Producto^ BuscarProducto(String^ buscar) {
		Producto^ aux = productoraiz;
		while (aux != nullptr && aux->Nombre != buscar) aux = aux->hermano;
		if (aux == nullptr) MessageBox::Show("No se encontro el producto");
		else MessageBox::Show("Producto encontrado");
		return aux;
	}
	void mostrarProductos(ListBox^ lb) {
		lb->Items->Clear();
		Producto^ aux = productoraiz;
		while (aux != nullptr) {
			lb->Items->Add(aux->Nombre);
			aux = aux->hermano;
		}
	}
};









