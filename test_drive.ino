int leftIn = 0;    // select the input pin for the potentiometer
int rightIn = 1;    // select the input pin for the potentiometer
int ledPin = 13;   // select the pin for the LED
int left = 0;       // variable to store the value coming from the sensor
int right = 0;       // variable to store the value coming from the sensor

int pwm_a = 3;
int dir_a_1 = 8;
int dir_a_2 = 9;

int pwm_b = 5;
int dir_b_1 = 10;
int dir_b_2 = 11;

int left_dir = 0;
int right_dir = 0;

int left_speed = 0;
int right_speed = 0;

void setup() {
  pinMode(ledPin, OUTPUT);  // declare the ledPin as an OUTPUT
  pinMode(leftIn, INPUT);
  pinMode(rightIn, INPUT);

  pinMode(dir_a_1, OUTPUT);
  pinMode(dir_a_2, OUTPUT);
  pinMode(pwm_a, OUTPUT);
  
  pinMode(dir_b_1, OUTPUT);
  pinMode(dir_b_2, OUTPUT);
  pinMode(pwm_b, OUTPUT);  
  Serial.begin(9600);
}

void loop() {
  left = analogRead(leftIn);    // read the value from the sensor
  right = analogRead(rightIn);    // read the value from the sensor

  if (left >= 490 && left <= 510) {
    left_dir = 0;
    left_speed = 0;
  } else {
    if (left < 500) {
      left_dir = 0;
    } else {
      left_dir = 1;
    }
    left_speed = abs(left - 500);    
  }

  if (right >= 490 && right <= 510) {
    right_dir = 0;
    right_speed = 0;
  } else {
    if (right < 500) {
      right_dir = 0;
    } else {
      right_dir = 1;
    } 
    right_speed = abs(right - 500);       
  }

  left_speed = left_speed * 2;
  right_speed = right_speed * 2;

  if (left_dir == 0) {
    digitalWrite(dir_a_1, LOW);  
    digitalWrite(dir_a_2, HIGH);     
  } else {
    digitalWrite(dir_a_1, HIGH);  
    digitalWrite(dir_a_2, LOW);    
  }

  if (right_dir == 0) {
    digitalWrite(dir_b_1, LOW);  
    digitalWrite(dir_b_2, HIGH);     
  } else {
    digitalWrite(dir_b_1, HIGH);  
    digitalWrite(dir_b_2, LOW);    
  }

  analogWrite(pwm_a, left_speed);
  analogWrite(pwm_b, right_speed);

/*
  Serial.print(left_dir);
  Serial.print(", ");
  Serial.print(left_speed);
  Serial.print(" / ");
  Serial.print(right_dir);
  Serial.print(", ");
  Serial.println(right_speed);  
  digitalWrite(ledPin, HIGH);  // turn the ledPin on
  delay(left);                  // stop the program for some time
  digitalWrite(ledPin, LOW);   // turn the ledPin off
  delay(right);                  // stop the program for some time
*/  
}
 
