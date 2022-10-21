#include <iostream>
#include <string.h>
#include <fstream>


using namespace std;

typedef struct{
  string modelo;
  string marca;
  string tipo;
  int ano;
  int km;
  float potencia;
  string combust;
  string cambio;
  string direcao;
  string cor;
  int portas;
  string placa;
}veiculo;

veiculo *carro[50];
veiculo *aux;

int busca (veiculo *p[], string placa2, int *tamanho){
  for (int i = 0; i < *tamanho; i ++){
    if (placa2 == p[i]->placa)
       return i;
  }
  return -1;
}

void remove(veiculo *p[], string placa2, int *tamanho){
  int i;
  int teste = busca(p,placa2,tamanho);  
  if ( teste == -1)
    cout << "\nVeículo não encontrado.";
  else{
    delete (p[teste]);
    for(i = teste; i < *tamanho; i ++)
      p[i] = p[i+1];
    p[i+1] = NULL;
    (*tamanho)--;
    cout << "\nVeículo removido com sucesso!";
  }
}

void inserir(veiculo *p[], veiculo *aux, int *tamanho){
    if ( (*tamanho) == 50 )
      cout << "\nImpossível inserir! Lista cheia.";
    else{
      (*tamanho)++;
      p[*tamanho] = aux;
      cout << "\nVeículo inserido com sucesso!!";
    }
  }



int main() {
  int contador = 0;
  ifstream database;
  database.open("BD_veiculos.txt");
  if ( database.is_open() ){
     for(int i = 0; !database.eof(); i ++ ){
        carro[i] = new veiculo;
        database >> carro[i]->modelo;
        database >> carro[i]->marca;
        database >> carro[i]->tipo;
        database >> carro[i]->ano;
        database >> carro[i]->km;
        database >> carro[i]->potencia;
        database >> carro[i]->combust;
        database >> carro[i]->cambio;
        database >> carro[i]->direcao;
        database >> carro[i]->cor;
        database >> carro[i]->portas;
        database >> carro[i]->placa;
        contador++;
     }
    database.close();
  }
  else
    cout << " Unable to open file\n ";

  int resposta;
  string placa;
  
  do{
  cout << "O que deseja?\n\n[1]Inserir novo veículo\n[2]Remover veículo\n[3]Sair\n\n";
  cin >> resposta;
  switch(resposta){
    case 1:
      aux = new veiculo;
      cout << "\nDigite agora os dados do novo veículo:\n\n";
      cout << "modelo: ";
      cin >> aux->modelo;
      cout << "marca: ";
      cin >> aux->marca;
      cout << "tipo: ";
      cin >> aux->tipo;
      cout << "ano: ";
      cin >> aux->ano;
      cout << "quilometragem: ";
      cin >> aux->km;
      cout << "potência: ";
      cin >> aux->potencia;
      cout << "combustível: ";
      cin >> aux->combust;
      cout << "câmbio: ";
      cin >> aux->cambio;
      cout << "direção: ";
      cin >> aux->direcao;
      cout << "cor: ";
      cin >> aux->cor;
      cout << "portas: ";
      cin >> aux->portas;
      cout << "placa: ";
      cin >> aux->placa;
      inserir(carro,aux,&contador);
      delete (aux);
      cout << "\nDeseja fazer mais alguma alteração?\n[1]Sim\n[2]Sair\n\n";
      cin >> resposta;
      if (resposta == 2)
        return 0;
      system("clear");
    break;
    case 2:
      cout << "\nDigite a placa do veículo que deseja remover: ";
      cin >> placa;
      remove(carro, placa, &contador);
      cout << endl << "\nDeseja fazer mais alterações?\n[1]Sim\n[2]Sair\n\n";
      cin >> resposta;
      if (resposta == 2)
        return 0;
      system("clear");
    break;
    case 3:
      return 0;
    break;
    default:
      cout << "Opção inválida. Escolha novamente!\n\n";
    }  
  }while(resposta != 3);  
  return 0;  
}
