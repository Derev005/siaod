#include "my_class.h"
#include <stdio.h>
int main() {
    if (fstream file("test.txt"); file.is_open()) {
        int choise;
        bool flag = true;
        cout << "0 - Main menu\n" << "1 - Output the contents of a text file\n" << "2 - Adding a new entry to the end of the file\n" <<
            "3 - Adding a new entry to the end of the file\n" << "4 - Number of numbers in the file\n" <<
                "5 - Task from the option\n" << "6 - EXIT\n" << "Your choice: ";
        cin >> choise;
        while (flag) {
            system("cls");
            switch (choise) {
                case 0: {
                    cout << "0 - Main menu\n" << "1 - Output the contents of a text file\n" << "2 - Adding a new entry to the end of the file\n" <<
                        "3 - Adding a new entry to the end of the file\n" << "4 - Number of numbers in the file\n" <<
                            "5 - Task from the option\n" << "6 - EXIT\n" << "Your choice: "; break;
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
        }
    }
    else cout << "ERROR";
    return 0;
}
