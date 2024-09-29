#include <iostream>
#include <fstream>
#include <bitset>
#include <ctime>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace chrono;

void Task2()
{
    int option = 1000;
    const long int size = 10000000;  // Размер std::bitset (10^7 бит)
    bitset<size>* numbers = new bitset<size>;  // Используем std::bitset для хранения битов

    long int input;
    ofstream outfile("sortedList.txt");

    cout << "Enter seven digit numbers one by one (0 to complete):" << endl;
    while (true) {
        cin >> input;
        if (input == 0) {
            break;
        }
        if (input >= size / 10 and input <= 9999999) {
            numbers->set(input - 1, 1);
        }
        else {
            cout << "Only seven digit numbers!" << endl;
        }
    }

    char spam;

    cout << "Need to enter an additional " << option << " seven-digit numbers? (y/n):";
    cin >> spam;

    if (spam == 'y' or spam == 'Y') {
        srand(static_cast<unsigned int>(time(nullptr)));
        for (long int i = option; i > 1; i--) {
            long int random_input = ((size / 10) * (1 + rand() % (8))) + ((rand() % (i + 1)) * (990));
            numbers->set(random_input, 1);
        }
    }

    auto start_time = high_resolution_clock::now();
    for (long int i = 0; i < size; i++) {
        if (numbers->test(i)) {
            outfile << i + 1 << endl;
        }
    }
    auto end_time = high_resolution_clock::now();
    auto exec_time = duration_cast<milliseconds>(end_time - start_time);
    outfile.close();
    cout << "The sorting result was written to a file." << endl;
    cout << "Time spent on execution " << exec_time.count() << " milliseconds." << endl;
}

int main() {
    Task2();
    return 0;
}
