//#include "Lox.h"
#include <iostream>
#include <string>

void runFile(const std::string& filePath){
    
}

void runPrompt(){

}

int main(int argc, char* argv[]) {
    if(argc > 2){
        std::cout <<"Usage: xlox [script]"<<std::endl;
        return 64;
    }else if(argc ==2){
        runFile(argv[1]);
    }else{
        runPrompt();
    }
}

