#include <iostream>
#include <list>
#include <string>
using namespace std;

struct Parse {
  int i = 0, n;
  string input = "";
  list<string> status;
  bool validity = true;
};

void getInput(Parse& parse) {
  printf(">> ");
  getline(cin, parse.input);
  parse.n = parse.input.size();
};

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

bool isLetter(char c) {
  int x = (int) c;
  if((x >= 65 && x <= 90) || (x >= 97 && x <= 122)) return true;
  return false;
}

bool isNumber(char c) {
  int x = (int) c;
  if(48 <= x && x <= 57) return true;
  return false;
}

bool isNull(char c) {
  if(c != '\0') return false;
  return true;
}

void A(Parse& parse) {
  if(isValid(parse)) {
    char h = head(parse);
    parse.validity = true;
  }
}

void B(Parse& parse) {
  if(isValid(parse)) {
    char h = head(parse);
    parse.validity = false;
  }
}

void S(Parse& parse) {
  if(isValid(parse)) {
    char h = head(parse);
    if(isLetter(h))
      A(parse);
    else if(isNull(h))
      B(parse);
    else
      parse.validity = false;
  }
}

int main() {
  do {
    Parse parse;
    getInput(parse);

    if(parse.input == "exit") break;

    S(parse);

    printf("=> ");
    if(parse.validity)
      printf("TRUE");
    else
      printf("FALSE");

    printf("\n");

  } while(true);
}
