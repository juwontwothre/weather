#ifndef WEATHEREVENT_H
#define WEATHEREVENT_H

#include <string>
using namespace std;

// 추상 클래스 WeatherEvent - 날씨 이벤트에 대한 기본 인터페이스 정의
class WeatherEvent {
public:
    // 순수 가상 함수 description: 날씨 이벤트를 설명하는 문자열을 반환
    virtual string description() const = 0; 
    
    // 가상 소멸자: 파생 클래스에서 올바르게 소멸될 수 있도록 해줌
    virtual ~WeatherEvent() {} 
};

// 랜덤 날씨 이벤트 클래스 - WeatherEvent를 상속받아 랜덤 날씨 이벤트 설명을 제공
class RandomWeatherEvent : public WeatherEvent {
public:
    // 날씨 이벤트 설명을 랜덤하게 반환하는 함수
    string description() const override; 
};

#endif
