#include <iostream>
#include <fstream>
#include <string>


struct Vertex {
    int vX,vY,vZ;
};

int main()
{
    std::fstream dataReader;
    std::string Output;
    dataReader.open("Data.MF4", std::ios::out | std::ios::in | std::ios::binary);
    //V(ID, X,Y,Z)
    //T(ID, V1,V2,V3)
    if (dataReader.is_open()) {
        /*dataReader << "NAME" << std::endl;
        dataReader << "AUTHOR" << std::endl;
        dataReader << " " << std::endl;
        dataReader << "Vertex:" << std::endl;
        for (int i = 0; i < 64; i++) {
            dataReader << "v" << i << std::endl;
        }
        dataReader << "EndVertex" << std::endl;*/
        dataReader.seekg(0);
        while(dataReader.eof()==0){
            dataReader >> Output;
            std::cout << Output << std::endl;
        }

        dataReader.close();
    }
    else {
        std::cout << "Error while opening the data" << std::endl;
        return -1;
    }
}
