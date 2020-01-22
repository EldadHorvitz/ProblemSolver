//
// Created by nizan on 14/01/2020.
//

#include <unistd.h>
#include "MyTestClientHandler.h"
#include "Matrix.h"
#include <algorithm>
#include <sstream>

using namespace std;


void readFromBuffer(string buffer, int numOfComma) {
    std::string delimiter = ",";
    size_t pos = 0;
    std::string token[numOfComma + 1];
    int i = 0;
    while ((pos = buffer.find(delimiter)) != std::string::npos) {
        token[i] = buffer.substr(0, pos);
        buffer.erase(0, pos + delimiter.length());
        i++;
        cout << token[i] << endl;
    }
    int c[numOfComma + 1];
    int j;
    for (j = 0; j <= numOfComma; j++) {
        c[j] = stoi(token[j]);
    }
    int k;
}


void MyTestClientHandler::handleClient(int socket) {
    //reading from client
    char buffer[1024] = {0};
    int numOfComma = 0;
    int firstTime = 1;
    Matrix *matrix1;
    while (1) {
        read(socket, buffer, 1024);
        string token(buffer);
        if (token == "end\r\n" || token == "end\n") {
            break;
        }
        if (firstTime) {
            firstTime = 0;
            numOfComma = std::count(token.begin(), token.end(), ',');
            matrix1 = new Matrix(numOfComma);
        }
        readFromBuffer(token, numOfComma);
        int i;
        for (i = 0; i <= numOfComma; i++) {
            read(socket, buffer, 1024);
            token = "";
            for (i = 0; i < 1024; i++) {
                token = token + buffer[i];
                if (buffer[i] == '\n') {
                    break;
                }
            }
            readFromBuffer(token, numOfComma);
        }
    }
    int matrix[numOfComma][numOfComma];

}


