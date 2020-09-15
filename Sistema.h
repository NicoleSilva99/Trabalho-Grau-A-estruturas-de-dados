#ifndef SISTEMA_H
#define SISTEMA_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Registro.h"
#include "DataHora.h"

using namespace std;


class Sistema: public DataHora {
public:
    Sistema(string nomeArquivo);
    virtual ~Sistema();
    void teste();

private:
    vector<Registro*>registros;
};

#endif // SISTEMA_H
