#include <iostream>
#include <stdexcept>
#include "9_14.h" // Asegúrate de que coincida con el nombre real de tu archivo .h

int main() {
    std::cout << "=========================================================\n";
    std::cout << "   STARTING INTEGRATED MONEY CLASS TESTS (EX 14 & 15)    \n";
    std::cout << "=========================================================\n\n";

    try {
        // ---------------------------------------------------------------------
        // TEST 1: Regla de redondeo 4/5 al inicializar (Ej 14)
        // ---------------------------------------------------------------------
        std::cout << "[Test 1] Testing 4/5 rounding rule (.5 rounds up)...\n";
        Finance::Money m1{ 100.454, "USD" }; // Menor a .5 centavos -> Debe bajar a $100.45
        Finance::Money m2{ 100.455, "USD" }; // Igual a .5 centavos -> Debe subir a $100.46
        Finance::Money m3{ -5.505, "USD" };  // Negativo -> Debe redondear a -$5.51

        std::cout << " -> Input: 100.454 | Got: " << m1 << " (Cents: " << m1.getCents() << ")\n";
        std::cout << " -> Input: 100.455 | Got: " << m2 << " (Cents: " << m2.getCents() << ")\n";
        std::cout << " -> Input: -5.505  | Got: " << m3 << " (Cents: " << m3.getCents() << ")\n\n";

        // ---------------------------------------------------------------------
        // TEST 2: Operaciones con la misma moneda (Aritmética directa en centavos)
        // ---------------------------------------------------------------------
        std::cout << "[Test 2] Testing arithmetic with IDENTICAL currencies...\n";
        Finance::Money walletMXN1{ 500.50, "MXN" };
        Finance::Money walletMXN2{ 200.25, "MXN" };

        Finance::Money totalSumMXN = walletMXN1 + walletMXN2;
        Finance::Money totalSubMXN = walletMXN1 - walletMXN2;

        std::cout << " -> " << walletMXN1 << " + " << walletMXN2 << " = " << totalSumMXN << " (Expected: $700.75 MXN)\n";
        std::cout << " -> " << walletMXN1 << " - " << walletMXN2 << " = " << totalSubMXN << " (Expected: $300.25 MXN)\n\n";

        // ---------------------------------------------------------------------
        // TEST 3: Operaciones con monedas distintas (Conversión y puente USD) (Ej 15)
        // ---------------------------------------------------------------------
        std::cout << "[Test 3] Testing arithmetic with DIFFERENT currencies...\n";
        // Simulamos exactamente el ejemplo del libro: USD 1.23 + DKK 5.00
        Finance::Money usdItem{ 1.23, "USD" };
        Finance::Money dkkItem{ 5.00, "DKK" };

        // El resultado final debe expresarse en la moneda del primer objeto (USD)
        Finance::Money resultMixed = usdItem + dkkItem;

        std::cout << " -> " << usdItem << " + " << dkkItem << " = " << resultMixed << "\n";
        std::cout << "    (Math: 1.23 USD + (5.00 DKK / 7.10) USD = ~1.9342 USD -> Redondeado a $1.93 USD)\n\n";

        // ---------------------------------------------------------------------
        // TEST 4: Multiplicación por un factor escalar (Impuestos/Descuentos)
        // ---------------------------------------------------------------------
        std::cout << "[Test 4] Testing scalar multiplication (e.g., 16% VAT tax)...\n";
        Finance::Money productEUR{ 10.00, "EUR" };
        Finance::Money taxEUR = productEUR * 0.16; // 16% de IVA

        std::cout << " -> 16% Tax on " << productEUR << " = " << taxEUR << " (Expected: $1.6 EUR)\n\n";

        // ---------------------------------------------------------------------
        // TEST 5: Operador de Entrada (Lectura interactiva con $)
        // ---------------------------------------------------------------------
        std::cout << "[Test 5] Testing interactive operator>> input...\n";
        Finance::Money userMoney;
        std::cout << "Enter an amount using the exact format '$123.45 MXN': ";

        if (std::cin >> userMoney) {
            std::cout << " -> Successfully read! Value stored: " << userMoney
                << " (Internal Cents: " << userMoney.getCents() << ")\n\n";
        }
        else {
            std::cout << " -> Error: Invalid input format. Make sure you included the '$' sign and currency code.\n\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

        // ---------------------------------------------------------------------
        // TEST 6: Protección contra monedas ilegales o no soportadas (Ej 15)
        // ---------------------------------------------------------------------
        std::cout << "[Test 6] Testing protection against unsupported currencies...\n";
        std::cout << "Attempting to create money with currency code 'YEN'...\n";

        // Esto debe disparar tu 'throw Invalid{}' dentro de convertionMultiplier
        Finance::Money illegalMoney{ 100.00, "YEN" };

        std::cout << " -> Error: The program allowed creating an unsupported currency!\n";

    }
    catch (const Finance::Invalid&) {
        std::cout << " -> Success: The system blocked the illegal currency and threw Finance::Invalid.\n";
    }

    std::cout << "\n=========================================================\n";
    std::cout << "               ALL MONEY TESTS COMPLETED                 \n";
    std::cout << "=========================================================\n";

    return 0;
}