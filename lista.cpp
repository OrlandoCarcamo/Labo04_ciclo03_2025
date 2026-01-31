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

    cout << "✅ Paquete insertado al final.\n";
}


int main(){

    return 0;
}