/**
 * \file buttonDebounce.cpp
 * \brief Archivo de implementación para la lectura de botones con una metodologia anti rebotes.
 * \author Joseph Santiago Portilla. Ing. Electrónico - @JoePortilla
 */

#include <Arduino.h>
#include "buttonDebounce.hpp"

bool buttonStatus = 0;                  // Estado actual del botón al ser leido por digitalRead()
bool lastStatus = 0;                    // Variable para detectar un cambio en el estado del botón.
bool cleanStatus = 0;                   // Lectura del estado estabilizado del botón
unsigned long lastStatusChangeTime = 0; // Tiempo transcurrido desde el primer cambio del estado del botón.

Boton::Boton() {}

void Boton::setup(uint8_t pin, uint8_t inputType, unsigned long debounceDelay)
{
    // Ajuste de variables
    _pin = pin;
    _debounceDelay = debounceDelay;
    _inputType = inputType;
    // Definición del pin como entrada del tipo _inputType.
    pinMode(_pin, _inputType);
}

bool Boton::status()
{
    // Lectura del estado del botón
    buttonStatus = digitalRead(_pin);

    // Se detecta si hubo un cambio en el estado del botón
    if (buttonStatus != lastStatus)
    {
        // Se reinicia el temporizador que permite controlar que pase suficiente tiempo para
        // que la señal del botón se estabilice.
        lastStatusChangeTime = millis();
    }

    // Se verifica que haya pasado el tiempo de estabilización Y se detecta si hubo cambio en el estado del botón.
    if ((millis() > lastStatusChangeTime + _debounceDelay) && (buttonStatus != cleanStatus))
    {
        // Lectura del estado estabilizado del botón
        cleanStatus = buttonStatus;
        // Si el botón esta pulsado
        if (cleanStatus == 1)
        {
            // Retorna un valor alto
            return 1;
        }
    }

    // Actualización del estado del botón.
    lastStatus = buttonStatus;

    // Si el botón no esta pulsado retorna un valor bajo.
    return 0;
}