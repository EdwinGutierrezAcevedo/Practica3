#include <iostream>
#include <fstream>
#include <bitset>
#include "banco.h"

int main() {
    Banco banco;
    int n,m;
    std::cout<<"Ingrese el modo de codidficado: "<<std::endl;
    std::cin>>m;
    std::cout<<"Introduzca la semilla: "<<std::endl;
    std::cin>>n;
    //banco.escribirArchivoBinario("archivotexto.txt", "archivo_binario.bin",m,n); toma un txt normmal y crea un binario codificado
    banco.escribirArchivoBinario("archivo_texto.txt", "archivo_binario.bin",m,n); //toma un txt codificado y crea un binario normal
    banco.iniciarSesion(m,n);
    banco.escribirArchivoTexto("archivo_binario.bin","archivo_texto.txt",m,n); //toma un binario codificado y lo escribe tal como esta en un archivo txt
    return 0;
}
