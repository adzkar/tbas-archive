#include <bits/stdc++.h>
using namespace std;
typedef map<string, bool> si;

struct Parse {
  unsigned int i = 0,n=0;
  string input = "";
  map<int, string> wl;
  bool status = true;
};

void getInput(Parse& p);
string head(Parse& p);
string toLower(string word);
bool isValid(Parse& p);

bool isValid(Parse& p);
bool isSubyek(Parse& p);
bool isPredikat(Parse& p);
bool isObyek(Parse& p);
bool isKet(Parse& p);

void S(Parse& p);
void A(Parse& p);
void B(Parse& p);
void C(Parse& p);
void D(Parse& p);
void E(Parse& p);

int main() {

  do {
    Parse parse;
    getInput(parse);
    if(toLower(parse.input) == "exit") break;
    cout << isSubyek(parse) << endl;

  } while(true);

  return 0;
}

void getInput(Parse& p) {
  printf(">> ");
  getline(cin, p.input);
  stringstream s(p.input);
  string word;
  while(s >> word) p.wl[p.n++] = word;
}

string head(Parse& p) {
  return p.wl[p.i++];
}

string toLower(string word) {
  transform(word.begin(), word.end(), word.begin(), ::tolower);
  return word;
}

bool isValid(Parse& p) {
  return p.status;
}

bool isSubyek(Parse& p) {
  string subyek[] = {"saya","kamu","dia","budi","andi"};
  int i = 0;
  cout << toLower(head(p)) << endl;
  for(i = 0;i < 5;i++)
    if(subyek[i] == toLower(head(p))) break;
  return p.input == subyek[i];
}

bool isPredikat(Parse& p);
bool isObyek(Parse& p);
bool isKet(Parse& p);

void S(Parse& p) {
  if(isValid(p)) {

  }
}
