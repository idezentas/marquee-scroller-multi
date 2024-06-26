#include "WString.h"
/** The MIT License (MIT)

Copyright (c) 2018 David Payne

Air Quality and Name Search added by idezentas

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#include <TimeLib.h>
#include "SunMoonCalc.h"

class OpenWeatherMapClient
{

private:
  String myApiKey = "";
  String myLang = "";
  String mySysLang = "";
  String units = "";
  String myCityName = "";
  String myWorldCityName1 = "";
  String myWorldCityName2 = "";
  String myWorldCityName3 = "";

  const char *servername = "api.openweathermap.org"; // remote server we will connect to

  String monthsArr[12];
  String daysArr[7];
  String dirArr[16];
  String airArr[5];
  String moonArr[8];

  typedef struct
  {
    String lat;
    String lon;
    String dt;
    String id;
    String city;
    String country;
    String temp;
    String humidity;
    String condition;
    String wind;
    String gust;
    String visibility;
    String weatherId;
    String description;
    String icon;
    boolean cached;
    String error;
    String pressure;
    String direction;
    String high;
    String low;
    String timeZone;
    String feel;
    String sunRise;
    String sunSet;
    String cloudcover;
    String seaLevel;
    String grndLevel;
    String rain;
    String aqi;
    String co;
    String no;
    String no2;
    String o3;
    String so2;
    String pm2_5;
    String pm10;
    String nh3;
  } weather;

  weather weathers[5];

  typedef struct
  {
    String sunRise;
    String sunNoon;
    String sunSet;
    String sunAzimuth;
    String sunElevation;
    String sunDistance;
    String moonRise;
    String moonNoon;
    String moonSet;
    String moonAzimuth;
    String moonElevation;
    String moonDistance;
    String moonAge;
    String moonIllumination;
    String moonPhase;
    String moonBrightLimbAngle;
    String moonAxisPositionAngle;
    String moonParallacticAngle;
  } moonS;

  moonS moonStruct[5];

  String roundValue(String value);
  String zeroPad(int number);
  String getMonthNameT(struct tm *time_local);
  String getWeekNameT(struct tm *time_local);

public:
  OpenWeatherMapClient(String ApiKey, boolean isMetric, String CityName, String language, String SysLang);
  void updateWeatherName(String CityName, int index);
  void updateCityAirPollution(String latitude, String longitude, int index);
  void updateSunMoonTime(time_t currentTime, String latitude, String longitude, int index);
  void updateWeatherApiKey(String ApiKey);
  void setMetric(boolean isMetric);
  void updateCityName(String CityName);
  void updateWorldCityName1(String WorldCityName1);
  void updateWorldCityName2(String WorldCityName2);
  void updateWorldCityName3(String WorldCityName3);
  void updateLanguage(String language);
  void updateSystemLanguage(String SysLang);

  String getLat(int index);
  String getLon(int index);
  String getDt(int index);
  String getID(int index);
  String getCity(int index);
  String getCountry(int index);
  String getTemp(int index);
  String getFeel(int index);
  String getFeelRounded(int index);
  String getTempRounded(int index);
  String getHumidity(int index);
  String getHumidityRounded(int index);
  String getCondition(int index);
  String getWind(int index);
  String getWindRounded(int index);
  String getGust(int index);
  String getGustRounded(int index);
  String getDirection(int index);
  String getDirectionRounded(int index);
  String getDirectionText(int index);
  String getPressure(int index);
  String getHigh(int index);
  String getHighRounded(int index);
  String getLow(int index);
  String getLowRounded(int index);
  String getVisibility(int index);
  String getVisibilityOtherUnit(int index);
  String getWeatherId(int index);
  String getDescription(int index);
  String getIcon(int index);
  boolean getCached(int index);
  String getMyCityName();
  String getWeatherIcon(int index);
  String getError(int index);
  String getWeekDay(int index, float offset);
  int getTimeZone(int index);
  String getCloudcover(int index);
  String getSeaLevel(int index);
  String getGrndLevel(int index);
  String getRain(int index);
  String getSunrise(int index);
  String getSunset(int index);
  String getSunDifference(int index);
  String cleanText(String text);
  String getAqi(int index);
  String getCO(int index);
  String getNO(int index);
  String getNO2(int index);
  String getO3(int index);
  String getSO2(int index);
  String getPM10(int index);
  String getPM2_5(int index);
  String getNH3(int index);
  time_t getCityTimeStamp(int index);
  String getMoonRise(int index);
  String getMoonSet(int index);
  String getMoonDifference(int index);
  String getMoonPhase(int index);
  String getMoonIllumination(int index);
};
