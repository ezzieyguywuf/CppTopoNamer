#ifndef SolidManager_Types_HEADER
#define SolidManager_Types_HEADER

#include <stdexcept>

namespace Manager{
    class Index{
        public:
            inline Index();
            inline Index(const Index& anIndex);
            inline Index(unsigned int anIndex);
            inline virtual ~Index() = 0;
            inline Index& operator=(const Index& anIndex);
            inline unsigned int get() const;
            inline bool isValid() const;
            inline bool operator <(const Index& anIndex) const;
            inline bool operator >(const Index& anIndex) const;
            inline bool operator ==(const Index& anIndex) const;
            inline bool operator !=(const Index& anIndex) const;

        protected:
            unsigned int index;
            bool valid;
    };

    class FaceIndex : public Index{
        public:
            inline FaceIndex();
            inline FaceIndex(const FaceIndex& aFaceIndex);
            inline FaceIndex(unsigned int anIndex);
            inline ~FaceIndex();
            inline FaceIndex operator=(const FaceIndex& aFaceIndex);
    };
    class EdgeIndex : public Index{
        public:
            inline EdgeIndex();
            inline EdgeIndex(const EdgeIndex& aEdgeIndex);
            inline EdgeIndex(unsigned int anIndex);
            inline ~EdgeIndex();
            inline EdgeIndex operator=(const EdgeIndex& aEdgeIndex);
    };
}

// ------------- Must define methods in pure virtual class in header ------------

using Manager::Index;
using Manager::FaceIndex;
using Manager::EdgeIndex;

Index::Index()
    : valid(false){};

Index::Index(const Index& anIndex)
    : index(anIndex.index), valid(anIndex.valid)
{}
Index::Index(unsigned int anIndex)
    : index(anIndex), valid(true)
{}

Index::~Index(){}

Index& Index::operator=(const Index& anIndex)
{
    this->valid = anIndex.valid;
    this->index = anIndex.index;
    return *this;
}

unsigned int Index::get() const
{
    if (not this->isValid())
        throw std::runtime_error("Index is not valid");
    return this->index;
}

bool Index::isValid() const
{
    return this->valid;
}

bool Index::operator<(const Index& anIndex) const
{
    if (not this->isValid())
        throw std::runtime_error("Index is not valid");
    return this->index < anIndex.get();
}

bool Index::operator>(const Index& anIndex) const
{
    if (not this->isValid())
        throw std::runtime_error("Index is not valid");
    return this->index > anIndex.get();
}

bool Index::operator==(const Index& anIndex) const
{
    if (not valid)
        throw std::runtime_error("Index is not valid");
    return this->index == anIndex.get();
}

bool Index::operator!=(const Index& anIndex) const
{
    if (not valid)
        throw std::runtime_error("Index is not valid");
    return this->index != anIndex.get();
}


FaceIndex::FaceIndex()
    : Index()
{}

FaceIndex::FaceIndex(const FaceIndex& aFaceIndex)
    : Index(aFaceIndex)
{}

FaceIndex::FaceIndex(unsigned int anIndex)
    : Index(anIndex)
{}

FaceIndex::~FaceIndex()
{}

FaceIndex FaceIndex::operator=(const FaceIndex& aFaceIndex)
{
    Index::operator=(aFaceIndex);
    return *this;
}

EdgeIndex::EdgeIndex()
    : Index()
{}

EdgeIndex::EdgeIndex(const EdgeIndex& aEdgeIndex)
    : Index(aEdgeIndex)
{}

EdgeIndex::EdgeIndex(unsigned int anIndex)
    : Index(anIndex)
{}

EdgeIndex::~EdgeIndex()
{}

EdgeIndex EdgeIndex::operator=(const EdgeIndex& aEdgeIndex)
{
    Index::operator=(aEdgeIndex);
    return *this;
}


#endif //SolidManager_Types_HEADER
