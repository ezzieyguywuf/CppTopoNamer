#ifndef ISolid_HEADER
#define ISolid_HEADER

#include <IFace.h>
#include <IEdge.h>
#include <vector>
#include <memory>

using std::vector;
using std::unique_ptr;

class ISolid
{
    public:
        // add a Face to the solid and return the index of the Face within the solid. This
        // index should always refer to the same Face.
        int addFace(const unique_ptr<IEdge>>& edge);
        //vector<int> addFaces(const vector<unique_ptr<IFace>>& faces);

    private:
        virtual int newFace(const vector<unique_ptr<IEdge>>& edges) = 0;
};

int ISolid::addFace(const vector<unique_ptr<IEdge>>& edges)
{
    this->newFace(edges);
}

//int ISolid::addFaces(const vector<unique_ptr<IEdge>>& edges)
//{
    //vector<int> indices;
    //int i;
    //for (const auto& edge : edges) {
        //i = this->newFace(edge);
        //indices.push_back(i);
    //}
    //return indices;
//}

#endif //ISolid_HEADER
