#include <Wire.h> // auxiliar para a biblioteca I2C
#include <LiquidCrystal_I2C.h> // biblioteca display I2C
#include <SoftwareSerial.h> // biblioteca serial bluetooth

LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3, POSITIVE); // direções de comunicação do display
SoftwareSerial bt(7, 8); //TX, RX (Bluetooth)
byte grau[8] = {B11000,B11000,B00000,B00000,B00000,B00000,B00000,B00000}; // simbolo de grau
byte lb1, lb2, potencia, bluetooth = 0; // variáveis globais

void setup() 
{ // inicio setup
  analogReference(INTERNAL); // altera tensão de referência
  bt.begin(9600); // inicia comunicação bluetooth
  lcd.begin (16, 2); // indica o tipo do display
  lcd.createChar(1, grau); // cria o caracter de grau
  pinMode(5, OUTPUT); // bloco 1 peltier
  pinMode(6, OUTPUT); // bloco 2 peltier
  pinMode(7, INPUT);  // TX do bluetooth
  pinMode(8, OUTPUT); // RX do bluetooth
  pinMode(9, INPUT_PULLUP); // botao +
  pinMode(10, INPUT_PULLUP); // botao -
} // final setup

void loop() 
{ //começo void loop

  byte temperatura = (analogRead(A3)*0.1075268817); // recebe valor da temperatura
  lcd.clear(); // limpa o display
  lcd.setCursor(0,0); // direciona a linha e a coluna do display
  lcd.print("TEMPERATURA:"); // escreve temperatura no display
  lcd.print(temperatura); // manda o valor da temperatura para o display
  lcd.write(1); // manda o simbolo de grau para o display
  lcd.print("C"); // manda o simbolo de celsius para o display
  lcd.setCursor(0,1); // direcina a linha e a coluna do display
  lcd.print("POTENCIA: "); // escreve potenia no display
  
  byte b1 = digitalRead(9); // estado do botão +
  byte b2 = digitalRead(10); // estado do botão -
  
  if(b1 == 0 && potencia<3 && lb1 == 0){ // se o botão + for precionado
    potencia++; // incrementa a potencia
    lb1=1;} // desativa o botão +
  else{ // se não for precionado
    if(lb1==1 && b1 == 1) // verifica se o botão está solto
    lb1=0;} // ativa o botão +

  if(b2 == 0 && potencia>0 && lb2 == 0){ // se o botão - for precionado
    potencia--; // decrementa a potencia
    lb2=1;} // desativa o botão -
  else{ // se não for precionado
    if(lb2 == 1 && b2 == 1) // verifica se o botão está solto
    lb2=0;} // ativa o botão -

  if (bt.available() > 0) 
  {//inicio leitura app
      bluetooth = bt.read(); // recebe a leitura do app
      
    if (bluetooth == 'B') // se o app mandar 'B'
      potencia = 1; // define a potencia como baixa
      
    if (bluetooth == 'M') // se o app mandar 'M'
      potencia = 2; // define a potencia como media

    if (bluetooth == 'A') // se o app mandar 'A'
      potencia = 3; // define a potencia como alta
      
    if (bluetooth == 'O') // se o app mandar 'O'
      potencia = 0; // define a potencia como off
  }// final leitura app

   if(potencia == 1) // se a potencia for = a 1
   { 
    lcd.print("BAIXA"); // escreve baixa no display
    bt.print("BAIXA|"); // escreve baixa no app
    bt.print(temperatura); // manda a temperatura para o app
   }
    
   if(potencia == 2) // se a potencia for = a 2
   {
    lcd.print("MEDIA");// escreve media no display
    bt.print("MEDIA|"); // escreve media no app
    bt.print(temperatura); // manda a temperatura para o app
   }
    
   if(potencia == 3) // se a potencia for = 3
   {
    lcd.print("ALTA"); // escreve alta no display
    bt.print("ALTA|"); //escreve alta no app
    bt.print(temperatura); // manda a temperatura para o app
   }
   
   if(potencia <=0) // se a potencia for = a 0
   {
    lcd.print("OFF"); // escreve off no display
    bt.print("OFF|"); // escreve off no app
    bt.print(temperatura); // manda a temperatura para o app
   }
   
   byte pwm = map(potencia, 0, 3, 0, 255); // cria o PWM
   analogWrite(5, pwm); // manda o PWM para o primeiro bloco peltier
   analogWrite(6, pwm); // manda o PWM para o segundo  bloco peltier
   delay(150); //atraso de 100ms

} // final void loop
