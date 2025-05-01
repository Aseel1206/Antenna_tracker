#include <Servo.h>

Servo panServo;
Servo tiltServo;

int panAngle = 90;   // default center (North facing)
int tiltAngle = 0;  // default center(forward)

String inputString = "";
bool inputComplete = false;

void setup() {
  Serial.begin(9600);

  panServo.attach(9);   // connect pan servo to pin 9
  tiltServo.attach(10); // connect tilt servo to pin 10
  panServo.write(0); // East
  panServo.write(180);//West
  tiltServo.write(90); // perpendicular (facing up)
  tiltServo.write(180);//backward
  panServo.write(panAngle);//North
  tiltServo.write(tiltAngle);//forward
}

void loop() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    if (inChar == '\n') {
      inputComplete = true;
      break;
    } else {
      inputString += inChar;
    }
  }

  if (inputComplete) {
    parseAndMove(inputString);
    inputString = "";
    inputComplete = false;
  }
}

void parseAndMove(String data) {
  int commaIndex = data.indexOf(',');

  if (commaIndex > 0) {
    String panStr = data.substring(0, commaIndex);
    String tiltStr = data.substring(commaIndex + 1);

    int pan = panStr.toInt();
    int tilt = tiltStr.toInt();

    pan = constrain(pan, 0, 180);
    tilt = constrain(tilt, 0, 180);

    panServo.write(pan);
    tiltServo.write(tilt);

    Serial.print("Pan: ");
    Serial.print(pan);
    Serial.print(" | Tilt: ");
    Serial.println(tilt);
  }
}
