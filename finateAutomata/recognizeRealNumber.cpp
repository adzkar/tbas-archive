#include <iostream>
#include <string>
#include <list>
using namespace std;

struct Parse {
  int i = 0,n = 1;
  string input = "";
  list<string> visited;
  bool validity = true;
};

void getInput(Parse& parse);

char head(Parse& parse);

bool isValid(Parse& parse);
bool isNull(char c);
bool isNumber(char c);
bool isE(char c);
bool isOperator(char c);
bool isDot(char c);

void S(Parse& parse);
void A(Parse& parse);
void B(Parse& parse);
void C(Parse& parse);
void D(Parse& parse);
void E(Parse& parse);
void F(Parse& parse);

int main() {

  do {
    Parse parse;
    getInput(parse);

    if(parse.input == "exit" || parse.input == "EXIT") break;

    S(parse);

    if(parse.validity)
      printf("=> REAL NUMBER");
    else
      printf("=> NOT REAL NUMBER");
    printf("\n");
    // show route
    // for(string visited: parse.visited) cout << visited << " ";

  } while(true);

  return 0;
}

void getInput(Parse& parse) {
  printf(">> ");
  getline(cin,parse.input);
  parse.n = parse.input.size();
}

char head(Parse& parse) {
  char c = '\0';
  if(parse.i < parse.n) {
    c = parse.input[parse.i];
    parse.i++;
  }
  return c;
}

bool isValid(Parse& parse) {
  return parse.validity;
}
bool isNull(char c) {
  if(c != '\0') return false;
  return true;
}
bool isNumber(char c) {
  int x = (int) c;
  if(x > 47 && x < 58) return true;
  return false;
}
bool isE(char c) {
  int x = (int) c;
  if(x != 69) return false;
  return true;
}
bool isOperator(char c) {
  int x = (int) c;
  if(x != 43 || x != 45) return false;
  return true;
}
bool isDot(char c) {
  int x = (int) c;
  if(x == 46 || x == 44) return true;
  else return false;
}

void S(Parse& parse){
  if (isValid(parse)) {
    char h = head(parse);
    if(isNumber(h))
      A(parse);
    else
      parse.validity = false;
    parse.visited.push_back("S");
  }
}
void A(Parse& parse) {
  if (isValid(parse)) {
    char h = head(parse);
    if(isNumber(h))
      A(parse);
    else if(isE(h))
      B(parse);
    else if(isDot(h))
      D(parse);
    else
      parse.validity = false;
    parse.visited.push_back("A");
  }
}
void B(Parse& parse) {
  if (isValid(parse)) {
    char h = head(parse);
    if(isNumber(h))
      F(parse);
    else if(isOperator(h))
      C(parse);
    else
      parse.validity = false;
    parse.visited.push_back("B");
  }
}
void C(Parse& parse) {
  if (isValid(parse)) {
    char h = head(parse);
    if (isNumber(h))
      F(parse);
    else
      parse.validity = false;
    parse.visited.push_back("C");
  }
}
void D(Parse& parse) {
  if (isValid(parse)) {
    char h = head(parse);
    if(isNumber(h))
      E(parse);
    else
      parse.validity = false;
    parse.visited.push_back("D");
  }
}
void E(Parse& parse) {
  if (isValid(parse)) {
    char h = head(parse);
    if (isNumber(h))
      E(parse);
    else if (isE(h))
      B(parse);
    parse.validity = true;
    parse.visited.push_back("E");
  }
}
void F(Parse& parse) {
  if (isValid(parse)) {
    char h = head(parse);
    if(isNumber(h))
      F(parse);
    parse.validity = true;
    parse.visited.push_back("F");
  }
}
