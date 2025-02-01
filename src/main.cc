// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 01 : Complejidad_computacional
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 01/31/25
// Archivo main.cc: Implementación del programa cliente
//        En este fichero se implementa la función del main
//
// Historial de revisiones
//        01/31/25 - Creación (primera versión) del código
#include"funciones_main/funciones_main.h"
#include"Multiplicacion/Multiplicacion.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
#include <iomanip>

int main(int argc, char *argv[]) {
  //Compruebo si se han introducido los argumentos necesarios
  Dato datos = recoger_parametro(argc, argv);
  if (datos.correcto == false) {
    std::cerr << "Error no se han introducido los datos correctamente" << std::endl;
    return 1;
  }
  // Inicializa la semilla para números aleatorios.
  srand(static_cast<unsigned int>(time(nullptr)));

  // Abrimos el archivo CSV para escritura.
  ofstream csvFile("resultados.csv");
  if (!csvFile.is_open()) {
    cerr << "No se pudo abrir el archivo resultados.csv para escritura." << endl;
    return 1;
  }

  // Escribimos la cabecera del CSV.
  csvFile << "tamaño,tiempo del algoritmo por filas,tiempo del algoritmo por columnas\n";
  
  // Inicializo el vector de estrategias de multiplicación.
  vector<Multiplicacion *> Estrategias = {new Multiplicacion_por_fila(), new Multiplicacion_por_columna()};

  int size_limit = datos.limit;
  for (int redundancia = 0 ; redundancia < 1 ; redundancia++) {
    for (int size = 1; size <= size_limit; size += 1) {
      // Genera matrices aleatorias cuadradas A y B de tamaño "size".
      Matrix Matrix_A = generateRandomMatrix(size, size);
      Matrix Matrix_B = generateRandomMatrix(size, size);
      
      // Estrategia 1: Recorrido por filas.
      auto start = chrono::high_resolution_clock::now();
      Matrix Matrix_C1 = Estrategias[0]->solve(Matrix_A, Matrix_B);
      auto end = chrono::high_resolution_clock::now();
      chrono::duration<double> durationRow = end - start;

      // Estrategia 2: Recorrido por columnas.
      start = chrono::high_resolution_clock::now();
      Matrix Matrix_C2 = Estrategias[1]->solve(Matrix_A, Matrix_B);
      end = chrono::high_resolution_clock::now();
      chrono::duration<double> durationCol = end - start;
      
      // Comprueba si las matrices son iguales.
      // cout << (Matrix_C1 == Matrix_C2);
      
      // Muestra los tiempos en consola.
      cout << "Tamaño: " << size << " x " << size << "\n";
      cout << "Tiempo (recorrido por filas): " << fixed << setprecision(10) << durationRow.count() << " ms\n";
      cout << "Tiempo (recorrido por columnas): " << fixed << setprecision(10) << durationCol.count() << " ms\n";
      cout << "---------------------------------------\n";

      // Escribe los datos en el archivo CSV.
      csvFile << size + (redundancia * size_limit) << "," << fixed << setprecision(10) << durationRow.count() << "," << fixed << setprecision(10) << durationCol.count() << "\n";

    }
  }
  delete Estrategias[0];
  delete Estrategias[1];

  csvFile.close();
  cout << "Se han guardado los resultados en resultados.csv" << endl;
  return 0;
}