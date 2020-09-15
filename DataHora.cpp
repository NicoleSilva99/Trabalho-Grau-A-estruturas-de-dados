#include "DataHora.h"

DataHora::DataHora() {
    this->mes = "NULL";
    this->dia = 0;
    this->hora = 0;
    this->minuto = 0;
    this->segundo = 0;
}
////////////////////////////////////////
DataHora::DataHora(vector<string>dataEhora) {
    string aux;
    this->mes = dataEhora.at(0);
    if(dataEhora.at(1).length() == 0) {
        aux = dataEhora.at(2);
        this->dia = atoi(aux.c_str());
        aux = dataEhora.at(3).substr(0,2);
        this->hora = atoi(aux.c_str());
        aux = dataEhora.at(3).substr(3,4);
        this->minuto = atoi(aux.c_str());
        aux = dataEhora.at(3).substr(6,7);
        this->segundo = atoi(aux.c_str());
    } else {
        aux = dataEhora.at(1);
        this->dia = atoi(aux.c_str());
        aux = dataEhora.at(2).substr(0,2);
        this->hora = atoi(aux.c_str());
        aux = dataEhora.at(2).substr(3,4);
        this->minuto = atoi(aux.c_str());
        aux = dataEhora.at(2).substr(6,7);
        this->segundo = atoi(aux.c_str());
    }
}
////////////////////////////////////////
DataHora::~DataHora() {}
////////////////////////////////////////
void DataHora::setMes(string mes) {
    this->mes = mes;
}
////////////////////////////////////////
string DataHora::getMes() {
    return this->mes;
}
////////////////////////////////////////
void DataHora::setDia(int dia) {
    this->dia = dia;
}
////////////////////////////////////////
int DataHora::getDia() {
    return this->dia;
}
////////////////////////////////////////
void DataHora::setHora(int hora) {
    this->hora = hora;
}
////////////////////////////////////////
int DataHora::getHora() {
    return this->hora;
}
////////////////////////////////////////
void DataHora::setMinuto(int minuto) {
    this->minuto = minuto;
}
////////////////////////////////////////
int DataHora::getMinuto() {
    return this->minuto;
}
////////////////////////////////////////
void DataHora::setSegundo(int segundo) {
    this->segundo = segundo;
}
////////////////////////////////////////
int DataHora::getSegundo() {
    return this->segundo;
}
////////////////////////////////////////
