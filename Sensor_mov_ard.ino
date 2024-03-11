#define trig 7 //Emisor de pulso
#define echo 6 //Receptor "del eco" del pulso
#define buzzer 12 //zumbador

void setup() {
  // put your setup code here, to run once:
  pinMode(trig,OUTPUT);//Emisor
  pinMode(echo,INPUT);//Receptor
  pinMode(buzzer,OUTPUT);//Emisor

}

bool sonando = false; // Variable para controlar el estado del zumbador

void loop() {
  long duration, distance;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration / 2) * 0.0343;
  
  if (distance < 150) {
    if (!sonando) { // Verifica si el zumbador no está sonando actualmente
      tone(buzzer, 1000);
      sonando = true; // Actualiza el estado del zumbador
    }
    delay(5000); // Espera 5 segundos
  } else {
    if (sonando) { // Verifica si el zumbador está sonando
      noTone(buzzer);
      sonando = false; // Actualiza el estado del zumbador
    }
  }
}
