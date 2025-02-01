// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 01 : Complejidad_computacional
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 01/31/25
// Archivo Multiplicacion.h : Declaración de la clase Multiplicacion
//        En este fichero se declara la clase Multiplicacion
//
// Historial de revisiones
//        01/31/25 - Creación (primera versión) del código
#ifndef C_Multiplicacion_H
#define C_Multiplicacion_H
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
typedef vector<vector<int>> Matrix;

class Multiplicacion {
 public:
  virtual Matrix solve(const Matrix &A, const Matrix &B) = 0;
  virtual ~Multiplicacion() {}
 protected:
  
};

class Multiplicacion_por_fila : public Multiplicacion {
 public:
  Matrix solve(const Matrix &A, const Matrix &B) override;
 private:
  
};

class Multiplicacion_por_columna : public Multiplicacion {
 public:
  Matrix solve(const Matrix &A, const Matrix &B) override;
 private:
  
};

#endif