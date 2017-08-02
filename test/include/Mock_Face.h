#ifndef Face_HEADER
#define Face_HEADER

#include <IFace.h>
#include <IEdge.h>
#include <vector>
#include <memory>

using std::vector;
using std::unique_ptr;

namespace Mock{
    class Face : public IFace_<Face>
    {
        public:
            Face(int value, const vector<unsigned int> indices);
            ~Face(){};

            bool operator==(const Face& aFace) const override;
            bool isFlipped(const Face& aFace) const override;
            vector<unsigned int> myEdgeIndices() const override;


            int getValue() const;
        private:
            int myValue;
            const vector<unsigned int> myIndices;
    };
};
#endif //Face_HEADER
