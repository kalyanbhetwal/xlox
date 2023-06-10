#include "TokenType.cpp"
#include <string>

class Token{
    public:
        TokenType type;
        std::string lexeme;
        std::string literal;
        int line;

        Token(TokenType type, const std::string& lexeme, const std::string& literal, int line){
            this->type = type;
            this->lexeme = lexeme;
            this->literal = literal;
            this->line = line;
        }
        std::string toString(){
            return std::to_string(static_cast<int>(type)) + " " + lexeme + " "+ literal;
        }
};