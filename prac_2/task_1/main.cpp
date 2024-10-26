#include "my_class.h"
#include <stdio.h>
inline void mainMenu() {
    cout << "0 - Main menu\n" << "1 - Output the contents of a text file\n" << "2 - Adding a new entry to the end of the file\n" <<
        "3 - Output of a number by ordinal number\n" << "4 - Number of numbers in the file\n" <<
            "5 - Task from the option\n" << "6 - EXIT\n" << "Your choice: ";
}
inline void brbrbr(fstream &file) {
    file.clear();
    file.seekg(0);
}
int main() {
    fstream file; string fileName; cout << "Enter file name: "; cin >> fileName;
    ofstream file1; file.open(fileName + ".txt"); file1.close();
    if (file.open(fileName + ".txt", ios::in | ios::out | ios::app); file.is_open()) {
        brbrbr(file);
        int choise;
        bool flag = true;
        mainMenu();
        cin >> choise;
        while (flag) {
            system("cls");
            switch (choise) {
                case 0: {
                    mainMenu();
                    break;
                }
                case 1: {
                    // вывод содержимого текстового файла на экран;
                    cout << "Output the contents of a text file\n---\n" << fileOutput(file) << "\n---\n";
                    break;
                }
                case 2: {
                    //добавление новой записи в конец файла;
                    cout << "Adding a new entry to the end of the file\n---\n" << fileRecord(file) << "\n---\n";
                    break;
                }
                case 3: {
                    //вывод числа по порядковому номеру;
                    int index;
                    cout << "Output of a number by ordinal number\n---\n";
                    cout << "Enter index: "; cin >> index;
                    cout << fileReturn(file, index) << "\n---\n";
                    break;
                }
                case 4: {
                    //количество числе в файле;
                    cout << "Number of numbers in the file\n---\nNumber of numbers in the file: " <<
                        fileNumber(file) << "\n---\n";
                    break;
                }
                case 5: {
                    //задание из варианта;
                    cout << "Task from the option\n---\n"; task_27(file); cout << "\n---\n";
                    break;
                }
                default: {
                    cout << "EXIT";
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << "Your choice: "; cin >> choise;
            }
            brbrbr(file);
        }
    }
    else cout << "ERROR";
    return 0;
}
