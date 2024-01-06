#include "Coordinates.h"
#include <iostream>
#include <cmath>

using namespace std;

const int Coordinates::EARTH_RADIUS = 6371;

Coordinates::Coordinates(double lat, double lon){
    if(lat < MIN_LAT || lat > MAX_LAT || lon < MIN_LONG || lon > MAX_LONG){
        cout << "\nINVALID INPUT";
        exit(0);
    }
    latitude = lat;
    longitude = lon;
};

Coordinates::Coordinates(const Coordinates& otherCoordinates){
    this->latitude = otherCoordinates.latitude;
    this->longitude = otherCoordinates.longitude;
}


bool Coordinates::compareDistances(const Coordinates& otherCoordinates, std::function<bool(double, double)> comparator){
    double aOne , cOne, dOne, aTwo, cTwo, dTwo;

    aOne = pow(sin((toRadias(this->latitude) - CEN_LAT)/2), 2) + cos(toRadias(this->latitude)) * cos(toRadias(static_cast<double>(CEN_LAT))) * pow(sin(toRadias(this->longitude - CEN_LONG)/2), 2);
    cOne = 2 * atan2(sqrt(aOne), sqrt(1 - aOne));

    aTwo = pow(sin((toRadias(otherCoordinates.latitude) - CEN_LAT)/2), 2) + cos(toRadias(otherCoordinates.latitude)) * cos(toRadias(static_cast<double>(CEN_LAT))) * pow(sin(toRadias(otherCoordinates.longitude - CEN_LONG)/2), 2);
    cTwo = 2 * atan2(sqrt(aTwo), sqrt(1 - aTwo));

    dOne = EARTH_RADIUS * cOne;
    dTwo = EARTH_RADIUS * cTwo;

    return comparator(dOne, dTwo);
}

double Coordinates::toRadias(double value){
    return value / 180 * 3.14159265358979323846;
}

void Coordinates::setLatitude(double lat){
    if(lat < MIN_LAT || lat > MAX_LAT){
        cout << "\nINVALID INPUT";
        exit(0);
    }
    latitude = lat;

}
void Coordinates::setLongitude(double lon){
    if(lon < MIN_LONG || lon > MAX_LONG){
        cout << "\nINVALID INPUT";
        exit(0);
    }
    longitude = lon;
}

void Coordinates::printCoordinates(char delimeter){
    cout << latitude << ", " << longitude << delimeter;

}
double Coordinates::getLatitude() const{
    return latitude;

}
double Coordinates::getLongitude() const{
    return longitude;

}

bool Coordinates::operator<=(const Coordinates& otherCoordinates){
    return compareDistances(otherCoordinates, std::less_equal<double>());
}

bool Coordinates::operator>=(const Coordinates& otherCoordinates){
       return compareDistances(otherCoordinates, std::greater_equal<double>());
}

bool Coordinates::operator!=(const Coordinates& otherCoordinates){
        return compareDistances(otherCoordinates, std::not_equal_to<double>());
}

Coordinates Coordinates::operator*(const Coordinates& otherCoordinates){
    Coordinates result;
    result.latitude = this->latitude * otherCoordinates.latitude < MIN_LAT? MIN_LAT : this->latitude * otherCoordinates.latitude > MAX_LAT? MAX_LAT : this->latitude * otherCoordinates.latitude;
    result.longitude = this->longitude * otherCoordinates.longitude < MIN_LONG? MIN_LONG : this->longitude * otherCoordinates.longitude > MAX_LONG? MAX_LONG : this->longitude * otherCoordinates.longitude;

    return result;

}
