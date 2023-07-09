#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void defineAst(const string& outputDir, const string& baseName, const vector<string>& types) {
    string path = outputDir + "/" + baseName + ".cpp";
    ofstream output(path);
    if (!output) {
        cerr << "Unable to create file: " << path << endl;
        return;
    }

    output << "#include \"" << baseName << ".hpp\"" << endl << endl;
    output << "using namespace std;" << endl << endl;
    output << "class " << baseName << " {" << endl;
    output << "public:" << endl;

    output << "};" << endl << endl;

    output.close();
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: generate_ast <output directory>" << endl;
        return 64;
    }

    string outputDir = argv[1];
    vector<string> types = {
        "Binary   : Expr* left, Token* op, Expr* right",
        "Grouping : Expr* expression",
        "Literal  : Object* value",
        "Unary    : Token* op, Expr* right"
    };

    defineAst(outputDir, "Expr", types);
    return 0;
}