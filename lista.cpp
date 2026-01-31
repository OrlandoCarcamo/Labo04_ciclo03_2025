#include <iostream>
using namespace std;


struct Nodo {
int id;
string nombre;
float peso;
int dato;
Nodo* sig;
Nodo* ant;
};

Nodo* buscarPorId(Nodo* head, int id){
    Nodo* aux = head;
    while (aux != nullptr){
        if (aux->id == id){
            return aux;
        }
        aux = aux->sig;
    }
    return nullptr;
}
void insertarInicio(Nodo*& head, Nodo*& tail, int id, string nombre, float peso) {
    if (buscarPorId(head, id) != NULL) {
        cout << " Error: ID repetido.\n";
        return;
    }

    Nodo* nuevo = new Nodo{id, nombre, peso, NULL, NULL};

    if (head == NULL) {
        head = tail = nuevo;
    } else {
        nuevo->sig = head;
        head->ant = nuevo;
        head = nuevo;
    }

    cout << " Paquete insertado al inicio.\n";
}
 
void insertarFinal(Nodo*& head, Nodo*& tail, int id, string nombre, float peso) {
    if (buscarPorId(head, id) != NULL) {
        cout << "Error: ID repetido.\n";
        return;
    }

    Nodo* nuevo = new Nodo{id, nombre, peso, NULL, NULL};

    if (head == NULL) {
        head = tail = nuevo;
    } else {
        tail->sig = nuevo;
        nuevo->ant = tail;
        tail = nuevo;
    }

    cout << " Paquete insertado al final.\n";
}
void mostrarAdelante(Nodo* head) {
    if (head == NULL) {
        cout << "⚠️ Lista vacia.\n";
        return;
    }

    Nodo* aux = head;
    cout << "\n--- LISTA ADELANTE ---\n";
    while (aux != NULL) {
        cout << "ID: " << aux->id
             << " | Nombre: " << aux->nombre
             << " | Peso: " << aux->peso << " kg\n";
        aux = aux->sig;
    }
}



int main(){

    return 0;
}