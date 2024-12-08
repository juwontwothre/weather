#include "WeatherSimulation.h"
#include <iostream>

int main() {
    // 사용자로부터 현재 날씨 정보를 입력 받음
    double temperature, humidity, co2Level;
    int futureDays;

    cout << "현재 온도를 입력하세요 (°C): ";
    cin >> temperature;
    cout << "현재 습도를 입력하세요 (%): ";
    cin >> humidity;
    cout << "현재 CO₂ 농도를 입력하세요 (ppm): ";
    cin >> co2Level;
    cout << "미래를 몇 일 뒤까지 예측할까요? (일): ";
    cin >> futureDays;

    // 날씨 예측 시뮬레이션 객체 생성
    WeatherSimulation simulation(temperature, humidity, co2Level);

    // 시뮬레이션 실행
    simulation.runSimulation(futureDays);

    return 0;
}
