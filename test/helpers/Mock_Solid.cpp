#include <Mock_Solid.h>

using Mock::Solid;
using std::vector;
using std::unique_ptr;

Solid::Solid(vector<unique_ptr<IEdge>> edges)
    : allEdges(edges)
{
}
