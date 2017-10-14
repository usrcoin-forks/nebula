#pragma once

#include <calibrae/protocol/asset.hpp>

namespace steemit { namespace chain { namespace util {

using steemit::protocol::asset;
using steemit::protocol::price;

inline asset to_sbd( const price& p, const asset& steem )
{
   FC_ASSERT( steem.symbol == NECTAR_SYMBOL );
   if( p.is_null() )
      return asset( 0, SBD_SYMBOL );
   return steem * p;
}

inline asset to_steem( const price& p, const asset& sbd )
{
   FC_ASSERT( sbd.symbol == SBD_SYMBOL );
   if( p.is_null() )
      return asset( 0, NECTAR_SYMBOL );
   return sbd * p;
}

} } }
