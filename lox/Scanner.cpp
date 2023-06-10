#include <iostream>
#include <string>
#include <vector>
#include "Token.cpp"

class Scanner{
    private:
        std::string source;
        std::vector<Token> tokens;
        int start;
        int current ;
        int line ;
    public:
        Scanner(const std::string& source): source(source), start(0), current(0), line(1){}

        std::vector<Token> scanTokens(){
            while(!isAtEnd()){
                start = current;
                scanToken();
            }
              tokens.push_back(Token(END_OF_FILE,"","",line));
              return tokens;
        }
        bool isAtEnd(){
            return current >= source.length();
        }
        void scanToken() {
            char c = advance();
            switch (c) {
                case '(': addToken(LEFT_PAREN); break;
                case ')': addToken(RIGHT_PAREN); break;
                case '{': addToken(LEFT_BRACE); break;
                case '}': addToken(RIGHT_BRACE); break;
                case ',': addToken(COMMA); break;
                case '.': addToken(DOT); break;
                case '-': addToken(MINUS); break;
                case '+': addToken(PLUS); break;
                case ';': addToken(SEMICOLON); break;
                case '*': addToken(STAR); break;
                case '!': addToken(match('=') ? BANG_EQUAL : BANG); break;
                case '=': addToken(match('=') ? EQUAL_EQUAL : EQUAL); break;
                case '<': addToken(match('=') ? LESS_EQUAL : LESS); break;
                case '>': addToken(match('=') ? GREATER_EQUAL : GREATER); break;
                case '/': 
                    if (match('/')) {
                    // A comment goes until the end of the line.
                        while(peek() != '\n' && !isAtEnd()) advance();
                    } else {
                        addToken(SLASH);
                    }
                case ' ':
                case '\r':
                case '\t':
                    // Ignore whitespace.
                break;
                case '\n':
                    line++;
                break;
                case '"': string(); break;

                default: std::cout <<"error" <<std::endl;//error(line,"Unexpected character."); break;
            }
        }

        void string() {
                while (peek() != '"' && !isAtEnd()) {
                    if (peek() == '\n') line++;
                    advance();
                }

                if (isAtEnd()) {
                    std::cout <<"error unterminated string."<<std::endl;
                   // error(line, "Unterminated string.");
                    return;
                }

                // The closing ".
                advance();

                // Trim the surrounding quotes.
                std::string value = source.substr(start + 1, current - start - 2);
                addToken(STRING, value);
            }
        bool match(char expected) {
            if (isAtEnd()) return false;
            if (source[current] != expected) return false;

            current++;
            return true;
        }
        char peek() {
            if (isAtEnd()) return '\0';
            return source[current];
        }
        char advance() {
                return source[current++];
        }

        void addToken(TokenType type) {
                addToken(type, "");
        }

        void addToken(TokenType type, const std::string& literal) {
                std::string text = source.substr(start, current - start);
                tokens.push_back(Token(type, text, literal, line));
        }
};