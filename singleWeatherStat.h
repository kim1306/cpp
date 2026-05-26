#ifndef SINGLEWEATHERSTAT_H_INCLUDED
#define SINGLEWEATHERSTAT_H_INCLUDED

#include "date.h"
#include "Time.h"


struct singleWeatherStat
{
    date d;
    Time t;
    float windSpeed;
    float temperature;
    float solarRadiation;


    singleWeatherStat()
        : d(10, 21, 2000), t(10, 10),
          windSpeed(0.0f), temperature(0.0f), solarRadiation(0.0f)
    {
    }

    singleWeatherStat(const date& date_val, const Time& time_val,
                      float wind, float temp, float solar)
        : d(date_val), t(time_val),
          windSpeed(wind), temperature(temp), solarRadiation(solar)
    {
    }

    bool operator<(const singleWeatherStat& other) const
    {
        if (d < other.d) return true;
        if (d > other.d) return false;
        return t < other.t;
    }

    bool operator>(const singleWeatherStat& other) const
    {
        return other < *this;
    }
    bool operator==(const singleWeatherStat& other) const
    {
        return d == other.d && t == other.t;
    }


    void display() const
    {
        std::cout << " | Wind: " << windSpeed << " m/s"
                  << " | Temp: " << temperature << " C"
                  << " | Solar: " << solarRadiation << " W/m*m";
    }
};

#endif // SINGLEWEATHERSTAT_H_INCLUDED
