#include <iostream> 
#include <fstream> 
#include <windows.h> 
using namespace std; 

struct Person 
{ 
    string name; 
    int first_mark; 
    int second_mark; 
    int third_mark; 
    int forth_mark; 
} A; 

void main() { 
    setlocale(LC_ALL, "rus"); 
    
    const char* nameA = "C:/Users/s0195879/source/repos/file/ANSWER.bin"; 
    ofstream fR; 
    ifstream fA; 
    fstream fN; 
    
    const char* nameN = "C:/Users/s0195879/source/repos/file/REQUEST.bin"; 
    long pred_size; 
    int answer; 
    
    while (true) 
    { 
        cout << "Введите имя: "; 
        cin >> A.name; 
        cout << "Введите 4 оценки (каждая от 0 до 100):" << endl; 
        
        cout << "Первая оценка: ";
        cin >> A.first_mark;
        cout << "Вторая оценка: ";
        cin >> A.second_mark;
        cout << "Третья оценка: ";
        cin >> A.third_mark;
        cout << "Четвертая оценка: ";
        cin >> A.forth_mark;
        
        // Проверка корректности введенных данных
        if (A.first_mark < 0 || A.first_mark > 100 ||
            A.second_mark < 0 || A.second_mark > 100 ||
            A.third_mark < 0 || A.third_mark > 100 ||
            A.forth_mark < 0 || A.forth_mark > 100) {
            cout << "Ошибка: все оценки должны быть в диапазоне от 0 до 100!" << endl;
            continue;
        }
        
        string s = "C:/Users/s0195879/source/repos/file/" + A.name + ".bin"; 
        const char* nameR = s.c_str(); 
        
        fR.open(nameR, ios::app | ios::binary); 
        fR.write((char*)&A, sizeof(A)); 
        fR.close(); 
        
        fN.open(nameN, ios::app | ios::binary); 
        fN.write((char*)&A.name, sizeof(A.name)); 
        fN.close(); 
        
        fA.open(nameR, ios::binary); 
        fA.seekg(0, ios::end); 
        pred_size = fA.tellg(); 
        
        while (pred_size >= fA.tellg()) 
        { 
            Sleep(100); 
            fA.seekg(0, ios::end); 
        } 
        
        fA.seekg(pred_size, ios::beg); 
        fA.read((char*)&answer, sizeof(answer)); 
        fA.close(); 
        
        cout << "Результат для студента " << A.name << ":" << endl;
        cout << "Сумма баллов: " << (A.first_mark + A.second_mark + A.third_mark + A.forth_mark) << endl;
        
        switch (answer) { 
            case 2: {cout << "Оценка: 2 (неудовлетворительно)"; break; } 
            case 3: {cout << "Оценка: 3 (удовлетворительно)"; break; } 
            case 4: {cout << "Оценка: 4 (хорошо)"; break; } 
            case 5: {cout << "Оценка: 5 (отлично)"; break; } 
            default: {cout << "Ошибка вычисления оценки"; break; }
        } 
        cout << endl << "------------------------" << endl; 
    } 
}