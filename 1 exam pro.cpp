#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Empleado {
    string cedula;
    string nombre;
    int tipo;
    double horasLaboradas;
    double precioHora;
    double salarioOrdinario;
    double aumento;
    double salarioBruto;
    double deduccionCCSS;
    double salarioNeto;
};

void calcularSalarios(Empleado &empleado) {
    empleado.salarioOrdinario = empleado.horasLaboradas * empleado.precioHora;
    switch (empleado.tipo) {
        case 1:
            empleado.aumento = empleado.salarioOrdinario * 0.15;
            break;
        case 2:
            empleado.aumento = empleado.salarioOrdinario * 0.10;
            break;
        case 3:
            empleado.aumento = empleado.salarioOrdinario * 0.05;
            break;
        default:
            empleado.aumento = 0;
            break;
    }
    empleado.salarioBruto = empleado.salarioOrdinario + empleado.aumento;
    empleado.deduccionCCSS = empleado.salarioBruto * 0.0917;
    empleado.salarioNeto = empleado.salarioBruto - empleado.deduccionCCSS;
}

void mostrarEmpleado(const Empleado &empleado) {
    cout << "Cédula: " << empleado.cedula << endl;
    cout << "Nombre: " << empleado.nombre << endl;
    cout << "Tipo de Empleado: " << empleado.tipo << endl;
    cout << "Salario por Hora: " << empleado.precioHora << endl;
    cout << "Cantidad de Horas Laboradas: " << empleado.horasLaboradas << endl;
    cout << "Salario Ordinario: " << empleado.salarioOrdinario << endl;
    cout << "Aumento: " << empleado.aumento << endl;
    cout << "Salario Bruto: " << empleado.salarioBruto << endl;
    cout << "Deducción CCSS: " << empleado.deduccionCCSS << endl;
    cout << "Salario Neto: " << empleado.salarioNeto << endl;
}

void mostrarEstadisticas(const vector<Empleado> &empleados) {
    int countOperarios = 0, countTecnicos = 0, countProfesionales = 0;
    double totalOperarios = 0, totalTecnicos = 0, totalProfesionales = 0;

    for ( auto &empleado : empleados) {
        switch (empleado.tipo) {
            case 1:
                countOperarios++;
                totalOperarios += empleado.salarioNeto;
                break;
            case 2:
                countTecnicos++;
                totalTecnicos += empleado.salarioNeto;
                break;
            case 3:
                countProfesionales++;
                totalProfesionales += empleado.salarioNeto;
                break;
        }
    }

    cout << "Cantidad de Operarios: " << countOperarios << endl;
    cout << "Cantidad de Técnicos: " << countTecnicos << endl;
    cout << "Cantidad de Profesionales: " << countProfesionales << endl;

    if (countOperarios > 0) cout << "Promedio Salario Neto Operarios: " << totalOperarios / countOperarios << endl;
    if (countTecnicos > 0) cout << "Promedio Salario Neto Técnicos: " << totalTecnicos / countTecnicos << endl;
    if (countProfesionales > 0) cout << "Promedio Salario Neto Profesionales: " << totalProfesionales / countProfesionales << endl;
}

int main() {
    vector<Empleado> empleados;
    char continuar;

    do {
        Empleado empleado;
        cout << "Ingrese la cédula del empleado: ";
        cin >> empleado.cedula;
        cout << "Ingrese el nombre completo del empleado: ";
        cin.ignore();
        getline(cin, empleado.nombre);
        cout << "Ingrese el tipo de empleado (1-Operario, 2-Técnico, 3-Profesional): ";
        cin >> empleado.tipo;
        cout << "Ingrese la cantidad de horas laboradas: ";
        cin >> empleado.horasLaboradas;
        cout << "Ingrese el precio por hora: ";
        cin >> empleado.precioHora;

        calcularSalarios(empleado);
        empleados.push_back(empleado);

        cout << "¿Desea ingresar otro empleado? (s/n): ";
        cin >> continuar;
    } while (continuar == 's' || continuar == 'S');

    for (const auto &empleado : empleados) {
        mostrarEmpleado(empleado);
        cout << "------------------------" << endl;
    }

    mostrarEstadisticas(empleados);

    return 0;
}

