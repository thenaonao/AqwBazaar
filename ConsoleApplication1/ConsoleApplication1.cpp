#include <iostream>
#include <fstream>
#include <string>


struct Vertex {
    int vX,vY,vZ;
    int id;
};

int main()
{
    std::ifstream dataReader;
    std::string Output;
    std::string OutBuffer;
    std::string a,b,c;
    bool isSemiColon = false;

    dataReader.open("Data.MF4", std::ios::out | std::ios::in | std::ios::binary);

    //V(ID, X,Y,Z)
    //T(ID, V1,V2,V3)

    if (dataReader.is_open()) {

        while(std::getline(dataReader, Output)){
            if (Output.find(";") != 0) isSemiColon = true;

            dataReader >> Output;
            std::cout << Output << std::endl;




            if (!isSemiColon) {
                OutBuffer += Output;
            }
            else{
                std::cout << OutBuffer << std::endl;
                OutBuffer = "";
                isSemiColon = false;
            }
        }

        dataReader.close();
    }
    else {
        std::cout << "Error while opening the map data" << std::endl;
        return -1;
    }
}
