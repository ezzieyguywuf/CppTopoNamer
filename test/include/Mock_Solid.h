#ifndef Solid_HEADER
#define Solid_HEADER

#include <ISolid.h>
#include <vector>
#include <memory>

using std::vector;
using std::unique_ptr;

namespace Mock{
    class Solid : public ISolid
    {
        public:
            Solid(vector<unique_ptr<IEdge>>& edges);
            ~Solid(){};

            int addFace(const vector<unique_ptr<IEdge>>& anEdge) override;

        private:
            vector<unique_ptr<IEdge>>& allEdges;
    };
}

#endif //Solid_HEADER
