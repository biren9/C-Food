cmake_minimum_required(VERSION 3.6.3)
project(C-Food)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        Automat/includes/Automat.h
        Automat/src/Automat.cpp
        Automat/src/TestAutomat.cpp
        #Buffer/includes/Buffer.h
        #Buffer/src/Buffer.cpp
        #Buffer/src/TestBuffer.cpp
        #Scanner/includes/Scanner.h
        #Scanner/src/Scanner.cpp
        #Scanner/src/TestScanner.cpp
        #Symboltable/includes/Symboltable.h
        #Symboltable/src/Symboltable.cpp
        #Symboltable/src/TestSymboltable.cpp
        )

add_executable(C-Food ${SOURCE_FILES})