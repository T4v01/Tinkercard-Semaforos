// ============================================
// Ejercicio 4: Semáforo con botón peatonal
// Autor: Gustavo Pantoja Olave
// Plataforma: Tinkercad Circuits / Arduino Uno
// ============================================
// Descripción:
//   Los carros permanecen en verde hasta que un peatón
//   presiona el botón. Entonces comienza el ciclo:
//   amarillo -> rojo carro -> verde peatón -> parpadeo -> reinicio.
//
// Conexión:
//   Carros:
//     - Rojo     -> pin 10 -> resistencia 220Ω -> GND
//     - Amarillo -> pin 9  -> resistencia 220Ω -> GND
//     - Verde    -> pin 8  -> resistencia 220Ω -> GND
//   Peatones:
//     - Rojo  -> pin 6 -> resistencia 220Ω -> GND
//     - Verde -> pin 7 -> resistencia 220Ω -> GND
//   Botón:
//     - 5V        -> pata 1a del pulsador
//     - Pin 2     -> pata 2a del pulsador
//     - Pin 2     -> resistencia 10kΩ -> GND (pull-down)
// ============================================

const int cRojo = 10;
const int cAmarillo = 9;
const int cVerde = 8;
const int pRojo = 6;
const int pVerde = 7;
const int boton = 2;

void setup() {
  pinMode(cRojo, OUTPUT);
  pinMode(cAmarillo, OUTPUT);
  pinMode(cVerde, OUTPUT);
  pinMode(pRojo, OUTPUT);
  pinMode(pVerde, OUTPUT);
  pinMode(boton, INPUT);

  // Estado inicial: carros en verde, peatones en rojo
  digitalWrite(cVerde, HIGH);
  digitalWrite(pRojo, HIGH);
}

void loop() {
  // Leer si el botón fue presionado
  if (digitalRead(boton) == HIGH) {
    delay(50);  // Antirrebote

    // ===== FASE 1: Carros verde -> amarillo =====
    digitalWrite(cVerde, LOW);
    digitalWrite(cAmarillo, HIGH);
    delay(2000);
    digitalWrite(cAmarillo, LOW);

    // ===== FASE 2: Carros rojo / Peatones verde =====
    digitalWrite(cRojo, HIGH);
    digitalWrite(pRojo, LOW);
    digitalWrite(pVerde, HIGH);
    delay(5000);

    // ===== FASE 3: Verde peatón parpadea (aviso) =====
    for (int i = 0; i < 4; i++) {
      digitalWrite(pVerde, LOW);
      delay(300);
      digitalWrite(pVerde, HIGH);
      delay(300);
    }

    // ===== FASE 4: Regresar al estado inicial =====
    digitalWrite(pVerde, LOW);
    digitalWrite(pRojo, HIGH);
    digitalWrite(cRojo, LOW);
    digitalWrite(cVerde, HIGH);
  }
}
