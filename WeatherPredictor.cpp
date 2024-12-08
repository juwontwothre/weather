#include "WeatherPredictor.h"
#include <iostream>

// 생성자: WeatherPredictor 객체를 초기화하는 생성자
// 입력된 온도, 습도, CO2 농도 값을 이용해 객체의 멤버 변수들을 초기화
WeatherPredictor::WeatherPredictor(double temp, double hum, double co2) 
    : temperature(temp), humidity(hum), co2Level(co2) {
    // 멤버 초기화 리스트를 통해 각각의 값을 설정
    // temperature: 현재 온도 (°C)
    // humidity: 현재 습도 (%)
    // co2Level: 현재 CO2 농도 (ppm)
}

// 날씨 예측 함수
// 입력된 온도, 습도, CO2 농도에 따라 날씨를 예측하고 그 결과를 문자열로 반환
std::string WeatherPredictor::predict() const {
    // 날씨 예측 로직
    if (temperature > 35.0) {
        // 온도가 35도 이상이면 폭염 경고
        return "더운 날씨와 폭염 경보!";
    } else if (humidity > 70.0) {
        // 습도가 70% 이상이면 비가 내릴 가능성
        return "습도가 높아 비가 내릴 가능성이 높습니다.";
    } else if (temperature < 0.0) {
        // 온도가 0도 이하이면 추운 날씨와 눈 가능성
        return "추운 날씨와 눈 가능성!";
    } else if (co2Level > 400.0) {
        // CO2 농도가 400ppm 이상이면 대기 오염 경고
        return "대기 오염 증가로 불쾌한 날씨!";
    } else {
        // 그 외의 경우, 온화하고 맑은 날씨
        return "온화하고 맑은 날씨!";
    }
}

// WeatherPredictor 객체를 출력할 수 있도록 operator<< 오버로딩
// ostream 객체에 WeatherPredictor의 온도, 습도, CO2 농도를 출력하는 함수
std::ostream& operator<<(std::ostream& os, const WeatherPredictor& predictor) {
    // 출력되는 내용은 온도, 습도, CO2 농도 순서
    os << "온도: " << predictor.temperature << "°C, "  // 온도 출력
       << "습도: " << predictor.humidity << "%, "      // 습도 출력
       << "CO2 농도: " << predictor.co2Level << "ppm"; // CO2 농도 출력

    // 출력이 완료된 후 ostream 객체를 반환
    return os;
}

