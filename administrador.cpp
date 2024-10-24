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

    std::cout << "Ingrese su cédula: ";
    std::getline(std::cin, cedula);
    std::cout << "Ingrese su contraseña: ";
    std::getline(std::cin, contrasena);
    std::cout << "Ingrese su saldo: ";
    std::getline(std::cin, saldo);

    original += "\n" + cedula + "|" + contrasena + "|" + saldo;
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
