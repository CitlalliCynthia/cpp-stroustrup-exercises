#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <vector>

/*
9. Define an Order class with (customer) name, address, data, and
vector<Purchase> members. Purchase is a class with a (product) name, unit_price,
and count members. Define a mechanism for reading and writing Orders to and
from a file. Define a mechanism for printing Orders. Create a file of at least
ten Orders, read it into a vector<Order>, sort it by name (of customer), and
write it back out to a file.
Create another file of at least ten Orders of which about a third are the same
as in the first file, read it into a write it back out to a file. Merge the two
files into a third using std::merge().
*/

struct Purchase {
    std::string name;
    double unit_price;
    int count;
};

struct Order {
    std::string name;
    std::string address;
    std::string data; // fecha o dato adicional
    std::vector<Purchase> purchases;
};

// --- Operadores de salida (escritura a archivo y consola) ---

std::ostream& operator<<(std::ostream& os, const Purchase& p) {
    return os << p.name << " | " << p.unit_price << " | " << p.count;
}

std::ostream& operator<<(std::ostream& os, const Order& o) {
    os << o.name << '\n'
        << o.address << '\n'
        << o.data << '\n'
        << o.purchases.size() << '\n';
    for (const auto& p : o.purchases) {
        os << p << '\n';
    }
    os << "---\n";
    return os;
}

// --- Operadores de entrada (lectura desde archivo) ---

std::istream& operator>>(std::istream& is, Purchase& p) {
    std::string line;
    if (!std::getline(is, line) || line.empty()) return is;

    std::size_t first_sep = line.find('|');
    std::size_t second_sep = line.find('|', first_sep + 1);

    if (first_sep == std::string::npos || second_sep == std::string::npos) {
        is.setstate(std::ios::failbit);
        return is;
    }

    // Extraer y limpiar espacios alrededor de '|'
    p.name = line.substr(0, first_sep);
    while (!p.name.empty() && p.name.back() == ' ') p.name.pop_back();

    p.unit_price = std::stod(line.substr(first_sep + 1, second_sep - first_sep - 1));
    p.count = std::stoi(line.substr(second_sep + 1));

    return is;
}

std::istream& operator>>(std::istream& is, Order& o) {
    std::string name, address, data, count_line, sep;

    // Ignorar líneas vacías previas al registro
    while (std::getline(is, name) && name.empty()) {}
    if (!is) return is;

    if (!std::getline(is, address) || !std::getline(is, data) || !std::getline(is, count_line)) {
        return is;
    }

    int num_purchases = std::stoi(count_line);
    std::vector<Purchase> purchases;
    for (int i = 0; i < num_purchases; ++i) {
        Purchase p;
        if (!(is >> p)) return is;
        purchases.push_back(p);
    }

    std::getline(is, sep); // Leer el separador "---"

    o = Order{ name, address, data, purchases };
    return is;
}

// --- Functors de comparación ---

struct Sort_by_name {
    bool operator()(const Order& a, const Order& b) const {
        return a.name < b.name;
    }
};

struct Sort_by_address {
    bool operator()(const Order& a, const Order& b) const {
        return a.address < b.address;
    }
};

// --- Funciones auxiliares ---

template <typename Container>
void write_orders(const std::string& filename, const Container& c) {
    std::ofstream ofs(filename);
    if (!ofs) throw std::runtime_error("No se pudo abrir para escribir: " + filename);
    for (const auto& o : c) {
        ofs << o;
    }
}

template <typename Container>
void read_orders(const std::string& filename, Container& c) {
    std::ifstream ifs(filename);
    if (!ifs) throw std::runtime_error("No se pudo abrir para leer: " + filename);
    for (Order o; ifs >> o; ) {
        c.push_back(o);
    }
}

void generate_sample_files() {
    std::vector<Order> list1 = {
        {"Carlos Ruiz", "Av. Reforma 101", "2026-11-01", {{"Laptop", 1200.0, 1}, {"Mouse", 25.5, 2}}},
        {"Ana Gomez", "Calle Sol 45", "2026-11-02", {{"Teclado", 80.0, 1}}},
        {"Luis Perez", "Blvd. Norte 88", "2026-11-03", {{"Monitor", 300.0, 2}}},
        {"Maria Lopez", "Av. Juarez 12", "2026-11-04", {{"Cable HDMI", 15.0, 3}}},
        {"Jorge Diaz", "Calle Luna 9", "2026-11-05", {{"Silla", 150.0, 1}}},
        {"Elena Torres", "Av. Central 300", "2026-11-06", {{"Escritorio", 250.0, 1}}},
        {"Pedro Sanchez", "Calle Pino 22", "2026-11-07", {{"Webcam", 60.0, 1}}},
        {"Sofia Castro", "Av. Mar 77", "2026-11-08", {{"Microfono", 110.0, 1}}},
        {"Diego Morales", "Calle Roble 5", "2026-11-09", {{"Audifonos", 95.0, 2}}},
        {"Lucia Herrera", "Av. Rio 14", "2026-11-10", {{"Tablet", 400.0, 1}}}
    };

    // Incluye ~1/3 de órdenes repetidas de list1 (Carlos, Ana, Luis)
    std::vector<Order> list2 = {
        {"Carlos Ruiz", "Av. Reforma 101", "2026-11-01", {{"Laptop", 1200.0, 1}, {"Mouse", 25.5, 2}}},
        {"Ana Gomez", "Calle Sol 45", "2026-11-02", {{"Teclado", 80.0, 1}}},
        {"Luis Perez", "Blvd. Norte 88", "2026-11-03", {{"Monitor", 300.0, 2}}},
        {"Valeria Ortiz", "Calle Palma 33", "2026-11-11", {{"Impresora", 180.0, 1}}},
        {"Fernando Silva", "Av. Bosque 50", "2026-11-12", {{"Router", 70.0, 1}}},
        {"Camila Reyes", "Calle Nube 18", "2026-11-13", {{"SSD 1TB", 90.0, 2}}},
        {"Andres Vargas", "Blvd. Sur 99", "2026-11-14", {{"RAM 16GB", 65.0, 2}}},
        {"Paula Mendoza", "Av. Valle 41", "2026-11-15", {{"Fuente 750W", 110.0, 1}}},
        {"Ricardo Rojas", "Calle Flor 62", "2026-11-16", {{"Gabinete", 85.0, 1}}},
        {"Natalia Vega", "Av. Sierra 27", "2026-11-17", {{"GPU", 550.0, 1}}}
    };

    write_orders("orders1.txt", list1);
    write_orders("orders2.txt", list2);
}

int main() {
    try {
        // 0. Crear los dos archivos iniciales con al menos 10 órdenes cada uno
        generate_sample_files();

        // 1. Leer archivo 1 en vector<Order>, ordenar por nombre y guardar
        std::vector<Order> vec_orders;
        read_orders("orders1.txt", vec_orders);
        std::sort(vec_orders.begin(), vec_orders.end(), Sort_by_name());
        write_orders("orders1_sorted.txt", vec_orders);

        // 2. Leer archivo 2 en list<Order>, ordenar por dirección y guardar
        std::list<Order> list_orders;
        read_orders("orders2.txt", list_orders);
        list_orders.sort(Sort_by_address()); // std::list tiene su propio .sort()
        write_orders("orders2_sorted.txt", list_orders);

        // 3. Combinar ambos con std::merge() en un tercer archivo
        // Nota: std::merge requiere que ambos rangos estén ordenados con el MISMO criterio.
        // Como list_orders estaba ordenado por dirección, lo reordenamos por nombre antes de hacer merge.
        list_orders.sort(Sort_by_name());

        std::vector<Order> merged_orders;
        std::merge(vec_orders.begin(), vec_orders.end(),
            list_orders.begin(), list_orders.end(),
            std::back_inserter(merged_orders),
            Sort_by_name());

        write_orders("orders_merged.txt", merged_orders);

        // Imprimir resultado en consola para verificar
        std::cout << "Total de ordenes combinadas: " << merged_orders.size() << "\n\n";
        for (const auto& o : merged_orders) {
            std::cout << o;
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}