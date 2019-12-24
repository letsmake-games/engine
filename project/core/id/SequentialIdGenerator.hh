//
// (c) LetsMakeGames 2019
// http://www.letsmake.games
//

#pragma once

#include "Engine.hh"

namespace Engine
{

template<typename IdType>
class SequentialIdGenerator final
{
public: // constructor / destructor ///////////////////////////////////////////

    SequentialIdGenerator() = default;

    SequentialIdGenerator(const SequentialIdGenerator& copy) = delete;

    SequentialIdGenerator(SequentialIdGenerator&& move) = delete;

    ~SequentialIdGenerator() = default;

public: // public methods /////////////////////////////////////////////////////

    //
    // resets the generator, it will begin reusing ids
    //
    inline void reset()
    {
        last = IdType::InvalidValue;
    }

    //
    // gets the last given valid id
    //

    inline IdType prev()
    {
        return IdType(last);
    }

    //
    // gets the next available id.
    //
    inline IdType next()
    {
        IdType result = IdType(last+1);
        if(result != IdType::InvalidId)
        {
            ++last;
        }

        return result;
    }

private: // private members ///////////////////////////////////////////////////

    typename IdType::IdType last = IdType::InvalidValue;

};

}
