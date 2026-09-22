int pinoBotao = A0; 
int pinoLed = 13;   

int estadoAtual = 0; // 0 = desligado, 1 = ligado, 2 = piscando

unsigned long tempoPressionado = 0;
unsigned long tempoMudancaEstado = 0;
unsigned long ultimoTempoPisca = 0;
unsigned long ultimoTempoDebounce = 0;

bool estadoBotao = HIGH; //HIGH = solto, LOW = pressionado, só para controlar melhor
bool ultimoEstadoLeitura = HIGH;
bool pressaoLonga = false;

void setup() {
  pinMode(pinoBotao, INPUT_PULLUP);
  pinMode(pinoLed, OUTPUT);
  digitalWrite(pinoLed, LOW);
}

void loop() {
  bool leitura = digitalRead(pinoBotao);

  // debounce
  if (leitura != ultimoEstadoLeitura) {
    ultimoTempoDebounce = millis();
  }
  // 50 ms de debounce, só ler após esse tempo
  if ((millis() - ultimoTempoDebounce) > 50) {
    if (leitura != estadoBotao) {
      estadoBotao = leitura;
      // esse bloco ocorre enquanto o botão estiver sendo apertado
      if (estadoBotao == LOW) { 
        tempoPressionado = millis();
        pressaoLonga = false;

        // se estiver piscando, desliga imediatamente ao pressionar
        if (estadoAtual == 2) {
          estadoAtual = 0; 
          tempoMudancaEstado = millis();
          digitalWrite(pinoLed, LOW);
          pressaoLonga = true; // evitar ação extra ao soltar
        }

      } else { // botão foi solto
        if (!pressaoLonga) {
          switch (estadoAtual) {
            case 0: // de desligado para ligado
              estadoAtual = 1;
              tempoMudancaEstado = millis();
              digitalWrite(pinoLed, HIGH);
              break;
            case 1: // de ligado para desligado
              estadoAtual = 0;
              tempoMudancaEstado = millis();
              digitalWrite(pinoLed, LOW);
              break;
          }
        }
      }
    }
  }

  // regras de tempo rodando continuamente
  switch (estadoAtual) {
    case 0:
      // segurou por 3 segundos
      if (estadoBotao == LOW && !pressaoLonga) {
        if (millis() - tempoPressionado >= 3000) {
          estadoAtual = 2; // muda para piscando
          tempoMudancaEstado = millis();
          ultimoTempoPisca = millis();
          digitalWrite(pinoLed, HIGH);
          pressaoLonga = true; 
        }
      }
      break;

    case 1:
      // passou 5 segundos
      if (millis() - tempoMudancaEstado >= 5000) {
        estadoAtual = 0; // desliga
        tempoMudancaEstado = millis();
        digitalWrite(pinoLed, LOW);
      }
      break;

    case 2:
      // passou 5 segundos
      if (millis() - tempoMudancaEstado >= 5000) {
        estadoAtual = 0; // desliga
        tempoMudancaEstado = millis();
        digitalWrite(pinoLed, LOW);
      } else {
        // continua piscando enquanto não der 5 segundos
        if (millis() - ultimoTempoPisca >= 250) {
          ultimoTempoPisca = millis();
          digitalWrite(pinoLed, !digitalRead(pinoLed));
        }
      }
      break;
  }
  ultimoEstadoLeitura = leitura;
}
