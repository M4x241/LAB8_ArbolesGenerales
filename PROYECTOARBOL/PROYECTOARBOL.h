#pragma once

#using <System.Windows.Forms.dll>
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::IO;


namespace PROYECTOARBOL {
	public ref class Receta
	{
	public:
		String^ Nombre;
		List<String^>^ Ingredientes;
		List<String^>^ Pasos;
		Receta^ hermano;
		Receta^ hijo;
	public:
		Receta() { Nombre = ""; Ingredientes = gcnew List<String^>(); Pasos = gcnew List<String^>(); }
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
			while (aux != nullptr && aux->Nombre != buscar) aux = aux->hermano;
			if (aux == nullptr) MessageBox::Show("No se encontro la receta");
			else MessageBox::Show("Receta encontrada");
			return aux;

		}
		void mostrarRecetas(ListBox^ lb, Label^ _label) {
			Receta^ aux = hijoraiz;
			while (aux != nullptr) {
				lb->Items->Add(aux->Ingredientes[0]);
				aux = aux->hermano;
			}
			//mostrar todos los elementos en pasos en label
			String^ pasos = "";
			aux = hijoraiz;
			while (aux != nullptr) {
				for each (String ^ paso in aux->Pasos)
				{
					pasos += paso + "\n";
				}
				aux = aux->hermano;
			}

		}
		void AgregarPaso(Receta^ receta, String^ paso) {
			receta->Pasos->Add(paso);
		}
		void AgregarIngrediente(Receta^ receta, String^ ingrediente) {
			receta->Ingredientes->Add(ingrediente);
		}
	};





	public ref class Pasteleria
	{
	private:
		Producto^ productoraiz;
	public:
		Pasteleria() {

		}
		void AgregarProducto(Producto^ nuevo) {
			if (productoraiz == nullptr) {
				productoraiz = nuevo;
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
			Producto^ aux = productoraiz;
			while (aux != nullptr) {
				lb->Items->Add(aux->Nombre);
				aux = aux->hermano;
			}
		}
	};
}
