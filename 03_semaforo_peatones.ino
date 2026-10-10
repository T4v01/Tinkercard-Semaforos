// ============================================
// Ejercicio 3: Semáforo para carros y peatones
// Autor: Gustavo Pantoja Olave
// Plataforma: Tinkercad Circuits / Arduino Uno
// ============================================
// Descripción:
//   Coordina un semáforo de carros con uno de peatones.
//   Cuando los carros tienen verde, los peatones tienen rojo,
//   y viceversa. El verde peatonal parpadea antes de cambiar.
//
// Conexión:
//   Carros:
//     - Rojo     -> pin 10 -> resistencia 220Ω -> GND
//     - Amarillo -> pin 9  -> resistencia 220Ω -> GND
//     - Verde    -> pin 8  -> resistencia 220Ω -> GND
//   Peatones:
//     - Rojo  -> pin 6 -> resistencia 220Ω -> GND
//     - Verde -> pin 7 -> resistencia 220Ω -> GND
// ============================================

void setup() {
  pinMode(10, OUTPUT);  // Rojo carro
  pinMode(9, OUTPUT);   // Amarillo carro
  pinMode(8, OUTPUT);   // Verde carro
  pinMode(6, OUTPUT);   // Rojo peatón
  pinMode(7, OUTPUT);   // Verde peatón
}

void loop() {
  // ===== FASE 1: Carros verde / Peatones rojo =====
  digitalWrite(8, HIGH);   // Verde carro encendido
  digitalWrite(6, HIGH);   // Rojo peatón encendido
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  digitalWrite(7, LOW);
  delay(5000);

  // ===== FASE 2: Carros amarillo / Peatones rojo =====
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);   // Amarillo carro encendido
  delay(2000);
  digitalWrite(9, LOW);

  // ===== FASE 3: Carros rojo / Peatones verde =====
  digitalWrite(10, HIGH);  // Rojo carro encendido
  digitalWrite(6, LOW);    // Apaga rojo peatón
  digitalWrite(7, HIGH);   // Verde peatón encendido
  delay(5000);

  // ===== FASE 4: Verde peatón parpadea (aviso) =====
  for (int i = 0; i < 4; i++) {
    digitalWrite(7, LOW);
    delay(300);
    digitalWrite(7, HIGH);
    delay(300);
  }

  // ===== FASE 5: Regresar al estado inicial =====
  digitalWrite(7, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(10, LOW);
  delay(1000);
}
