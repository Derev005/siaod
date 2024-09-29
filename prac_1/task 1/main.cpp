#include <iostream>
#include <bitset>

using namespace std;

void Task_1() {
    cout << "Task 1" << endl;
    int var_1 = 0x75, mask = 0xF000;
    var_1 |= mask;
    cout << "Result (2 CC): " << bitset<sizeof(int) * 8>(var_1) << endl;
    cout << "Result (10 CC): " << var_1 << endl;
    cout << "Result (16 CC): " << hex << var_1 << endl;
}

void Task_2() {
    cout << "Task 2" << endl;
    int var_2;
    cin >> var_2;
    unsigned int mask = 0xFFFFF5F7;
    var_2 &= mask;
    cout << "Result (2 CC): " << bitset<sizeof(int) * 8>(var_2) << endl;
    cout << "Result (10 CC): " << var_2 << endl;
    cout << "Result (16 CC): " << hex << var_2 << endl;
}

void Task_3() {
    cout << "Task 3" << endl;
    int var_3;
    cin >> var_3;
    var_3 = var_3 << 7;
    cout << "Result (2 CC): " << bitset<sizeof(int) * 8>(var_3) << endl;
    cout << "Result (10 CC): " << var_3 << endl;
    cout << "Result (16 CC): " << hex << var_3 << endl;
}

void Task_4() {
    cout << "Task 4" << endl;
    int var_4;
    cin >> var_4;
    var_4 = var_4 >> 8;
    cout << "Result (2 CC): " << bitset<sizeof(int) * 8>(var_4) << endl;
    cout << "Result (10 CC): " << var_4 << endl;
    cout << "Result (16 CC): " << hex << var_4 << endl;
}

void Task_5() {
    cout << "Task 5" << endl;
    int var_5, mask = 0x8000;
    cin >> var_5;
    var_5 |= mask;
    cout << "Result (2 CC): " << bitset<sizeof(int) * 8>(var_5) << endl;
    cout << "Result (10 CC): " << var_5 << endl;
    cout << "Result (16 CC): " << hex << var_5 << endl;
}

int main() {
    Task_1();
    Task_2();
    Task_3();
    Task_4();
    Task_5();
}
