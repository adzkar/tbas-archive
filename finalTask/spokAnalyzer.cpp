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
bool isSubyek(string word);
bool isPredikat(string word);
bool isObyek(string word);
bool isKet(string word);

void S(Parse& p);
void A(Parse& p);
void B(Parse& p);
void C(Parse& p);
void D(Parse& p);

int main() {

  do {
    Parse parse;
    getInput(parse);
    if(toLower(parse.input) == "exit") break;

    S(parse);

    cout << "=> ";
    if(parse.status) cout << parse.input << " [Valid]" << endl;
    else cout << parse.input << " [Invalid]" << endl;

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
  string word = "";
  if(p.i < p.n) {
    word = p.wl[p.i];
    p.i++;
  }
  return word;
}

string toLower(string word) {
  transform(word.begin(), word.end(), word.begin(), ::tolower);
  return word;
}

bool isValid(Parse& p) {
  return p.status;
}

bool isSubyek(string word) {
  string subyek[] = {"saya","kamu","dia","budi","andi"};
  int i = 0;
  while(subyek[i] != toLower(word) && i < 5) i++;
  return toLower(word) == subyek[i];
}

bool isPredikat(string word) {
  string pre[] = {"bermain","belajar","membaca","melempar","melihat"};
  int i = 0;
  while(pre[i] != toLower(word) && i < 5) i++;
  return toLower(word) == pre[i];
}

bool isObyek(string word) {
  string oby[] = {"bola","batu","buku","pemandangan","TBA"};
  int i = 0;
  while(oby[i] != toLower(word) && i < 5) i++;
  return toLower(word) == oby[i];
}

bool isKet(string word) {
  string ket[] = {"kemarin","sekarang","lusa","besok","dilapangan"};
  int i = 0;
  while(ket[i] != toLower(word) && i < 5) i++;
  return toLower(word) == ket[i];
}

void S(Parse& p) {
  if(isValid(p)) {
    string word = head(p);
    if(isSubyek(word))
      A(p);
    else p.status = false;
  }
}

void A(Parse& p) {
  if(isValid(p)) {
    string word = head(p);
    if(isPredikat(word))
      B(p);
    else p.status = false;
  }
}

void B(Parse& p) {
  if(isValid(p)) {
    string word = head(p);
    if(isObyek(word))
      C(p);
    else if(isKet(word))
      D(p);
    else p.status = false;
    p.status = true;
  }
}

void C(Parse& p) {
  if(isValid(p)) {
    string word = head(p);
    if(isKet(word))
      D(p);
    else p.status = false;
    p.status = true;
  }
}

void D(Parse& p) {
  if(isValid(p)) {
    string word = head(p);
    if(isSubyek(word) || isPredikat(word) || isObyek(word) || isKet(word)) p.status = false;
    else p.status = true;
  }
}
