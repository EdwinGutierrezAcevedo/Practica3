#include <iostream>
#include <fstream>
#include <bitset>
#include "usuario.h"

//Usuario::Usuario() {}

void Usuario::setCedula(const std::string &ced) {
    cedula = ced;
}

void Usuario::setContrasena(const std::string &cont) {
    contrasena = cont;
}

void Usuario::setSaldo(double sal) {
    saldo = sal;
}

std::string Usuario::getCedula() const {
    return cedula;
}

std::string Usuario::getContrasena() const {
    return contrasena;
}

double Usuario::getSaldo() const {
    return saldo;
}

void Usuario::consultarSaldo() const {
    std::cout << "Saldo actual: " << saldo << std::endl;
}

void Usuario::retirarDinero(double cantidad) {
    if (cantidad <= saldo) {
        saldo -= cantidad;
        std::cout << "Retiro exitoso. Saldo restante: " << saldo << std::endl;
    } else {
        std::cout << "Saldo insuficiente." << std::endl;
    }
}

std::string Usuario::toString() const {
    return cedula + "|" + contrasena + "|" + std::to_string(saldo);
}


std::string Usuario::obtenerSaldo(const std::string& datos, const std::string& contrasena, const std::string& cedula) {
    std::string contenido, contrasena_g, cedula_g, saldo_g,saldo="";
    int contFilas = 0, contColumnas = 0;
    char caracter;

    for (size_t i = 0; i < datos.size(); i++) {
        caracter = datos[i];

        if (caracter == '\n') {
            saldo_g = contenido.substr(0, contenido.size());
            contenido = "";
            contFilas++;
            contColumnas = 0;
        } else {
            contenido += caracter;

            if (caracter == '|' && contColumnas == 0) {
                cedula_g = contenido.substr(0, contenido.size() - 1);
                contenido = "";
                contColumnas++;
            } else if (caracter == '|' && contColumnas == 1) {
                contrasena_g = contenido.substr(0, contenido.size() - 1);
                contenido = "";
                contColumnas++;
            } /*else if (caracter == '\n' && contColumnas == 2) {
                saldo_g = contenido.substr(0, contenido.size() - 1);
                contenido = "";
                contColumnas++;
            }*/
        }

        if (cedula_g == cedula && contrasena_g == contrasena) {
            saldo=saldo_g;
        }
    }

    return saldo;
}

