//
// Created by nizan on 14/01/2020.
//

#include <unistd.h>
#include "MyTestClientHandler.h"
#include "Matrix.h"
#include <algorithm>

using namespace std;


void readFromBuffer(string buffer) {
    std::string delimiter = ",";
    size_t pos = 0;
    std::string token[37];
    int i = 0;
    while ((pos = buffer.find(delimiter)) != std::string::npos) {
        token[i] = buffer.substr(0, pos);
        buffer.erase(0, pos + delimiter.length());
        i++;
        cout << token[i] << endl;
    }
    int c = 0;
}


void MyTestClientHandler::handleClient(int socket) {
    //reading from client
    char buffer[1024] = {0};
    int numOfComma = 0;
    string s = "";
    int firstTime = 1;
    Matrix *matrix1;
    while (1) {
        read(socket, buffer, 1024);
        string delimiter = "\n";
        s += buffer;
        size_t pos = 0;
        string token;
        while ((pos = s.find(delimiter)) != string::npos) {
            token = s.substr(0, pos);
            readFromBuffer(token);
            s.erase(0, pos + delimiter.length());
        }
        if (firstTime) {
            firstTime = 0;
            numOfComma = std::count(token.begin(), token.end(), ',');
            matrix1 = new Matrix(numOfComma);
        }
        if (token == "end") {
            break;
        }

    }
    int matrix[numOfComma][numOfComma];

}


