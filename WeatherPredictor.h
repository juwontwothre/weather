#pragma once
#include <iostream>
#include <string>

class WeatherPredictor {
private:
    double temperature;  // 온도
    double humidity;     // 습도
    double co2Level;     // CO2 농도

public:
    // 생성자: 온도, 습도, CO2 농도를 초기화
    WeatherPredictor(double temp, double hum, double co2);

    // 날씨 예측 함수: 온도, 습도, CO2 농도에 따른 예측 결과 반환
    std::string predict() const;

    // WeatherPredictor 객체를 ostream에 출력할 수 있도록 operator<< 오버로딩
    friend std::ostream& operator<<(std::ostream& os, const WeatherPredictor& predictor);
};


