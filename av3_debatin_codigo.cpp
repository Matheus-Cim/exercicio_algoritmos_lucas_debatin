// Trabalho de Algoritmos
// Professor: Lucas Debatin
// Disciplina: Introdução à Ciência da Computação - Univali

#include <iostream>
#include <string>
using namespace std;

float calcularMedia(float n1, float n2, float n3) {
    return (n1 + n2 + n3) / 3;
}

int main() {

    string nomes[5];
    float notas[5][3];
    float medias[5];
    int quantidade;

    do {
        cout << "Quantos alunos? (0 a 5): ";
        cin >> quantidade;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            quantidade = -1;
        }

    } while (quantidade < 0 || quantidade > 5);

    cin.ignore();

    for (int i = 0; i < quantidade; i++) {

        cout << "\nAluno " << i + 1 << endl;

        cout << "Nome: ";
        getline(cin, nomes[i]);

        for (int j = 0; j < 3; j++) {

            do {
                cout << "Nota " << j + 1 << ": ";
                cin >> notas[i][j];

                if (cin.fail()) {
                    cout << "Digite um numero valido!" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    notas[i][j] = -1;
                } else if (notas[i][j] < 0 || notas[i][j] > 10) {
                    cout << "Nota invalida! Digite um valor entre 0 e 10." << endl;
                    cin.ignore(1000, '\n');
                }

            } while (notas[i][j] < 0 || notas[i][j] > 10);
        }

        medias[i] = calcularMedia(
            notas[i][0],
            notas[i][1],
            notas[i][2]
        );

        cin.ignore();
    }

    cout << "\n----------------------------------------" << endl;
    cout << "Nome / N1 / N2 / N3 / Media / Situacao" << endl;
    cout << "----------------------------------------" << endl;

    for (int i = 0; i < quantidade; i++) {

        cout << nomes[i] << " / "
             << notas[i][0] << " / "
             << notas[i][1] << " / "
             << notas[i][2] << " / "
             << medias[i] << " / ";

        if (medias[i] >= 7)
            cout << "Aprovado" << endl;
        else
            cout << "Reprovado" << endl;
    }

    if (quantidade > 0) {

        int melhor = 0;

        for (int i = 1; i < quantidade; i++) {
            if (medias[i] > medias[melhor]) {
                melhor = i;
            }
        }

        cout << "\nMelhor aluno: " << nomes[melhor] << " Media: "<< medias[melhor] << endl;
    }

    return 0;
}
