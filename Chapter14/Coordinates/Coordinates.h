#ifndef COORDINATES_H
#define COORDINATES_H

#include <functional>
class Coordinates{
    private:
        static const int EARTH_RADIUS;
        enum LIMITS{CEN_LAT = 0, CEN_LONG = 0, MIN_LAT = -90, MAX_LAT = 90, MIN_LONG = -180, MAX_LONG = 180};
        double latitude;
        double longitude;

        bool compareDistances(const Coordinates& otherCoordinates, std::function<bool(double, double)> comparator);
        double toRadias(double value);

    public:
        Coordinates(double lat = 0, double lon = 0);
        Coordinates(const Coordinates& otherCoordinates);
        
        void setLatitude(double lat);
        void setLongitude(double lon);

        void printCoordinates(char delimeter = ' ');
        double getLatitude() const;
        double getLongitude() const;

        bool operator<=(const Coordinates& otherCoordinates);
        bool operator>=(const Coordinates& otherCoordinates);
        bool operator!=(const Coordinates& otherCoordinates);
        Coordinates operator*(const Coordinates& otherCoordinates);

};


#endif