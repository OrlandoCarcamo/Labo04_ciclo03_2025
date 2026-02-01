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
int id;
string nombre;
float peso;
int opcion;

Nodo* head = nullptr;
Nodo* tail = nullptr;
  
    do{
    cout << "......Bienvenido......" << endl;
    cout << "Seleccione una opcion:" << endl;
    cout << "1) Insertar paquete al final." << endl;
    cout << "2) Insertar paquete al inicio." << endl;
    cout << "3) Mostrar lista adelante." << endl;
    cout << "4) Mostrar lista atras." << endl;
    cout << "5) Buscar paquete por id." << endl;
    cout << "6) Eliminar paquete por id." << endl;
    cout << "7) Liberar lista." << endl;
    cout << "8) Mostrar cantidad de paquetes." << endl;
    cout << "9) Salir." << endl;
cin >> opcion;

switch (opcion){
    
    case 1:    
    cout << "ID: ";
        cin >> id;
    cout << "Nombre: ";
        cin >> nombre;
    cout << "Peso: ";
        cin >> peso;
    insertarFinal( head, tail, id, nombre, peso);
    break;



    case 2:  
    cout << "ID: ";
        cin >> id;
    cout << "Nombre: ";
        cin >> nombre;
    cout << "Peso: ";
        cin >> peso;
    insertarInicio( head,  tail,  id,  nombre, peso);
    break;



    case 3:
    mostrarAdelante( head);
    break;



    case 4:  
    mostrarAtras( tail);
    break;



    case 5:
     cout << "ID a buscar: ";
    cin >> id;

    {
        Nodo* encontrado = buscarPorId(head, id);

        if (encontrado != nullptr)
            cout << "Encontrado -> Nombre: " << encontrado->nombre
                 << " | Peso: " << encontrado->peso << " kg\n";
        else
            cout << "No existe ese ID\n";
    }
    break;



    case 6:  
    cout << "ID a eliminar: ";
        cin >> id;
    eliminar( head,  tail,  id );
    break;



    case 7:  
    liberarlist( head,  tail);
     break;



    case 8: 
    cout << "Cantidad de paquetes: " << contarpacks(head) << endl;
    break;



    case 9: 
    cout << "Saliendo del programa..." << endl;
    break;


    default: cout << "Seleccione una opcion valida." << endl;

}
} while (opcion != 9);
    return 0;
}
