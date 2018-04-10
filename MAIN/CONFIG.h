#pragma once
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//#define _DEBUG // закомментировать для выключения отладочной информации
#define IGNORE_ROD_POSITION // ЗАКОММЕНТИРОВАТЬ, ЕСЛИ НЕ НАДО ИГНОРИРОВАТЬ ПОЗИЦИЮ ШТАНГИ ПРИ СРАВНЕНИИ ЭТАЛОНОВ !!!
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// настройки пинов прерываний
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define INTERRUPT1_PIN 7
#define INTERRUPT2_PIN 8
#define INTERRUPT3_PIN 35

#define INTERRUPT_RESERVE_RECORDS 100 // на сколько импульсов первоначально резервировать памяти в списках прерываний, для оптимизации работы с памятью

#define INTERRUPT_MAX_IDLE_TIME 1200000    // время, в микросекундах, после получения последнего импульса и до момента, когда будет принято решение, что импульсы на входе закончились
#define INTERRUPT_SCREEN_SEE_TIME 6000    // сколько миллисекунд демонстрировать экран с графиками прерываний?
#define INTERRUPT_CHART_X_POINTS 150      // кол-во точек по X на графике прерываний
#define INTERRUPT_CHART_Y_POINTS 100      // кол-во точек по Y на графике прерываний
#define INTERRUPT_CHART_X_COORD 5         // Х-координата графика прерываний на экране
#define INTERRUPT_CHART_Y_COORD 120       // стартовая Y-координата графика прерываний на экране

// стартовые координаты верхнего/левого угла сетки
#define INTERRUPT_CHART_GRID_X_START 5 
#define INTERRUPT_CHART_GRID_Y_START 20
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// настройка светодиодов
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define LED_ON_LEVEL HIGH // уровень включения светодиодов

#define LED_READY  37                // Индикация светодиодом "Готов"
#define LED_FAILURE  36              // Индикация светодиодом "Авария"
#define LED_TEST  38                 // Индикация светодиодом "Тест"
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// настройка кнопок
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define BUTTON_RED  39                  // Кнопка №1, красная
#define BUTTON_BLUE1  40                  // Кнопка №2, синяя
#define BUTTON_BLUE2  41                  // Кнопка №3, синяя
#define BUTTON_YELLOW  9                   // Кнопка №4, жёлтая
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// настройка логов
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define LOGS_DIRECTORY "/LOG" // папка, в которой лежат логи
#define ETHALONS_DIRECTORY "/ETL" // папка, где лежат эталоны
#define ETHALON_NAME_PREFIX "/et" // префикс имени файла эталона
#define ETHALON_UP_POSTFIX "up" // постфикс для имени файла эталона, поднятие штанги
#define ETHALON_DOWN_POSTFIX "dwn" // постфикс для имени файла эталона, опускание штанги
#define ETHALON_FILE_EXT ".etl" // расширение файла эталона
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define DATA_MEASURE_THRESHOLD 2000 // через сколько миллисекунд обновлять показания с линий вольтажа и температуру с часов
#define VOLTAGE_THRESHOLD 10 // порог изменений, в процентах, для принятия решения о том, хороший вольтаж или нет
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// настройки EEPROM
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// импульсы по каналам
#define COUNT_PULSES_STORE_ADDRESS1 10 // по какому адресу храним переменную для кол-ва импульсов канала 1 (2 байта)
#define COUNT_PULSES_STORE_ADDRESS2 12 // по какому адресу храним переменную для кол-ва импульсов канала 2 (2 байта)
#define COUNT_PULSES_STORE_ADDRESS3 14 // по какому адресу храним переменную для кол-ва импульсов канала 3 (2 байта)

// дельты импульсов по каналам
#define CHANNEL_PULSES_DELTA_ADDRESS1 16 // адрес хранения дельты импульсов канала 1 (1 байт)
#define CHANNEL_PULSES_DELTA_ADDRESS2 17 // адрес хранения дельты импульсов канала 1 (1 байт)
#define CHANNEL_PULSES_DELTA_ADDRESS3 18 // адрес хранения дельты импульсов канала 1 (1 байт)

// моторесурс по каналам
#define MOTORESOURCE_STORE_ADDRESS1  100 // адрес хранения кол-ва срабатываний защиты канала 1 (4 байта)
#define MOTORESOURCE_STORE_ADDRESS2  104 // адрес хранения кол-ва срабатываний защиты канала 2 (4 байта)
#define MOTORESOURCE_STORE_ADDRESS3  108 // адрес хранения кол-ва срабатываний защиты канала 3 (4 байта)

#define MOTORESOURCE_MAX_STORE_ADDRESS1  112 // адрес хранения макс. кол-ва срабатываний защиты канала 1 (4 байта)
#define MOTORESOURCE_MAX_STORE_ADDRESS2  116 // адрес хранения макс. кол-ва срабатываний защиты канала 2 (4 байта)
#define MOTORESOURCE_MAX_STORE_ADDRESS3  120 // адрес хранения макс. кол-ва срабатываний защиты канала 3 (4 байта)

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// настройки обновления состояния исправности индуктивных датчиков
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define INDUCTIVE_SENSORS_UPDATE_INTERVAL 1000 // интервал обновления, в миллисекундах
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// версия ПО
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define SOFTWARE_VERSION "v.0.1a"
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// время в миллисекундах, после которого идёт переключение на главный экран, если какой-то экран висит долгое время
#define RESET_TO_MAIN_SCREEN_DELAY 60000
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// частота мигания надписью моторесурса, если он исчерпан, миллисекунд
#define MOTORESOURCE_BLINK_DURATION 800

// через сколько процентов до максимального мигать надписью моторесурса (например, если уканано 10, то будет мигать после 90% выработки)
#define MOTORESOURCE_BLINK_PERCENTS 10
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// кол-во кадров в секунду для отображения синусоид
#define CHART_FPS 30
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// дельта времени импульсов (микросекунд) при сравнении эталона с пачкой пойманных импульсов
#define ETHALON_COMPARE_DELTA 500





















#define NVIC_PriorityGroup_0   ((uint32_t)0x700)
#define NVIC_PriorityGroup_1   ((uint32_t)0x600)
#define NVIC_PriorityGroup_2   ((uint32_t)0x500)
#define NVIC_PriorityGroup_3   ((uint32_t)0x400)
#define NVIC_PriorityGroup_4   ((uint32_t)0x300)







#ifdef _DEBUG
  #define DBG(s) { Serial << (s); }
  #define DBGLN(s) { Serial << (s) << ENDL; }
#else
  #define DBG(s) (void) 0
  #define DBGLN(s) (void) 0
#endif
#define ENDL '\n'
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
template <typename T> inline Stream& operator << (Stream &s, T n) { s.print(n); return s; }
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#define CORE_COMMAND_GET F("GET=") // префикс для команды получения данных из ядра
#define CORE_COMMAND_SET F("SET=") // префикс для команды сохранения данных в ядро
#define CORE_COMMAND_ANSWER_OK F("OK=") // какой префикс будет посылаться в ответ на команду получения данных и её успешной отработке
#define CORE_COMMAND_ANSWER_ERROR F("ER=") // какой префикс будет посылаться в ответ на команду получения данных и её неуспешной отработке
#define CORE_COMMAND_PARAM_DELIMITER '|' // разделитель параметров
#define CORE_END_OF_DATA F("[END]")
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------

