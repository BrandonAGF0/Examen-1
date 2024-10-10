#include <iostream>
#include <vector>
#include <string>

struct Venta {
    int numeroFactura;
    std::string cedula;
    std::string nombre;
    int localidad;
    int cantidadEntradas;
    double subtotal;
    double cargosPorServicios;
    double totalPagar;
};

int main() {
    std::vector<Venta> ventas;
    int entradasSol = 0, entradasSombra = 0, entradasPreferencial = 0;
    double dineroSol = 0, dineroSombra = 0, dineroPreferencial = 0;
    int numeroFactura = 1;
    const double precioSol = 10500, precioSombra = 20500, precioPreferencial = 25500;
    const double cargoServicio = 1000;

    while (true) {
        Venta venta;
        venta.numeroFactura = numeroFactura++;
        std::cout << "Ingrese la cédula del comprador: ";
        std::cin >> venta.cedula;
        std::cout << "Ingrese el nombre del comprador: ";
        std::cin.ignore();
        std::getline(std::cin, venta.nombre);
        std::cout << "Seleccione la localidad (1: Sol Norte/Sur, 2: Sombra Este/Oeste, 3: Preferencial): ";
        std::cin >> venta.localidad;
        std::cout << "Ingrese la cantidad de entradas (máximo 4): ";
        std::cin >> venta.cantidadEntradas;

        if (venta.cantidadEntradas > 4) {
            std::cout << "Error: No se pueden comprar más de 4 entradas por cliente.\n";
            continue;
        }

        switch (venta.localidad) {
            case 1:
                venta.subtotal = venta.cantidadEntradas * precioSol;
                entradasSol += venta.cantidadEntradas;
                dineroSol += venta.subtotal;
                break;
            case 2:
                venta.subtotal = venta.cantidadEntradas * precioSombra;
                entradasSombra += venta.cantidadEntradas;
                dineroSombra += venta.subtotal;
                break;
            case 3:
                venta.subtotal = venta.cantidadEntradas * precioPreferencial;
                entradasPreferencial += venta.cantidadEntradas;
                dineroPreferencial += venta.subtotal;
                break;
            default:
                std::cout << "Error: Localidad no válida.\n";
                continue;
        }

        venta.cargosPorServicios = venta.cantidadEntradas * cargoServicio;
        venta.totalPagar = venta.subtotal + venta.cargosPorServicios;
        ventas.push_back(venta);

        std::cout << "¿Desea ingresar otra venta? (s/n): ";
        char continuar;
        std::cin >> continuar;
        if (continuar == 'n' || continuar == 'N') break;
    }

    std::cout << "\nResumen de ventas:\n";
    
    int main()  {
        std::cout << "Factura: " << venta.numeroFactura << "\n"
                  << "Cédula: " << venta.cedula << "\n"
                  << "Nombre: " << venta.nombre << "\n"
                  << "Localidad: " << venta.localidad << "\n"
                  << "Cantidad de entradas: " << venta.cantidadEntradas << "\n"
                  << "Subtotal: " << venta.subtotal << "\n"
                  << "Cargos por servicios: " << venta.cargosPorServicios << "\n"
                  << "Total a pagar: " << venta.totalPagar << "\n\n";
    }

    std::cout << "Estadísticas finales:\n"
              << "Entradas Sol Norte/Sur: " << entradasSol << "\n"
              << "Dinero Sol Norte/Sur: " << dineroSol << "\n"
              << "Entradas Sombra Este/Oeste: " << entradasSombra << "\n"
              << "Dinero Sombra Este/Oeste: " << dineroSombra << "\n"
              << "Entradas Preferencial: " << entradasPreferencial << "\n"
              << "Dinero Preferencial: " << dineroPreferencial << "\n";

    return 0;
}

