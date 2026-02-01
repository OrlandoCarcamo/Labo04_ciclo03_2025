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
// Funcion eliminar, valida si la lista esta vacia, y si no, procede con el resto del codigo.
bool eliminar(Nodo*& head, Nodo*& tail, int id ){
    if (head == nullptr) {
        cout << "La lista esta vacia"<< endl;
        return false;
    }
    Nodo* borrar = head;
    //Se estara ejecutando siempre y cuando el puntero no se encuentre con la lista vacia o el final de la lista
    while (borrar != nullptr){
        // evalua si el dato ingresado es el mismo que se encuentra en el nodo.
        if (borrar->id == id){
            if (head == tail){
                //manera resumida, en ves de colocar head = null; tail = null, me gusto, la vi en un video.
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
// en caso llegue al final, sale del while y por ende no se encontro el elemento 
        cout << "No se ha encontrado el id. " << endl;
        return false;
    
    }
// funcion para liberar los elementos de la lista, se guarda el nodo actual y se mueve al siguiente antes de borrar
void liberarlist(Nodo*& head, Nodo *& tail){
    Nodo* aux= head;
    while (aux != nullptr){
        Nodo* borrar = aux;
        aux = aux->sig;
        delete borrar;
    }
    head = tail = nullptr;
   
    

};

int contarpacks(Nodo* head){
   int contador = 0;
    Nodo* aux = head;
    //contador inicializado en 0,cada vez que ingrese al siguente se le sumara 1.
    while (aux != nullptr){
        contador++;
        aux = aux->sig;
    }
    return contador;
};

int main(){

    return 0;
}
