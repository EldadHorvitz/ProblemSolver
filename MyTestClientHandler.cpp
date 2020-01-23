//
// Created by nizan on 14/01/2020.
//

#include <unistd.h>
#include "MyTestClientHandler.h"
#include "Matrix.h"
#include "Problem.h"
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

}


void MyTestClientHandler::handleClient(int socket) {
    //reading from client
    Problem *problem = new Problem();
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
        numOfComma = std::count(token.begin(), token.end(), ',');
        if (numOfComma > 1) {
            problem->insertLine(token);
        } else if (numOfComma == 1) {
            if (firstTime) {
                firstTime = 0;
            } else {

            }
        }
    }

}


