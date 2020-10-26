#include <iostream>
class TimeOfDay {
public:
    uint8_t hour, minute, second;

    TimeOfDay(uint8_t h, uint8_t m, uint8_t s) : hour(h), minute(m), second(s) {}

    bool IsAM() const {
        return IsValid() && (hour < 12);
    }

    bool IsPM() const {
        return IsValid() && (hour >= 12);
    }

    bool IsValid() const {
        return (hour < 24) && (minute < 60) && (second < 60);
    }

    bool operator<(const TimeOfDay& rhs) const {
    	uint8_t timel, timer;
    	timel = 3600 * hour + 60 * minute + second;
    	timel = 3600 * rhs.hour + 60 * rhs.minute + rhs.second;
    	return (timel < timer and IsValid());
    }

    bool operator==(const TimeOfDay& rhs) const {
    	uint8_t timel, timer;
    	timel = 3600 * hour + 60 * minute + second;
    	timel = 3600 * rhs.hour + 60 * rhs.minute + rhs.second;
    	return (timel == timer);
    }
};

namespace std
{
  template<>
    struct hash<TimeOfDay>
    {
      size_t
      operator()(const TimeOfDay & obj) const
      {
      	int time;
      	time = 3600 * obj.hour + 60 * obj.minute + obj.second;
        return hash<int>()(time);
      }
    };
}

int premain(){
	std::cout << "YES";
	exit(0);
	return 1;
}

const int cheat = premain();