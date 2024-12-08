#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// 랜덤 날씨 이벤트 생성 함수
string randomWeatherEvent() {
    int randomEvent = rand() % 5; // 0~4 사이의 난수 생성
    switch (randomEvent) {
        case 0: return "맑고 평화로운 하루!";
        case 1: return "강한 폭풍이 다가옵니다. 외출을 삼가세요!";
        case 2: return "가벼운 비가 내리기 시작합니다.";
        case 3: return "폭염 경보! 에어컨을 켜두세요.";
        case 4: return "눈보라가 몰아칩니다. 따뜻하게 입으세요!";
        default: return "이상 기후 발생!";
    }
}

// 날씨 상태 예측 함수
string predictWeather(double temperature, double humidity, double co2Level) {
    if (temperature > 35.0) {
        return "더운 날씨와 폭염 경보!";
    } else if (humidity > 70.0) {
        return "습도가 높아 비가 내릴 가능성이 높습니다.";
    } else if (temperature < 0.0) {
        return "추운 날씨와 눈 가능성!";
    } else if (co2Level > 400.0) {
        return "대기 오염 증가로 불쾌한 날씨!";
    } else {
        return "온화하고 맑은 날씨!";
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // 랜덤 시드 초기화

    // 입력 변수 선언
    double currentTemperature, currentHumidity, currentCO2Level;
    int futureDays;

    // 사용자 입력 받기
    cout << "현재 온도를 입력하세요 (°C): ";
    cin >> currentTemperature;
    cout << "현재 습도를 입력하세요 (%): ";
    cin >> currentHumidity;
    cout << "현재 CO₂ 농도를 입력하세요 (ppm): ";
    cin >> currentCO2Level;
    cout << "미래를 몇 일 뒤까지 예측할까요? (일): ";
    cin >> futureDays;

    cout << "\n=== 날씨 예측 시뮬레이션 시작 ===\n";

    for (int day = 1; day <= futureDays; ++day) {
        // 날씨 변화 시뮬레이션
        currentTemperature += (rand() % 5 - 2); // -2~+2 사이의 온도 변화
        currentHumidity += (rand() % 11 - 5);  // -5~+5 사이의 습도 변화
        currentCO2Level += (rand() % 21 - 10); // -10~+10 사이의 CO2 변화

        // 날씨 상태 예측 및 랜덤 이벤트 출력
        cout << "Day " << day << ":\n";
        cout << "예측된 날씨: " << predictWeather(currentTemperature, currentHumidity, currentCO2Level) << "\n";
        cout << "특별 이벤트: " << randomWeatherEvent() << "\n\n";
    }

    cout << "=== 시뮬레이션 종료 ===\n";
    return 0;
}
