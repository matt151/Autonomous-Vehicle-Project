//Using the ultrasonic senors to cause the motors to move when no object is in the way, but to stop when an aboject is a specified distance away
// This code allows the vehicle to follow the black line as long as there is no object in its way. 
// It utilizes both the ultrasound and the IR eyes to guide the Vehicle 

const int d= 15;
//Ultrasound pins
const int US_TRIG = 14;// arduino pin number
const int US_ECHO = 15;// arduino pin number
//IR eyes
const int LEYE = 21;
const int REYE = 13;
//PWM output pins
const int en1= 17;
const int en2 = 16;
//Motor output pins
const int IN1 = 3;   // Left motor(sitting in it) positive (forward @ high)
const int IN2 = 2;  //Left motor(sitting in it) negative (reverse @ high)
const int IN3 = 9;  //Right motor(sitting in it) postive ( forward @ high)
const int IN4 = 10; //Right motor(sitting in it) negative (reverse @ high)
char user_input;

void setup() {
  // put your setup code here, to run once:
  Serial.begin( 9600 );
  
  pinMode(US_TRIG, OUTPUT);//send out signal to be reflected back
  pinMode(US_ECHO, INPUT);// reads in a signal to calculate its distance away

  pinMode( LEYE, INPUT );
  pinMode( REYE, INPUT );

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
// Ultrasound code
  int distance;
  long duration;

  digitalWrite( US_TRIG, LOW );
  delayMicroseconds(2);
  digitalWrite( US_TRIG, HIGH );
  delayMicroseconds( 10 );
  digitalWrite( US_TRIG, LOW );

  duration = pulseIn( US_ECHO, HIGH );

  distance = duration/58;
 

if (distance >= d ){

if (digitalRead(LEYE)==LOW){
 Serial.print("low - move forward");//low = no black line detected
   analogWrite(en1,200);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
}
else { 
  Serial.print("high- black line detected STOP");
    analogWrite(en1,0);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  
}
  
//Right eye
   if (digitalRead(REYE)==LOW){
  
   //right motor forward
   analogWrite(en2,200);
   digitalWrite(IN3,HIGH);
   digitalWrite(IN4,LOW);
}
else{
    //stop
    Serial.print("high- black line detected STOP");
    
   analogWrite(en2,0);
   digitalWrite(IN3,HIGH);
   digitalWrite(IN4,LOW);
}
}

else {
  
    //left motor stop
  analogWrite(en1,0);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);

   //right motor stop
   analogWrite(en2,0);
    digitalWrite(IN3,HIGH);
     digitalWrite(IN4,LOW);
}

  Serial.print("Distance detected: ");
  Serial.print( distance );
  Serial.println(" cm");
  //delay (1000);
}


void both_forward ()
{
  //left motor forward
  analogWrite(en1,255);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);

   //right motor forward
   analogWrite(en2,255);
    digitalWrite(IN3,HIGH);
     digitalWrite(IN4,LOW);
}

void both_forward50 ()
{
  //left motor forward
  analogWrite(en1,100);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);

   //right motor forward
   analogWrite(en2,100);
   digitalWrite(IN3,HIGH);
   digitalWrite(IN4,LOW);
}

void right_forward()
{
//right motor forward
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
 }

void left_forward()
{
  //left motor forward
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
}

void both_reverse()
{
  //left motor reverse
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);

   //right motor revrse
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
}

void right_reverse()
{
  //right motor revrse
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
}

void left_reverse()
{
  //left motor reverse
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  
}

void both_stop()
{
  //left motor stop
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);

   //right motor stop
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
}

void right_stop()
{
  //right motor stop
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
}

void left_stop()
{
  //left motor stop
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
}
