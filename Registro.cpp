#include "Registro.h"

Registro::Registro() {}
////////////////////////////////////////
Registro::Registro(string linha) {
    vector<string> valores = separar(linha, ' ');
    vector<string> dataEhora;
    dataEhora.push_back(valores.at(0));
    dataEhora.push_back(valores.at(1));
    dataEhora.push_back(valores.at(2));
    dataEhora.push_back(valores.at(3));
    dataEhora.push_back(valores.at(4));

    if (valores.at(1).length() == 0) {//QUANDO O DIA É MENOR DO QUE 10, O TAMANHO FICA COMO ZERO, POR ISSO FIZEMOS ESSE IF
        this->codigo = (valores.at(6).substr(1, valores.at(6).length()-2)); //REMOVER OS COLCHETES
        for (int i = 7; i < valores.size(); i++) { //PERCORRENDO A LINHA PARA VER SE EXISTE A PALAVRA CLASSIFICATION
            if (valores.at(i).find("Classification") != string::npos) { //ENQUANTO FOR DIFERENTE DE "CLASSIFICATION", SALVA NA MENSAGEM E SE FOR DIFERENTE DE NPOS É PORQUE EXISTE A PALAVRA CLASSIFICATION NESSA POSIÇÃO DO VETOR
                this->mensagem = (valores.at(7)); //NO CASO DOS DIAS MENORES DO QUE 10, TEMOS QUE O INÍCIO DA MENSAGEM SE DÁ NA POSIÇÃO 7
                this->mensagem.append(" "); //BOTAMOS ESPAÇO PORQUE O APPEND NÃO CONSIDERA ESPAÇOS
                for (int j = 8; j < i; j++) { //PERCORRE DA PRÓXIMA POSIÇÃO DEPOIS DA MENSAGEM INICIAL
                    this->mensagem.append(valores.at(j)); //VAI ADICIONANDO NA STRING ANTERIOR AS PRÓXIMAS PARTES DA MENSAGEM
                    this->mensagem.append(" "); //ESPAÇO NOVAMENTO
                }

                //SALVANDO CLASSIFICACAO
                this->classificacao = (valores.at(++i)); //PARA COMEÇAR A SALVAR DEPOIS DE CLASSIFICATION
                i++;
                this->classificacao.append(" ");
                while (valores.at(i).find("[") == string::npos) { //SE FOR DIFERENTE DE NPOS É PORQUE ENCONTROU O COLCHETE
                    this->classificacao.append(valores.at(i));
                    this->classificacao.append(" ");
                    i++;
                }
                this->classificacao = classificacao.substr(0,(classificacao.length()-2));
                //SALVANDO PRIORIDADE
                i++; //PARA IR DEPOIS DE PRIORIDADE
                string aux = valores.at(i).substr(0,1);
                this->prioridade = atoi(aux.c_str());

                //SALVANDO PROTOCOLO
                i++;
                this->protocolo = valores.at(i).substr(1, (valores.at(i).length()-2));
                //SALVANDO ORIGEM IP
                i++;
                int pos = valores.at(i).find(":");
                if (pos != string::npos) { //SE ENCONTRAR DOIS PONTOS, OU SEJA, SE TIVER PORTA
                    this->origemIP = valores.at(i).substr(0, pos);
                    string aux = valores.at(i).substr(pos+1, valores.at(i).length());
                    this->origemPorta = atoi(aux.c_str());
                } else {
                    this->origemIP = valores.at(i);
                    this->origemPorta = 0;
                }
                //SALVANDO DESTINO IP
                i+=2;
                pos = valores.at(i).find(":");
                if (pos != string::npos) { //SE ENCONTRAR DOIS PONTOS, OU SEJA, SE TIVER PORTA
                    this->destinoIP = valores.at(i).substr(0, pos);
                    string aux = valores.at(i).substr(pos+1, valores.at(i).length());
                    this->destinoPorta = atoi(aux.c_str());
                } else {
                    this->destinoIP = valores.at(i);
                    this->destinoPorta = 0;
                }
                break;
            } else if (valores.at(i).find("{") != string::npos) { //ENQUANTO FOR DIFERENTE DE "CHAVE", SALVA NA MENSAGEM
                this->mensagem = (valores.at(7)); //NO CASO DOS DIAS MENORES DO QUE 10, TEMOS QUE O INÍCIO DA MENSAGEM SE DÁ NA POSIÇÃO 7
                mensagem.append(" "); //BOTAMOS ESPAÇO PORQUE O APPEND NÃO CONSIDERA ESPAÇOS
                for (int j = 8; j < i; j++) { //PERCORRE DA PRÓXIMA POSIÇÃO DEPOIS DA MENSAGEM INICIAL
                    mensagem.append(valores.at(j)); //VAI ADICIONANDO NA STRING ANTERIOR AS PRÓXIMAS PARTES DA MENSAGEM
                    mensagem.append(" "); //ESPAÇO NOVAMENTO
                }
                //SALVANDO PROTOCOLO
                this->protocolo = valores.at(i).substr(1, (valores.at(i).length()-2));
                //SALVANDO ORIGEM IP
                i++;
                int pos = valores.at(i).find(":");
                if (pos != string::npos) { //SE ENCONTRAR DOIS PONTOS, OU SEJA, SE TIVER PORTA
                    this->origemIP = valores.at(i).substr(0, pos);
                    string aux = valores.at(i).substr(pos+1, valores.at(i).length());
                    this->origemPorta = atoi(aux.c_str());
                } else {
                    this->origemIP = valores.at(i);
                    this->origemPorta = 0;
                }
                //SALVANDO DESTINO IP
                i+=2;
                pos = valores.at(i).find(":");
                if (pos != string::npos) { //SE ENCONTRAR DOIS PONTOS, OU SEJA, SE TIVER PORTA
                    this->destinoIP = valores.at(i).substr(0, pos);
                    string aux = valores.at(i).substr(pos+1, valores.at(i).length());
                    this->destinoPorta = atoi(aux.c_str());
                } else {
                    this->destinoIP = valores.at(i);
                    this->destinoPorta = 0;
                }
            }
        }
    } else { //DIAS MAIORES DO QUE 10
        this->setCodigo(valores.at(5).substr(1, valores.at(5).length()-2));
        for (int i = 6; i < valores.size(); i++) { //PERCORRENDO A LINHA PARA VER SE EXISTE A PALAVRA CLASSIFICATION
            if (valores.at(i).find("Classification") != string::npos) { //SE FOR DIFERENTE DE NPOS É PORQUE EXISTE A PALAVRA CLASSIFICATION NESSA LINHA
                this->mensagem = (valores.at(6)); //NO CASO DOS DIAS MENORES DO QUE 10, TEMOS QUE O INÍCIO DA MENSAGEM SE DÁ NA POSIÇÃO 7
                mensagem.append(" "); //BOTAMOS ESPAÇO PORQUE O APPEND NÃO CONSIDERA ESPAÇOS
                for (int j = 7; j < i; j++) { //PERCORRE DA PRÓXIMA POSIÇÃO DEPOIS DA MENSAGEM INICIAL
                    mensagem.append(valores.at(j)); //VAI ADICIONANDO NA STRING ANTERIOR AS PRÓXIMAS PARTES DA MENSAGEM
                    mensagem.append(" "); //ESPAÇO NOVAMENTO
                }

                //SALVANDO CLASSIFICAÇÃO
                this->classificacao = (valores.at(++i)); //PARA COMEÇAR A SALVAR DEPOIS DE CLASSIFICATION
                i++;
                this->classificacao.append(" ");
                while (valores.at(i).find("[") == string::npos) { //SE FOR DIFERENTE DE NPOS É PORQUE ENCONTROU O COLCHETE
                    this->classificacao.append(valores.at(i));
                    this->classificacao.append(" ");
                    i++;
                }
                this->classificacao = classificacao.substr(0,(classificacao.length()-2));
                //SALVANDO PRIORIDADE
                i++; //PARA IR DEPOIS DE PRIORIDADE
                string aux = valores.at(i).substr(0,1);
                this->prioridade = atoi(aux.c_str());
                //SALVANDO PROTOCOLO
                i++;
                this->protocolo = valores.at(i).substr(1, (valores.at(i).length()-2));
                //SALVANDO ORIGEM IP
                i++;
                int pos = valores.at(i).find(":");
                if (pos != string::npos) { //SE ENCONTRAR DOIS PONTOS, OU SEJA, SE TIVER PORTA
                    this->origemIP = valores.at(i).substr(0, pos);
                    string aux = valores.at(i).substr(pos+1, valores.at(i).length());
                    this->origemPorta = atoi(aux.c_str());
                } else {
                    this->origemIP = valores.at(i);
                    this->origemPorta = 0;
                }
                //SALVANDO DESTINO IP
                i+=2;
                pos = valores.at(i).find(":");
                if (pos != string::npos) { //SE ENCONTRAR DOIS PONTOS, OU SEJA, SE TIVER PORTA
                    this->destinoIP = valores.at(i).substr(0, pos);
                    string aux = valores.at(i).substr(pos+1, valores.at(i).length());
                    this->destinoPorta = atoi(aux.c_str());
                } else {
                    this->destinoIP = valores.at(i);
                    this->destinoPorta = 0;
                }

                break;
            } else if (valores.at(i).find("{") != string::npos) { //ENQUANTO FOR DIFERENTE DE "CHAVE", SALVA NA MENSAGEM
                this->mensagem = (valores.at(6)); //NO CASO DOS DIAS MENORES DO QUE 10, TEMOS QUE O INÍCIO DA MENSAGEM SE DÁ NA POSIÇÃO 7
                mensagem.append(" "); //BOTAMOS ESPAÇO PORQUE O APPEND NÃO CONSIDERA ESPAÇOS
                for (int j = 7; j < i; j++) { //PERCORRE DA PRÓXIMA POSIÇÃO DEPOIS DA MENSAGEM INICIAL
                    mensagem.append(valores.at(j)); //VAI ADICIONANDO NA STRING ANTERIOR AS PRÓXIMAS PARTES DA MENSAGEM
                    mensagem.append(" "); //ESPAÇO NOVAMENTO
                }
                //SALVANDO PROTOCOLO
                this->protocolo = valores.at(i).substr(1, (valores.at(i).length()-2));
                //SALVANDO ORIGEM IP
                i++;
                int pos = valores.at(i).find(":");
                if (pos != string::npos) { //SE ENCONTRAR DOIS PONTOS, OU SEJA, SE TIVER PORTA
                    this->origemIP = valores.at(i).substr(0, pos);
                    string aux = valores.at(i).substr(pos+1, valores.at(i).length());
                    this->origemPorta = atoi(aux.c_str());
                } else {
                    this->origemIP = valores.at(i);
                    this->origemPorta = 0;
                }
                //SALVANDO DESTINO IP
                i+=2;
                pos = valores.at(i).find(":");
                if (pos != string::npos) { //SE ENCONTRAR DOIS PONTOS, OU SEJA, SE TIVER PORTA
                    this->destinoIP = valores.at(i).substr(0, pos);
                    string aux = valores.at(i).substr(pos+1, valores.at(i).length());
                    this->destinoPorta = atoi(aux.c_str());
                } else {
                    this->destinoIP = valores.at(i);
                    this->destinoPorta = 0;
                }
            }
        }
    }
    DataHora temp(dataEhora);
    dataHora = temp;
}
////////////////////////////////////////
Registro::~Registro() {}
////////////////////////////////////////
string Registro::getCodigo() {
    return this->codigo;
}
////////////////////////////////////////
string Registro::getMensagem() {
    return this->mensagem;
}
////////////////////////////////////////
string Registro::getClassificacao() {
    return this->classificacao;
}
////////////////////////////////////////
int Registro::getPrioridade() {
    return this->prioridade;
}
////////////////////////////////////////
string Registro::getProtocolo() {
    return this->protocolo;
}
////////////////////////////////////////
string Registro::getOrigemIP() {
    return this->origemIP;
}
////////////////////////////////////////
int Registro::getOrigemPorta() {
    return this->origemPorta;
}
////////////////////////////////////////
string Registro::getDestinoIP() {
    return this->destinoIP;
}
////////////////////////////////////////
int Registro::getDestinoPorta() {
    return this->destinoPorta;
}
////////////////////////////////////////
void Registro::setCodigo(string codigo) {
    this->codigo = codigo;
}
////////////////////////////////////////
void Registro::setMensagem(string mensagem) {
    this->mensagem = mensagem;
}
////////////////////////////////////////
void Registro::setClassificacao(string classificacao) {
    this->classificacao = classificacao;
}
////////////////////////////////////////
void Registro::setPrioridade(int prioridade) {
    this->prioridade = prioridade;
}
////////////////////////////////////////
void Registro::setProtocolo(string protocolo) {
    this->protocolo = protocolo;
}
////////////////////////////////////////
void Registro::setOrigemIP(string origemIP) {
    this->origemIP = origemIP;
}
////////////////////////////////////////
void Registro::setOrigemPorta(int origemPorta) {
    this->origemPorta = origemPorta;
}
////////////////////////////////////////
void Registro::setDestinoIP(string destinoIP) {
    this->destinoIP = destinoIP;
}
////////////////////////////////////////
void Registro::setDestinoPorta(int destinoPorta) {
    this->destinoPorta = destinoPorta;
}
////////////////////////////////////////
DataHora Registro::getDataHora() {
    return this->dataHora;
}
////////////////////////////////////////
vector<string> Registro::separar(string linha, char separador) { //PEGAMOS A LINHA DO ARQUIVO E PASSAMOS APENAS ATÉ O SEPARADOR PARA DENTRO DE UMA POSIÇÃO DO VECTOR
    vector<string> aux;
    string espaco;
    istringstream ss(linha);
    while (getline(ss, espaco, separador) ) {
        aux.push_back(espaco);
    }
    return aux;
}
