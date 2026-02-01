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
 
//Recorre la lista desde el inicio, si encuentra el id, devuelve el puntero al nodo, si no lo encuentra devuelve nullptr
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
    if (buscarPorId(head, id) != NULL) { // Verifica si el ID ya existe
        cout << " Error: ID repetido.\n";
        return;
    }

    Nodo* nuevo = new Nodo{id, nombre, peso, NULL, NULL}; //Si no existe, crea el nuevo nodo

    if (head == NULL) {
        head = tail = nuevo; //Si la lista esta vacia, el nuevo nodo es head y tail
    } else {
        nuevo->sig = head; //Si no esta vacia, el nuevo nodo apunta a head
        head->ant = nuevo;
        head = nuevo;
    }

    cout << " Paquete insertado al inicio.\n";
}
 
void insertarFinal(Nodo*& head, Nodo*& tail, int id, string nombre, float peso) {
    if (buscarPorId(head, id) != NULL) { //Lo mismo, busca si el ID ya existe
        cout << "Error: ID repetido.\n";
        return;
    }

    Nodo* nuevo = new Nodo{id, nombre, peso, NULL, NULL}; //Si no existe,  se crea nuevo nodo :)

    if (head == NULL) {
        head = tail = nuevo;
    } else {
        tail->sig = nuevo;
        nuevo->ant = tail;
        tail = nuevo; //El tail ahora es el nuevo nodo
    }

    cout << " Paquete insertado al final.\n";
}
void mostrarAdelante(Nodo* head) {
    if (head == NULL) { //Revisa si la lista esta vacia
        cout << "⚠️ Lista vacia.\n";
        return;
    }

    Nodo* aux = head;
    cout << "\n--- LISTA ADELANTE ---\n";
    while (aux != NULL) { //Recorre la lista desde la cabeza hasta la cola
        cout << "ID: " << aux->id
             << " | Nombre: " << aux->nombre
             << " | Peso: " << aux->peso << " kg\n";
        aux = aux->sig;
    }
}

void mostrarAtras(Nodo* tail) {
    if (tail == NULL) { //Tambien checa si la lista esta vacia
        cout << "⚠️ Lista vacia.\n";
        return;
    }

    Nodo* aux = tail;
    cout << "\n--- LISTA ATRAS ---\n";
    while (aux != NULL) { //Recorre la lista desde la cola hasta la cabeza
        cout << "ID: " << aux->id
             << " | Nombre: " << aux->nombre
             << " | Peso: " << aux->peso << " kg\n";
        aux = aux->ant;
    }
}


int main(){

    return 0;
}