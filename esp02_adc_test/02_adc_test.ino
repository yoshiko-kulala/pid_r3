#include "driver/adc.h" 
#include "esp_adc_cal.h"
#define ADC_PIN 36
esp_adc_cal_characteristics_t adcChar;

void setup() { 
  pinMode(ADC_PIN,ANALOG);
  Serial.begin(115200);
  esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_12, 1100, &adcChar);
  Serial.println("espcal,analogRead,MilliVolts");
}

void loop(){
  Serial.println((int)analogReadMilliVolts(ADC_PIN));
  delay(100);
}
