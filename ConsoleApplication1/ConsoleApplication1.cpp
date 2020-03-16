#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::fstream dataReader;
    std::string Output;
    dataReader.open("Data.MF4", std::ios::out | std::ios::in | std::ios::binary);

    if (dataReader.is_open()) {
        for (int i = 0; i < 64; i++) {
            dataReader << i << std::endl;
        }
        dataReader.seekg(0);
        for (int j = 0; j < 64; j++) {
            dataReader >> Output;
            std::cout << Output << std::endl;
        }

        dataReader.close();
    }
    else {
        std::cout << "Error while opening the data" << std::endl;
        return -1;
    }
    //std::cout << "test" << std::endl;
}
