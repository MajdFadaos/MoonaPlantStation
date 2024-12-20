
#include <RTClib.h>

// Init rtc object
//   DS1302 rtc;
//   DS1302 rtc(ce_pin, sck_pin, io_pin);
//
// ce_pin  (RST): default 4
// sck_pin (CLK): default 5
// io_pin  (DAT): default 6
//DS1302 rtc;

// RTC_PINS
#define RTC_SDA_PIN 11
#define RTC_SCL_PIN 13
#define RTC_RST_PIN 9
DS1302 rtc(RTC_RST_PIN, RTC_SCL_PIN, RTC_SDA_PIN);

// buffer for DateTime.tostr
char buf[20];

void setup() {
  Serial.begin(115200);
  rtc.begin();
  
  if (!rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(__DATE__, __TIME__));
  }
}

void loop() {
  DateTime now = rtc.now();
  
  Serial.println(now.tostr(buf));

/*
  Serial.print(" since midnight 1970/01/01 = ");
  Serial.print(now.unixtime());
  Serial.print("s = ");
  Serial.print(now.unixtime() / 86400L);
  Serial.println("d");

  // calculate a date which is 7 days and 30 seconds into the future
  DateTime future(now + (7 * 86400L + 30));

  Serial.print(" now + 7d + 30s: ");
  Serial.println(future.tostr(buf));

  // calculate a date which is 30 days before
  DateTime past(now - TimeDelta(30 * 86400L));

  Serial.print(" now - 30d: ");
  Serial.println(past.tostr(buf));

  Serial.println();
  */
  delay(1000);
}
