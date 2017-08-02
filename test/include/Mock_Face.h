#ifndef Face_HEADER
#define Face_HEADER

#include <IFace.h>
#include <IEdge.h>
#include <Mock_Edge.h>
#include <vector>
#include <memory>

using std::vector;
using std::unique_ptr;

namespace Mock{
    class Face : public IFace_<Face>
    {
        public:
            Face(int myValue, vector<Mock::Edge> edges);
            ~Face(){};

            // overrides from IFace_
            bool operator==(const Face& aFace) const override;
            bool isFlipped(const Face& aFace) const override;
            const vector<unique_ptr<IEdge>>& getEdgeVector() const override;

            // unique to Mock::Face
            int getValue() const;
            void changeEdge(int index, Mock::Edge newEdge);
        private:
            int myValue;
            vector<Mock::Edge> myEdges;
            vector<unique_ptr<IEdge>> shareEdges;
    };
};
#endif //Face_HEADER
