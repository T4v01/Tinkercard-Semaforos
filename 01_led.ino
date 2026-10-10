// ============================================
// Ejercicio 1: Encender y apagar un LED
// Autor: Gustavo Pantoja Olave
// Plataforma: Tinkercad Circuits / Arduino Uno
// ============================================
// Descripción:
//   El LED está conectado al pin digital 13.
//   Se enciende durante 1 segundo y se apaga
//   durante 1 segundo, en un ciclo infinito.
//
// Conexión:
//   - Ánodo del LED (pata larga)  -> pin 13
//   - Cátodo del LED (pata corta) -> resistencia 220Ω -> GND
// ============================================

void setup() {
  pinMode(13, OUTPUT);   // Configura el pin 13 como salida
}

void loop() {
  digitalWrite(13, HIGH);   // Enciende el LED
  delay(1000);              // Espera 1 segundo
  digitalWrite(13, LOW);    // Apaga el LED
  delay(1000);              // Espera 1 segundo
}
