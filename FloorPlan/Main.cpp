

#include "Helpers.h"
#include "Geom.h"








int main() {

	double time = getTime();

	for (int i = 0; i < 1000000; i++) {
		auto bos = createBox(0, 10, 0, 10);
		//std::cout << bos->getGeometryType() << std::endl;
	}

	std::cout << getTime() - time << std::endl;
	return 0;
}


/*#include <iostream>
#include "Geom.h"
#include "Ops.h"
#include "Room.h"
#include "Helpers.h"

int main() {

    double t1 = getTime();

    for (int i = 0; i < 1000; i++) {

        auto room1 = Room(point_t(1, 1), 2, 2);
        auto room2 = Room(point_t(2, 2), 2, 2);


        //auto intersection = room1 - (room1 * room2);

        //std::cout << "Room 1: " << bg::wkt(intersection) << std::endl;

        //std::cout << "Room 1 bef: " << bg::wkt(room1.get_poly()) << std::endl;
        room1 -= room2;
        //std::cout << "Room 1 aft: " << bg::wkt(room1.get_poly()) << std::endl;
    }

    std::cout << getTime() - t1 << std::endl;

    return 0;
}

*/