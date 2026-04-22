#include <Arduino.h>

// [] TROCAR O 5V PARA 12V DA PONTE H
// [] COLOCAR O GND DA PONTE H NO ARDUINO
// [] FAZER O TESTE NO 5V DO ARDUINO NO NA PORTA motorTrasEsq/Dir
// [] COLOCAR O ULTRASONICO
// [] COLOCAR O SENSOR DE LINHA CENTRAL

// Motores
#define motorFrenteDir1 22
#define motorFrenteDir2 24
#define velFrenteDir 11

#define motorFrenteEsq1 26
#define motorFrenteEsq2 28
#define velFrenteEsq 10

#define motorTrasDir1 30
#define motorTrasDir2 32
#define velTrasDir 9

#define motorTrasEsq1 34
#define motorTrasEsq2 36
#define velTrasEsq 8

int vel;

// Sensor Obstáculo
#define trig 46
#define echo 48
int ultimo = 0;
int limite = 15;

// Sensor Linha
int esq = 44;
int cen = 42;
int dir = 40;

void frente(){
  digitalWrite(motorFrenteDir1,HIGH);
  digitalWrite(motorFrenteDir2,LOW);
  analogWrite(velFrenteDir,vel);
  
  digitalWrite(motorFrenteEsq1,HIGH);
  digitalWrite(motorFrenteEsq2,LOW);
  analogWrite(velFrenteEsq,vel); 

  digitalWrite(motorTrasDir1,LOW);
  digitalWrite(motorTrasDir2,LOW);
  analogWrite(velTrasDir,vel);

  digitalWrite(motorTrasEsq1,LOW);
  digitalWrite(motorTrasEsq2,LOW);
  analogWrite(velTrasEsq,vel);
}

void para(){
  digitalWrite(motorFrenteDir1,LOW);
  digitalWrite(motorFrenteDir2,LOW);
  analogWrite(velFrenteDir,vel);
  
  digitalWrite(motorFrenteEsq1,LOW);
  digitalWrite(motorFrenteEsq2,LOW);
  analogWrite(velFrenteEsq,vel); 

  digitalWrite(motorTrasDir1,LOW);
  digitalWrite(motorTrasDir2,LOW);
  analogWrite(velTrasDir,vel);

  digitalWrite(motorTrasEsq1,LOW);
  digitalWrite(motorTrasEsq2,LOW);
  analogWrite(velTrasEsq,vel);
}

void direita(){
  digitalWrite(motorFrenteDir1,HIGH);
  digitalWrite(motorFrenteDir2,LOW);
  analogWrite(velFrenteDir,vel);
  
  digitalWrite(motorFrenteEsq1,LOW);
  digitalWrite(motorFrenteEsq2,LOW);
  analogWrite(velFrenteEsq,vel); 

  digitalWrite(motorTrasDir1,LOW);
  digitalWrite(motorTrasDir2,LOW);
  analogWrite(velTrasDir,vel);

  digitalWrite(motorTrasEsq1,LOW);
  digitalWrite(motorTrasEsq2,LOW);
  analogWrite(velTrasEsq,vel);
}

void esquerda(){
  digitalWrite(motorFrenteDir1,LOW);
  digitalWrite(motorFrenteDir2,LOW);
  analogWrite(velFrenteDir,vel);
  
  digitalWrite(motorFrenteEsq1,HIGH);
  digitalWrite(motorFrenteEsq2,LOW);
  analogWrite(velFrenteEsq,vel); 

  digitalWrite(motorTrasDir1,LOW);
  digitalWrite(motorTrasDir2,LOW);
  analogWrite(velTrasDir,vel);

  digitalWrite(motorTrasEsq1,LOW);
  digitalWrite(motorTrasEsq2,LOW);
  analogWrite(velTrasEsq,vel);
}

void seguirLinha(){
  if(digitalRead(esq) == HIGH && digitalRead(dir) == HIGH){
    frente();
  }
  else if(digitalRead(esq) == HIGH && digitalRead(dir) == LOW){
    esquerda();
    ultimo = 2;
  }
  else if (digitalRead(esq) == LOW && digitalRead(dir) == HIGH)
  {
    direita();
    ultimo = 1;
  }
}

long distancia(){
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  long duracao = pulseIn(echo,HIGH);

  long dist = duracao * 0.034 / 2;
  return dist;
}

void procurarLinha(){
  while(true){
    if (cen == HIGH && esq == HIGH && dir == HIGH){
      break;
    }
    if (ultimo = 2){
      esquerda();
    }
    else if (ultimo = 1){
      direita();
    }
    else{
      direita();
    }
  }
}

void desviar(){
  para();
  delay(200);

  direita();
  delay(400);

  frente();
  delay(500);

  procurarLinha();
}

void setup(){
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);

  pinMode(esq,INPUT);
  pinMode(cen,INPUT);
  pinMode(dir,INPUT);
  
  pinMode(motorFrenteDir1,OUTPUT);
  pinMode(motorFrenteDir2,OUTPUT);
  pinMode(velFrenteDir,OUTPUT);

  pinMode(motorFrenteEsq1,OUTPUT);
  pinMode(motorFrenteEsq2,OUTPUT);
  pinMode(velFrenteEsq,OUTPUT);

  pinMode(motorTrasDir1,OUTPUT);
  pinMode(motorTrasDir2,OUTPUT);
  pinMode(velTrasDir,OUTPUT);

  pinMode(motorTrasEsq1,OUTPUT);
  pinMode(motorTrasEsq2,OUTPUT);
  pinMode(velTrasEsq,OUTPUT);
}

// IT'S TIME TO SHINE, MY GABY!!
// NHINHINHINHI

void loop(){
  vel = 120;

  long dist = distancia();
  if (dist < limite){
    desviar();
  }
  else{
    seguirLinha();
  }
}
