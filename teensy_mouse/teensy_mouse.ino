#include <Mouse.h>

const int joyY_pin = A8;
const int joyX_pin = A7;

const int joystick_btpin = 14;

const int mouse_left_btpin = 15;
const int scrolldown_btpin = 16;
const int scrollup_btpin = 17;
const int close_btpin = 19;

const int custom_btpin = 18;


int rawx, rawy, x, y;
int threshold = 10;  // dead zone

int mouseX = 0;
int mouseY = 0;
bool isMoving = false;

int joybt, mouse_left, scrolldown, scrollup, custom;

int close;
int close_prev = HIGH;

void setup() {
  Serial.begin(11520);

  pinMode(joystick_btpin, INPUT_PULLUP);
  pinMode(mouse_left_btpin, INPUT_PULLUP);
  pinMode(custom_btpin, INPUT_PULLUP);
  pinMode(close_btpin, INPUT_PULLUP);
  pinMode(scrolldown_btpin, INPUT_PULLUP);
  pinMode(scrollup_btpin, INPUT_PULLUP);

  Mouse.begin();

  delay(2000);

  if (digitalRead(mouse_left_btpin) == HIGH)
    wait(2, 20);  // wait 2 minutes, 20 seconds (140000 ms)

  delay(1000);
  moveToCorner();            // move mouse to (0, 0)
  delay(1000);
  mouseMoveTo(218, 142);     // move to relative pos
  delay(500);
  Mouse.press(MOUSE_LEFT);
  delay(100);
  Mouse.release(MOUSE_LEFT);
}

void loop() {

  rawx = analogRead(joyX_pin);
  rawy = analogRead(joyY_pin);

  joybt = digitalRead(joystick_btpin);
  mouse_left = digitalRead(mouse_left_btpin);

  close = digitalRead(close_btpin);
  scrolldown = digitalRead(scrolldown_btpin);
  scrollup = digitalRead(scrollup_btpin);

  custom = digitalRead(custom_btpin);

  x = -(rawx - 512);
  y = rawy - 512;

  // dead zone
  if (abs(x) < threshold) x = 0;
  if (abs(y) < threshold) y = 0;

  // 
  x = x / 250;
  y = y / 250;

  Mouse.move(x, y);  // (x, y)

  // bts
  if (digitalRead(mouse_left_btpin) == LOW) Mouse.press(MOUSE_LEFT);
  else Mouse.release(MOUSE_LEFT);

  //Serial.printf("close: %d || close_prev: %d\n", close, close_prev);

  if (close == LOW && close_prev == HIGH) {
    // Ctrl + W
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('w');
    delay(10);
    Keyboard.releaseAll();
    //Serial.println("close");
  }

  // update close state
  close_prev = close;


  // scroll
  if (digitalRead(scrolldown_btpin) == LOW) {
    // Scroll down
    Mouse.scroll(-1);
    delay(100);
  }

  if (digitalRead(scrollup_btpin) == LOW) {
    // Scroll up
    Mouse.scroll(1);
    delay(100);
  }
  /**/

  delay(10);
}



void moveToCorner() {
  for (int i = 0; i < 100; i++) {
    Mouse.move(-127, -127);
    delay(10);
  }
  mouseX = 0;
  mouseY = 0;
}


void mouseMoveTo(int targetX, int targetY) {
  int dx = targetX - mouseX;
  int dy = targetY - mouseY;

  while (dx != 0 || dy != 0) {
    int stepX = constrain(dx, -127, 127);
    int stepY = constrain(dy, -127, 127);

    Mouse.move(stepX, stepY);
    mouseX += stepX;
    mouseY += stepY;

    dx = targetX - mouseX;
    dy = targetY - mouseY;

    delay(5);
  }
}

void wait(int minutes, int seconds) {
  unsigned long totalMs = (minutes * 60UL + seconds) * 1000UL;
  delay(totalMs);
}