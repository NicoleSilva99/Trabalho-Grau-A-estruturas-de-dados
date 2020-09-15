#include "Sistema.h"

Sistema::Sistema(string nomeArquivo) {
//Leitura do arquivo
    string linha;
    fstream fs(nomeArquivo, iostream::in);
    if (fs.is_open()) {
        while (!fs.eof()) {
            getline(fs, linha);
            registros.push_back(new Registro(linha));
        }
        fs.close();
    } else {
        cout << "Erro!" << endl;
    }
}
////////////////////////////////////////
Sistema::~Sistema() {}
////////////////////////////////////////
void Sistema::teste() {
    cout << registros[15224]->getDataHora().getMes() << endl;
    cout << registros[15224]->getDataHora().getDia() << endl;
    cout << registros[15224]->getDataHora().getHora() << ":";
    cout << registros[15224]->getDataHora().getMinuto() << ":";
    cout << registros[15224]->getDataHora().getSegundo() << endl;
    cout << "Codigo: " << registros[15224]->getCodigo() << endl;
    cout << "Mensagem: " << registros[15224]->getMensagem()<< endl;
    cout << "Classificacao: " << registros[15224]->getClassificacao() << endl;
    cout << "Prioridade:" << registros[15224]->getPrioridade() << endl;
    cout << "Protocolo: " << registros[15224]->getProtocolo() << endl;
    cout << "Origem IP: " << registros[9657]->getOrigemIP() << endl;
    cout << "Origem Porta: " << registros[9657]->getOrigemPorta() << endl;
    cout << "Destino IP: " << registros[9657]->getDestinoIP() << endl;
    cout << "Destino Porta: " << registros[9657]->getDestinoPorta() << endl;
}
