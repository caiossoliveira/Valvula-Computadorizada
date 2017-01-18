int mPino1 = 10;
int mPino2 = 9;
int mPino3 = 11;
int mPino4 = 12;
int contador = 0;

char result[3];
String concacPorcentagem;
float porcentagem;
void leitura();
float aux;

int tempo = 50;

void setup() {
  Serial.begin(9600);
  
  pinMode(mPino1, OUTPUT);  
  pinMode(mPino2, OUTPUT);
  pinMode(mPino3, OUTPUT);
  pinMode(mPino4, OUTPUT);
}

void loop() {

  delay(500);
 
  leitura();

  if(result[0] == 'a'){

    while(contador < ((porcentagem / 100) * 254)){ //360

       aux = (porcentagem / 100) * 254;

      Serial.println(contador);
      Serial.println(aux);

      digitalWrite(mPino1, HIGH);
      delay(tempo);
      digitalWrite(mPino1, LOW);
      digitalWrite(mPino2, HIGH);
      delay(tempo);
      digitalWrite(mPino2, LOW);
      digitalWrite(mPino3, HIGH);
      delay(tempo);
      digitalWrite(mPino3, LOW);
      digitalWrite(mPino4, HIGH);
      delay(tempo);
      digitalWrite(mPino4, LOW);
      contador++;
    }
    result[0] = 's';
    contador = 0;
  }

  else if (result[0] == 'f'){

    while(contador < ((porcentagem / 100) * 254)){ //360

       aux = (porcentagem / 100) * 254;

      Serial.println(contador);
      Serial.println(aux);

      digitalWrite(mPino4, HIGH);
      delay(tempo);
      digitalWrite(mPino4, LOW);
      digitalWrite(mPino3, HIGH);
      delay(tempo);
      digitalWrite(mPino3, LOW);
      digitalWrite(mPino2, HIGH);
      delay(tempo);
      digitalWrite(mPino2, LOW);
      digitalWrite(mPino1, HIGH);
      delay(tempo);
      digitalWrite(mPino1, LOW);
      contador++;
    }
    result[0] = 's';
    contador = 0;
  }

else if (result[0] == 'A'){

    while(contador < 254){ //360

       aux = (porcentagem / 100) * 254;

      Serial.println(contador);
      Serial.println(aux);

      digitalWrite(mPino1, HIGH);
      delay(tempo);
      digitalWrite(mPino1, LOW);
      digitalWrite(mPino2, HIGH);
      delay(tempo);
      digitalWrite(mPino2, LOW);
      digitalWrite(mPino3, HIGH);
      delay(tempo);
      digitalWrite(mPino3, LOW);
      digitalWrite(mPino4, HIGH);
      delay(tempo);
      digitalWrite(mPino4, LOW);
      contador++;

     // Serial.println(contador);
    }
    result[0] = 's';
    contador = 0;
  }

else if (result[0] == 'F'){

    Serial.println("F");

    while(contador < 254){ //360

      aux = (porcentagem / 100) * 254;
      Serial.println(contador);
      Serial.println(aux);

      digitalWrite(mPino4, HIGH);
      delay(tempo);
      digitalWrite(mPino4, LOW);
      digitalWrite(mPino3, HIGH);
      delay(tempo);
      digitalWrite(mPino3, LOW);
      digitalWrite(mPino2, HIGH);
      delay(tempo);
      digitalWrite(mPino2, LOW);
      digitalWrite(mPino1, HIGH);
      delay(tempo);
      digitalWrite(mPino1, LOW);
      contador++;

 //     Serial.println(contador);
    }
    result[0] = 's';
    contador = 0;
  }
}



void leitura(){

  if(Serial.available()){
    concacPorcentagem =  "";
    for(int i=0; i<3; i++){
      result[i] = Serial.read();
    }

    concacPorcentagem.concat(result[1]);
    concacPorcentagem.concat(result[2]);

    porcentagem = concacPorcentagem.toInt();
  }
}

