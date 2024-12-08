#ifndef WEATHERLOGGER_H
#define WEATHERLOGGER_H

#include <vector>
#include <string>
using namespace std;

template <typename T>
class WeatherLogger {
private:
    vector<T> logs; // 예측 결과를 저장할 벡터

public:
    // 로그를 벡터에 추가하는 함수
    void addLog(const T& log);

    // 로그를 파일로 저장하는 함수
    void saveToFile(const string& filename) const;
};

#endif
