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
            ~Solid(){};

            const vector<unique_ptr<IFace>>& getFaceVector() const override;

        private:
            vector<unique_ptr<IFace>> myFaces;
    };
}

#endif //Solid_HEADER
