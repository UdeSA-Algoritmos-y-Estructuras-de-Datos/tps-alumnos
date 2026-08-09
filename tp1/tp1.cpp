#include "tp1.h"

/* ---------------------------------------------------------------
 * Parte 1: funciones libres (no operan sobre un arreglo).
 * --------------------------------------------------------------- */

bool is_prime(int x) {
    // TODO: determinar si x es primo.
    return false;
}

int storage_capacity(float d, float v) {
    // TODO: calcular cuántos productos de volumen v entran en el depósito d.
    return 0;
}

void swap(int *x, int *y) {
    // TODO: intercambiar los valores de x e y.
}

/* ---------------------------------------------------------------
 * Parte 2: CustomVector. Administra su propia memoria con
 * new/delete. Recordá la regla de los tres: destructor,
 * constructor de copia y operator=.
 * --------------------------------------------------------------- */

CustomVector::CustomVector(int length) {
    // TODO: reservar memoria para 'length' enteros y setear capacity.
    this->length = 0;
    this->capacity = 0;
    this->data = nullptr;
}

CustomVector::CustomVector(const int *array, int length) {
    // TODO: reservar memoria, copiar 'length' enteros desde 'array' y
    // setear capacity.
    this->length = 0;
    this->capacity = 0;
    this->data = nullptr;
}

CustomVector::CustomVector(const CustomVector &other) {
    // TODO: copia profunda del contenido de 'other' (incluida capacity).
    this->length = 0;
    this->capacity = 0;
    this->data = nullptr;
}

CustomVector &CustomVector::operator=(const CustomVector &other) {
    // TODO: liberar lo anterior y hacer una copia profunda de 'other'
    // (incluida capacity).
    return *this;
}

CustomVector::~CustomVector() {
    // TODO: liberar la memoria del vector.
}

int CustomVector::get_length() const {
    return this->length;
}

int &CustomVector::operator[](int i) {
    // TODO: devolver el elemento en la posición i.
    return this->data[i];
}

const int &CustomVector::operator[](int i) const {
    // TODO: devolver el elemento en la posición i.
    return this->data[i];
}

int CustomVector::max() const {
    // TODO: devolver el máximo del vector.
    return 0;
}

void CustomVector::map(int (*f)(int)) {
    // TODO: aplicar f a cada elemento. Si f es NULL, no hacer nada.
}

void CustomVector::bubble_sort() {
    // TODO: ordenar el vector ascendentemente con bubble sort.
}

bool CustomVector::equal(const CustomVector &other) const {
    // TODO: determinar si los dos vectores son idénticamente iguales.
    return false;
}

bool CustomVector::is_anagram(const CustomVector &other) const {
    // TODO: determinar si los dos vectores son anagramas.
    return false;
}

int CustomVector::get_capacity() const {
    return this->capacity;
}

void CustomVector::push_back(int value) {
    // TODO: agregar 'value' al final del vector, creciendo la capacity
    // si hace falta.
}

void CustomVector::remove() {
    // TODO: quitar el último elemento del vector. Si está vacío, no
    // hacer nada.
}

/* ---------------------------------------------------------------
 * Parte 3: reserva de UN solo objeto (new / delete escalar).
 * --------------------------------------------------------------- */

CustomVector *war_winner(const CustomVector &a, const CustomVector &b) {
    // TODO: devolver un CustomVector nuevo con el ganador de cada
    // ronda (el máximo entre a[i] y b[i]).
    return nullptr;
}

void destroy_vector(CustomVector *vector) {
    // TODO: liberar vector con delete (versión escalar, sin []).
}

CustomVector *tournament_champion(CustomVector **decks, int num_decks) {
    // TODO: enfrentar decks[0] contra cada mazo siguiente con
    // war_winner, liberando el campeón anterior y el mazo que
    // perdió en cada pelea, y devolver el campeón final.
    return nullptr;
}
