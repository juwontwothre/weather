#include "WeatherSimulation.h"
#include <iostream>
#include <cstdlib>

// 생성자: WeatherPredictor 객체와 랜덤 날씨 이벤트 배열 초기화
WeatherSimulation::WeatherSimulation(double temp, double hum, double co2) {
    predictor = make_unique<WeatherPredictor>(temp, hum, co2); // 예측기 생성
    events.resize(5); // 5개의 랜덤 날씨 이벤트 생성
    
    // 날씨 이벤트 배열 초기화
    for (auto& event : events) {
        event = make_shared<RandomWeatherEvent>(); // RandomWeatherEvent의 인스턴스를 shared_ptr로 생성
    }
}

// 날씨 예측 및 이벤트 출력 함수
void WeatherSimulation::runSimulation(int futureDays) {
    // 예측 결과를 기록하기 위한 로거 객체
    WeatherLogger<string> logger;
    logger.addLog("날씨 예측 시작");

    // 미래 날짜에 대해 예측을 수행
    for (int day = 1; day <= futureDays; ++day) {
        // 미래의 온도, 습도, CO2 농도를 랜덤하게 설정
        double temperature = rand() % 10 + 20.0; // 20~29°C 범위의 온도
        double humidity = rand() % 20 + 50.0;    // 50~69% 범위의 습도
        double co2Level = rand() % 50 + 300.0;   // 300~349 ppm 범위의 CO2 농도

        // 날씨 예측 및 랜덤 날씨 이벤트 설명
        string prediction = predictor->predict(); // 예측된 날씨
        string eventDescription = events[day % events.size()]->description(); // 랜덤 날씨 이벤트

        // 예측 결과를 로그에 추가
        logger.addLog("Day " + to_string(day) + ": " + prediction + ", 이벤트: " + eventDescription);

        // 예측 및 이벤트 출력
        cout << "Day " << day << ":\n";
        cout << *predictor << "\n"; // 예측된 날씨 출력 (WeatherPredictor 객체 출력)
        cout << "특별 이벤트: " << eventDescription << "\n\n"; // 랜덤 날씨 이벤트 출력
    }

    // 예측 종료 후 로그 저장
    logger.addLog("날씨 예측 종료");
    logger.saveToFile("weather_log.txt");
    cout << "예측 결과가 'weather_log.txt'에 저장되었습니다.\n";
}

