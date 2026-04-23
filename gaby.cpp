// Motor Frente Direito
#define motorFrenteDir1 22
#define motorFrenteDir2 24
#define velFrenteDir 11

// Motor Frente Esquerda
#define motorFrenteEsq1 3
#define motorFrenteEsq2 2
#define velFrenteEsq 10

// Motor Atrás Direito
#define motorTrasDir1 8
#define motorTrasDir2 7
#define velTrasDir 9

// Motor Atrás Esquerdo
#define motorTrasEsq1 6
#define motorTrasEsq2 5
#define velTrasEsq 4

int vel;

// IR Linha
int esq = 13;
int dir = 12;
int cen = 26;

void frente(){
  // Frente
  digitalWrite(motorFrenteDir1,HIGH);
  digitalWrite(motorFrenteDir2,LOW);
  analogWrite(velFrenteDir,vel);
  
  digitalWrite(motorFrenteEsq1,HIGH);
  digitalWrite(motorFrenteEsq2,LOW);
  analogWrite(velFrenteEsq,vel); 

  // Atrás
  digitalWrite(motorTrasDir1,HIGH);
  digitalWrite(motorTrasDir2,LOW);
  analogWrite(velTrasDir,vel);

  digitalWrite(motorTrasEsq1,HIGH);
  digitalWrite(motorTrasEsq2,LOW);
  analogWrite(velTrasEsq,vel);
}

void para(){
  // Frente
  digitalWrite(motorFrenteDir1,LOW);
  digitalWrite(motorFrenteDir2,LOW);
  analogWrite(velFrenteDir,vel);
  
  digitalWrite(motorFrenteEsq1,LOW);
  digitalWrite(motorFrenteEsq2,LOW);
  analogWrite(velFrenteEsq,vel); 

  // Atrás
  digitalWrite(motorTrasDir1,LOW);
  digitalWrite(motorTrasDir2,LOW);
  analogWrite(velTrasDir,vel);

  digitalWrite(motorTrasEsq1,LOW);
  digitalWrite(motorTrasEsq2,LOW);
  analogWrite(velTrasEsq,vel);
}

void direita(){
  // Frente
  digitalWrite(motorFrenteDir1,HIGH);
  digitalWrite(motorFrenteDir2,LOW);
  analogWrite(velFrenteDir,130);
  
  digitalWrite(motorFrenteEsq1,HIGH);
  digitalWrite(motorFrenteEsq2,LOW);
  analogWrite(velFrenteEsq,60); 

  // Atrás
  digitalWrite(motorTrasDir1,HIGH);
  digitalWrite(motorTrasDir2,LOW);
  analogWrite(velTrasDir,130);

  digitalWrite(motorTrasEsq1,HIGH);
  digitalWrite(motorTrasEsq2,LOW);
  analogWrite(velTrasEsq,60);
}

void esquerda(){
  // Frente
  digitalWrite(motorFrenteDir1,HIGH);
  digitalWrite(motorFrenteDir2,LOW);
  analogWrite(velFrenteDir,60);
  
  digitalWrite(motorFrenteEsq1,HIGH);
  digitalWrite(motorFrenteEsq2,LOW);
  analogWrite(velFrenteEsq,130); 

  // Atrás
  digitalWrite(motorTrasDir1,HIGH);
  digitalWrite(motorTrasDir2,LOW);
  analogWrite(velTrasDir,60);

  digitalWrite(motorTrasEsq1,HIGH);
  digitalWrite(motorTrasEsq2,LOW);
  analogWrite(velTrasEsq,130);
}

void setup(){
  // IR Linha
  pinMode(esq,INPUT);
  pinMode(dir,INPUT);
  
  // Motor Frente Direito
  pinMode(motorFrenteDir1,OUTPUT);
  pinMode(motorFrenteDir2,OUTPUT);
  pinMode(velFrenteDir,OUTPUT);

  // Motor Frente Esquerdo
  pinMode(motorFrenteEsq1,OUTPUT);
  pinMode(motorFrenteEsq2,OUTPUT);
  pinMode(velFrenteEsq,OUTPUT);

  // Motor Atrás Direito
  pinMode(motorTrasDir1,OUTPUT);
  pinMode(motorTrasDir2,OUTPUT);
  pinMode(velTrasDir,OUTPUT);

  // Motor Atrás Esquerdo
  pinMode(motorTrasEsq1,OUTPUT);
  pinMode(motorTrasEsq2,OUTPUT);
  pinMode(velTrasEsq,OUTPUT);
}

// IT'S TIME TO SHINE, MY GABY!!
// NHINHINHINHI

void loop(){
  vel = 120;

  // Frente
  if(digitalRead(esq) == HIGH && digitalRead(dir) == HIGH){
    frente();
  } 

  // Parar, Por equanto não para apenas segue reto
  if(digitalRead(esq) == LOW && digitalRead(dir) == LOW){
    frente();
  } 

  // Esqerda
  if(digitalRead(esq) == HIGH && digitalRead(dir) == LOW){
    esquerda();
  } 

  //  Direita
  if(digitalRead(esq) == LOW && digitalRead(dir) == HIGH){
    direita();
  }

  // Frente
  digitalWrite(motorFrenteDir1,HIGH);
  digitalWrite(motorFrenteDir2,LOW);
  analogWrite(velFrenteDir,130);
  
  digitalWrite(motorFrenteEsq1,HIGH);
  digitalWrite(motorFrenteEsq2,LOW);
  analogWrite(velFrenteEsq,60); 

  // Atrás
  digitalWrite(motorTrasDir1,HIGH);
  digitalWrite(motorTrasDir2,LOW);
  analogWrite(velTrasDir,130);

  digitalWrite(motorTrasEsq1,HIGH);
  digitalWrite(motorTrasEsq2,LOW);
  analogWrite(velTrasEsq,60);  

}
