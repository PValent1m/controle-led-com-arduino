  //variáveis convencionais
  int estado=0;
  int r = 8;
  int g = 7;

  void setup() {
    pinMode(A0, INPUT_PULLUP);
    pinMode(r,OUTPUT);
    pinMode(g,OUTPUT);
    digitalWrite(r, LOW);
    digitalWrite(g,LOW);
  }

  void loop() {

    int botao = digitalRead(A0);
//maquina de estado
    switch(estado){

      case 0: 

      if(botao==0) {
        estado = 1; 
        digitalWrite(g,HIGH);
        digitalWrite(r, LOW); 
        delay(50);
      }
      break;

      case 1:

      if(botao==1) { 
        estado = 2;
        delay(50);
      }
      break;

      case 2:

      if(botao==0) {
        estado = 3;
        digitalWrite(g,LOW);
        digitalWrite(r,HIGH);
        delay(50);
      }
      break;

      case 3:

      if(botao==1) {
        estado = 4;
        delay(50);
      }
      break;

      case 4:

      if(botao==0) {
        estado = 5;
        digitalWrite(g,LOW);
        digitalWrite(r,LOW);
        delay(50);
      }
      break;

      case 5:

      if(botao==1) {
        estado = 6;
        delay(50);
      }
      break;

      case 6:
      
      if(botao==0) {
        estado = 7;
        digitalWrite(g,HIGH);
        digitalWrite(r,HIGH);
        delay(50);
      }
      break;

      case 7:

      if(botao==1) {
        estado = 8;
        delay(50);
      }
      break;

      case 8:

      if(botao==0) {
        estado = 9;
        digitalWrite(g,LOW);
        digitalWrite(r,LOW);
        delay(50);
      }
      break;

      case 9:

      if(botao==1) {
        estado = 0;
        delay(50);
      }
      break;

    }
  }
