//
// Created by Kirill on 10/25/2024.
//
#ifndef MY_CLASS_H
#define MY_CLASS_H

#include <iostream>
#include <fstream>
#include <ranges>
#include <string>
#include <vector>

using namespace std;

//проверка char == int
inline bool chek(const char ch) {
    if (ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5'
        || ch == '6' || ch == '7' || ch == '8' || ch == '9' || ch == '0') return true;
    return false;
}

//возврат содержимого текстового файла
inline string fileOutput(fstream &file) {
    string readline;
    for (string line; getline(file, line);) { readline += line + "\n"; }
    return readline;
}

//добавление новой записи в конец файла
inline string fileRecord(fstream &file) {
    file.clear();
    file.seekp(0, ios::end);
    string line, readline;
    cout << "Enter a string of numbers, to complete enter (exit):\n";
    while (true) {
        getline(cin, line);
        if (line == "exit") {
            break;
        }
        readline += line + "\n";
    }
    file << readline;
    return "The recording was successful\n";
}


//прочитать значение числа, указав его порядковый номер в файле, и вернуть его значение при успешном выполнении и код
//завершения если номер превышает количество чисел в файле
inline int fileReturn(fstream &file, const int &nubmer) {
    int number1 = 0;
    string e = "0", line;
    while (getline(file, line)) {
        int q = 0, index = -1;
        for (const char i : line) {
            index++;
            if (chek(i)) q++;
            else q = 0;
            if (q == 1) number1++;
            if (number1 == nubmer) {
                for (int j = index; j < line.size(); j++) {
                    if (chek(line[j])) e += line[j];
                    else break;
                }
                return stoi(e);
            }
        }
    }
    cout << "error";
    return -1;
}

//определить количество чисел в файле
inline int fileNumber(fstream &file) {
    int number = 0;
    string line;
    while (getline(file, line)) {
        int q = 0;
        for (const char i : line) {
            if (chek(i)) q++;
            else q = 0;
            if (q == 1) number++;
        }
    }
    return number;
}

//задание из индивидуального варианта
inline void task_27(fstream &file) {
    string line;
    vector <int> even, odd;
    while (getline(file, line)) {
        int q = 0, index = -1;
        for (const char i : line) {
            index++; string e = "0";
            if (chek(i)) q++;
            else q = 0;
            if (q == 1) {
                for (int j = index; j < line.size(); j++) {
                    if (chek(line[j])) e += line[j];
                    else break;
                }
                if (int count = stoi(e); count % 2 == 0) {
                    even.push_back(count);
                }
                else odd.push_back(count);
            }
        }
    }
    ofstream file1; file.open("task_27.txt"); file1.close();
    if (fstream file_task("task_27.txt", ios::in | ios::out | ios::app); file_task.is_open()) {
        file_task << even.size() << ' '; cout << even.size() << ' ';
        for (const int i : even) { file_task << i << ' '; cout << i << ' '; }
        file_task << '\n' << odd.size() << ' '; cout << '\n' << odd.size() << ' ';
        for (const int i : odd) { file_task << i << ' '; cout << i << ' '; }
        file_task.close();
    }
    else cout << "error";
}
#endif //MY_CLASS_H
