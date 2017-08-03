#ifndef ISolid_HEADER
#define ISolid_HEADER

#include <IFace.h>
#include <vector>
#include <memory>

using std::vector;
using std::unique_ptr;

class ISolid
{
    public:
        ~ISolid(){};
        const vector<unique_ptr<IFace>>& getFaces() const;

    private:
        virtual const vector<unique_ptr<IFace>>& getFaceVector() const = 0;
};

const vector<unique_ptr<IFace>>& ISolid::getFaces() const
{
    return this->getFaceVector();
}

#endif //ISolid_HEADER
