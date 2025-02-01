// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 01 : Complejidad_computacional
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 01/31/25
// Archivo Multiplicacion.cc: Implementación de Multiplicacion
//        En este fichero se implementa las funciones de la clase Multiplicacion
//
// Historial de revisiones
//        01/31/25 - Creación (primera versión) del código

#include"Multiplicacion.h"

/** Matrix Multiplicacion_por_fila::solve(const Matrix &A, const Matrix &B)
  * @brief Función que realiza la multiplicación de dos matrices mediante la estrategia de recorrer la matriz por filas.
  * @param A Matriz a multiplicar.
  * @param B Matriz a multiplicar.
  * @return Matriz resultante de la multiplicación de las dos matrices.
  */
Matrix Multiplicacion_por_fila::solve(const Matrix &Matrix_A, const Matrix &Matrix_B) {
  int m = Matrix_A.size(); // filas de A
  int p = Matrix_A[0].size();  // columnas de A, también filas de B
  int n = Matrix_B[0].size();  // columnas de B

  // Inicializa la matriz resultado con ceros.
  Matrix Matrix_C(m, vector<int>(n, 0));

  // Recorre la matriz A por filas.
  for (int i = 0; i < m; ++i) { // Recorre las filas de A
    for (int j = 0; j < n; ++j) { // Recorre las columnas de B
      for (int k = 0; k < p; ++k) { // Recorre las columnas de A y las filas de B
        Matrix_C[i][j] += Matrix_A[i][k] * Matrix_B[k][j];
      }
    }
  }
  return Matrix_C;
}

/** Matrix Multiplicacion_por_columna::solve(const Matrix &A, const Matrix &B)
  * @brief Función que realiza la multiplicación de dos matrices mediante la estrategia de recorrer la matriz por columnas.
  * @param A Matriz a multiplicar.
  * @param B Matriz a multiplicar.
  * @return Matriz resultante de la multiplicación de las dos matrices.
  */
Matrix Multiplicacion_por_columna::solve(const Matrix &Matrix_A, const Matrix &Matrix_B) {
  int m = Matrix_A.size();
  int p = Matrix_A[0].size();
  int n = Matrix_B[0].size();

  Matrix Matrix_C(m, vector<int>(n, 0));

  for (int j = 0; j < n; ++j) { // recorre las columnas de B
    for (int i = 0; i < m; ++i) { // recorre las filas de A
      for (int k = 0; k < p; ++k) { 
        Matrix_C[i][j] += Matrix_A[i][k] * Matrix_B[k][j];
      }
    }
  }

  return Matrix_C;
}
