int pot = A1; 
int led = 13; 
int valor = 0; 
int pot2 = A2; 
int led2 = 12; 
int valor2 = 0; 

void setup() { 
  pinMode(led, OUTPUT); 
  Serial.begin(9600); 
  pinMode(led, OUTPUT); 
} 

void loop() {
  valor = analogRead(pot); 
  digitalWrite(led, HIGH); 
  delay(valor); 
  digitalWrite(led, LOW); 
  delay(valor); 
  valor2 = analogRead(pot2); 
  Serial.println(valor2); 
  if(valor2 > 0) { 
    analogWrite(led2, (valor2/4));
  } 
}
