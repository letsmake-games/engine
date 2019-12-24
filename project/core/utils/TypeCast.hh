//
// (C) LetsMakeGames 2019
// http://www.letsmake.games
//

#pragma once

#include "Engine.hh"

#include <memory>

namespace Engine
{

//
// pointer casting ////////////////////////////////////////////////////////////
//
template<class T, class U>
static std::shared_ptr<T> ptrCast(std::shared_ptr<U> from)
{
    return std::static_pointer_cast<T>(from);
}

//
// handle casting /////////////////////////////////////////////////////////////
//

template<class T, class U>
static std::weak_ptr<T> handleCast(std::weak_ptr<U> from)
{
    return std::static_pointer_cast<T>(from.lock());
}

}
