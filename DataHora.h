#ifndef DATAHORA_H
#define DATAHORA_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class DataHora {
public:
    DataHora();
    DataHora(vector<string>dataEhora);
    virtual ~DataHora();
    void setAno(int ano);
    int getAno();
    void setMes(string mes);
    string getMes();
    void setDia(int dia);
    int getDia();
    void setHora(int hora);
    int getHora();
    void setMinuto(int minuto);
    int getMinuto();
    void setSegundo(int segundo);
    int getSegundo();


private:
    string mes;
    int dia;
    int hora;
    int minuto;
    int segundo;
};

#endif // DATAHORA_H
