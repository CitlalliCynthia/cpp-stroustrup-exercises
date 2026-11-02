#include <iostream>
#include <string>

/*
14. Could the “list of gods” example from §17.10.1 have been written using a singly-linked list; that is, could we have left the prev member out of Link? Why might we want to do that? For what kind of examples would it make sense to use a singly-linked list? Re-implement that example using only a singly-linked list.
*/

struct God {
    std::string name;
    std::string mythology;
    std::string vehicle;
    std::string weapon;

    God(const std::string& n, const std::string& m, const std::string& v, const std::string& w)
        : name(n), mythology(m), vehicle(v), weapon(w) {
    }

    friend bool operator==(const God& a, const God& b) {
        return (a.name == b.name && a.mythology == b.mythology && a.vehicle == b.vehicle && a.weapon == b.weapon);
    }

    friend bool operator!=(const God& a, const God& b) {
        return !(a == b);
    }
};

class Link {
public:
    God value;
    Link(const God& v, Link* s = NULL) : value{ v }, succ{ s } {}

    Link* insert(Link* n); //insert n before this object
    Link* add(Link* n);  //insert n after this object
    Link* next() const { return succ; }

    //To modify succ
    void set_next(Link* n) { succ = n; }
private:
    Link* succ; // Only link
};

Link* Link::insert(Link* n) {
    if (n == NULL) return this;
    n->succ = this->succ;
    this->succ = n;

    //Exchanging 'this' and 'n'
    God temp = this->value;
    this->value = n->value;
    n->value = temp;

    return this;
}

Link* Link::add(Link* n) {
    if (n == NULL) return this;
    n->succ = this->succ;
    this->succ = n;
    return n;
}

//Orders the list and returns the head (beginning)
Link* add_ordered(Link* head, Link* n) {
    if (n == NULL) return head;
    if (head == NULL) return n;

    if (head->value.name > n->value.name) {
        n->set_next(head);
        return n;
    }

    Link* p = head;
    while (p) {
        if (p->next() != NULL && p->next()->value.name > n->value.name) {
            p->add(n);
            break;
        }
        if (p->next() == NULL) {
            p->add(n);
            break;
        }
        p = p->next();
    }
    return head;
}

void print_all(Link* p) {
    if (p == NULL) {
        std::cout << "{ }\n";
        return;
    }
    std::cout << "{ \n";
    while (p) {
        std::cout << "  (Name: " << p->value.name << " Mythology: " << p->value.mythology
            << " Vehicle: " << p->value.vehicle << " Weapon: " << p->value.weapon << ")";
        if (p->next() != NULL) std::cout << ",\n";
        p = p->next();
    }
    std::cout << "\n}";
}

void destroy_list(Link* head) {
    while (head) {
        Link* next_node = head->next();
        delete head;
        head = next_node;
    }
}

int main() {
    Link* mixed_gods = new Link(God("Thor", "Norse", "Chariot", "Mjolnir"));
    mixed_gods = new Link(God("Ra", "Egyptian", "Solar Barque", "Sun Disk"), mixed_gods);
    mixed_gods = new Link(God("Zeus", "Greek", "Pegasus", "Lightning"), mixed_gods);
    mixed_gods = new Link(God("Odin", "Norse", "Sleipner", "Gungnir"), mixed_gods);
    mixed_gods = new Link(God("Hera", "Greek", "Chariot", "Peacock"), mixed_gods);
    mixed_gods = new Link(God("Anubis", "Egyptian", "None", "Staff"), mixed_gods);

    std::cout << "--- ORIGINAL MIXED LIST ---\n";
    print_all(mixed_gods);
    std::cout << "\n\n";

    Link* norse_list = NULL;
    Link* greek_list = NULL;
    Link* egyptian_list = NULL;

    Link* current = mixed_gods;
    while (current) {
        Link* new_node = new Link(current->value);

        if (current->value.mythology == "Norse") {
            norse_list = add_ordered(norse_list, new_node);
        }
        else if (current->value.mythology == "Greek") {
            greek_list = add_ordered(greek_list, new_node);
        }
        else if (current->value.mythology == "Egyptian") {
            egyptian_list = add_ordered(egyptian_list, new_node);
        }
        current = current->next();
    }

    std::cout << "--- NORDIC (ORDERED) ---\n";
    print_all(norse_list);
    std::cout << "\n\n";

    std::cout << "--- GREEK (ORDERED) ---\n";
    print_all(greek_list);
    std::cout << "\n\n";

    std::cout << "--- EGYPTIAN (ORDERED) ---\n";
    print_all(egyptian_list);
    std::cout << "\n\n";

    destroy_list(mixed_gods);
    destroy_list(norse_list);
    destroy_list(greek_list);
    destroy_list(egyptian_list);

    return 0;
}