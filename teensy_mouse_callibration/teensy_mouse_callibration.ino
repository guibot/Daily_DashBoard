#include <Mouse.h>

int mouseX = 0;
int mouseY = 0;
bool isMoving = false;

void setup() {
  Mouse.begin();
  delay(1000);
  moveToCorner();            // força o cursor para (0, 0)
  delay(1000);
  mouseMoveTo(218, 142);     // move para posição relativa
}

void loop() {
  // vazio para este exemplo
}

// Etapa 1: empurra o cursor para o canto superior esquerdo
void moveToCorner() {
  for (int i = 0; i < 100; i++) {
    Mouse.move(-127, -127);
    delay(10);
  }
  mouseX = 0;
  mouseY = 0;
}

// Etapa 2: simula movimento absoluto a partir de (0,0)
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
