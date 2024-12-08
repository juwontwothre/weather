#include "WeatherEvent.h"
#include <cstdlib>

// 랜덤 날씨 이벤트 설명을 랜덤하게 반환하는 함수
string RandomWeatherEvent::description() const {
    // 0~4 사이의 난수 생성
    int randomEvent = rand() % 5; 
    
    // 난수에 따른 날씨 이벤트를 반환
    switch (randomEvent) {
        case 0: return "맑고 평화로운 하루!";
        case 1: return "강한 폭풍이 다가옵니다. 외출을 삼가세요!";
        case 2: return "가벼운 비가 내리기 시작합니다.";
        case 3: return "폭염 경보! 에어컨을 켜두세요.";
        case 4: return "눈보라가 몰아칩니다. 따뜻하게 입으세요!";
        default: return "이상 기후 발생!"; // 기본값으로 이상 기후가 발생했다고 출력
    }
}

