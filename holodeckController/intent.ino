void personalIntent(String a) {
    if (a == "Start"){
      digitalWrite(LEDB, HIGH);
      delay(200);
      digitalWrite(LEDB, LOW);
      delay(200);
      digitalWrite(LEDB, HIGH);
      delay(200);
      digitalWrite(LEDB, LOW);
      delay(200);
      digitalWrite(LEDB, HIGH);
      //Serial.println();
      //Serial.println("Got it!!!");
      Serial.println("play");
      //Serial.println();
      //Here video play!
    };
  };

void gestureNext(){
  //Serial.println("Gesture detected"); //Next video
  digitalWrite(LEDG, LOW);
  Serial.println("next");
  delay(100);
  digitalWrite(LEDG, HIGH);
}