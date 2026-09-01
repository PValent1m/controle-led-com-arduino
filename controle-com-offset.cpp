int offset = 0;
void setup() {
  pinMode(A3, INPUT);
  pinMode(10, OUTPUT);
  pinMode(2,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  
  int valor_lido = analogRead(A3);
  int novo_valor = map(valor_lido,offset,1023,0,255);
  int botao = digitalRead(2);
  
  if(Serial.available()){
    char letra = Serial.read();
    if(letra == 'r' || letra  == 'R'){
      offset = 0;
    }
  }
  if(valor_lido<=offset){
    analogWrite(10, LOW);

  }

  else{
  analogWrite(10, novo_valor);
  Serial.println(offset);
  if(botao == 0){
    analogWrite(10, offset);
    offset = valor_lido;
    }
  }
 
}
