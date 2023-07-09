#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: generate_ast <output directory>" << endl;
        return 64;
    }

    string outputDir = argv[1];
    vector<string> expressions = {
        "Binary   : Expr* left, Token* op, Expr* right",
        "Grouping : Expr* expression",
        "Literal  : Object* value",
        "Unary    : Token* op, Expr* right"
    };
    return 0;
}