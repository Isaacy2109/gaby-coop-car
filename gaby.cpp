#include <Arduino.h>

// TO DO:
// [] TESTAR OS SENSORES "esq" e "dir" E SE SEGUEM LINHA
// [] COLOCAR O SENSOR "cen"
// [] TESTAR O MODO GAP
// [] TESTAR O DESVIO DE OBSTÁCULO
// [] MEMORIA DE ULTIMA DIRAÇÃO PÓS DESVIO

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
int ultimoMovimento = 0;
int limiteDistancia = 15;

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

  digitalWrite(motorTrasDir1,HIGH);
  digitalWrite(motorTrasDir2,LOW);
  analogWrite(velTrasDir,vel);

  digitalWrite(motorTrasEsq1,HIGH);
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
  analogWrite(velFrenteDir,60);
  
  digitalWrite(motorFrenteEsq1,LOW);
  digitalWrite(motorFrenteEsq2,LOW);
  analogWrite(velFrenteEsq,vel); 

  digitalWrite(motorTrasDir1,HIGH);
  digitalWrite(motorTrasDir2,LOW);
  analogWrite(velTrasDir,60);

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
  analogWrite(velFrenteEsq,60); 

  digitalWrite(motorTrasDir1,LOW);
  digitalWrite(motorTrasDir2,LOW);
  analogWrite(velTrasDir,vel);

  digitalWrite(motorTrasEsq1,HIGH);
  digitalWrite(motorTrasEsq2,LOW);
  analogWrite(velTrasEsq,60);
}

void seguirLinha(){
  if(digitalRead(esq) == LOW && digitalRead(dir) == HIGH){
    para();
    delay(200);
    frente();
    ultimoMovimento = 1;
  }

  else if(digitalRead(esq) == HIGH && digitalRead(dir) == LOW){
    para();
    delay(200);
    esquerda();
    ultimoMovimento = 2;
  }

  frente();
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
    if (esq == HIGH && dir == HIGH){
      break;
    }

    else if (ultimoMovimento == 2){
      esquerda();
    }
    
    else if (ultimoMovimento == 1){
      direita();
    }
    frente();
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

  /* long dist = distancia();
  if (dist < limiteDistancia){
    desviar();
  }
  seguirLinha(); */

  seguirLinha();
}
