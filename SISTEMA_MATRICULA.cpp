#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Estructura para almacenar la informacion de un estudiante
class Estudiante {
public:
    string nombre;
    string cedula;
    string carrera;
    string nivel;

    Estudiante(string nombre, string cedula, string carrera, string nivel)
        : nombre(nombre), cedula(cedula), carrera(carrera), nivel(nivel) {}
};

// Estructura para almacenar la informacion de un curso
class Curso {
public:
    string nombre;
    string codigo;
    int creditos;
    string profesor;

    Curso(string nombre, string codigo, int creditos, string profesor)
        : nombre(nombre), codigo(codigo), creditos(creditos), profesor(profesor) {}
};

// Estructura para almacenar la informacion del horario
class Horario {
public:
    string dia;
    string hora_inicio;
    string hora_fin;
    string aula;

    Horario(string dia, string hora_inicio, string hora_fin, string aula)
        : dia(dia), hora_inicio(hora_inicio), hora_fin(hora_fin), aula(aula) {}
};

// Estructura para gestionar la matricula de los estudiantes
class Matricula {
public:
    Estudiante* estudiante;
    vector<Curso*> cursos;
    double costo;

    Matricula(Estudiante* estudiante)
        : estudiante(estudiante), costo(0) {}

    void registrarCurso(Curso* curso) {
        cursos.push_back(curso);
        costo += curso->creditos * 50.0;  // Suponemos que cada credito cuesta 50 unidades
    }

    void mostrarMatricula() {
        cout << "Estudiante: " << estudiante->nombre << endl;
        cout << "Cursos Matriculados: " << endl;
        for (auto& curso : cursos) {
            cout << "- " << curso->nombre << " (" << curso->codigo << ")" << endl;
        }
        cout << "Costo total: " << costo << endl;
    }
};

class Sistema {
private:
    vector<Estudiante> estudiantes;
    vector<Curso> cursos;
    vector<Horario> horarios;
    vector<Matricula> matriculas;

public:
    void mostrarMenu() {
        cout << "\n1. Archivo\n";
        cout << "   1.1 Acerca de\n";
        cout << "   1.2 Salir\n";
        cout << "2. Mantenimiento\n";
        cout << "   2.1 Estudiantes\n";
        cout << "   2.2 Cursos\n";
        cout << "   2.3 Horarios\n";
        cout << "3. Matricula\n";
        cout << "   3.1 Registro de Matricula\n";
        cout << "4. Consulta\n";
        cout << "   4.1 Estudiantes\n";
        cout << "   4.2 Cursos\n";
        cout << "Selecciona una opcion: ";
    }

    void mostrarAcercaDe() {
        cout << "\nSistema desarrollado por el Ingeniero Anderson Chacon, "
            << "dueno de Futures Company.\n"
            << "Este sistema fue desarrollado para brindar un uso facil "
            << "al sistema de matricula de la Universidad Nacional.\n"
            << "El sistema creado es muy intuitivo y facil de usar, "
            << "disfruten del programa.\n"
            << "Soporte tecnico a 62929423 y chaconsamuel8@gmail.com\n";
    }

    void agregarEstudiante() {
        string nombre, cedula, carrera, nivel;
        cout << "Nombre del estudiante: ";
        cin >> nombre;
        cout << "Cedula: ";
        cin >> cedula;
        cout << "Carrera: ";
        cin >> carrera;
        cout << "Nivel: ";
        cin >> nivel;

        estudiantes.push_back(Estudiante(nombre, cedula, carrera, nivel));
        cout << "Estudiante registrado exitosamente." << endl;
    }

    void agregarCurso() {
        string nombre, codigo, profesor;
        int creditos;
        cout << "Nombre del curso: ";
        cin >> nombre;
        cout << "Codigo: ";
        cin >> codigo;
        cout << "Creditos: ";
        cin >> creditos;
        cout << "Profesor: ";
        cin >> profesor;

        cursos.push_back(Curso(nombre, codigo, creditos, profesor));
        cout << "Curso registrado exitosamente." << endl;
    }

    void agregarHorario() {
        string dia, hora_inicio, hora_fin, aula;
        cout << "Dia: ";
        cin >> dia;
        cout << "Hora de inicio: ";
        cin >> hora_inicio;
        cout << "Hora de fin: ";
        cin >> hora_fin;
        cout << "Aula: ";
        cin >> aula;

        horarios.push_back(Horario(dia, hora_inicio, hora_fin, aula));
        cout << "Horario registrado exitosamente." << endl;
    }

    void registrarMatricula() {
        string cedula;
        cout << "Ingrese la cedula del estudiante: ";
        cin >> cedula;

        Estudiante* estudiante = nullptr;
        for (auto& est : estudiantes) {
            if (est.cedula == cedula) {
                estudiante = &est;
                break;
            }
        }

        if (estudiante == nullptr) {
            cout << "Estudiante no encontrado." << endl;
            return;
        }

        Matricula matricula(estudiante);

        cout << "Cursos disponibles:" << endl;
        for (int i = 0; i < cursos.size(); i++) {
            cout << i + 1 << ". " << cursos[i].nombre << endl;
        }

        int opcion;
        cout << "Seleccione el curso a matricular (0 para terminar): ";
        while (cin >> opcion && opcion != 0) {
            if (opcion > 0 && opcion <= cursos.size()) {
                matricula.registrarCurso(&cursos[opcion - 1]);
            }
            cout << "Seleccione otro curso (0 para terminar): ";
        }

        matricula.mostrarMatricula();
        matriculas.push_back(matricula);
    }

    void consultarEstudiantes() {
        cout << "Estudiantes registrados:" << endl;
        for (auto& est : estudiantes) {
            cout << "- " << est.nombre << " (" << est.cedula << ")" << endl;
        }
    }

    void consultarCursos() {
        cout << "Cursos disponibles:" << endl;
        for (auto& cur : cursos) {
            cout << "- " << cur.nombre << " (" << cur.codigo << ") Profesor: " << cur.profesor << endl;
        }
    }

    void ejecutar() {
        int opcion;
        do {
            mostrarMenu();
            cin >> opcion;
            switch (opcion) {
            case 1:
                mostrarAcercaDe();
                break;
            case 2:
                cout << "\n1. Estudiantes\n2. Cursos\n3. Horarios\nSeleccione opcion: ";
                cin >> opcion;
                if (opcion == 1) agregarEstudiante();
                else if (opcion == 2) agregarCurso();
                else if (opcion == 3) agregarHorario();
                break;
            case 3:
                registrarMatricula();
                break;
            case 4:
                cout << "\n1. Estudiantes\n2. Cursos\nSeleccione opcion: ";
                cin >> opcion;
                if (opcion == 1) consultarEstudiantes();
                else if (opcion == 2) consultarCursos();
                break;
            case 0:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
                break;
            }
        } while (opcion != 0);
    }
};

int main() {
    Sistema sistema;
    sistema.ejecutar();
    return 0;
}
