#ifndef SolidManager_Types_HEADER
#define SolidManager_Types_HEADER

#include <stdexcept>

namespace Manager{
    class Index{
        public:
            Index()
                : valid(false){};
            Index(unsigned int anIndex)
                : index(anIndex), valid(true){};
            virtual ~Index() = 0;
            unsigned int get() const{
                if (not valid)
                {
                    throw std::runtime_error("Index is not valid");
                }
                return index;
            }
            bool isNull() const{
                return valid;
            }
            bool operator <(const Index& anIndex) const{
                if (not valid)
                {
                    throw std::runtime_error("Index is not valid");
                }
                return index < anIndex.get();
            }

        protected:
            unsigned int index;
            bool valid;
    };
    inline Index::~Index(){};

    class FaceIndex : public Index{
        public:
            FaceIndex(){};
            FaceIndex(unsigned int anIndex)
                : Index(anIndex){};
            FaceIndex(const FaceIndex& aFace)
                : Index(aFace.index)
            {
            }
            FaceIndex operator=(const FaceIndex& aFace){
                index = aFace.index;
                valid = true;
                return *this;
            }
    };
    class EdgeIndex : public Index{
        public:
            EdgeIndex(){};
            EdgeIndex(unsigned int anIndex)
                : Index(anIndex){};
            EdgeIndex(const EdgeIndex& aEdge)
                : Index(aEdge.index)
            {
            }
            EdgeIndex operator=(const EdgeIndex& anEdge){
                index = anEdge.index;
                valid = true;
                return *this;
            }
    };
}
#endif //SolidManager_Types_HEADER
