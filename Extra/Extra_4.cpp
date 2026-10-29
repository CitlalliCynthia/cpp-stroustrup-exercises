#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include <stdexcept>

/*
El Desafío : "El Sistema de Reportes Automatizado"

Imagina que trabajas en una empresa que audita sistemas de archivos y necesitas procesar un archivo de texto llamado datos.txt.
1. Crea una clase abstracta llamada Reporte con un método virtual puro : virtual void generar(const std::string & linea) = 0; y su respectivo destructor virtual.
2. Crea tres clases hijas :
• ReporteMayusculas : Toma cada línea del archivo, la convierte completamente a mayúsculas y la imprime en pantalla.
• ReporteContadorPalabras : Cuenta cuántas palabras tiene cada línea y muestra el número con un formato ordenado.
• ReporteEstadisticas : Cuenta cuántas letras del abecedario hay en total por línea.
3. En el main :
• Abre un archivo datos.txt usando std::ifstream.
• Crea un std::vector<Reporte*>(en el Stack) que guarde punteros a los tres tipos de reportes creados en el Heap con new.
• Lee el archivo línea por línea con un bucle.Por cada línea leída, recorre tu vector de reportes con un for y mándales esa línea para que cada reporte haga su magia de forma polimórfica.
• Al terminar, limpia la memoria del Heap recorriendo el vector con delete.
*/

class Report {

public:

	virtual void generate(const std::string& line) = 0;
	virtual ~Report() {}
};

class UpperReport : public Report {

public:
	void generate(const std::string& line) {
		std::string temp = "";
		for (size_t i = 0; i < line.size(); i++) {
			temp += toupper(line[i]);
		}

		std::cout << "Uppercase: " << temp << "\n";
	}

};

class WordCountReport : public Report {

public:
	void generate(const std::string& line) {
		int count = 0;
		std::istringstream ss(line);

		for (std::string temp; ss >> temp;) {
			count++;
		}

		std::cout << "Word count is: " << count << "\n";
	}
};

class StatisticsReport : public Report {

public:
	void generate(const std::string & line) {
		int counter = 0;
		for (size_t i = 0; i < line.size(); i++) {
			if(isalpha(static_cast<unsigned char>(line[i])))
				counter++;
		}

		std::cout << "The count of letters is: " << counter << "\n";
	}
};

int main() {

	std::vector<Report*> reports;

	reports.push_back(new UpperReport());
	reports.push_back(new WordCountReport());
	reports.push_back(new StatisticsReport());

	try {
		std::ifstream ist("input.txt");
		if (!ist) throw std::runtime_error("Can't open input file.");

		for (std::string temp; std::getline(ist, temp);) {
			for (size_t i = 0; i < reports.size(); i++) {
				reports[i]->generate(temp);
			}
			std::cout << "\n";
		}
	}
	catch (const std::runtime_error& e) {
		std::cerr << "Error: " << e.what();
	}

	for (size_t i = 0; i < reports.size(); i++) {
		delete reports[i];
	}

	reports.clear();
	
	return 0;
}