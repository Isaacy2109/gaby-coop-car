// Motores
#define motorFrenteDireita1 22
#define motorFrenteDireita2 24
#define velFrenteDireita 11

#define motorFrenteEsquerda1 26
#define motorFrenteEsquerda2 28
#define velFrenteEsquerda 10

#define motorTrasDireita1 30
#define motorTrasDireita2 32
#define velTrasDireita 9

#define motorTrasEsquerda1 32
#define motorTrasEsquerda2 36
#define velTrasEsquerda 8

int velFrente;
int velTras;

int ultimo;

// Sensor Linha
int linhaEsquerda = 44;
int linhaDireita = 40;

void parar(){
    digitalWrite(motorFrenteDireita1, LOW);
    digitalWrite(motorFrenteDireita2, LOW);
    analogWrite(velFrenteDireita, 0);

    digitalWrite(motorFrenteEsquerda1, LOW);
    digitalWrite(motorFrenteEsquerda2, LOW);
    analogWrite(velFrenteEsquerda, 0);

    digitalWrite(motorTrasDireita1, LOW);
    digitalWrite(motorFrenteDireita2, LOW);
    analogWrite(velTrasDireita, 0);

    digitalWrite(motorTrasEsquerda1, LOW);
    digitalWrite(motorTrasEsquerda2, LOW);
    analogWrite(velTrasEsquerda, 0);
}

void andarFrente(int velFrente, int velTras){
    digitalWrite(motorFrenteDireita1, HIGH);
    digitalWrite(motorFrenteDireita2, LOW);
    analogWrite(velFrenteDireita, velFrente);

    digitalWrite(motorFrenteEsquerda1, HIGH);
    digitalWrite(motorFrenteEsquerda2, LOW);
    analogWrite(velFrenteEsquerda, velFrente);

    digitalWrite(motorTrasDireita1, HIGH);
    digitalWrite(motorFrenteDireita2, LOW);
    analogWrite(velTrasDireita, velTras);

    digitalWrite(motorTrasEsquerda1, HIGH);
    digitalWrite(motorTrasEsquerda2, LOW);
    analogWrite(velTrasEsquerda, velTras);
}

void andarDireita(int velFrente, int velTras){
    digitalWrite(motorFrenteDireita1, HIGH);
    digitalWrite(motorFrenteDireita2, LOW);
    analogWrite(velFrenteDireita, velFrente);

    digitalWrite(motorFrenteEsquerda1, LOW);
    digitalWrite(motorFrenteEsquerda2, HIGH);
    analogWrite(velFrenteEsquerda, velFrente);

    digitalWrite(motorTrasDireita1, HIGH);
    digitalWrite(motorFrenteDireita2, LOW);
    analogWrite(velTrasDireita, velTras);

    digitalWrite(motorTrasEsquerda1, LOW);
    digitalWrite(motorTrasEsquerda2, HIGH);
    analogWrite(velTrasEsquerda, velTras);
}

void andarEsquerda(int velFrente, int velTras){
    digitalWrite(motorFrenteDireita1, LOW);
    digitalWrite(motorFrenteDireita2, HIGH);
    analogWrite(velFrenteDireita, velFrente);

    digitalWrite(motorFrenteEsquerda1, HIGH);
    digitalWrite(motorFrenteEsquerda2, LOW);
    analogWrite(velFrenteEsquerda, velFrente);

    digitalWrite(motorTrasDireita1, LOW);
    digitalWrite(motorFrenteDireita2, HIGH);
    analogWrite(velTrasDireita, velTras);

    digitalWrite(motorTrasEsquerda1, HIGH);
    digitalWrite(motorTrasEsquerda2, LOW);
    analogWrite(velTrasEsquerda, velTras);
}

void seguirLinha(){

    if(digitalRead(linhaEsquerda) == LOW && digitalRead(linhaDireita) == HIGH){
        andarDireita(255,255); // Velocidade: Frente / Atrás 
        ultimo = 1;
    }else if(digitalRead(linhaEsquerda) == HIGH && digitalRead(linhaEsquerda) == LOW){
        andarEsquerda(255,255); // Velocidade: Frente / Atrás
        ultimo = 2
    }else{
        andarFrente(255,255); // Velocidade: Frente / Atrás
    }

    /*

    // Não sei porque fiz isso 
    // Mas está melhor

    if(digitalRead(linhaEsquerda) == HIGH && digitalRead(linhaDireita) == HIGH){
        andarFrente(255, 255); // Velocidade: Frente / Atrás
    } else if(digitalRead(linhaEsquerda) == HIGH && digitalRead(linhaDireita) == HIGH){
        andarEsquerda(255, 255); // Velocidade: Frente / Atrás
    } else if(digitalRead(linhaEsquerda) == LOW && digitalRead(linhaDireita) == HIGH){
        andarDireita(255, 255); // Velocidade: Frente / Atrás
    }
    */
}

void setup(){
    pinMode(linhaEsquerda, INPUT);
    pinMode(linhaDireita, INPUT);

    pinMode(motorFrenteDireita1, OUTPUT);
    pinMode(motorFrenteDireita2, OUTPUT);
    pinMode(velFrenteDireita, OUTPUT);

    pinMode(motorFrenteEsquerda1, OUTPUT);
    pinMode(motorFrenteEsquerda2, OUTPUT);
    pinMode(velFrenteEsquerda, OUTPUT);

    pinMode(motorTrasDireita1, OUTPUT);
    pinMode(motorTrasDireita2, OUTPUT);
    pinMode(velTrasDireita, OUTPUT);

    pinMode(motorTrasEsquerda1, OUTPUT);
    pinMode(motorTrasEsquerda2, OUTPUT);
    pinMode(velTrasEsquerda, OUTPUT);
}

/* It's Time to Shine, my Gaby!!
Nhinhinhinhinhi */ 
void loop(){
    // Seguir Linha
    seguirLinha();
}
// Misericordia
