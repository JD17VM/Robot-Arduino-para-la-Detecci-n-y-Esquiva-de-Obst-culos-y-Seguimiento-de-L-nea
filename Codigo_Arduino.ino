int IN1_A = 2;
int IN2_A = 4;
int ENA_A = 3;

int IN1_B = 6;
int IN2_B = 7;
int ENA_B = 5;


int pinsensor_izquierda = 13;
int pinsensor_derecha = 10;

int LED_rojo = 11;
int LED_verde = 12;

const short int TRIG_ENTRADA = 8; // trigger en pin 4
const short int ECO_ENTRADA = 9;  // echo en pin 3 --

int distancia;


void amarillo()
{
    digitalWrite(LED_verde, LOW);
    digitalWrite(LED_rojo, HIGH);
}

void verde()
{
    digitalWrite(LED_verde, HIGH);
    digitalWrite(LED_rojo, LOW);
}

int distancia_medida_cm(int trig, int eco)
{
    int d, duracion;
    digitalWrite(trig, HIGH);
    delay(10);
    digitalWrite(trig, LOW);

    duracion = pulseIn(eco, HIGH);
    d = duracion / 58.2;

    return d;
}


void avanza_rapido()
{
    analogWrite(ENA_A, 90);
    digitalWrite(IN1_A, HIGH);
    digitalWrite(IN2_A, LOW);

    analogWrite(ENA_B, 120);
    digitalWrite(IN1_B, HIGH);
    digitalWrite(IN2_B, LOW);
}


void avanza()
{
    analogWrite(ENA_A, 75);
    digitalWrite(IN1_A, HIGH);
    digitalWrite(IN2_A, LOW);

    analogWrite(ENA_B, 95);
    digitalWrite(IN1_B, HIGH);
    digitalWrite(IN2_B, LOW);
}


void retrocede()
{
    digitalWrite(ENA_A, HIGH);
    digitalWrite(IN1_A, LOW);
    digitalWrite(IN2_A, HIGH);

    digitalWrite(ENA_B, HIGH);
    digitalWrite(IN1_B, LOW);
    digitalWrite(IN2_B, HIGH);
}

void derecha()
{
    analogWrite(ENA_A, 254);
    digitalWrite(IN1_A, HIGH);
    digitalWrite(IN2_A, LOW);

    analogWrite(ENA_B, 220);
    digitalWrite(IN1_B, LOW);
    digitalWrite(IN2_B, HIGH);
}


void izquierda()
{
    analogWrite(ENA_A, 220);
    digitalWrite(IN1_A, LOW);
    digitalWrite(IN2_A, HIGH);

    analogWrite(ENA_B, 254);
    digitalWrite(IN1_B, HIGH);
    digitalWrite(IN2_B, LOW);
}

void derecha_rapido(){
  analogWrite(ENA_A, 200);
  digitalWrite(IN1_A, HIGH);
  digitalWrite(IN2_A, LOW);

  analogWrite(ENA_B, 150);
  digitalWrite(IN1_B, LOW);
  digitalWrite(IN2_B, HIGH);
}


void izquierda_rapido(){
  analogWrite(ENA_A, 150);
  digitalWrite(IN1_A, LOW);
  digitalWrite(IN2_A, HIGH);

  analogWrite(ENA_B, 200);
  digitalWrite(IN1_B, HIGH);
  digitalWrite(IN2_B, LOW);
}


void parar()
{
    digitalWrite(ENA_A, LOW);
    digitalWrite(IN1_A, LOW);
    digitalWrite(IN2_A, LOW);

    digitalWrite(ENA_B, LOW);
    digitalWrite(IN1_B, LOW);
    digitalWrite(IN2_B, LOW);
}

void med(){
  int distancia = distancia_medida_cm(TRIG_ENTRADA, ECO_ENTRADA);

  if(distancia < 30){
    amarillo();
    parar();
    delay(300);
    derecha_rapido();
    delay(500);
  }else{
    avanza_rapido();
    verde();
  }
}

void res(){

  int sensor_izquierda = digitalRead(pinsensor_izquierda);
  int sensor_derecha = digitalRead(pinsensor_derecha);
  if(sensor_izquierda == HIGH && sensor_derecha == HIGH){
    parar();
  }else if(sensor_izquierda == LOW && sensor_derecha == HIGH){
    izquierda();
  }else if(sensor_izquierda == HIGH && sensor_derecha == LOW){
    derecha();
  }else if(sensor_izquierda == LOW && sensor_derecha == LOW){
    avanza();
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(pinsensor_izquierda,INPUT);
  pinMode(pinsensor_derecha,INPUT);

  pinMode(IN1_A, OUTPUT);
  pinMode(IN2_A, OUTPUT);
  pinMode(ENA_A, OUTPUT);

  pinMode(IN1_B, OUTPUT);
  pinMode(IN2_B, OUTPUT);
  pinMode(ENA_B, OUTPUT);

  pinMode(LED_rojo, OUTPUT);
  pinMode(LED_verde, OUTPUT);

  pinMode(TRIG_ENTRADA, OUTPUT);  // trigger como salida
  pinMode(ECO_ENTRADA, INPUT);

}

//HIGH = BLANCO
//LOW = NEGRO
//A = DERECHA
//B = IZQUIERDA

void loop() {
       med();
       //avanza();
       
}
