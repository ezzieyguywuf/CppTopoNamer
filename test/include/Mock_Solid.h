#ifndef Solid_HEADER
#define Solid_HEADER

#include <ISolid.h>
#include <IFace.h>
#include <Mock_Face.h>

#include <vector>
#include <memory>

using std::vector;
using std::unique_ptr;

namespace Mock{
    class Solid : public ISolid
    {
        public:
            Solid(vector<Face> faces);
            Solid(const Solid& aSolid);
            Solid(Solid&& aSolid);
            Solid operator=(const Solid& aSolid);
            Solid operator=(Solid&& aSolid);
            ~Solid(){};

            const vector<unique_ptr<IFace>>& getFaceVector() const override;
            const vector<unique_ptr<IEdge>>& getEdgeVector() const override;

            const unique_ptr<IFace>& getFace(int which) const;

        private:
            bool checkEdge(const unique_ptr<IEdge>& anEdge) const;
            vector<unique_ptr<IFace>> myFaces;
            vector<unique_ptr<IEdge>> myEdges;
    };
}

#endif //Solid_HEADER
