#include <iostream>
#include <list>
using namespace std;

struct Token {
  string type = "";
  Token(string t) {
    this->type = t;
  }
};

struct Parsec {
  int n = 0, pos = 0;
  string input = "";
  list<Token> tokens;
  bool validity = true;
};

char head(Parsec& parsec);
void getInput(Parsec& parsec);

bool isNull(char c);
bool isNumber(char c);
bool isOperator(char c);
bool isNumberSign(char c);

bool isValid(Parsec& parsec);

void S(Parsec& parsec);
void A(Parsec& parsec);
void B(Parsec& parsec);
void C(Parsec& parsec);

int main() {
  do {
    Parsec parsec;
    getInput(parsec);
    if(parsec.input == "exit") break;

    S(parsec);

    if(!isValid(parsec)) {
      Token token ("ERR");
      parsec.tokens.push_back(token);
    }

    printf("=> ");
    for(Token t : parsec.tokens) cout << t.type << " ";
    printf("\n");
  } while(true);

  return 0;
};

char head(Parsec& parsec) {
  char c = '\0';
  if(parsec.pos < parsec.n) {
    c = parsec.input[parsec.pos];
    parsec.pos++;
  }
  return c;
}

void getInput(Parsec& parsec) {
  printf(">> ");
  getline(cin, parsec.input);
  parsec.n = parsec.input.size();
}

bool isNull(char c) {
  if(c != '\0') return false;
  return true;
}

bool isNumber(char c) {
  int x = (int) c;
  if(!(47 < x && x < 58)) return false;
  return true;
}

bool isOperator(char c) {
  int x = (int) c;
  if(x != 42 && x != 43 && x != 45 && x != 47) return false;
  return true;
}

bool isNumberSign(char c) {
  int x = (int) c;
  if(x != 43 && x != 45) return false;
  return true;
}

bool isValid(Parsec& parsec) {
  return parsec.validity;
}

void S(Parsec& parsec) {
  if(isValid(parsec)) {
    char h = head(parsec);
    if(isNumberSign(h))
      A(parsec);
    else if(isNumber(h))
      B(parsec);
    else parsec.validity = false;
  }
}

void A(Parsec& parsec) {
  if(isValid(parsec)) {
    char h = head(parsec);
    if(isNumber(h))
      B(parsec);
    else parsec.validity = false;
  }
}

void B(Parsec& parsec) {
  if(isValid(parsec)) {
    char h = head(parsec);
    if(isNull(h)) {
      Token token("NUM");
      parsec.tokens.push_back(token);
    } else if(isNumber(h))
        B(parsec);
    else if(isOperator(h)) {
      Token token("NUM");
      parsec.tokens.push_back(token);

      C(parsec);
    } else parsec.validity = false;
  }
}

void C(Parsec& parsec) {
  if(isValid(parsec)) {
    char h = head(parsec);
    if(isNumber(h)) {
      Token token("OPR");
      parsec.tokens.push_back(token);
      B(parsec);
    } else parsec.validity = false;
  }
}
