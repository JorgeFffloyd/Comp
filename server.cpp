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
}B; 

int answer; 
long size_pred; 
long size_pred_name; 

int calculateGrade(int score) {
    if (score >= 0 && score <= 49) return 2;   // неудовлетворительно
    if (score >= 50 && score <= 74) return 3;  // удовлетворительно
    if (score >= 75 && score <= 89) return 4;  // хорошо
    if (score >= 90 && score <= 100) return 5; // отлично
    return 2; // по умолчанию неудовлетворительно
}

int main() { 
    ifstream fR; 
    ofstream fA; 
    ifstream fN; 
    setlocale(LC_ALL, "rus"); 
    
    const char* nameN = "C:/Users/s0195879/source/repos/file/REQUEST.bin"; 
    const char* nameA = "C:/Users/s0195879/source/repos/file/ANSWER.bin"; 
    
    fN.open(nameN, ios::binary); 
    fN.seekg(0, ios::end); 
    size_pred_name = fN.tellg(); 
    fN.close(); 
    
    cout << "Server is working" << endl; 
    
    while (true) 
    { 
        fN.open(nameN, ios::binary); 
        fN.seekg(0, ios::end); 
        
        while (size_pred_name >= fN.tellg()) 
        { 
            Sleep(100); 
            fN.seekg(0, ios::end); 
        } 
        
        fN.seekg(size_pred_name, ios::beg); 
        fN.read((char*)&B.name, sizeof(B.name)); 
        size_pred_name = fN.tellg(); 
        fN.close(); 
        
        string s = "C:/Users/s0195879/source/repos/file/" + B.name + ".bin"; 
        const char* nameR = s.c_str(); 
        
        fR.open(nameR, ios::binary); 
        fR.seekg(ios::beg, 0); 
        fR.read((char*)&B, sizeof(B)); 
        
        // Рассчитываем общую сумму баллов
        int total_score = B.first_mark + B.second_mark + B.third_mark + B.forth_mark;
        
        // Определяем оценку по критериям
        answer = calculateGrade(total_score);
        
        fR.close(); 
        
        cout << "Сервер обработал данные студента " << B.name << endl;
        cout << "Баллы: " << B.first_mark << ", " << B.second_mark << ", " 
             << B.third_mark << ", " << B.forth_mark << endl;
        cout << "Сумма баллов: " << total_score << ", Оценка: " << answer << endl;
        
        fA.open(nameR, ios::binary | ios::app); 
        fA.write((char*)&answer, sizeof(answer)); 
        fA.close(); 
    } 
}