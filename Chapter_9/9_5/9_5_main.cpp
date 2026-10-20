#include <iostream>
#include <stdexcept>
#include "9_5.h"          // Contiene Book, Isbn, Genre
#include "9_5_Patron.h"   // Contiene Patron
#include "9_5_library.h"  // Contiene Library, Transaction

int main() {
    std::cout << "=========================================================\n";
    std::cout << "   STARTING INTEGRATED LIBRARY SYSTEM TESTS (EX 7-9)     \n";
    std::cout << "=========================================================\n\n";

    // 1. Inicializamos nuestra biblioteca
    library::Library myLibrary;

    // 2. Creamos libros válidos con sus respectivos Géneros (Ej 7)
    library::Book book1{ {"1-2-3-a"}, "1984", "George Orwell", library::Genre::fiction };
    library::Book book2{ {"4-5-6-b"}, "A Brief History of Time", "Stephen Hawking", library::Genre::nonfiction };
    library::Book book3{ {"7-8-9-c"}, "The Hobbit", "J.R.R. Tolkien", library::Genre::fiction };

    // 3. Creamos usuarios (Ej 8)
    library::Patron patron1{ "Alice Smith", 1001 };
    library::Patron patron2{ "Bob Jones", 1002 };
    library::Patron patron3{ "Charlie Brown", 1003 };

    // Aplicamos una deuda inicial a Charlie para probar filtros más adelante
    patron3.addFee(15); // Charlie debe $15

    // 4. Registramos los recursos en la biblioteca (Ej 9)
    std::cout << "[Step 1] Registering books and patrons into the library...\n";
    myLibrary.addBook(book1);
    myLibrary.addBook(book2);

    myLibrary.addPatron(patron1);
    myLibrary.addPatron(patron2);
    myLibrary.addPatron(patron3); // Registramos a Charlie con todo y su deuda
    std::cout << "-> Registration complete.\n\n";

    // -------------------------------------------------------------------------
    // TEST 1: Préstamo Exitoso (Condiciones ideales)
    // -------------------------------------------------------------------------
    try {
        std::cout << "[Test 1] Attempting a VALID checkout...\n";
        std::cout << "User: " << patron1.getUserName() << " | Book: " << book1.getTitle() << "\n";

        // Esto debería pedirte ingresar la fecha por consola debido a tu función createDate()
        myLibrary.chekoutBook(book1, patron1);

        std::cout << "-> TEST 1 PASSED: Transaction successfully stored.\n\n";
    }
    catch (const library::Invalid&) {
        std::cout << "-> TEST 1 FAILED: Unexpected exception thrown.\n\n";
    }

    // -------------------------------------------------------------------------
    // TEST 2: Error por Libro No Registrado
    // -------------------------------------------------------------------------
    try {
        std::cout << "[Test 2] Attempting to checkout a book NOT in the library...\n";
        // Recuerda que book3 ("The Hobbit") NO lo agregamos con myLibrary.addBook()
        myLibrary.chekoutBook(book3, patron1);

        std::cout << "-> TEST 2 FAILED: The library allowed renting an unregistered book.\n\n";
    }
    catch (const library::Invalid&) {
        std::cout << "-> TEST 2 PASSED: Successfully blocked. Book was not found in the system.\n\n";
    }

    // -------------------------------------------------------------------------
    // TEST 3: Error por Usuario No Registrado
    // -------------------------------------------------------------------------
    try {
        std::cout << "[Test 3] Attempting checkout with a patron NOT in the library...\n";
        library::Patron stranger{ "Ghost User", 9999 }; // Usuario fantasma
        myLibrary.chekoutBook(book2, stranger);

        std::cout << "-> TEST 3 FAILED: The library allowed renting to an unregistered user.\n\n";
    }
    catch (const library::Invalid&) {
        std::cout << "-> TEST 3 PASSED: Successfully blocked. Patron was not found in the system.\n\n";
    }

    // -------------------------------------------------------------------------
    // TEST 4: Error por Usuario con Deudas (Fees)
    // -------------------------------------------------------------------------
    try {
        std::cout << "[Test 4] Attempting checkout with a patron who OWES FEES...\n";
        // Charlie (patron3) está registrado y book2 también, pero Charlie debe dinero
        std::cout << "User: " << patron3.getUserName() << " (Owes: $" << patron3.getlibraryFees() << ")\n";
        myLibrary.chekoutBook(book2, patron3);

        std::cout << "-> TEST 4 FAILED: The library allowed renting to a user with fees.\n\n";
    }
    catch (const library::Invalid&) {
        std::cout << "-> TEST 4 PASSED: Successfully blocked. Renting denied due to outstanding fees.\n\n";
    }

    // -------------------------------------------------------------------------
    // TEST 5: Lista de Deudores
    // -------------------------------------------------------------------------
    std::cout << "[Test 5] Querying the list of patrons who owe fees...\n";
    std::vector<library::Patron> debtors = myLibrary.whoOwesFees();

    std::cout << "Debtors found in system:\n";
    for (const auto& debtor : debtors) {
        std::cout << " - " << debtor.getUserName() << " (Card: " << debtor.getlibraryCardNumber()
            << ") owes: $" << debtor.getlibraryFees() << "\n";
    }

    std::cout << "\n=========================================================\n";
    std::cout << "               ALL LIBRARY TESTS COMPLETED               \n";
    std::cout << "=========================================================\n";

    return 0;
}