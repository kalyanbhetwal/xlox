//#include "Lox.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

void run(const std::string& sourceCode){

}
// take file as input and run it
void runFile(const std::string& filePath){
    std::ifstream file(filePath, std::ios::binary);
    if(!file){
        std::cerr << "Failed to open an file: "<<std::endl;
        return;
    }
    std::ostringstream oss;
    oss << file.rdbuf();
    std::string sourceCode = oss.str();
    file.close();
    run(sourceCode);
    
}
//run in REPL mode
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

