#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

Int dinoY = 50;
Int groundLevel = 50;
Int jump = 0;
Int cactusX = SCREEN_WIDTH;
Bool isJumping = false;
Bool gameOver = false;

Void setup() {
  pinMode(2, INPUT_PULLUP); // Button to jump
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
}

Void loop() {
  If (digitalRead(2) == LOW && !isJumping && !gameOver) {
    isJumping = true;
  }

  If (isJumping) {
    dinoY -= 4;
    if (dinoY <= 20) isJumping = false;
  } else if (dinoY < groundLevel) {
    dinoY += 4;
  }

  cactusX -= 4;
  if (cactusX < 0) cactusX = SCREEN_WIDTH;

  if (cactusX < 20 && dinoY >= groundLevel – 10) {
    gameOver = true;
  }

  Display.clearDisplay();

  If (gameOver) {
    Display.setTextSize(2);
    Display.setTextColor(WHITE);
    Display.setCursor(10, 30);
    Display.print(“Game Over”);
  } else {
    Display.fillRect(10, dinoY, 10, 10, WHITE); // Dino
    Display.fillRect(cactusX, groundLevel – 10, 10, 10, WHITE); // Cactus
  }

  Display.display();
  Delay(50);
}
