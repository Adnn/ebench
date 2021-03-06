#pragma once


#include <ebench/aunteater.h>


namespace ad {
namespace ebench {


aunteater::Entity makeEntity()
{
    return aunteater::Entity{}
            .add<Position>()
            .add<Displacement>();
}


void createEntities(aunteater::Engine & aEngine, std::size_t aCount)
{
    for (std::size_t id = 0; id != aCount; ++id)
    {
        aEngine.addEntity(makeEntity());
    }
}


template <int N=0>
aunteater::Engine & addSystems(aunteater::Engine & aEngine)
{
    return aEngine;
}


template <class T_systemHead, class... VT_systemTail>
aunteater::Engine & addSystems(aunteater::Engine & aEngine)
{
    aEngine.addSystem<T_systemHead>();
    return addSystems<VT_systemTail...>(aEngine);
}


void simulateStep(aunteater::Engine & aEngine)
{
    aunteater::Timer timer;
    timer.mark(1.0);
    aEngine.update(timer);
}


} // namespace ebench
} // namespace ad
