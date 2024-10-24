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
    std::cout << "Ingrese su contrasena: "<<std::endl;
    std::cin>>contrasena;
    std::cout << "Ingrese su saldo: "<<std::endl;
    std::cin>>saldo;
    original += "\n" + cedula + "|" + contrasena + "|" + saldo;
    std::cout<<"Usuario creado"<<std::endl;
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


void Administrador::menuUsuario(unsigned int saldo) {
    int opcion;
    do{
        std::cout << "1. Consultar saldo" << std::endl;
        std::cout << "2. Retirar dinero" << std::endl;
        std::cout << "3. Salir" << std::endl;
        std::cout << "Recuerde que cada consulta o retiro de dinero tiene un costo de 1000 COP" << std::endl;
        std::cin >> opcion;
        switch (opcion) {
        case 1:
            if(saldo-1000.0>=0){
                std::cout << std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl;
                std::cout << std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl;
                std::cout<<"Su saldo es de : "<<saldo<<" - 1000 COP";
                saldo-=1000.0;
                std::cout<<" = "<<saldo<<std::endl;

            }
            else{
                std::cout << std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl;
                std::cout << std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl;
                std::cout << "No tiene suficiente saldo para realizar esta accion" << std::endl;
            }
            break;
        case 2: {
            unsigned int cantidad;
            if(saldo-1000>=0){
                saldo-=1000;
                std::cout << "Ingrese la cantidad a retirar: ";
                std::cin >> cantidad;
                usuario1.retirarDinero(cantidad,saldo);
            }
            else{
                std::cout << std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl;
                std::cout << std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl<< std::endl;
                std::cout << "No tiene suficiente saldo para realizar esta accion" << std::endl;
            }
            break;
        }
        case 3:
            std::cout << "Saliendo..." << std::endl;
            break;
        default:
            std::cout << "Opcion no valida." << std::endl;
        }
    } while (opcion != 3&&opcion != 2);
}
