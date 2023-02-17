/**
 * \file buttonDebounce.hpp
 * \brief Archivo de cabecera para la lectura de botones con una metodologia anti rebotes.
 * \author Joseph Santiago Portilla. Ing. Electrónico - @JoePortilla
 */

#ifndef BUTTONDEBOUNCE_HPP
#define BUTTONDEBOUNCE_HPP

/**
 * \brief Clase para instanciar un Boton. Incluye funciones que permiten configurar sus pines,
 * tipo de entrada, retardo de rebote y obtener la lectura de su estado.
 */
class Boton
{
public:
    /**
     * \brief Constructor inicial.
     */
    Boton();

    /**
     * \brief Función para configurar el boton.
     * \param pin: GPIO al que se conecta el botón.
     * \param inputType: Tipo de entrada del GPIO (INPUT_PULLDOWN, INPUT_PULLUP, INPUT)
     * \param debounceDelay: Tiempo de espera para la estabilización de la señal del botón.
     * \returns No hay retorno.
     */
    void setup(uint8_t pin, uint8_t inputType = INPUT_PULLDOWN, unsigned long debounceDelay = 50);

    /**
     * \brief Función para leer el estado del botón.
     * \param NA: Sin párametros.
     * \returns Estado del botón. (0 ó 1)
     */
    bool status();

private:
    int _pin;                     // GPIO al que se conecta el botón.
    int _inputType;               // Tipo de entrada del GPIO (INPUT_PULLDOWN, INPUT_PULLUP, INPUT)
    unsigned long _debounceDelay; // Tiempo de espera para la estabilización de la señal del botón.
};

#endif