#include <iostream>
using namespace std;

// Definición de la estructura del Nodo
struct Nodo {
    int dato;
    Nodo* izquierdo;
    Nodo* derecho;
};

// Funciones para el árbol binario
Nodo* crearNodo(int dato);
void insertar(Nodo*& arbol, int dato);
void eliminar(Nodo*& arbol, int dato);
Nodo* minimo(Nodo* arbol);
void eliminarNodo(Nodo*& nodoEliminar);

bool buscar(Nodo* arbol, int dato);
void preorden(Nodo* arbol);
void inorden(Nodo* arbol);
void postorden(Nodo* arbol);

int main() {
    Nodo* arbol = nullptr;

    // Ingresar datos
    insertar(arbol, 8);
    insertar(arbol, 3);
    insertar(arbol, 10);
    insertar(arbol, 1);
    insertar(arbol, 6);
    insertar(arbol, 14);
    insertar(arbol, 4);
    insertar(arbol, 7);
    insertar(arbol, 13);

    // Eliminar dato
    eliminar(arbol, 3);

    // Buscar un dato
    if (buscar(arbol, 4)) {
        cout << "El dato 4 se encuentra en el árbol" << endl;
    } else {
        cout << "El dato 4 no se encuentra en el árbol" << endl;
    }

    // Recorrido del árbol
    cout << "Recorrido Preorden: ";
    preorden(arbol);
    cout << endl;

    cout << "Recorrido Inorden: ";
    inorden(arbol);
    cout << endl;

    cout << "Recorrido Postorden: ";
    postorden(arbol);
    cout << endl;

    return 0;
}

// Función para crear un nuevo nodo
Nodo* crearNodo(int dato) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = dato;
    nuevo->izquierdo = nullptr;
    nuevo->derecho = nullptr;

    return nuevo;
}

// Función para insertar un dato en el árbol
void insertar(Nodo*& arbol, int dato) {
    if (arbol == nullptr) {
        Nodo* nuevo = crearNodo(dato);
        arbol = nuevo;
    } else if (dato < arbol->dato) {
        insertar(arbol->izquierdo, dato);
    } else {
        insertar(arbol->derecho, dato);
    }
}

// Función para eliminar un dato del árbol
void eliminar(Nodo*& arbol, int dato) {
    if (arbol == nullptr) {
        return;
    }

    if (dato < arbol->dato) {
        eliminar(arbol->izquierdo, dato);
    } else if (dato > arbol->dato) {
        eliminar(arbol->derecho, dato);
    } else {
        eliminarNodo(arbol);
    }
}

// Función para encontrar el nodo con el mínimo valor
Nodo* minimo(Nodo* arbol) {
    if (arbol == nullptr) {
        return nullptr;
    }

    if (arbol->izquierdo) {
        return minimo(arbol->izquierdo);
    } else {
        return arbol;
    }
}

// Función para eliminar un nodo del árbol
void eliminarNodo(Nodo*& nodoEliminar) {
    if (nodoEliminar->izquierdo && nodoEliminar->derecho) {
        Nodo* nodoMinimo = minimo(nodoEliminar->derecho);
        nodoEliminar->dato = nodoMinimo->dato;
        eliminar(nodoEliminar->derecho, nodoMinimo->dato);
    } else if (nodoEliminar->izquierdo) {
        Nodo* nodoTemp = nodoEliminar;
        nodoEliminar = nodoEliminar->izquierdo;
        delete nodoTemp;
    } else if (nodoEliminar->derecho) {
        Nodo* nodoTemp = nodoEliminar;
        nodoEliminar = nodoEliminar->derecho;
        delete nodoTemp;
    } else {
        delete nodoEliminar;
        nodoEliminar = nullptr;
    }
}

// Función para buscar un dato en el árbol
bool buscar(Nodo* arbol, int dato) {
    if (arbol == nullptr) {
        return false;
    } else if (arbol->dato == dato) {
        return true;
    } else if (dato < arbol->dato) {
        return buscar(arbol->izquierdo, dato);
    } else {
        return buscar(arbol->derecho, dato);
    }
}

// Función para recorrer el árbol en preorden
void preorden(Nodo* arbol) {
    if (arbol == nullptr) {
        return;
    }
    cout << arbol->dato << " ";
    preorden(arbol->izquierdo);
    preorden(arbol->derecho);
}

// Función para recorrer el árbol en orden (Inorden)
void inorden(Nodo* arbol) {
    if (arbol == nullptr) {
        return;
    }
    inorden(arbol->izquierdo);
    cout << arbol->dato << " ";
    inorden(arbol->derecho);
}

// Función para recorrer el árbol en postorden
void postorden(Nodo* arbol) {
    if (arbol == nullptr) {
        return;
    }
    postorden(arbol->izquierdo);
    postorden(arbol->derecho);
    cout << arbol->dato << " ";
}