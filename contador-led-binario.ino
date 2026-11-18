const int PINES[] = {13, 12, 14, 27};  // de izquierda (8) a derecha (1)
const int BITS = 4;
const int VELOCIDAD_MS = 700;          // tiempo entre cada numero

void mostrarNumero(int numero) {
  for (int i = 0; i < BITS; i++) {
    // El primer LED representa el bit 3 (valor 8), el ultimo el bit 0 (valor 1)
    int bit = (numero >> (BITS - 1 - i)) & 1;
    digitalWrite(PINES[i], bit);
  }
}

void setup() {
  Serial.begin(115200);

  for (int i = 0; i < BITS; i++) {
    pinMode(PINES[i], OUTPUT);
    digitalWrite(PINES[i], LOW);
  }

  Serial.println("\n=== Contador binario ===");
  Serial.println("LEDs de izquierda a derecha valen: 8 4 2 1\n");
}

void loop() {
  for (int n = 0; n < 16; n++) {
    mostrarNumero(n);

    // Imprimir en decimal y binario (con ceros a la izquierda)
    Serial.printf("Decimal: %2d  |  Binario: ", n);
    for (int b = BITS - 1; b >= 0; b--) {
      Serial.print((n >> b) & 1);
    }
    Serial.println();

    delay(VELOCIDAD_MS);
  }

  Serial.println("--- reinicio ---\n");
  delay(1000);
}