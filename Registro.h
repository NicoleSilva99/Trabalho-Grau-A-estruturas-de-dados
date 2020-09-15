#ifndef REGISTRO_H
#define REGISTRO_H
#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include "DataHora.h"
#include <vector>

using namespace std;

class Registro: public DataHora {
public:
    Registro();
    Registro(string linha);
    virtual ~Registro();
    string getCodigo();
    void setCodigo(string codigo);
    string getMensagem();
    void setMensagem(string mensagem);
    string getClassificacao();
    void setClassificacao(string classificacao);
    int getPrioridade();
    void setPrioridade(int prioridade);
    string getProtocolo();
    void setProtocolo (string protocolo);
    string getOrigemIP();
    void setOrigemIP(string origemIP);
    int getOrigemPorta();
    void setOrigemPorta(int origemPorta);
    string getDestinoIP();
    void setDestinoIP(string destinoIP);
    int getDestinoPorta();
    void setDestinoPorta(int destinoPorta);
    DataHora getDataHora();

private:
    DataHora dataHora;
    string codigo;
    string mensagem;
    string classificacao;
    int prioridade;
    string protocolo;
    string origemIP;
    int origemPorta;
    string destinoIP;
    int destinoPorta;
    string lixo;
    vector<string> separar(string linha, char separador);
};

#endif // REGISTRO_H
