#define trigPin 6  
#define echoPin 5
#define buzzer 2
float delay1; 


void setup() 
{
  Serial.begin (9600); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  pinMode(buzzer,OUTPUT);
  
}


void loop() 
{
  long duration, distance;
  digitalWrite(trigPin, LOW);        
  delayMicroseconds(2);              
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);           
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  delay1= (distance *3) +30;
  Serial.print(distance);
  Serial.println("  cm");
  if (distance < 50)
  {
   digitalWrite(buzzer,HIGH);
   delay(delay1);
   digitalWrite(buzzer,LOW);
 
  }
  else
  {
    digitalWrite(buzzer,LOW);

  }
  
 delay(200);
}
