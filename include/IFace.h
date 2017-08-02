#ifndef IFace_HEADER
#define IFace_HEADER

#include <IEdge.h>
#include <vector>
#include <memory>

using std::unique_ptr;
using std::vector;

class IFace{
    public:
        ~IFace(){};
        bool operator==(const IFace& aFace) const;
        vector<unsigned int> getEdgeIndices() const;
    protected:
        virtual bool checkEquals_(const IFace& aFace) const = 0;
        virtual vector<unsigned int> myEdgeIndices() const = 0 ;
};

template <class T>
class IFace_ : public IFace
{
    protected:
        bool checkEquals_(const IFace& aFace) const override;

    private:
        virtual bool operator==(const T& aFace) const = 0 ;
        virtual bool isFlipped(const T& aFace) const = 0;
};

// ----- Definitions for abstract classes must be in the header file -------

bool IFace::operator==(const IFace& aFace) const
{
    return this->checkEquals_(aFace);
}

vector<unsigned int> IFace::getEdgeIndices() const{
    return this->myEdgeIndices();
}

template <class T>
bool IFace_<T>::checkEquals_(const IFace& aFace) const
{
    const T* other = dynamic_cast<const T*>(&aFace);
    return (other != nullptr) && (static_cast<const T&>(*this) == *other);
}

#endif //IFace_HEADER
