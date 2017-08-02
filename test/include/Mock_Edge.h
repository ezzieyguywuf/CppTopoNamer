#ifndef Edge_HEADER
#define Edge_HEADER

#include <IEdge.h>

namespace Mock{
    // An implementation of the IEdge interface. Notice that we inherit from IEdge_
    // instead of IEdge directly. This is because IEdge_ contains some basic,
    // 'boilerplate' that any descendent of IEdge must have, therefore it has been put in
    // one common location.
    class Edge : public IEdge_<Edge>
    {
        public:
            Edge(int val);
            ~Edge(){};

            bool operator==(const Edge& anEdge) const override;
            bool isFlipped(const Edge& anEdge) const override;

            int getVal() const;
        private:
            int val;
    };
};

#endif //Edge_HEADER
