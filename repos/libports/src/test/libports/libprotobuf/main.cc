/* just a simple test file to confirm linking */

#include "vehicle.pb.h"

int main() {
	protobuf::Vehicle veh;
	veh.set_name("Hello World!");
}
