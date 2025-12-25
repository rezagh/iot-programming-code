void setup() {


}

void loop() {

  //do-while control statement
  do { 
      // statement block 
  } while (condition);

  //do-while example
  int x = 0;
  do {
    delay(5);        
    digitalWrite(LEDpin, HIGH);
  } while (x < 100);

//-------

  while (condition) { // statement(s) 
  }


  var = 0;
  while (var < 200) {
    // do something repetitive 200 times
    var++;
  }

//---------

  for (initialization; condition; increment) { 
      // statement(s); 
  }

    for (int i = 0; i <= 255; i++) {
      analogWrite(PWMpin, i);
      delay(10);
    }

//---------


  if (condition) {
    //statement(s)
  }

  if (x > 120) digitalWrite(LEDpin, HIGH);

  if (x > 120)
  digitalWrite(LEDpin, HIGH);

  if (x > 120) {digitalWrite(LEDpin, HIGH);}

  if (x > 120) {
    digitalWrite(LEDpin1, HIGH);
    digitalWrite(LEDpin2, HIGH);



}
