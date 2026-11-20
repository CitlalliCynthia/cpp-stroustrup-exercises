#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

/*
13. Write a program to “clean up” a text file for use in a word query program; 
that is, replace punctuation with whitespace,put words into lower case, replace 
don’t with do not (etc.), and remove plurals (e.g., ships becomes ship). Don’t 
be too ambitious. For example, it is hard to determine plurals in general, so 
just remove an s if you find both ship and ships. Use that program on a real-
world text file with at least 5000 words (e.g., a research paper).
*/


// Reemplaza todas las ocurrencias de 'from' por 'to' en un string
void replace_all(std::string& str, const std::string& from, const std::string& to) {
    if (from.empty()) return;
    std::size_t pos = 0;
    while ((pos = str.find(from, pos)) != std::string::npos) {
        str.replace(pos, from.length(), to);
        pos += to.length();
    }
}

// Expande contracciones comunes en inglés (debe llamarse ya en minúsculas)
void expand_contractions(std::string& text) {
    const std::vector<std::pair<std::string, std::string>> contractions = {
        {"don't", "do not"},     {"doesn't", "does not"}, {"didn't", "did not"},
        {"can't", "cannot"},     {"won't", "will not"},     {"wouldn't", "would not"},
        {"shouldn't", "should not"}, {"couldn't", "could not"},
        {"isn't", "is not"},     {"aren't", "are not"},     {"wasn't", "was not"},
        {"weren't", "were not"}, {"haven't", "have not"},   {"hasn't", "has not"},
        {"hadn't", "had not"},   {"it's", "it is"},         {"that's", "that is"},
        {"what's", "what is"},   {"there's", "there is"},   {"i'm", "i am"},
        {"you're", "you are"},   {"we're", "we are"},       {"they're", "they are"},
        {"i've", "i have"},      {"you've", "you have"},    {"we've", "we have"},
        {"they've", "they have"},{"i'll", "i will"},        {"you'll", "you will"},
        {"we'll", "we will"},    {"they'll", "they will"}
    };

    for (const auto& pair : contractions) {
        replace_all(text, pair.first, pair.second);
    }
}

// Limpia el texto: minúsculas, contracciones, puntuación y plurales simples
std::vector<std::string> clean_text(std::string text) {
    // 1. Convertir todo a minúsculas
    for (char& c : text) {
        c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    }

    // 2. Expandir contracciones antes de eliminar los apóstrofes
    expand_contractions(text);

    // 3. Reemplazar puntuación con espacios en blanco
    for (char& c : text) {
        if (std::ispunct(static_cast<unsigned char>(c))) {
            c = ' ';
        }
    }

    // 4. Extraer palabras y registrar el vocabulario único
    std::stringstream ss(text);
    std::vector<std::string> words;
    std::set<std::string> vocabulary;

    for (std::string w; ss >> w; ) {
        words.push_back(w);
        vocabulary.insert(w);
    }

    // 5. Eliminar plurales simples (si existe "ship" y "ships", cambiar "ships" -> "ship")
    for (std::string& w : words) {
        if (w.size() > 1 && w.back() == 's') {
            std::string singular = w.substr(0, w.size() - 1);
            if (vocabulary.find(singular) != vocabulary.end()) {
                w = singular;
            }
        }
    }

    return words;
}

int main() {
    // Crear un archivo de prueba pequeño
    {
        std::ofstream sample("input.txt");
        sample << "Don't worry! Ships sail across the ocean, and one big ship "
            << "can't sink easily. They're fast ships, aren't they?\n";
    }

    std::ifstream ifs("input.txt");
    if (!ifs) {
        std::cerr << "No se pudo abrir input.txt\n";
        return 1;
    }

    // Leer todo el contenido del archivo en un string
    std::stringstream buffer;
    buffer << ifs.rdbuf();

    std::vector<std::string> cleaned_words = clean_text(buffer.str());

    // Guardar el resultado limpio en otro archivo y mostrarlo en consola
    std::ofstream ofs("cleaned_output.txt");
    for (std::size_t i = 0; i < cleaned_words.size(); ++i) {
        ofs << cleaned_words[i] << (i + 1 < cleaned_words.size() ? " " : "\n");
        std::cout << cleaned_words[i] << '\n';
    }

    return 0;
}