int LEDs[] = {2, 3, 4, 5, 6, 7};
const int quantidadeLEDs = 6;

unsigned long tempoAnterior = 0;
const unsigned long intervalo = 500;

int LEDatual = 0;

void setup() {
  for (int i = 0; i < quantidadeLEDs; i++) {
    pinMode(LEDs[i], OUTPUT);
    digitalWrite(LEDs[i], LOW);
  }
}

void loop() {
  unsigned long tempoAtual = millis();

  if (tempoAtual - tempoAnterior >= intervalo) {
    tempoAnterior = tempoAtual;

    for (int i = 0; i < quantidadeLEDs; i++) {
      digitalWrite(LEDs[i], LOW);
    }

    digitalWrite(LEDs[LEDatual], HIGH);

    LEDatual++;

    if (LEDatual >= quantidadeLEDs) {
      LEDatual = 0;
    }
  }
}