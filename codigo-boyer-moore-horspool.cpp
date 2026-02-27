#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define ALPHABET_SIZE 256

// Função que constrói a tabela de deslocamento 
void buildShiftTable(const string& pattern, vector<int>& shiftTable) {
    int m = pattern.length();

    // Inicializa todos os caracteres com valor m
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        shiftTable[i] = m;
    }

    // Para cada caractere do padrão, define o deslocamento como m - 1 - i
    for (int i = 0; i < m - 1; i++) {
        shiftTable[(unsigned char)pattern[i]] = m - 1 - i;
    }
}

// Implementação do BMH
void boyerMooreHorspool(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();

    if (m > n) {
        cout << "Padrão maior que o texto.\n";
        return;
    }

    vector<int> shiftTable(ALPHABET_SIZE);

    // Cria a tabela de deslocamento
    buildShiftTable(pattern, shiftTable);

    int i = 0;  // posição atual no texto

    // Percorre o texto enquanto ainda é possível alinhar o padrão
    while (i <= n - m) {

        int j = m - 1; 
        
        while (j >= 0 && pattern[j] == text[i + j]) {
            j--;
        }

        if (j < 0) {
            cout << "Padrão encontrado na posição: " << i << endl;
        }

        i += shiftTable[(unsigned char)text[i + m - 1]];
    }
}

int main() {
    string text;
    string pattern;

    cout << "Digite o texto: ";
    getline(cin, text);

    cout << "Digite o padrao: ";
    getline(cin, pattern);

    boyerMooreHorspool(text, pattern);

    return 0;
}