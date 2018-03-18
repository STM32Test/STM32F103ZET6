#include <Arduino.h>
#include "CONFIG.h"
#include "UTFTMenu.h"
#include "DS3231.h"               // подключаем часы
#include "ConfigPin.h"
#include "AT24CX.h"
#include "InterruptHandler.h"
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// подключаем наши экраны
#include "Screen1.h"              // Главный экран
#include "Screen2.h"              // Вызов меню настроек
#include "Screen3.h"              //
#include "Screen4.h"              // Вызов меню установки времени и даты
#include "Screen5.h"              // Вызов установки времени
#include "Screen6.h"              // Вызов установки даты
#include "InterruptScreen.h"      // экран с графиком прерывания
#include "Buttons.h"  // наши железные кнопки
#include "InfoDiodes.h" // информационные диоды
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void setup() 
{
  Serial.begin(115200);
  while(!Serial);
  
  ConfigPin::setup();
 
  DBGLN(F("Init ADC..."));
  RealtimeClock.begin(1);           // запускаем их на шине I2C 1 (SDA1, SCL1);
 // RealtimeClock.setTime(0,1,11,1,7,2,2018);

  Screen.setup();


  DBGLN(F("Init screen..."));
  Screen.setup();

  DBGLN(F("Add screen1...")); 

  Screen.addScreen(Screen1::create());           // первый экран покажется по умолчанию
  DBGLN(F("Add screen2..."));

  // добавляем второй экран
  Screen.addScreen(Screen2::create());
  DBGLN(F("Add screen3..."));
  // добавляем третий экран. Переход в меню настройки
  Screen.addScreen(Screen3::create());
  DBGLN(F("Add screen4..."));
  // добавляем четвертый экран. Меню установки даты и времени
  Screen.addScreen(Screen4::create());
  DBGLN(F("Add screen5..."));
  // добавляем 5 экран. Установка времени
  Screen.addScreen(Screen5::create());
  DBGLN(F("Add screen6..."));
  // добавляем 6 экран. Установка даты
  Screen.addScreen(Screen6::create());
  DBGLN(F("Add interrupt screen..."));
  // добавляем экран с графиком прерываний
  Screen.addScreen(InterruptScreen::create());

  // переключаемся на первый экран
  Screen.switchToScreen("Main");

  // поднимаем наши прерывания - РАСКОММЕНТИРОВАТЬ И ЗАКОММЕНТИРОВАТЬ ТЕСТОВЫЙ КОД НИЖЕ!!!
  InterruptHandler.begin();

  // настраиваем информационные диоды
  InfoDiodes.begin();

  // настраиваем железные кнопки
  Buttons.begin();


  DBGLN(F("Inited."));

}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void loop() 
{
  // обновляем кнопки
  Buttons.update();
  Screen.update();

  // обновляем прерывания
  InterruptHandler.update();

}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void yield()
{
   // обновляем прерывания
   InterruptHandler.update();
   Buttons.update();
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------

