#include "Lox.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

void run(const std::string& sourceCode){

    // Indicate an error in the exit code.
    if(hadError)return;


}

void report(int line, const std::string& where, const std::string& message){
    std::cout << "[line " << line << "] Error" << where + ": " << message <<std::endl;

}

//error handling
void error(int line, const std::string& message){
    report(line, "", message);
    hadError = true;
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
    std::string line;
    for(;;){
        std::cout << "> ";
        std::getline(std::cin, line);
    if(std::cin.eof()){
        break;
    }
    run(line);
    }

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

