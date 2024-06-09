#include <Arduino.h>
#include "NeuralNetwork.h"

NeuralNetwork *nn;

void setup()
{
  Serial.begin(115200);
  nn = new NeuralNetwork();
}

void loop()
{
  float number = random(0, 628318)/100000.0;
  float sin_result = sin(number);
  nn->getInputBuffer()[0] = number;

  float result = nn->predict();

  Serial.printf("%.2f - result %.2f sin_result %.2f\n", number, result, sin_result);

  delay(1000);
}