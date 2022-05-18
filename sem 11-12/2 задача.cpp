#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::cout << "В моем txt 22 строки." << std::endl;
    // ifstream для размера строки
    std::ifstream file;
    file.open("3.txt");
    if (file.is_open()) {std::cout << "Файл открылся." << std::endl;}

    // buffer
    char* buffer = new char[101];
       // buffer[100] = 0;
    file.getline(buffer,100,'\n');
    std::cout << "// Первая строка: " << buffer << "\n" << "// Ее размер: " << std::strlen(buffer) << std::endl;
    int length = std::strlen(buffer)+1;
    delete [] buffer;


    // start
    double str_num;
    std::cout << "Введите номер искомой строки: ";
    std::cin >> str_num;
    if (str_num == 1) {str_num = 1.0/length + 1;}
    std::fstream F;
    // input + output
    F.open("3.txt", std::ios::in | std::ios::out);
    F.seekg((str_num-1)*length-1, std::ios::beg);


    // buffer2
    char* buffer2 = new char [length];
    F.read(buffer2,length);
    F.close();
    std::cout.write(buffer2,length);
    delete[] buffer2;

    return 0;
}