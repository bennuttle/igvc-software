#include <queue>
#include "gpsfilereader.h"

#ifndef GPSWAYPOINTSOURCE_H
#define GPSWAYPOINTSOURCE_H

#endif // GPSWAYPOINTSOURCE_H

class GPSWaypointSource
{
public:
    GPSWaypointSource(std::string file);
    GPSData getNext();
private:
    std::queue<GPSData> _data;
};
