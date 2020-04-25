#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <locale.h>

using namespace std;

void decimalToBinary();
void binaryToDecimal();

int main () {
    int choice;

    setlocale(LC_ALL, "Portuguese");

    cout << "--------------------\n";
    cout << "Calculadora de Bases\n";
    cout << "--------------------\n\n";

    cout << "O que voc� quer calcular?\n";
    cout << "1 - decimal para bin�rio;\n";
    cout << "2 - bin�rio para decimal;\n\n";
    cout << "Digite sua escolha: ";
    cin >> choice;

    system("clear||cls");

    if (!cin.good()) {
        cout << "\n\n***S�o aceitos apenas n�meros!!\n\n";
        return 0;
    }

    if (choice == 1) {
        decimalToBinary();
    } else if (choice == 2) {
        binaryToDecimal();
    } else {
        cout << "\n\nFavor digitar uma op��o v�lida!\n\n";
        main();
    }

    return 0;
}

void binaryToDecimal() {
    int number, aux, decimal = 0, base = 1, showResult = 1;

    cout << "\n\n2 - bin�rio para decimal\n";
    cout << "------------------------\n\n";
    cout << "Informe o n�mero bin�rio: ";
    cin >> number;

    if (!cin.good()) {
        system("clear||cls");
        cout << "\n\n***S�o aceitos apenas n�meros!!\n\n";
        return;
    }

    while (number) {
        aux = number % 10;
        number = number / 10;
        decimal += aux * base;
        base *= 2;
        if (aux != 0 && aux != 1) {
            number = 0;
            showResult = 0;
            system("cls");
            cout << "\n\n***Informe um bin�rio v�lido!!\n";
            binaryToDecimal();
        }
    }

    if (showResult) {
        cout << "\n\nO resultado em decimal �: " << decimal << "\n\n\n";
    }
};

void decimalToBinary() {
    int number = 0;
    string binaryStrNumber = "";

    cout << "\n\n1 - decimal para bin�rio\n";
    cout << "------------------------\n\n";
    cout << "Informe o n�mero decimal: ";
    cin >> number;

    if (!cin.good()) {
        system("clear||cls");
        cout << "\n\n***S�o aceitos apenas n�meros!!\n\n";
        return;
    }

    if (number == 0) {
        system("cls");
        cout << "\n\n***Informe um n�mero v�lido!!\n";
        decimalToBinary();
    } else {
        while (number > 0) {
            int bit = floor(number % 2);
            binaryStrNumber = to_string(bit) + binaryStrNumber;
            number = floor(number / 2);
        }

        cout << "\n\nO resultado em bin�rio �: " << binaryStrNumber << "\n\n\n";
    }
};
