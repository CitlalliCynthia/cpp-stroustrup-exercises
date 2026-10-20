#include <cmath>
#include <iostream>
#include "9_14.h"

namespace Finance {

    Money::Money(const std::string& curr) : cents(0), currency(curr) {}

	Money::Money(const double quantity, const std::string& curr) {
        cents = roundToCents(quantity);
        currency = curr;
	}

    Money::Money(long int quantity, const std::string& curr) : cents(quantity), currency(curr) {}

    long int Money::roundToCents(double quantity) {
        double totalCents = quantity * 100.0;

        //to separate the decimal part (everything already in cents)
        double integralPart;
        double fractionalCent = std::modf(totalCents, &integralPart);

        // 3. Obtenemos el valor absoluto de la fracción para que funcione con números negativos
        // Regla 4/5: Si la fracción de centavo es >= 0.5, sumamos 1 centavo (si es positivo) o restamos 1 (si es negativo)
        long int finalCents = static_cast<long int>(integralPart);

        if (std::abs(fractionalCent) >= 0.5) {
            if (totalCents >= 0) {
                finalCents += 1; // Redondea hacia arriba
            }
            else {
                finalCents -= 1; // Redondea hacia abajo si es negativo
            }
        }

        return finalCents;
    }

    double convertionMultiplier(std::string currency) {
        if (currency == "USD") return 1.000;
        else if (currency == "EUR") return 0.9500;
        else if (currency == "DKK") return 7.1000;
        else if (currency == "MXN") return 20.1500;
        else throw Invalid{};
    }

    Money operator+(const Money& a, const Money& b) {
        const std::string& aCurrency = a.getCurrency();
        const std::string& bCurrency = b.getCurrency();
        
        if (aCurrency == bCurrency) {
            return Money(a.getCents() +b.getCents(),aCurrency);
        }

        double aToDollars = a.getMoney() / convertionMultiplier(aCurrency);
        double bToDollars = b.getMoney() / convertionMultiplier(bCurrency);

        double total = aToDollars + bToDollars;
        
        total *= convertionMultiplier(aCurrency);
        
        return Money(total, aCurrency);
    }

    Money operator-(const Money& a, const Money& b) {
        const std::string& aCurrency = a.getCurrency();
        const std::string& bCurrency = b.getCurrency();

        if (aCurrency == bCurrency) {
            return Money(a.getCents() - b.getCents(), aCurrency);
        }

        double aToDollars = a.getMoney() / convertionMultiplier(aCurrency);
        double bToDollars = b.getMoney() / convertionMultiplier(bCurrency);

        double total = aToDollars - bToDollars;

        total *= convertionMultiplier(aCurrency);

        return Money(total, aCurrency);
    }

    Money operator*(const Money& m, const double factor) {
       return Money(m.getMoney() * factor, m.getCurrency());
    }

    std::ostream& operator<<(std::ostream& os, const Money& m) {
        os << "$" << m.getMoney() << " " << m.getCurrency();
        return os;
    }

    std::istream& operator>>(std::istream& is, Money& m) {
        char dollarSign;
        double dollarsInput;
        std::string currencyInput;

        // Leemos el '$' y luego el número decimal (ej: 123.45)
        if (is >> dollarSign >> dollarsInput >> currencyInput) {
            if (dollarSign == '$') {
                m = Money(dollarsInput, currencyInput); // Asignamos el nuevo valor redondeado
            }
            else {
                is.setstate(std::ios::failbit); // Marcamos error si no introdujeron el '$'
            }
        }
        return is;
    }
}