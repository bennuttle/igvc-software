/*
 * GPS.hpp
 *
 *  Created on: Nov 5, 2012
 *      Author: Matthew Barulic
 */

#ifndef GPS_HPP_
#define GPS_HPP_

#include <time.h>
#include "events/Event.hpp"
#include "sensors/DataStructures/GPSData.h"

namespace IGVC {
namespace Sensors {



/*
 * Interface for GPS devices.
 */
class GPS
{
public:
	virtual ~GPS() { }

	/*
	 * Returns the most recent state acquired from the GPS device.
	 */
	virtual GPSData GetState() = 0;

	/*
	 * Returns the GPSState with the given timestamp.
	 * Throws an error if no such GPSState exists in the buffer.
	 */
	virtual GPSData GetStateAtTime(timeval time) = 0;

	/*
	 * Return true if there is at least one state in the buffer.
	 */
	virtual bool StateIsAvailable() = 0;

    Event<GPSData> onNewData;
    Event<void*> onDeviceFailure;
    Event<void*> onDataExpiration;
};

} //Sensors
} //IGVC


#endif /* GPS_HPP_ */
