//
// (C) LetsMakeGames 2019
// http://www.letsmake.games/
//

#include "core/id/ClassId.hh"

namespace blacktriangles
{

//
// constructor / destructor ///////////////////////////////////////////////////
//

ClassId::ClassId()
    : name()
    , id()
    , base_id(nullptr)
{
}

//
// ----------------------------------------------------------------------------
//

ClassId::ClassId(const std::string& name)
    : name(name)
    , id(name)
    , base_id(nullptr)
{
}

//
// ----------------------------------------------------------------------------
//

ClassId::ClassId(const std::string& name, const ClassId& base)
    : name(name)
    , id(name)
    , base_id(&base)
{
}

//
// public methods /////////////////////////////////////////////////////////////
//

bool ClassId::isTypeOf(const ClassId& class_id) const
{
    if(&class_id == this) return true;
    if(base_id == nullptr) return false;
    return base_id->isTypeOf(class_id);
}

}
