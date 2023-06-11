#include <string>
#include "Token.hpp"

Token::Token(TokenType type, const std::string& lexeme, const std::string& literal, int line){
            this->type = type;
            this->lexeme = lexeme;
            this->literal = literal;
            this->line = line;
        }
std::string Token::toString(){
            return std::to_string(static_cast<int>(type)) + " " + lexeme + " "+ literal;
        }