#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Scanner.hpp"

const std::map<std::string, TokenType> Scanner::keywords;
Scanner::Scanner(const std::string& source): source(source), start(0), current(0), line(1){};
        std::vector<Token> Scanner::scanTokens(){
            while(!isAtEnd()){
                start = current;
                scanToken();
            }
              tokens.push_back(Token(END_OF_FILE,"","",line));
              return tokens;
        }
bool Scanner::isAtEnd(){
            return current >= source.length();
        }
void Scanner::scanToken() {
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
                //handle strings
                case '"': string(); break;
                case 'o':
                  if (match('r')){
                    addToken(OR);
                  }
                  break;

                default: 
                // handle numbers
                if (isDigit(c)){
                    number();
                }else if(isAlpha(c)){
                    identifier();
                }
                else{
                    std::cout <<"error" <<std::endl;//error(line,"Unexpected character."); break;
                }
            }
        }
void Scanner::identifier(){
            while(isAlphanumeric(peek())) advance();
            std::string text = source.substr(start, current);
            TokenType type = IDENTIFIER;
            auto it = Scanner::keywords.find(text);
            if (it != Scanner::keywords.end()) {
                type = it->second;
            }
            addToken(type);
        }

bool Scanner::isDigit(const char& c){
            return c >='0' && c<='9';
        }
void Scanner::number(){
            while( isDigit(peek())) advance();
            if (peek() =='.' && isDigit(peekNext())){
                advance();
                while (isDigit(peek())) advance();
            }
            addToken(NUMBER, source.substr(start, current - start));

        }
void Scanner::string() {
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
bool Scanner::match(char expected) {
            if (isAtEnd()) return false;
            if (source[current] != expected) return false;
            current++;
            return true;
        }
char Scanner::peek() {
            if (isAtEnd()) return '\0';
            return source[current];
        }

char Scanner::peekNext(){
            if(current + 1 >= source.length()) return '\0';
            return source[current+1];
        }
bool Scanner::isAlpha(char c){
            return (c >= 'a' && c <= 'z') ||
            (c>='A' && c<='Z') || c=='_';
        }

bool Scanner::isAlphanumeric(char c){
            return isAlpha(c) || isDigit(c);
        }

char Scanner::advance() {
                return source[current++];
        }

void Scanner::addToken(TokenType type) {
                addToken(type, "");
        }

void Scanner::addToken(TokenType type, const std::string& literal) {
                std::string text = source.substr(start, current - start);
                tokens.push_back(Token(type, text, literal, line));
        }
