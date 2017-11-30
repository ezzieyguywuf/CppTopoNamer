#ifndef OccObjectMaker_HEADER
#define OccObjectMaker_HEADER

#include <memory> // for unique_ptr
#include <vector>
#include <map>
#include <tuple>
#include <utility> // for pair
#include <string>

#include <Topology/ISolid.h>
#include <Managers/Types.h>

using std::unique_ptr;
using std::vector;
using std::tuple;
using std::pair;

using Manager::FaceIndex;

class OccObjectMaker
{
    public:
        unique_ptr<ISolid> makeBox();
        unique_ptr<ISolid> makeCyl();
        //unique_ptr<ISolid> makeFuse();
        // As a result of this operation, origBox should have the same number of Faces,
        // however each Face should be different (per the current FreeCAD implementation)
        tuple<unique_ptr<ISolid>, vector<pair<FaceIndex, FaceIndex>>> 
            increaseBoxHeight(const ISolid& origBox);
};
#endif // OccObjectMaker_HEADER
