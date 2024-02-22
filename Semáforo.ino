void setup()
{
pinMode(13, OUTPUT); //vermelho carros
pinMode(12, OUTPUT); //amarelo carros
pinMode(11, OUTPUT); //verde carros
pinMode(10, OUTPUT); //vermelho pessoa
pinMode(9, OUTPUT); //verde pessoa
}
void loop()
{
digitalWrite(13, HIGH); //vermelho carros
digitalWrite(9, HIGH); //verde pessoa
delay(8000);
digitalWrite(9, LOW); //verde pessoa
delay(500);
digitalWrite(9, HIGH); //verde pessoa
delay(500);
digitalWrite(9,LOW); //verde pessoa
delay(500);
digitalWrite(9, HIGH); //verde pessoa
delay(500);
digitalWrite(9,LOW); //verde pessoa
digitalWrite(13, LOW); //vermelho carros
digitalWrite(11, HIGH); //verde carros
digitalWrite(10, HIGH); //vermelho pessoa
delay(10000);
digitalWrite(11, LOW); //verde carros
digitalWrite(12, HIGH); //amarelo carros
delay(2000);
digitalWrite(12, LOW); //amarelo carros
digitalWrite(10, LOW); //vermelho pessoa
}
