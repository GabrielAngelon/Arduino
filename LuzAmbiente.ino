int ledVermelho = 5; //ledVermelho
int ledAmarelo = 6; //ledAmarelo
int ledVerde = 7; //ledVerde

int sensorLDR = A5; //sensor de luz
int buzzerPin = 9; //buzzer

int Velho = -1; // variavel para rastrear o estado anterior
bool buzzerTocado = false; // variavel de controle do buzzer

void setup()
{
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);

  pinMode(buzzerPin , OUTPUT);
  pinMode(sensorLDR, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int leitura = analogRead(sensorLDR);
  Serial.println(leitura);
  
  int Novo = -1; // variavel para rastrear o novo estado

  if (leitura >= 889 && leitura <= 916) { //100% e 80%
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, LOW);
    Novo = 3; // estado correspondente ao LED vermelho
  }  
  else if (leitura > 916 && leitura <= 956) { // 79% e 50%
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledVerde, LOW);
    Novo = 2; // estado correspondente ao LED amarelo
  }
  else if (leitura > 956) { // 49%
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledVerde, HIGH);
    Novo = 1; // estado correspondente ao LED verde
  }
  
  // verificar mudança de estado
  if (Novo != Velho) {
    if (Novo == 3) { // tocar o buzzer três vezes para o LED vermelho
      for (int i = 0; i < 3; i++) {
        tone(buzzerPin, 1200); // liga o buzzer
        delay(500);
        noTone(buzzerPin); // desliga o buzzer
        delay(500);
      }
    }
    else if (Novo == 2) { // tocar o buzzer duas vezes para o LED amarelo
      for (int i = 0; i < 2; i++) {
        tone(buzzerPin, 1200); // liga o buzzer
        delay(500);
        noTone(buzzerPin); // desliga o buzzer
        delay(500);
      }
    }
    else if (Novo == 1) { // tocar o buzzer uma vez para o LED verde
      tone(buzzerPin, 1200); // Liga o buzzer
      delay(500);
      noTone(buzzerPin); // desliga o buzzer
      delay(500);
    }
    // atualizar o estado anterior
    Velho = Novo;
  }
}
