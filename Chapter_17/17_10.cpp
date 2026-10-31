#include <iostream>
#include <string>

/*
11. Complete the “list of gods” example from §17.10.1 and run it.
*/

class Link {
public:
    std::string value;

    Link(const std::string& v, Link* p = nullptr, Link* s = nullptr)
        : value{ v }, prev{ p }, succ{ s } {
    }

    Link* insert(Link* n);                        // Inserta n antes de este objeto
    Link* add(Link* n);                           // Inserta n después de este objeto
    Link* erase();                                // Remueve este objeto de la lista
    Link* find(const std::string& s);             // Busca s en la lista
    const Link* find(const std::string& s) const; // Busca s en una lista constante
    Link* advance(int n) const;                   // Se mueve n posiciones en la lista

    Link* next() const { return succ; }
    Link* previous() const { return prev; }

private:
    Link* prev;
    Link* succ;
};

// 1. INSERT (Inserta antes del nodo actual)
Link* Link::insert(Link* n) {
    if (n == nullptr) return this;
    if (this == nullptr) return n;

    n->succ = this;     // 'this' viene después de n
    if (prev) prev->succ = n;
    n->prev = prev;     // El predecesor de 'this' se vuelve el predecesor de n
    prev = n;           // n se vuelve el predecesor de 'this'
    return n;
}

// 2. ADD (Inserta después del nodo actual)
Link* Link::add(Link* n) {
    if (n == nullptr) return this;
    if (this == nullptr) return n;

    n->prev = this;     // 'this' viene antes de n
    if (succ) succ->prev = n;
    n->succ = succ;     // El sucesor de 'this' se vuelve el sucesor de n
    succ = n;           // n se vuelve el sucesor de 'this'
    return n;
}

// 3. ERASE (Remueve el nodo actual y une a sus vecinos)
Link* Link::erase() {
    if (this == nullptr) return nullptr;
    if (succ) succ->prev = prev;
    if (prev) prev->succ = succ;
    Link* temp = succ ? succ : prev; // Devuelve el nodo que queda al lado
    succ = nullptr;
    prev = nullptr;
    return temp;
}

// 4. FIND (Busca un texto hacia adelante en la lista)
Link* Link::find(const std::string& s) {
    Link* p = this;
    while (p) {
        if (p->value == s) return p;
        p = p->next();
    }
    return nullptr;
}

// 5. FIND CONST (Versión constante para objetos de solo lectura)
const Link* Link::find(const std::string& s) const {
    const Link* p = this;
    while (p) {
        if (p->value == s) return p;
        p = p->next();
    }
    return nullptr;
}

// 6. ADVANCE (Se mueve n posiciones, soporta números negativos)
Link* Link::advance(int n) const {
    Link* p = const_cast<Link*>(this);
    if (p == nullptr) return nullptr;

    if (n > 0) {
        while (n--) {
            if (p->succ == nullptr) return nullptr;
            p = p->succ;
        }
    }
    else if (n < 0) {
        while (n++) {
            if (p->prev == nullptr) return nullptr;
            p = p->prev;
        }
    }
    return p;
}

// Función auxiliar global para imprimir la lista completa
void print_all(Link* p) {
    std::cout << "{ ";
    while (p) {
        std::cout << p->value;
        p = p->next();
        if (p) std::cout << ", ";
    }
    std::cout << " }";
}

int main() {
    // Crear lista de dioses nórdicos
    Link* norse_gods = new Link{ "Thor" };
    norse_gods = norse_gods->insert(new Link{ "Odin" });
    norse_gods = norse_gods->insert(new Link{ "Zeus" }); // Zeus se coló aquí erróneamente
    norse_gods = norse_gods->insert(new Link{ "Freia" });

    // Crear lista de deidades griegas
    Link* greek_gods = new Link{ "Hera" };
    greek_gods = greek_gods->insert(new Link{ "Athena" });
    greek_gods = greek_gods->insert(new Link{ "Mars" }); // Marte está en latín, debe ser Ares
    greek_gods = greek_gods->insert(new Link{ "Poseidon" });

    // Corregir el nombre de Mars a Ares
    Link* p = greek_gods->find("Mars");
    if (p) p->value = "Ares";

    // Mudar a Zeus de la lista nórdica a la lista griega
    Link* p2 = norse_gods->find("Zeus");
    if (p2) {
        // Si Zeus resulta ser la cabeza actual del puntero norse_gods, 
        // movemos el inicio de la lista al siguiente antes de sacarlo
        if (p2 == norse_gods) norse_gods = p2->next();

        p2->erase(); // Lo desconectamos de los nórdicos
        greek_gods = greek_gods->insert(p2); // Lo insertamos con los griegos
    }

    // Mostrar resultados
    std::cout << "Nordic gods: ";
    print_all(norse_gods);
    std::cout << "\n";

    std::cout << "Greek gods:  ";
    print_all(greek_gods);
    std::cout << "\n";

    // Limpieza de memoria (Opcional pero buena práctica para evitar memory leaks)
    while (norse_gods) {
        Link* next = norse_gods->next();
        delete norse_gods;
        norse_gods = next;
    }
    while (greek_gods) {
        Link* next = greek_gods->next();
        delete greek_gods;
        greek_gods = next;
    }

    return 0;
}