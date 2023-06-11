#include <map>
#include <string>
#include "Token.hpp"
#include<vector>

class Scanner {
    
public:
  std::string source;
  std::vector<Token> tokens;
  int start;
  int current ;
  int line ;
  Scanner(const std::string& source);
  static const std::map<std::string, TokenType> keywords;
  static std::map<std::string, TokenType> initializeKeywords() {
            std::map<std::string, TokenType> map;
            map["and"] = AND;
            map["class"] = CLASS;
            map["else"] = ELSE;
            map["false"] = FALSE;
            map["for"] = FOR;
            map["fun"] = FUN;
            map["if"] = IF;
            map["nil"] = NIL;
            map["or"] = OR;
            map["print"] = PRINT;
            map["return"] = RETURN;
            map["super"] = SUPER;
            map["this"] = THIS;
            map["true"] = TRUE;
            map["var"] = VAR;
            map["while"] = WHILE;
            return map;
        }
        

static const std::map<std::string, TokenType>&getKeywords() {
            static std::map<std::string, TokenType> initializedMap = initializeKeywords();
            return initializedMap;
        }
  std::vector<Token> scanTokens();
  bool isAtEnd();
  void scanToken();
  void identifier();
  bool isDigit(const char& c);
  void number();
  void string();
  bool match(char expected);
  char peek();
  char peekNext();
  bool isAlpha(char c);
  bool isAlphanumeric(char c);
  char advance(); 
  void addToken(TokenType type);
  void addToken(TokenType type, const std::string& literal);
};