#include <iostream>
#include <list>
using namespace std;

struct Token {
  string type = "";
  Token(string t) {
    this->type = t;
  }
}

struct Parsec {
  int n = 0, pos = 0;
  string input = "";
  list<Token> tokens;
  bool validity = true;
}

char head(Parsec& parsec);
void getInput(Parsec& parsec);

bool isNull(char c);
bool isNumber(char c);
bool isOperator(char c);
bool isNumberSign(char c);

int main() {
  do {
    Parsec parsec;
    getInput(parsec);
    if(parsec.input == "exit") break;
    cout << "=> " << parsec.input << endl;
  } while(true);

  return 0;
}

char head(Parsec& parsec) {
  char c = '\0';
}
