#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

// Función para dividir una cadena por un delimitador
vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(str);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Función para convertir una cadena a long long
long long stringToLongLong(const string& str) {
    long long result = 0;
    bool negative = false;
    size_t start = 0;

    if (str[0] == '-') {
        negative = true;
        start = 1;
    }

    for (size_t i = start; i < str.size(); ++i) {
        if (isdigit(str[i])) {
            result = result * 10 + (str[i] - '0');
        } else {
            throw invalid_argument("Invalid character in string");
        }
    }

    return negative ? -result : result;
}

// Función recursiva para probar todas las combinaciones de operadores
bool tryOperatorsCombinations(const vector<long long>& numbers, long long target, int index, long long currentResult) {
    // Caso base: si hemos usado todos los números, verificar si alcanzamos el objetivo
    if (index == numbers.size()) {
        return currentResult == target;
    }

    // Intentar con el primer número como punto de partida
    if (index == 0) {
        return tryOperatorsCombinations(numbers, target, index + 1, numbers[0]);
    }

    // Intentar con la suma
    if (tryOperatorsCombinations(numbers, target, index + 1, currentResult + numbers[index])) {
        return true;
    }

    // Intentar con la multiplicación
    if (tryOperatorsCombinations(numbers, target, index + 1, currentResult * numbers[index])) {
        return true;
    }

    return false;
}

// Función para verificar si se puede formar el número objetivo con las combinaciones de operadores
bool canFormNumber(long long target, const vector<long long>& numbers) {
    if (numbers.size() < 2) return false;
    return tryOperatorsCombinations(numbers, target, 0, 0);
}

// Función para calcular el resultado total de las ecuaciones válidas
long long checkPossibleFormation(const vector<long long>& leftNumbers, const vector<vector<long long>>& allRightNumbers) {
    long long sum = 0;
    for (size_t i = 0; i < leftNumbers.size(); i++) {
        long long target = leftNumbers[i];
        
        if (canFormNumber(target, allRightNumbers[i])) {
            sum += target;
        }
    }
    return sum;
}

int main() {
    ifstream inputFile("input7");
    string line;

    vector<long long> leftNumbers;
    vector<vector<long long>> allRightNumbers;

    while (getline(inputFile, line)) {
        auto parts = split(line, ':');
        if (parts.size() != 2) {
            cerr << "Formato de entrada inválido" << endl;
            return 1;
        }

        try {
            long long leftNumber = stringToLongLong(parts[0]);
            leftNumbers.push_back(leftNumber);
        } catch (const invalid_argument& e) {
            cerr << "Error de conversión en la parte izquierda: " << parts[0] << endl;
            return 1;
        }

        vector<long long> rightNumbers;
        auto numbers = split(parts[1], ' ');
        for (const auto& num : numbers) {
            try {
                rightNumbers.push_back(stringToLongLong(num));
            } catch (const invalid_argument& e) {
                cerr << "Error de conversión en la parte derecha: " << num << endl;
                return 1;
            }
        }
        allRightNumbers.push_back(rightNumbers);
    }

    inputFile.close();

    long long result = checkPossibleFormation(leftNumbers, allRightNumbers);
    cout << "Resultado total de calibración: " << result << endl;

    return 0;
}