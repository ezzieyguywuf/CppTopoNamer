#ifndef CppTopoNamer_Types_HEADER
#define CppTopoNamer_Types_HEADER

#include "IEdge.h"
#include "IFace.h"
#include "ISolid.h"
#include <vector>

namespace Topo{
    typedef pIEdge = std::unique_ptr<IEdge>;
    typedef pIEdges = std::vector<std::unique_ptr<IEdge>>;
    typedef pIFace = std::unique_ptr<IFace>;
    typedef pIFaces = std::vector<std::unique_ptr<IFace>>;
    typedef pISolid = std::unique_ptr<ISolid>;
    typedef pISolids = std::vector<std::unique_ptr<ISolid>>;
}

#endif //CppTopoNamer_Types_HEADER
