#include "WeatherLogger.h"
#include <fstream>
#include <stdexcept>

// 예측 결과를 로그에 추가하는 함수
template <typename T>
void WeatherLogger<T>::addLog(const T& log) {
    logs.push_back(log); // 벡터에 로그 추가
}

// 로그를 파일에 저장하는 함수
template <typename T>
void WeatherLogger<T>::saveToFile(const string& filename) const {
    ofstream file(filename); // 파일 열기
    // 파일 열기 실패 시 예외 처리
    if (!file) throw runtime_error("파일 열기 실패: " + filename);
    
    // 벡터에 저장된 모든 로그를 파일에 작성
    for (const auto& log : logs) {
        file << log << endl;
    }
    file.close(); // 파일 닫기
}

// 템플릿 함수 인스턴스화 (WeatherLogger<string>을 사용하기 위해)
template class WeatherLogger<string>;
