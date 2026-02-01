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

void mostrarAtras(Nodo* tail) {
    if (tail == NULL) {
        cout << "⚠️ Lista vacia.\n";
        return;
    }

    Nodo* aux = tail;
    cout << "\n--- LISTA ATRAS ---\n";
    while (aux != NULL) {
        cout << "ID: " << aux->id
             << " | Nombre: " << aux->nombre
             << " | Peso: " << aux->peso << " kg\n";
        aux = aux->ant;
    }
}

bool eliminar(Nodo*& head, Nodo*& tail, int id ){
    if (head == nullptr) {
        cout << "La lista esta vacia"<< endl;
        return false;
    }
    Nodo* borrar = head;
    
    while (borrar != nullptr){

        if (borrar->id == id){
            if (head == tail){
                head = tail = nullptr;
            }
            else if (borrar == head){
                head = head->sig;
                head->ant= nullptr;
            }

            else if (borrar == tail){ 
            tail = tail->ant;
            tail->sig= nullptr; 
            }
            else {
            borrar->ant->sig = borrar->sig;
            borrar->sig->ant= borrar->ant;
            }
            delete borrar;
            cout << "Elemento eliminado. " << endl;
            return true;
    }
   
    borrar = borrar->sig;
} 

        cout << "No se ha encontrado el id. " << endl;
        return false;
    
    }

void liberarlist(Nodo*& head, Nodo *& tail){
    Nodo* aux= head;
    while (aux != nullptr){
        Nodo* borrar = aux;
        aux = aux->sig;
        delete borrar;
    }
    head = tail = nullptr;
   
    

};

int main(){

    return 0;
}
