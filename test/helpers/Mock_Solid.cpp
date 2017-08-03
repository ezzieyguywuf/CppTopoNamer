#include <Mock_Solid.h>
#include <IFace.h>

using Mock::Solid;
using Mock::Edge;
using std::vector;
using std::unique_ptr;

Solid::Solid(vector<Face> faces)
{
    for (auto face : faces)
    {
        myFaces.push_back(std::move(unique_ptr<IFace>(new Mock::Face(face))));
    }
}

const vector<unique_ptr<IFace>>& Solid::getFaceVector() const
{
    return myFaces;
}
const unique_ptr<IFace>& Solid::getFace(int which) const{
    return myFaces[which];
}
