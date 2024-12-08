#ifndef WEATHERSIMULATION_H
#define WEATHERSIMULATION_H

#include "WeatherPredictor.h"
#include "WeatherEvent.h"
#include "WeatherLogger.h"
#include <memory>
#include <vector>
using namespace std;

class WeatherSimulation {
private:
    unique_ptr<WeatherPredictor> predictor; // WeatherPredictor 객체 포인터
    vector<shared_ptr<WeatherEvent>> events; // WeatherEvent 객체 배열

public:
    // 생성자: 날씨 예측 및 이벤트 객체를 초기화
    WeatherSimulation(double temp, double hum, double co2);

    // 시뮬레이션을 실행하는 함수
    void runSimulation(int futureDays);
};

#endif
