/*
  BluetoothBuzzer
  When a button is pressed, sends a keypress over serial (bluetooth)
  
  Natsumi Hoshino <http://www.natsumihoshino.com>
  2013
 */
 
// Define the default number of this buzzer
int buzzerNumber = 1; //edit this

// Define the pin corresponding to the buzzer button
int buzzerBtn = 2;

void setup() {
  pinMode(buzzerBtn, INPUT);
  digitalWrite(buzzerBtn, HIGH); //pull-up resistor
  Serial.begin(9600);
}

void loop() {
  // On button press, send in this buzzer's number
  if(digitalRead(buzzerBtn) == LOW) {
    Serial.println(buzzerNumber);
    delay(1000);  //pause for a while
  }
  else if (Serial.available()) {
    int n = Serial.parseInt();
    if (n != 0) {
      buzzerNumber = n;
      Serial.print("Button number is now ");
    }
    else {
      Serial.print("Error: NaN. Button number is still ");
    }
    Serial.println(buzzerNumber);
    delay(1000);
  }
}
