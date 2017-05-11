\ |

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring>
using namespace std;

#define MAX 11234;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

int main(void){
  char linha[MAX];
  map<string, int> estados;
  map<string, int> terminais;
  vii tabela;
  int ide, idt; // id dos estados e id dos terminais.
  ide = idt = 0;
  while(fgets(linha, MAX, stdin) != EOF){
    if(linha[0] == '<') trata_gramatica(linha, estados, terminais, ide, idt, tabela);
    else{

    }

  }
  return 0;
}

void trata_gramatica(char linha[], map<string, int> &estados, map<string, int> &terminais,
		     int &ide, int &idt, vii &tabela){
  
  int i, j;
  char s[MAX];
  // passa o estado em que está pra um vetor aux
  for(i = 1; linha[i] != '>'; i++) s[i-1] = linha[i];
  s[i] = '\0';
  // se nao existir esse estado, taca ele lá no map
  if(estados.find(string(s)) == estados.end()) estados[s] = ide++;
  // passa o ( ::= )
  i += 6;
  // se ele nao for um epslon transição
  if(linha[i] != '<'){
    // passa o que ele espera que venha e para que estado ele irá;
    for(j = 0; linha[i] != '<'; s[j++] = linha[i++]);
    s[i] = '\0';
    if(terminais.find(string(s)) == terminais.end()) terminais[s] = idt++;
    for(j = 0; linha[i] != '>'; s[j++] = linha[i++]);
    s[i] = '\0';
    if(estados.find(string(s)) == estados.end()) estados[s] = ide++;
  }
  
}


