#ifndef USUARIO_H
#define USUARIO_H

class Usuario
{

private:
    std::string cedula;
    std::string contrasena;
    double saldo;

public:
    Usuario() : saldo(0.0) {}
    void setCedula(const std::string &ced);
    void setContrasena(const std::string &cont);
    void setSaldo(double sal);
    std::string getCedula() const;
    std::string getContrasena() const;
    double getSaldo() const;
    void retirarDinero(unsigned int cantidad, unsigned int& saldo);
    std::string obtenerSaldo(const std::string& datos, const std::string& contrasena, const std::string &cedula) const;
};

#endif // USUARIO_H
