//pines para el motor A
#define In1 12
#define In2 10
#define PWMA 11

//pines para el motor b
#define In3 8
#define In4 7
#define PWMB 9 

//PINES DE LOS SENSORES
#define sensor_Frontal_Derecho A2
#define sensor_Frontal_Izquierdo A1
#define sensor_Izquierdo A0
#define sensor_Derecho A3

//estados de los sensores

boolean E_SFD = false; 
boolean E_SFI = false;
boolean E_SI = false;
boolean E_SD = false;

void setup() {
// SENSORES
pinMode(sensor_Frontal_Derecho, INPUT);
pinMode(sensor_Frontal_Izquierdo, INPUT);
pinMode(sensor_Izquierdo, INPUT);
pinMode(sensor_Derecho, INPUT);

//MOTORES
pinMode(In1, OUTPUT);
pinMode(In2, OUTPUT);
pinMode(In3, OUTPUT);
pinMode(In4, OUTPUT);
pinMode(PWMA, OUTPUT);
pinMode(PWMB, OUTPUT);

}

void loop() {
// put your main code here, to run repeatedly:
E_SFD = (leer_sensor(sensor_Frontal_Derecho));
E_SFI = (leer_sensor(sensor_Frontal_Izquierdo));
E_SI = (leer_sensor(sensor_Izquierdo));
E_SD = (leer_sensor(sensor_Derecho));

//ADELANTE
if(E_SFD == 1 && E_SFI == 1){
adelante();
analogWrite(PWMA,200);
analogWrite(PWMB,200);
}


//IZQUIERDA
else if(E_SI == 1){
izquierda();
analogWrite(PWMA,130);
analogWrite(PWMB,130);  
}


//DERECHA
else if(E_SD == 1){
digitalWrite(In1,HIGH);
digitalWrite(In2,LOW);
digitalWrite(In3,LOW);
digitalWrite(In4,HIGH);
analogWrite(PWMA,150);
analogWrite(PWMB,150);
}
else{
digitalWrite(In1,LOW);
digitalWrite(In2,LOW);
digitalWrite(In3,LOW);
digitalWrite(In4,LOW);
analogWrite(PWMA,0);
analogWrite(PWMB,0);
} 


}
boolean leer_sensor(int pin){
int lectura = 0;
float voltaje = 0.0;
bool estado;

lectura = analogRead (pin);
voltaje = lectura*5.0/1023.0;

if (voltaje>=0.95) estado = true;
else estado = false;

return estado;
}

void adelante()
{
digitalWrite(In1, HIGH);
digitalWrite(In2,LOW);
digitalWrite(In3,HIGH);
digitalWrite(In4,LOW);
}

void izquierda()
{
digitalWrite(In1,LOW);
digitalWrite(In2,HIGH);
digitalWrite(In3,HIGH);
digitalWrite(In4,LOW);
}
