#ifndef SolidManager_Types_HEADER
#define SolidManager_Types_HEADER

namespace Manager{
    class Index{
        public:
            Index(){};
            Index(unsigned int anIndex)
                : index(anIndex){};
            virtual ~Index() = 0;
            unsigned int get() const{
                return index;
            }
            bool operator <(const Index& anIndex) const{
                return index < anIndex.get();
            }

        protected:
            unsigned int index;
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
                return *this;
            }
    };
}
#endif //SolidManager_Types_HEADER
