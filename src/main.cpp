/**
 * \file main.hpp
 * \brief Ejemplo de medición antirebotes del estado de un botón pulsador
 * \author Joseph Santiago Portilla. Ing. Electrónico - @JoePortilla
 */

#include <Arduino.h>
#include "buttonDebounce.hpp"

// Creación de un objeto de la clase Boton
Boton button1;

const uint8_t button1Pin = 15; // GPIO al que se conecta el botón.
uint8_t i = 0;                 // Contador de ejemplo

void setup()
{
  // Inicializar la comunicación serial a 115200 baudios.
  Serial.begin(115200);
  // Ajustes iniciales del botón
  button1.setup(button1Pin, INPUT_PULLDOWN);
}

void loop()
{
  // Si se presiona el botón aumentar el contador en 1 e imprimir.
  if (button1.status() == 1)
  {
    i++;
    Serial.println(i);
  }
}
