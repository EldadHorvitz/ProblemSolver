cmake_minimum_required(VERSION 3.15)
project(ex4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(ex4 main.cpp Server.cpp Server.h Solver.cpp Solver.h ClientHandler.cpp ClientHandler.h CasheManager.cpp CasheManager.h MySerialServer.cpp MySerialServer.h MyTestClientHandler.cpp MyTestClientHandler.h MyParallelServer.cpp MyParallelServer.h Matrix.cpp Matrix.h StringReverser.cpp StringReverser.h Searchable.h Searcher.h)
