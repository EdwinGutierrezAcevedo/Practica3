#include <iostream>
#include <fstream>
#include <bitset>
#include "administrador.h"

Administrador::Administrador() {}

std::string Administrador::getContrasenaAdmin() const
{
    return contrasenaAdmin;
}



void Administrador::agregarDatos(std::string &original) {
    std::string cedula, contrasena, saldo;

    std::cout << "Ingrese su cedula: "<<std::endl;
    std::cin>>cedula;
    //std::getline(std::cin, cedula);
    std::cout << "Ingrese su contrasena: "<<std::endl;
    std::cin>>contrasena;
    //std::getline(std::cin, contrasena);
    std::cout << "Ingrese su saldo: "<<std::endl;
    //std::getline(std::cin, saldo);
    std::cin>>saldo;
    original += "\n" + cedula + "|" + contrasena + "|" + saldo;
    std::cout<<original<<std::endl;
}

bool Administrador::buscarContrasena(const std::string& contrasenas, const std::string& contrasenaAComparar) {
    std::string contrasena;
    for (size_t i = 0; i < contrasenas.size(); ++i) {
        if (contrasenas[i] == '\n') {
            if (contrasena == contrasenaAComparar) {
                return true;
            }
            contrasena.clear();
        } else {
            contrasena += contrasenas[i];
        }
    }
    // Verificar la última línea si no termina con '\n'
    if (contrasena == contrasenaAComparar) {
        return true;
    }
    return false;
}
