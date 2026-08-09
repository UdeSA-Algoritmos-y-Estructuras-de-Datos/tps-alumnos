#ifndef TP1_TP1_H
#define TP1_TP1_H

/*
 * ============================================================
 *  Funciones que NO operan sobre un arreglo -> siguen siendo
 *  funciones libres.
 * ============================================================
 */

/*
 * Determina si un número es primo.
 */
bool is_prime(int x);

/*
 * Dado el volumen de un depósito D y el volumen de un producto V
 * la función calcula cuántos productos entran en el depósito.
 */
int storage_capacity(float d, float v);

/*
 * Intercambia dos valores de enteros.
 * Opera sobre dos enteros sueltos, no sobre un arreglo, por eso
 * se mantiene como función libre.
 */
void swap(int *x, int *y);

/*
 * ============================================================
 *  Arreglo de enteros -> clase CustomVector.
 *
 *  La clase es dueña de su memoria (RAII): la reserva en el
 *  constructor con new[] y la libera en el destructor con
 *  delete[]. Por eso no hace falta ninguna función para liberar
 *  a mano.
 * ============================================================
 */
class CustomVector {
private:
    int *data;
    int length;
    int capacity;

public:
    /*
     * Crea un vector de 'length' enteros sin inicializar.
     */
    explicit CustomVector(int length);

    /*
     * Crea un vector copiando 'length' enteros desde 'array'.
     */
    CustomVector(const int *array, int length);

    /*
     * Constructor de copia: hace una copia profunda.
     * (Reemplaza a la vieja función copy_array.)
     */
    CustomVector(const CustomVector &other);

    /*
     * Asignación por copia: copia profunda liberando lo anterior.
     * (Necesario junto al constructor de copia y al destructor:
     *  "regla de los tres".)
     */
    CustomVector &operator=(const CustomVector &other);

    /*
     * Destructor: libera la memoria con delete[].
     */
    ~CustomVector();

    /*
     * Cantidad de elementos del vector.
     */
    int get_length() const;

    /*
     * Acceso a un elemento por índice (lectura/escritura y solo lectura).
     */
    int &operator[](int i);
    const int &operator[](int i) const;

    /*
     * Devuelve el máximo del vector. (ex array_max)
     */
    int max() const;

    /*
     * Aplica la función a cada elemento del vector.
     * Si f es NULL no hace nada. (ex array_map)
     */
    void map(int (*f)(int));

    /*
     * Ordena el vector ascendentemente con bubble sort. (ex bubble_sort)
     */
    void bubble_sort();

    /*
     * Determina si dos vectores son idénticamente iguales. (ex array_equal)
     */
    bool equal(const CustomVector &other) const;

    /*
     * Determina si dos vectores son anagramas: en algún orden,
     * son el mismo arreglo. (ex integer_anagrams)
     */
    bool is_anagram(const CustomVector &other) const;

    /*
     * Cantidad de enteros para los que hay memoria reservada
     * actualmente (siempre >= get_length()).
     */
    int get_capacity() const;

    /*
     * Agrega 'value' al final del vector, creciendo la capacity
     * si hace falta.
     */
    void push_back(int value);

    /*
     * Quita el último elemento del vector.
     * Si el vector está vacío, no hace nada.
     */
    void remove();
};

/*
 * Juego de guerra de cartas: 'a' y 'b' son dos mazos. Por cada
 * ronda (posición) gana la carta más alta. Devuelve un
 * CustomVector nuevo con el ganador de cada ronda; las cartas
 * sobrantes del mazo más largo no juegan. Se libera con
 * destroy_vector.
 */
CustomVector *war_winner(const CustomVector &a, const CustomVector &b);

/*
 * Libera un CustomVector reservado con war_winner.
 */
void destroy_vector(CustomVector *vector);

/*
 * Torneo de eliminación: 'decks' tiene 'num_decks' mazos. Arranca
 * con decks[0] como campeón y lo va enfrentando, uno por uno,
 * contra cada mazo siguiente con war_winner. En cada pelea se
 * liberan el campeón anterior y el mazo que perdió, y el ganador
 * de war_winner pasa a ser el nuevo campeón.
 * La función toma posesión de 'decks' (el array y los mazos se
 * liberan durante el torneo) y devuelve el campeón final, que hay
 * que liberar aparte con destroy_vector.
 */
CustomVector *tournament_champion(CustomVector **decks, int num_decks);

#endif // TP1_TP1_H
