#include "GPSWaypointSource.h"

GPSWaypointSource::GPSWaypointSource(std::string file)
{
    GPSFileReader::read(file, _data);
}

GPSData GPSWaypointSource::getNext()
{
    GPSData temp = _data.front();
    _data.pop();
    return temp;
}
