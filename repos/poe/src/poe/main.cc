#include <base/printf.h>
#include "position.pb.h"
#include "setup.pb.h"
#include "vehicle.pb.h"
#include "state.pb.h"

int main(int argc, char* argv[]) {
  protobuf::Vehicle veh;
  veh.set_name("veh_1");
  PDBG("Vehicle name: %s", veh.name().c_str());
  return 0;
}
