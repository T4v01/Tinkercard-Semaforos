// ============================================
// Ejercicio 2: Semáforo americano
// Autor: Gustavo Pantoja Olave
// Plataforma: Tinkercad Circuits / Arduino Uno
// ============================================
// Descripción:
//   Simula un semáforo americano con 3 LEDs.
//   Secuencia: Verde (5s) -> Amarillo (2s) -> Rojo (5s)
//   Se repite infinitamente.
//
// Conexión:
//   - LED rojo     -> pin 10 -> resistencia 220Ω -> GND
//   - LED amarillo -> pin 9  -> resistencia 220Ω -> GND
//   - LED verde    -> pin 8  -> resistencia 220Ω -> GND
// ============================================

void setup() {
  pinMode(10, OUTPUT);  // LED rojo
  pinMode(9, OUTPUT);   // LED amarillo
  pinMode(8, OUTPUT);   // LED verde
}

void loop() {
  // ===== Verde encendido 5 segundos =====
  digitalWrite(8, HIGH);
  delay(5000);
  digitalWrite(8, LOW);

  // ===== Amarillo encendido 2 segundos =====
  digitalWrite(9, HIGH);
  delay(2000);
  digitalWrite(9, LOW);

  // ===== Rojo encendido 5 segundos =====
  digitalWrite(10, HIGH);
  delay(5000);
  digitalWrite(10, LOW);
}
