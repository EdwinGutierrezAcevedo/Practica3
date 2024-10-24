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


void Usuario::retirarDinero(double cantidad,double saldo) {
    if (cantidad+1000.0 <= saldo) {
        saldo -= cantidad;
        std::cout << "Retiro exitoso. Saldo restante: " << saldo <<" - 1000 COP";
        saldo-=1000.0;
        std::cout<<" = "<<saldo<<std::endl;
    } else {
        std::cout << "Saldo insuficiente." << std::endl;
    }
}


std::string Usuario::obtenerSaldo(const std::string& datos, const std::string& contrasena, const std::string& cedula) const {
    std::string contenido, contrasena_g, cedula_g, saldo_g;
    int contFilas = 0, contColumnas = 0;
    char caracter;

    for (size_t i = 0; i < datos.size(); i++) {
        caracter = datos[i];
        if (caracter == '\n') {
            if (cedula_g == cedula && contrasena_g == contrasena) {
                saldo_g = contenido.substr(0, contenido.size());
                return saldo_g;
            }
            else{
                contenido = "";
                contFilas++;
                contColumnas = 0;
            }
        }
        else {
            contenido += caracter;
            if (caracter == '|' && contColumnas == 0) {
                cedula_g = contenido.substr(0, contenido.size() - 1);
                contenido = "";
                contColumnas++;
            }
            else if (caracter == '|' && contColumnas == 1) {
                contrasena_g = contenido.substr(0, contenido.size() - 1);
                contenido = "";
                contColumnas++;
            }
        }
    }

    return "";
}

