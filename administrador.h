#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include "usuario.h"
class Administrador
{
    std::string contrasenaAdmin;

    Usuario usuario1;


public:
    Administrador();
    std::string getContrasenaAdmin() const;

    void agregarDatos(std::string &original);
    bool buscarContrasena(const std::string& contrasenas, const std::string& contrasenaAComparar);
};

#endif // ADMINISTRADOR_H
