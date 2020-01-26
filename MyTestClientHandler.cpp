//
// Created by nizan on 14/01/2020.
//

#include <unistd.h>
#include "MyTestClientHandler.h"
#include "Problem.h"
#include "CasheManager.h"
#include "Solver.h"
#include "OA.h"
#include <algorithm>
#include <sstream>
#include <thread>

using namespace std;


void readFromClient(int socket) {


}


void MyTestClientHandler::handleClient(int socket) {
    //reading from client
    Problem *problem = new Problem();
    string solution;
    char buffer[1024] = {0};
    int numOfComma = 0;
    int firstTime = 1;
    string delimiter = "\n";
    string token;
    string s = "";


    while (1) {
        read(socket, buffer, 1024);
        s += buffer;
        size_t pos = 0;
        while ((pos = s.find('\n')) != string::npos) {
            token = s.substr(0, pos);
            if (token == "end\r\n" || token == "end\n" || token == "end\r") {
                break;
            }
            numOfComma = std::count(token.begin(), token.end(), ',');
            if (numOfComma > 1) {
                problem->insertLine(token);
            } else if (numOfComma == 1) {
                if (firstTime) {
                    firstTime = 0;
                    problem->insertToState();
                    problem->insertStartPoint(token);
                } else {
                    problem->insertEndPoint(token);
                }
            }
            s.erase(0, pos + delimiter.length());
        }
        if (token == "end\r\n" || token == "end\n" || token == "end\r") {
            break;
        }
        // token = "";
    }


/*
CasheManager<Problem*,string>* cm;

   cm=new CasheManager<Problem*,string> ();

   if (cm->count(problem)){
       solution=cm->get(problem);
   }else{
       Solver<Problem*,string> *so;
       so=new OA<Problem*,string>();
       solution=so->solve(problem);
       cm->insert(problem,solution);
   }*/
    Solver<Problem, string> *so;
    so = new OA<Problem, string>();
    solution = so->solve(problem);
    cout << solution <<
         endl;
}


